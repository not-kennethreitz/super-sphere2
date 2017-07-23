Timer = require('vendor/hump.timer')
Signal = require('vendor/hump.signal')
Gamestate = require('vendor/hump.gamestate')
keys = require('keys')
sound = require('sound')
game = require('game')

local FONT_HEIGHT = 72
local INTRO_LENGTH = 1
local DEATH_LENGTH = 0.8
local GAME_NAME = 'Super Sphere II'

-- Game States.

local intro = {}
local pause = {}
local play = {}
local dead = {}


Signal.register('pause', function()
    Gamestate.push(pause)
end)

Signal.register('unpause', function()
    Gamestate.pop()
end)

Signal.register('toggle-pause', function()
    if Gamestate.current() == pause then
        Signal.emit('unpause')
    else
        Signal.emit('pause')
    end
end)

Signal.register('death', function()
    Gamestate.switch(dead)
end)


function love.load()
    -- Dimensions.
    X, Y = love.graphics.getDimensions()
    print('Running in '..X..'x'..Y..' mode.')

    Gamestate.registerEvents()

    music = love.audio.newSource('assets/music.mp3')
    music:setLooping(true)

    jump_sound = love.audio.newSource('assets/jump.wav')
    eat_sound = love.audio.newSource('assets/eat.wav')

    font = love.graphics.newFont('assets/leaguespartan-bold.ttf', FONT_HEIGHT)
    love.graphics.setFont(font, 55)

    -- The operating system.
    mobile = (love.system.getOS() == 'iOS') or (love.system.getOS() == 'Android')

    -- Initialize the pseudo random number generator
    math.randomseed(os.time())
    math.random(); math.random(); math.random()

    Gamestate.switch(intro)
    Gamestate.push(intro)
end

function love.resize(w, h)
    X, Y = love.graphics.getDimensions()
end


function love.focus(f)
    if f then
        Signal.emit('unpause')
    else
        Signal.emit('pause')
    end
end

-- The Intro.
-- --------

function intro:init()
    IntroTimer = Timer.new()
end

function intro:draw()
    love.graphics.printf(GAME_NAME, 0, Y/2 - FONT_HEIGHT/2, X, 'center')
end

function intro:enter(previous)

    IntroTimer:script(function(wait)
        -- Wait for things to order properly.
        wait(0.05)

        print("Making introductions...")
        wait(INTRO_LENGTH)

        Gamestate.push(play)
    end)

end

function intro:update(dt)
    IntroTimer:update(dt)
end



-- The Pause Menu.
-- --------

function pause:draw()
    love.graphics.setColor({255, 255, 255})
    love.graphics.printf("PAUSE", 0, Y/2 - FONT_HEIGHT/2, X, 'center')
end

function pause:keypressed(key, scancode, isrepeat)
    play:keypressed(key, scancode, isrepeat)
end

function pause:joystickpressed(joystick, button)
    play:joystickpressed(joystick, button)
end


-- Game Over.
-- ---------

function dead:enter()
    dead.clear = false

    Signal.emit('game-over-started')

    Timer.after(DEATH_LENGTH, function()
        dead.clear = true
        Signal.emit('game-over-finished')
    end)
end

function dead:exit()
    dead.clear = false
end

function dead:draw()
    love.graphics.setColor({255, 255, 255})
    love.graphics.printf("Game Over", 0, Y/2 - FONT_HEIGHT/2, X, 'center')
    love.graphics.printf(game:visual_score(), (X/24)*1, ((Y/12)*1 - FONT_HEIGHT/2), (X/24)*3, 'left')
end

-- Mouse support.
function dead:mousepressed(x, y, button, istouch)
    if dead.clear then
        play:mousepressed(x, y, button, istouch)
    end
end

-- Joystick support.
function dead:joystickpressed(joystick, button)
    if dead.clear then
        play:joystickpressed(joystick, button)
    end
end

function dead:keypressed(key, scancode, isrepeat)
    if dead.clear then
        play:keypressed(key, scancode, isrepeat)
    end
end




-- The Game.
-- --------

function play:enter()
    -- Signal.emit('started')
end

function draw_background()
    -- Left Side
    love.graphics.setColor({255, 255, 255, 25})
    love.graphics.polygon('fill',
        0, 0,
        0, Y,
        X/2, Y,
        X/2, 0)

    -- Right Side.
    love.graphics.setColor({255, 255, 255, 18})
    love.graphics.polygon('fill',
        X/2, 0,
        X/2, Y,
        X, Y,
        X, 0)
end

function draw_score()
    love.graphics.setColor({255, 255, 255})
    love.graphics.printf(game:visual_score(), (X/24)*1, ((Y/12)*1 - FONT_HEIGHT/2), (X/24)*3, 'left')
end

function play:draw()
    draw_background()
    draw_score()
    game:draw_obstacles()
    game.guy:draw()

end

function play:update(dt)
    game:update(dt)
end

function play:leave()
    Signal.emit('ended')
end


-- The Controls.
-- ------------

function left_or_right(x, y)
    return x < X/2 and 'left' or 'right'
end

-- Mouse support.
function play:mousepressed(x, y, button, istouch)
    Signal.emit('user-input')
    Signal.emit(left_or_right(x, y))
end

function play:mousereleased(x, y)
    Signal.emit(left_or_right(x, y)..'-released')
end

-- Joystick support.
function play:joystickpressed(joystick, button)
    Signal.emit('register-joystick', joystick)

    Signal.emit('user-input')
    Signal.emit(button)
    -- print(joystick:getButtonCount())

    -- print(js:getButtonCount())
    -- print(button)
end

function play:keypressed(key, scancode, isrepeat)
    if not isrepeat then
        Signal.emit('user-input')
        Signal.emit('keypressed', key)
        Signal.emit(key)
    end
end

function play:keyreleased(key, scancode)
    Signal.emit('keyreleased', key)
    Signal.emit(key..'-released')
end


function love.update(dt)
    Timer.update(dt)
    keys(dt)
end


Signal.register('game-over', function()
    print('Game Over!')
    Gamestate.switch(dead)
    -- Timer.clear()
end)

Signal.register('quit', function()
    print('Quitting!')
    love.event.quit()
end)

Signal.register('user-input', function()
    if Gamestate.current() == dead then
        game:initialize(false)
        Gamestate.switch(play)
    end
end)

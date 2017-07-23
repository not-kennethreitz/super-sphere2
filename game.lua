Timer = require('vendor/hump.timer')
Signal = require('vendor/hump.signal')
Class = require('vendor/middleclass')
lue = require('vendor/lue')

BreathTimer = Timer.new()
GameTimer = Timer.new()

local SCORE_MULTIPLIER = 54
local POISON_RATE = 80


-- Helper methods.
function comma_value(amount)
  local formatted = amount
  while true do
    formatted, k = string.gsub(formatted, "^(-?%d+)(%d%d%d)", '%1,%2')
    if (k==0) then
      break
    end
  end
  return formatted
end

local Breath = Class('Breath')

Breath.static.standard_interval = 0.8
Breath.static.fast_interval = 0.1
Breath.static.in_out_ratio = 0.8
Breath.static.recovery_time = 1

function Breath:initialize()
    self.rate = 0.8
    self.status = 0
    self._inhale = true
    self.timer = nil
end

function Breath:update(dt)
    self:cycle(dt)
end

function Breath:cycle(dt)
    if self.status < 0 then
        self._inhale = true
    end

    if self._inhale then
        self.status = self.status + ((dt/1) * (1 / self.rate))
    else
        self.status = self.status - ((dt/1) * (1 / self.rate))
    end

    if self.status > 1 then
        self._inhale = false
    end
end


-- Obstacles.
local Obstacle = Class('Obstacle')
Obstacle.static.start_fall_speed = 3.5
Obstacle.static.end_fall_speed = 0.7
Obstacle.static.end_speed_time = 60
Obstacle.static.fall_speed = Obstacle.static.start_fall_speed

function Obstacle:initialize(pos, fs, p)
    self.breath = Breath()
    if p == nil then
        self.poison = math.random(1, 100) > POISON_RATE
    else
        self.poison = p
    end

    self.position = pos or math.random(1, 3)
    if self.poison then
        self.breath.rate = 0.07
        self.approach = -0.05
        self.approach = 0
        self._fall_speed = math.random(1, 5)
    else
        self.approach = 0
    end

    -- self.approach = 0
    self.color = Obstacle:random_color()
    self.destroyed = false
    self._fall_speed = fs
    self.game = nil

    -- Make poison obstacles render offscreen.
    if self.poison then
        target_approach = 1.1
    else
        target_approach = 1
    end

    -- Make the balls fall.
    GameTimer:tween(self:fall_speed(), self, {approach = target_approach}, 'in-cubic')
end

function Obstacle:fall_speed()
    return self._fall_speed or Obstacle.fall_speed
end

function Obstacle:draw()
    x_locations = {(X/6)*1, (X/6)*3, (X/6)*5}

    love.graphics.setColor(self.color)
    love.graphics.circle('fill', x_locations[self.position], Y*self.approach, self:current_size())
end

function Obstacle:current_size()
    if self.poison then
        size = (X/80)
    else
        size = (X/40)
    end

    return size + (X/300)*self.breath.status
end

function Obstacle:random_color()

    local c = lue:getHueColor(128, 200)
    lue:setHueSpeed(255)
    return c
end

function Obstacle:destroy()
    self.destroyed = true
end

function Obstacle:update(dt)
    -- Gets called every frame.
    self.breath:update(dt)

    -- Destroy fallen obstacles.
    if self.approach > 1 then
        self:destroy()
    end

    if self.poison then
        -- Change the color of poision obstacles.
        self.color = {255, 0, 0}
    else
        -- Random colors for normal ones.
        self.color = Obstacle:random_color()
    end
end







local Jump = Class('Jump')
Jump.static.duration = 0.08

function Jump:initialize()
    self.current = 0
    self.direction = 0
end

function Jump:now(direction)
    -- Only jump if not currently in the air.
    if not self:in_air() then
        -- Jump = 1 at max.
        self.current = 1

        -- Which direction the jump is in.
        self.direction = direction

        -- Make the jump happen.
        GameTimer:tween(Jump.duration, self, {current = 0})
        -- Enssure that 0 is set aferwards.
        GameTimer:after(Jump.duration + 0.05, function() self.current = 0 end)
        -- Emit 'landed' signal.
        GameTimer:after(Jump.duration, function() Signal.emit('landed') end)
        -- Reset direction to 0.
        GameTimer:after(Jump.duration + 0.05, function() self.direction = 0 end)

    end
end

function Jump:in_air()
    return self.current ~= 0
end



local Guy = Class('Guy')

function Guy:initialize()
    self.jump = Jump()
    self.breath = Breath()
    self.position = 2
    self.eaten = 0

    self:script()
end

function Guy:script()
    Signal.emit('normal-breathing')
end

function Guy:apparent_position()
    -- goes from 1 to 0

    if self.jump:in_air() then
        return 0
        -- return self.position - self.jump.direction
    else
        return self.position
    end


end

function Guy:draw()
    local x_breath_offset = (self.breath.status * (X / 500))

    if self.jump:in_air() then
        love.graphics.setColor(lue:getHueColor(128, 200))
    else
        love.graphics.setColor({255, 255, 255})
    end
    love.graphics.circle('fill', (self:x_center()), (self:y_center() - x_breath_offset), game.guy:current_size())
end

function Guy:x_center()

    x_locations = {(X/6)*1, (X/6)*3, (X/6)*5}
    track_distance = x_locations[2] - x_locations[1]

    jump_offset = (-1 * self.jump.direction) * ((self.jump.current) * track_distance)

    return x_locations[self.position] + jump_offset
    -- else
    --     return (X / 8) * 5 - ((X / 8) * 2) * self.current_jump
    -- end
end

function Guy:y_center()
    return Y
end


function Guy:current_size()
    return (Y/10) + (self.eaten * 4) + (self.breath.status * (X/500))
end

function Guy:update(dt)
    self.breath:update(dt)
    BreathTimer:update(dt)
end

Signal.register('obstacle-caught', function(obstacle)
    game.guy.eaten = game.guy.eaten + 1
end)


Signal.register('heavy-breathing', function()

    -- Abandon previous tweens.
    BreathTimer:clear()

    BreathTimer:tween(0.1, game.guy.breath, {rate = Breath.fast_interval}, 'out-expo')
    BreathTimer:after(0.15, function()
        BreathTimer:tween(Breath.recovery_time, game.guy.breath, {rate = Breath.standard_interval}, 'in-quint')
    end)

    BreathTimer:after(Breath.recovery_time, function()
        Signal.emit('normal-breathing')
    end)
end)



local Game = Class('Game')

function Game:initialize(do_demo)
    self.elapsed = 0
    self.started = false
    self.demo = do_demo
    self.guy = Guy()
    self.obstacles = {}
    self.obstacle_interval = 2
    self.obstacle_min_interval = Jump.duration * 7

    GameTimer:clear()

    GameTimer:script(function(wait)

        if self.demo then
            wait(0.01)
            print('Demo starting...')


            demo_obstacle = Obstacle(1, 1, false)
            table.insert(self.obstacles, demo_obstacle)

            wait(0.8)

            self:left()

            wait(0.2)
            demo_obstacle = Obstacle(2, 1, true)
            table.insert(self.obstacles, demo_obstacle)

            wait(0.3)
            self:right()

            wait(0.5)
            self:right()
            wait(0.3)
            self:left()

            wait(0.3)
        end

        GameTimer:tween(60, self,  {obstacle_interval = self.obstacle_min_interval}, 'out-quad')

        Signal.emit('started')
        print('Game starting...')
        self.started = true
        self:obsticate()
    end)

    -- Restore Poision rate.
    POISON_RATE = 80

    -- Restore fall speed.
    Obstacle.static.fall_speed = Obstacle.static.start_fall_speed

    -- Make obstacles fall faster and faster.
    GameTimer:tween(Obstacle.static.end_speed_time, Obstacle.static, {fall_speed = Obstacle.static.end_fall_speed})

end

function Game:obsticate()
    GameTimer:after(math.random(1, 3)/10, function()

        -- if self:score() > 1 then
        --     num_balls = math.random(1, 2)
        -- else
        --     num_balls = 1
        -- end

        num_balls = 1

        self:new_obstacles(num_balls)
    end)

    GameTimer:after(self.obstacle_interval, function()
        self:obsticate()
    end)
end

function Game:update(dt)
    lue:update(dt)
    GameTimer:update(dt)

    if self.started then
        self.elapsed = self.elapsed + dt
    end

    self.guy:update(dt)
    self:catch_obstacles()

    for i, obstacle in ipairs(self.obstacles) do

        obstacle:update(dt)

        if obstacle.destroyed then
            table.remove(self.obstacles, i)
        end
    end

    for i, obstacle in ipairs(self.obstacles) do

        if obstacle.approach == 1 and not obstacle.poison then
            Signal.emit('game-over')
        end
    end

    POISON_RATE = POISON_RATE - dt
    if POISON_RATE < 30 then
        POISON_RATE = 30
    end
end

function Game:new_obstacles(n)
    for i=1,n do
        -- Timer.after(math.random(7, 10), function()
            table.insert(self.obstacles, Obstacle())
        -- end)
    end

end

function Game:draw_obstacles()
    for i, obstacle in ipairs(self.obstacles) do
        obstacle:draw()
    end
end

function Game:catch_obstacles()
    for i, obstacle in ipairs(game.obstacles) do
        if obstacle.position == game.guy:apparent_position() and obstacle.approach > 0.82 then
            if not (obstacle.poision and obstacle.approach > 0.9) then
                Signal.emit('obstacle-caught', obstacle)
            end
        end
    end
end

function Game:score()
    return self.elapsed * SCORE_MULTIPLIER
end

function Game:visual_score()
    return comma_value(math.floor(self:score()))
end

function Game:left()
    if self.guy.position ~= 1 then
        if not game.guy.jump:in_air() then
            Signal.emit('jump', -1)
        end
    else
        Signal.emit('mis-jump')
    end
end

function Game:right()
    if self.guy.position ~= 3 then
        if not game.guy.jump:in_air() then
            Signal.emit('jump', 1)
        end
    else
        Signal.emit('mis-jump')
    end
end



game = Game(true)

Signal.register('jump', function(direction)
    game.guy.jump:now(direction)
    game.guy.position = game.guy.position + direction
end)

Signal.register('obstacle-caught', function(obstacle)

    if obstacle.poison then
        Signal.emit('game-over')
    else
        obstacle:destroy()
    end

    Signal.emit('heavy-breathing')
end)



Signal.register('left-event', function()
    game:left()
end)

Signal.register('right-event', function()
    game:right()
end)

return game
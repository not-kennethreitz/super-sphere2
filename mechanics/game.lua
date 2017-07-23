Timer = require('vendor/hump.timer')
Signal = require('vendor/hump.signal')
Class = require('vendor/middleclass')
lue = require('vendor/lue')

Breath = require('mechanics/breath')
Obstacle = require('mechanics/obstacle')
Jump = require('mechanics/jump')
Guy = require('mechanics/guy')

BreathTimer = Timer.new()
GameTimer = Timer.new()

local SCORE_MULTIPLIER = 54


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
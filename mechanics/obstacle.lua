Breath = require('mechanics/Breath')

local POISON_RATE = 80


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

return Obstacle
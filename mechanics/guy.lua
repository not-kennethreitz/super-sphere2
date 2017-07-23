
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

return Guy

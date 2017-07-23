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

return Jump
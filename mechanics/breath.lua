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

return Breath
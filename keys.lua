Signal = require('vendor/hump.signal')
Timer = require('vendor/hump.timer')

KEY_REPEAT = 0.2
LeftTimer = Timer.new()
RightTimer = Timer.new()

js = love.joystick.getJoysticks()[1]

-- Escape vavles.
Signal.register('escape', function()
    Signal.emit('toggle-pause')
end)

Signal.register('q', function()
    Signal.emit('quit')
end)


-- Left / Right support.
Signal.register('left', function()
    -- LeftTimer = Timer.new()

    RightTimer:clear()
    Signal.emit('left-event')

    LeftTimer:every(KEY_REPEAT, function()
        Signal.emit('left-event')
    end)
end)

Signal.register('right', function()

    LeftTimer:clear()
    Signal.emit('right-event')

    RightTimer:every(KEY_REPEAT, function()
        Signal.emit('right-event')
    end)
end)

Signal.register('left-released', function()
    LeftTimer:clear()
end)

Signal.register('right-released', function()
    RightTimer:clear()
end)


once = false
Signal.register('register-joystick', function(joystick)
    js = joystick

    if not once then
        Signal.register(js:getButtonCount(), function()
            Signal.emit('toggle-pause')
        end)
        once = true
    end
end)

js_l_hats_on = false
js_r_hats_on = false

function js_hat_manager(d)

    if d == 'l' then
        if not js_l_hats_on then
            Signal.emit('left')
            js_l_hats_on = true
        end

    elseif d == 'r' then
        if not js_r_hats_on then
            Signal.emit('right')
            js_r_hats_on = true
        end
    else
        if js_l_hats_on then
            Signal.emit('left-released')
            js_l_hats_on = false
        end

        if js_r_hats_on then
            Signal.emit('right-released')
            js_r_hats_on = false
        end

        return nil
    end
end

js_l_axis_on = false
js_r_axis_on = false

function js_axis_manager(v)

    if v < -0.5 then
        if not js_l_axis_on then
            Signal.emit('left')
            js_l_axis_on = true
        end

    elseif v > 0.5 then
        if not js_r_axis_on then
            Signal.emit('right')
            js_r_axis_on = true
        end
    else
        if js_l_axis_on then
            Signal.emit('left-released')
            js_l_axis_on = false
        end

        if js_r_axis_on then
            Signal.emit('right-released')
            js_r_axis_on = false
        end

        return nil
    end
end



function update(dt)
    LeftTimer:update(dt)
    RightTimer:update(dt)

    if js then
        js_axis_manager(js:getAxis(1))
        js_hat_manager(js:getHat(1))
    end

end

return update
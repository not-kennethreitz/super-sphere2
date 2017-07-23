Signal = require('vendor/hump.signal')

Signal.register('started', function()
    music:play()
end)

Signal.register('ended', function()
    love.audio.stop()
end)

Signal.register('pause', function()
    love.audio.pause()
end)

Signal.register('unpause', function()
    love.audio.resume()
end)

Signal.register('game-over-started', function()
    game_over_music:play()
end)

Signal.register('game-over-finished', function()
    game_over_music:stop()
end)


Signal.register('jump', function()
    jump_sound:setPitch(0.9)
    jump_sound:play()
end)

Signal.register('obstacle-caught', function()
    jump_sound:setPitch(1.1)
    eat_sound:play()
end)


Signal.register('obstacle-destroyed', function()
    jump_sound:setPitch(0.5)
    jump_sound:play()
end)
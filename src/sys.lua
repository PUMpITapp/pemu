local sys = {}

--------------------------------------------------------------------------------
--- Timer Class
--------------------------------------------------------------------------------

Timer = {}

function Timer:new(interval, callback)
  o = { interval=interval, callback=callback}
  self.__index = self
  return setmetatable(o, self)
end

function Timer:set_interval()
  -- body
end

function stop()
  -- body
end

function start()
  -- body
end

--------------------------------------------------------------------------------
--- Sys Module definitions
--------------------------------------------------------------------------------

function sys.new_timer(interval_millisec, callback)

end

function sys.stop()

end

function sys.time()

end

return sys

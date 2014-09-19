local gfx = {}

--------------------------------------------------------------------------------
--- Surface Class
--------------------------------------------------------------------------------

Surface = {}

function Surface:new(width, height)
  o = {x=0, y=0, w=width, h=height, r=0, g=0, b=0, a=0}
  self.__index = self
  self.__cref = surface_new(o.x, o.y, o.w, o.h, o.r, o.g, o.b, o.a)
  return setmetatable(o, self)
end

function Surface:clear()
  print("Not implemented yet.")
end

function Surface:fill()
  print("Not implemented yet.")
end

function Surface:copyfrom()
  print("Not implemented yet.")
end

function Surface:get_width()
  return self.w
end

function Surface:get_height()
  return self.h
end

function Surface:get_pixel()
  print("Not implemented yet.")
end

function Surface:set_pixel()
  print("Not implemented yet.")
end

function Surface:premultiply()
  print("Not implemented yet.")
end

function Surface:destroy()
  print("Not implemented yet.")
end


--------------------------------------------------------------------------------
--- GFX Module definitions
--------------------------------------------------------------------------------
gfx.screen = Surface:new(640, 480)

function gfx.set_auto_update()
  return gfx_set_auto_update()
end

function gfx.new_surface(width, height)
  if width < 0 then
    error("invalid width")
  end
  if height < 0 then
    error("invalid height")
  end
  return Surface:new(width, height)
end

function gfx.get_memory_use()
  return gfx_get_memory_use()
end

function gfx.get_memory_limit()
  return gfx_get_memory_limit()
end

function gfx.update()
  return gfx_update()
end

function gfx.loadpng(path)
  return gfx_loadpng()
end

function gfx.loadjpeg(path)
  return gfx_loadjpeg()
end

return gfx

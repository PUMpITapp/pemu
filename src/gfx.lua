local gfx = {}

--------------------------------------------------------------------------------
--- Surface Class
--------------------------------------------------------------------------------

Surface = {}

function Surface:new(w, h)
  o = {}
  self.__index = self
  self.__cref = surface_new(w, h)
  return setmetatable(o, self)
end

function Surface:getDefaultSurface(w, h)
  o = {}
  self.__index = self
  self.__cref = surface_getWindowSurface()
  return setmetatable(o, self)
end

function Surface:clear(c, r)
  surface_clear(self.__cref, c, r)
end

function Surface:fill(c, r)
  surface_fill(self.__cref, c, r)
end

function Surface:copyfrom(ss, sr, dr, b)
  surface_copyfrom(self.__cref, ss.__cref, sr, dr, b)
end

function Surface:get_width()
  return surface_get_width(self.__cref)
end

function Surface:get_height()
  return surface_get_height(self.__cref)
end

function Surface:get_pixel(x, y)
  print("Not implemented yet.")
end

function Surface:set_pixel(x, y, c)
  print("Not implemented yet.")
end

function Surface:premultiply()
  surface_premultiply(self.__cref)
end

function Surface:destroy()
  surface_destroy(self.__cref)
end


--------------------------------------------------------------------------------
--- GFX Module definitions
--------------------------------------------------------------------------------
gfx.screen = Surface:getDefaultSurface()

function gfx.set_auto_update()
  return gfx_set_auto_update()
end

function gfx.new_surface(w, h)
  if w < 0 or h > 9999 then
    error("invalid width")
  end
  if w < 0 or h > 9999 then
    error("invalid height")
  end
  return Surface:new(w, h)
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

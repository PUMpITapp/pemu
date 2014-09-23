#include "gfx.h"


int
gfx_set_auto_update(lua_State *L) {
  return 1;
}

int
gfx_get_memory_use(lua_State *L) {
  lua_pushnumber(L, 0);
  return 1;
}

int
gfx_get_memory_limit(lua_State *L) {
  lua_pushnumber(L, MEMORY_LIMIT);
  return 1;
}

int
gfx_update(lua_State *L) {
  SDL_UpdateWindowSurface(window);
  return 0;
}

int
gfx_loadpng(lua_State *L) {
  const char *path = luaL_checkstring(L, 1);

  SDL_Surface *surface = IMG_Load(path);

  lua_pushlightuserdata(L, (void*)surface);
  return 1;
}

int
gfx_loadjpeg(lua_State *L) {
  const char *path = luaL_checkstring(L, 1);

  SDL_Surface *surface = IMG_Load(path);

  lua_pushlightuserdata(L, (void*)surface);
  return 1;
}

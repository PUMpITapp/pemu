#include "gfx.h"


int
gfx_set_auto_update(lua_State *L) {
  return 1;
}

int
gfx_new_surface(lua_State *L) {
  return 1;
}

int
gfx_get_memory_use(lua_State *L) {
  return 1;
}

int
gfx_get_memory_limit(lua_State *L) {
  lua_pushnumber(L, 1000);
  return 1;
}

int
gfx_update(lua_State *L) {
  return 1;
}

int
gfx_loadpng(lua_State *L) {
  return 1;
}

int
gfx_loadjpeg(lua_State *L) {
  return 1;
}

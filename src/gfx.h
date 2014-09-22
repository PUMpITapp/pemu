#ifndef GFX_H
#define GFX_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SDL2/SDL.h>

extern SDL_Window *window;

int gfx_set_auto_update(lua_State *L);
int gfx_new_surface(lua_State *L);
int gfx_get_memory_use(lua_State *L);
int gfx_get_memory_limit(lua_State *L);
int gfx_update(lua_State *L);
int gfx_loadpng(lua_State *L);
int gfx_loadjpeg(lua_State *L);

#endif

#ifndef GFX_H
#define GFX_H

#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>

#define RGB_SIZE 4

extern SDL_Window *window;
extern int MEMORY_LIMIT;
extern int MEMORY_USED;

int gfx_set_auto_update(lua_State *L);
int gfx_new_surface(lua_State *L);
int gfx_get_memory_use(lua_State *L);
int gfx_get_memory_limit(lua_State *L);
int gfx_update(lua_State *L);
int gfx_loadpng(lua_State *L);
int gfx_loadjpeg(lua_State *L);

#endif

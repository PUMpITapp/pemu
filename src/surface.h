#ifndef SURFACE_H
#define SURFACE_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SDL2/SDL.h>

extern SDL_Window *window;

int surface_new(lua_State *);
int surface_clear(lua_State *L);
int surface_fill(lua_State *L);
int surface_copyfrom(lua_State *L);
int surface_get_width(lua_State *L);
int surface_get_height(lua_State *L);
int surface_get_pixel(lua_State *L);
int surface_set_pixel(lua_State *L);
int surface_premultiply(lua_State *L);
int surface_destroy(lua_State *L);

#endif

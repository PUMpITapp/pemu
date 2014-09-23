#ifndef SURFACE_H
#define SURFACE_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SDL2/SDL.h>
#include <assert.h>

extern SDL_Window *window;

int surface_getWindowSurface(lua_State*);
int surface_new(lua_State*);
int surface_clear(lua_State*);
int surface_fill(lua_State*);
int surface_copyfrom(lua_State*);
int surface_get_width(lua_State*);
int surface_get_height(lua_State*);
int surface_get_pixel(lua_State*);
int surface_set_pixel(lua_State*);
int surface_premultiply(lua_State*);
int surface_destroy(lua_State*);

#endif

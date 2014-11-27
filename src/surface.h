#ifndef SURFACE_H
#define SURFACE_H

#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
#include <SDL2/SDL.h>
#include <assert.h>
#include "utils.h"

#define RGB_SIZE 4

extern SDL_Window *window;
extern int MEMORY_LIMIT;
extern int MEMORY_USED;

int surface_get_window_surface(lua_State*);
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

#ifndef UTILS_H
#define UTILS_H

#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
#include <SDL2/SDL.h>

uint32_t colorTable_to_uint32t(lua_State*, int, SDL_Surface*);
SDL_Rect* rectTable_to_SDL_Rect(lua_State *, int, int w, int h);
void stackDump(lua_State *);

#endif

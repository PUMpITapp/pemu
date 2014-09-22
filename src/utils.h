#ifndef UTILS_H
#define UTILS_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SDL2/SDL.h>

uint32_t colorTable_to_uint32t(lua_State*, int, SDL_Surface*);
SDL_Rect* rectTable_to_SDL_Rect(lua_State *, int, int w, int h);
void stackDump(lua_State *);

#endif

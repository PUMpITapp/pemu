#ifndef ONKEY_H
#define ONKEY_H

#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
#include <SDL2/SDL.h>
#include <assert.h>
#include <string.h>

int onKeyPressed(lua_State *, SDL_KeyboardEvent, char *);

#endif

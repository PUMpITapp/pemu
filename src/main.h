#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Thread.h>
#include <SDL2/SDL_image.h>

SDL_Window *window;

typedef struct {
  lua_State *L;
  char *file;
} ThreadData;

#endif

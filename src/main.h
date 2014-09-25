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
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>

SDL_Window *window;
static int width = 1024;
static int height = 768;
static int MAJ_VERSION = 1;
static int MIN_VERSION = 0;

typedef struct {
  lua_State *L;
  char *file;
} ThreadData;

#endif

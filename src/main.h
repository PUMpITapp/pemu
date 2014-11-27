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
#include "gfx.h"
#include "surface.h"
#include "onkey.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define RGB_SIZE 4

SDL_Window *window;
int MEMORY_LIMIT = 10485760;
int MEMORY_USED = WINDOW_WIDTH * WINDOW_HEIGHT * RGB_SIZE;

static int MAJ_VERSION = 1;
static int MIN_VERSION = 0;

#endif

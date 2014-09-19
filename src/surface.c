#include "surface.h"
#include "main.h"


int
surface_new(lua_State *L) {
  SDL_Surface *surface;
  SDL_Rect position;

  int x = luaL_checknumber(L, 1);
  int y = luaL_checknumber(L, 2);
  int w = luaL_checknumber(L, 3);
  int h = luaL_checknumber(L, 4);
  float r = luaL_checknumber(L, 5);
  float g = luaL_checknumber(L, 6);
  float b = luaL_checknumber(L, 7);
  float a = luaL_checknumber(L, 8);
  printf("debug: x: %d, y: %d, w: %d, h: %d, r: %f, g: %f, b: %f, a: %f\n", x, y, w, h, r, g, b, a);

  position.x = x;
  position.y = y;

  surface = SDL_CreateRGBSurface(0,w,h,32,0,0,0,0);
  SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &position);
  SDL_UpdateWindowSurface(window);

  lua_pushlightuserdata(L, (void*)surface);
  return 1;
}

int
surface_clear(lua_State *L) {
  return 1;
}

int
surface_fill(lua_State *L) {
  SDL_Rect position;

  SDL_Surface *surface = (SDL_Surface*)lua_touserdata(L, 1);
  float r = luaL_checknumber(L, 2);
  float g = luaL_checknumber(L, 3);
  float b = luaL_checknumber(L, 4);
  float a = luaL_checknumber(L, 5);
  int x = luaL_checknumber(L, 6);
  int y = luaL_checknumber(L, 7);
  int w = luaL_checknumber(L, 8);
  int h = luaL_checknumber(L, 9);

  position.x = x;
  position.y = y;

  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));
  SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), &position);
  return 0;
}

int
surface_copyfrom(lua_State *L) {
  return 1;
}

int
surface_get_width(lua_State *L) {
  return 1;
}

int
surface_get_height(lua_State *L) {
  return 1;
}

int
surface_get_pixel(lua_State *L) {
  return 1;
}

int
surface_set_pixel(lua_State *L) {
  return 1;
}

int
surface_premultiply(lua_State *L) {
  return 1;
}

int
surface_destroy(lua_State *L) {
  SDL_Surface *surface = (SDL_Surface*)lua_touserdata(L, 1);
  SDL_FreeSurface(surface);
  return 0;
}

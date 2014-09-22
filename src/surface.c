#include "surface.h"
#include "main.h"
#include "utils.h"


int
surface_getWindowSurface(lua_State *L) {
  SDL_Surface *surface = SDL_GetWindowSurface(window);
  lua_pushlightuserdata(L, (void*)surface);
  return 1;
}

int
surface_new(lua_State *L) {
  SDL_Surface *surface;
  
  int w = luaL_checknumber(L, 1);
  int h = luaL_checknumber(L, 2);

  surface = SDL_CreateRGBSurface(0,w,h,32,0,0,0,0);

  lua_pushlightuserdata(L, (void*)surface);
  return 1;
}

int
surface_clear(lua_State *L) {
  SDL_Surface *surface;
  SDL_Rect *position;
  uint32_t color;

  surface = (SDL_Surface*)lua_touserdata(L, 1);

  if (lua_istable(L, 2))
    color = colorTable_to_uint32t(L, 2, surface);
  else
    color = SDL_MapRGBA(surface->format, 0, 0, 0, 0);

  if (lua_istable(L, 3))
    position = rectTable_to_SDL_Rect(L, 3, -1, -1);
  else
    position = NULL;

  SDL_FillRect(surface, position, color);
  SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), NULL);

  if (position != NULL)
    free(position);

  return 0;
}

int
surface_fill(lua_State *L) {
  SDL_Surface *surface;
  SDL_Rect *position;
  uint32_t color;

  surface = (SDL_Surface*)lua_touserdata(L, 1);
  color = colorTable_to_uint32t(L, 2, surface);
  
  if (lua_istable(L, 3))
    position = rectTable_to_SDL_Rect(L, 3, -1, -1);
  else
    position = NULL;

  SDL_FillRect(surface, position, color);
  SDL_BlitSurface(surface, NULL, SDL_GetWindowSurface(window), NULL);

  if (position != NULL)
    free(position);

  return 0;
}

int
surface_copyfrom(lua_State *L) {
  SDL_Surface *src_surface, *dst_surface;
  SDL_Rect *src_rect, *dst_rect;
  int blend = 0;

  src_surface = (SDL_Surface*)lua_touserdata(L, 1);
  dst_surface = (SDL_Surface*)lua_touserdata(L, 2);

  if (lua_istable(L, 3))
    src_rect = rectTable_to_SDL_Rect(L, 3, -1, -1);
  else
    src_rect = NULL;

  if (lua_istable(L, 4))
    dst_rect = rectTable_to_SDL_Rect(L, 3, src_rect->w, src_rect->h);
  else {
    dst_rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    dst_rect->x = 0;
    dst_rect->y = 0;

    if (src_rect) {
      dst_rect->w = src_rect->w;
      dst_rect->h = src_rect->h;
    } else {
      dst_rect->w = src_surface->w;
      dst_rect->h = src_surface->h;
    }
  }

  if (lua_isboolean(L, 5))
    blend = lua_toboolean(L, 5);
  
  return 0;
}

int
surface_get_width(lua_State *L) {
  SDL_Surface *surface = (SDL_Surface*)lua_touserdata(L, 1);
  lua_pushinteger(L, surface->w);
  return 1;
}

int
surface_get_height(lua_State *L) {
  SDL_Surface *surface = (SDL_Surface*)lua_touserdata(L, 1);
  lua_pushinteger(L, surface->h);
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

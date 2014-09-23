#include "utils.h"
#include "stdint.h"
#include <assert.h>


uint32_t
colorTable_to_uint32t(lua_State *L, int index, SDL_Surface *surface) {
  int i;
  float c[4];

  luaL_checktype(L, index, LUA_TTABLE);

  lua_rawgeti(L, index, 1); /* -12 */
  lua_getfield(L, index, "r"); /* -11 */
  lua_getfield(L, index, "red"); /* -10 */

  lua_rawgeti(L, index, 2); /* -9 */
  lua_getfield(L, index, "g"); /* -8 */
  lua_getfield(L, index, "green"); /* -7 */

  lua_rawgeti(L, index, 3); /* -6 */
  lua_getfield(L, index, "b"); /* -5 */
  lua_getfield(L, index, "blue"); /* -4 */

  lua_rawgeti(L, index, 4); /* -3 */
  lua_getfield(L, index, "a"); /* -2 */
  lua_getfield(L, index, "alpha"); /* -1 */

  for (i = 0; i < 4; i++) {
    if (lua_isnumber(L, -12+(i*3))) {
      c[i] = lua_tonumber(L, -12+(i*3));
    } else if (lua_isnumber(L, -11+(i*3))) {
      c[i] = lua_tonumber(L, -11+(i*3));
    } else if (lua_isnumber(L, -10+(i*3))) {
      c[i] = lua_tonumber(L, -10+(i*3));
    } else {
      if (i == 3)
        c[i] = 255;
      else
        c[i] = 0;
    }
  }

  return SDL_MapRGBA(surface->format, c[0], c[1], c[2], c[3]);
}

SDL_Rect*
rectTable_to_SDL_Rect(lua_State *L, int index, int d_w, int d_h) {
  SDL_Rect* position = NULL;

  luaL_checktype(L, index, LUA_TTABLE);
  
  position = (SDL_Rect*)malloc(sizeof(SDL_Rect));
  assert(position != NULL);

  lua_getfield(L, index, "x"); /* -6 */
  lua_getfield(L, index, "y"); /* -5 */
  lua_getfield(L, index, "w"); /* -4 */
  lua_getfield(L, index, "h"); /* -3 */
  lua_getfield(L, index, "width"); /* -2 */
  lua_getfield(L, index, "height"); /* -1 */

  position->x = luaL_checknumber(L, -6);
  position->y = luaL_checknumber(L, -5);

  if (lua_isnumber(L, -4)) {
    position->w = lua_tonumber(L, -4);
  } else if (lua_isnumber(L, -2)) {
    position->w = lua_tonumber(L, -2);
  } else {
    if (d_w > -1)
      position->w = d_w;
    else
      luaL_error(L, "missing width in rectangle");
  }

  if (lua_isnumber(L, -3)) {
    position->h = lua_tonumber(L, -3);
  } else if (lua_isnumber(L, -1)) {
    position->h = lua_tonumber(L, -1);
  } else {
    if (d_h > -1)
      position->h = d_h;
    else
      luaL_error(L, "missing height in rectangle");
  }

  return position;
}

void
stackDump (lua_State *L) {
  int i;
  int top = lua_gettop(L);
  for (i = 1; i <= top; i++) {  /* repeat for each level */
    int t = lua_type(L, i);
    switch (t) {

      case LUA_TSTRING:  /* strings */
        printf("`%s'", lua_tostring(L, i));
        break;

      case LUA_TBOOLEAN:  /* booleans */
        printf(lua_toboolean(L, i) ? "true" : "false");
        break;

      case LUA_TNUMBER:  /* numbers */
        printf("%g", lua_tonumber(L, i));
        break;

      default:  /* other values */
        printf("%s", lua_typename(L, t));
        break;

    }
    printf("  ");  /* put a separator */
  }
  printf("\n");  /* end the listing */
}

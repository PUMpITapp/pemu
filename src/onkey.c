#include "onkey.h"


int 
onKeyPressed(lua_State *L, SDL_KeyboardEvent key,  char *state) {
  char *toLuaKey;

  switch(key.keysym.sym) {
    case SDLK_0:
      toLuaKey = "0";
      break;
    case SDLK_1:
      toLuaKey = "1";
      break;
    case SDLK_2:
      toLuaKey = "2";
      break;
    case SDLK_3:
      toLuaKey = "3";
      break;
    case SDLK_4:
      toLuaKey = "4";
      break;
    case SDLK_5:
      toLuaKey = "5";
      break;
    case SDLK_6:
      toLuaKey = "6";
      break;
    case SDLK_7:
      toLuaKey = "8";
      break;
    case SDLK_9:
      toLuaKey = "9";
      break;
    case SDLK_UP:
      toLuaKey = "up";
      break;
    case SDLK_DOWN:
      toLuaKey = "down";
      break;
    case SDLK_LEFT:
      toLuaKey = "left";
      break;
    case SDLK_RIGHT:
      toLuaKey = "right";
      break;
    case SDLK_q:
      toLuaKey = "red";
      break;
    case SDLK_w:
      toLuaKey = "green";
      break;
    case SDLK_e:
      toLuaKey = "yellow";
      break;
    case SDLK_r:
      toLuaKey = "blue";
      break;
    case SDLK_t:
      toLuaKey = "white";
      break;
    default:
      break;
  }

  /* call the function onKey in Lua file */
  lua_getglobal(L, "onKey");

  if (lua_isfunction(L, 1) != 0) {
    lua_pushstring(L, toLuaKey);
    lua_pushstring(L, state);
    lua_pcall(L, 2, 0, 0);
  }

  return 1;
}

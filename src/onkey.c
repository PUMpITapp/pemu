#include "onkey.h"


int 
onKeyPressed(lua_State *L, SDL_KeyboardEvent key,  char *state) {
  char *toLuaKey;

  switch(key.keysym.scancode) {
    case SDL_SCANCODE_0 :
      toLuaKey = "0";
      break;
    case SDL_SCANCODE_1:
      toLuaKey = "1";
      break;
    case SDL_SCANCODE_2:
      toLuaKey = "2";
      break;
    case SDL_SCANCODE_3:
      toLuaKey = "3";
      break;
    case SDL_SCANCODE_4:
      toLuaKey = "4";
      break;
    case SDL_SCANCODE_5:
      toLuaKey = "5";
      break;
    case SDL_SCANCODE_6:
      toLuaKey = "6";
      break;
    case SDL_SCANCODE_7:
      toLuaKey = "7";
      break;
    case SDL_SCANCODE_8:
      toLuaKey = "8";
      break;
    case SDL_SCANCODE_9:
      toLuaKey = "9";
      break;
    case SDL_SCANCODE_UP:
      toLuaKey = "up";
      break;
    case SDL_SCANCODE_DOWN:
      toLuaKey = "down";
      break;
    case SDL_SCANCODE_LEFT:
      toLuaKey = "left";
      break;
    case SDL_SCANCODE_RIGHT:
      toLuaKey = "right";
      break;
    case SDL_SCANCODE_Q:
      toLuaKey = "red";
      break;
    case SDL_SCANCODE_W:
      toLuaKey = "green";
      break;
    case SDL_SCANCODE_E:
      toLuaKey = "yellow";
      break;
    case SDL_SCANCODE_R:
      toLuaKey = "blue";
      break;
    case SDL_SCANCODE_T:
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

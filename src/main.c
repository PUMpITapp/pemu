#include "main.h"
#include "gfx.h"
#include "surface.h"

static int width = 1024;
static int height = 768;

static void
sdl_event_loop() {
    int notFinished = 1;
    SDL_Event event;

    while (notFinished) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                notFinished = 0;
        }
    }
}

static int
lua_console(void *ptr) {
  char buff[256];
  int error;
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  /* Pushing functions to lua */
  lua_pushcfunction(L, &gfx_get_memory_limit);
  lua_setglobal(L, "gfx_get_memory_limit");
  lua_pushcfunction(L, &surface_new);
  lua_setglobal(L, "surface_new");

  while (fgets(buff, sizeof(buff), stdin) != NULL) {
    error = luaL_loadbuffer(L, buff, strlen(buff), "line") || lua_pcall(L, 0, 0
      , 0);
    if (error) {
      fprintf(stderr, "%s", lua_tostring(L, -1));
      lua_pop(L, 1);  /* pop error message from the stack */
    }
  }

  lua_close(L);
  return 0;
}

int main(int argc, char *argv[]) {
  SDL_Thread *luaThread = NULL;

  /* Init SDL and create window */
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("PumpITApp!",
                 SDL_WINDOWPOS_UNDEFINED,
                 SDL_WINDOWPOS_UNDEFINED,
                 width, height, SDL_WINDOW_OPENGL);

  /* Create the thread running the lua console */
  luaThread = SDL_CreateThread(lua_console, NULL, NULL);

  /* Start SDL event loop */
  sdl_event_loop();

  /* Clean everything before finish */
  SDL_Quit();
  return 0;
}

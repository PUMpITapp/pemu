#include "main.h"
#include "gfx.h"
#include "surface.h"
#include "onkey.h"
#include <stdio.h>

lua_State *L;

static void
sdl_event_loop() {
  int notFinished = 1;
  SDL_Event event;

  while (notFinished) {
    SDL_WaitEvent(&event);
    switch (event.type) {
      case SDL_KEYDOWN:
        onKeyPressed(L, event.key, "down");
        break;
      case SDL_KEYUP:
        onKeyPressed(L, event.key, "up");
        break;
      case SDL_QUIT:
        notFinished = 0;
        break;
      default:
        break;
     }
  }
}

static void
lua_register_c_functions(lua_State *L) {
  /* GFX */
  lua_pushcfunction(L, &gfx_set_auto_update);
  lua_setglobal(L, "gfx_set_auto_update");
  lua_pushcfunction(L, &gfx_get_memory_use);
  lua_setglobal(L, "gfx_get_memory_use");
  lua_pushcfunction(L, &gfx_get_memory_limit);
  lua_setglobal(L, "gfx_get_memory_limit");
  lua_pushcfunction(L, &gfx_update);
  lua_setglobal(L, "gfx_update");
  lua_pushcfunction(L, &gfx_loadpng);
  lua_setglobal(L, "gfx_loadpng");
  lua_pushcfunction(L, &gfx_loadjpeg);
  lua_setglobal(L, "gfx_loadjpeg");
  /* Surface */
  lua_pushcfunction(L, &surface_get_window_surface);
  lua_setglobal(L, "surface_get_window_surface");
  lua_pushcfunction(L, &surface_new);
  lua_setglobal(L, "surface_new");
  lua_pushcfunction(L, &surface_clear);
  lua_setglobal(L, "surface_clear");
  lua_pushcfunction(L, &surface_fill);
  lua_setglobal(L, "surface_fill");
  lua_pushcfunction(L, &surface_copyfrom);
  lua_setglobal(L, "surface_copyfrom");
  lua_pushcfunction(L, &surface_get_width);
  lua_setglobal(L, "surface_get_width");
  lua_pushcfunction(L, &surface_get_height);
  lua_setglobal(L, "surface_get_height");
  lua_pushcfunction(L, &surface_get_pixel);
  lua_setglobal(L, "surface_get_pixel");
  lua_pushcfunction(L, &surface_set_pixel);
  lua_setglobal(L, "surface_set_pixel");
  lua_pushcfunction(L, &surface_premultiply);
  lua_setglobal(L, "surface_premultiply");
  lua_pushcfunction(L, &surface_destroy);
  lua_setglobal(L, "surface_destroy");
}

static int
lua_vm_loadfile(char *file) {
  if (file != NULL) {
    if (luaL_loadfile(L, file) || lua_pcall(L, 0, 0, 0))
      luaL_error(L, "cannot run configuration file: %s", lua_tostring(L, -1));
  }
  return 0;
}

lua_State*
lua_init() {
  L = luaL_newstate();
  luaL_openlibs(L);
  lua_register_c_functions(L);
  return L;
}

int
main(int argc, char *argv[]) {
  lua_State *L = NULL;
  char *fvalue = NULL;
  int hflag = 0;
  int index;
  int c;

  /* Argument option handling */
  opterr = 0;
  while ((c = getopt(argc, argv, "hf:")) != -1)
  switch (c) {
    case 'h':
      hflag = 1;
      break;
    case 'f':
      fvalue = optarg;
      break;
    case '?':
      if (optopt == 'f')
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint(optopt))
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      return 1;
    default:
      abort();
  }

  for (index = optind; index < argc; index++)
    printf("Non-option argument %s\n", argv[index]);

  if (hflag) {
    printf("pemu version %d.%d\n", MAJ_VERSION, MIN_VERSION);
    printf("\nusage: pemu [options]\n");
    printf("\nOPTIONS:\n");
    printf("  -h shows this help.\n");
    printf("  -f file loads the LUA file and waits for stddin input after the execution.\n");
  } else {
    /* Init SDL and create window */
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    L = lua_init();
    window = SDL_CreateWindow("PumpITApp!",
                   SDL_WINDOWPOS_CENTERED,
                   SDL_WINDOWPOS_CENTERED,
                   width, height, SDL_WINDOW_OPENGL);

    /* LUA loads the file directly at startup */
    lua_vm_loadfile(fvalue);

    /* Start SDL event loop */
    sdl_event_loop();

    /* Clean everything before finish */
    lua_close(L);
    IMG_Quit();
    SDL_Quit();
  }
  return 0;
}

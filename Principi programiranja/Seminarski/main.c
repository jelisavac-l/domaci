#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *args[])
{
  // Pokazivac na prozor
  SDL_Window *window;

  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Geo554", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  SDL_Surface *screen = SDL_GetWindowSurface(window);
  if (window == NULL)
  {
    printf("Nije moguce otvoriti novi prozor: %s\n", SDL_GetError());
    return 1;
  }

  // Glavni loop
  bool run = true;
  while (run)
  {
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
      switch (ev.type)
      {
      case SDL_QUIT:
        {
        run = false;
        break;
        }
      }
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

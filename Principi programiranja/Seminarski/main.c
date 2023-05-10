#include "SDL2/SDL.h"
#include <stdio.h>
#include <stdbool.h>

const int WIDTH = 640;
const int HEIGHT = 480;
const int BALL_SIZE = 80;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool Initialize(void);
void Update(float);
void Shutdown(void);

int main(int argc, char *args[])
{
    atexit(Shutdown);   // :)

    if(!Initialize())
    {
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // "Clear Color"
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect ballrect = {
        .x = WIDTH/2 - BALL_SIZE/2,
        .y = HEIGHT/2 - BALL_SIZE/2,
        .w = BALL_SIZE,
        .h = BALL_SIZE
    };
    SDL_RenderFillRect(renderer, &ballrect);
    SDL_RenderPresent(renderer);

    

    // Glavni loop
    bool run = true;
    while(run)
    {
        SDL_Event ev;
        while(SDL_PollEvent(&ev))   // Obrada eventova, isto kao u SFMLu
        {
            switch(ev.type)
            {
                case SDL_QUIT:  // Event kliktanja na X dugme
                {
                    run = false;
                    break;
                }
            }
        }
    }

    return 0;
}

bool Initialize(void)
{
    window = SDL_CreateWindow("Geo554", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Init(SDL_INIT_EVERYTHING);  // Ukljucivanje svih SDL podsistema
    if(window == NULL)
    {
        printf("Greska prilikom otvaranja prozora za skicu: %s\n", SDL_GetError());
        return false;
    }
    return true;
}
void Update(float elapsed)
{

}
void Shutdown(void)
{
    // Moze se desiti greska pre inicijalizacije windowa i renderera,
    // zato valja proveriti za svaki slucaj.
    if(renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if(window)
    {
       SDL_DestroyWindow(window); 
    }
    SDL_Quit();
}
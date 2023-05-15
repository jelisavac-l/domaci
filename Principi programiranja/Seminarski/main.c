#include "SDL2/SDL.h"
#include "kki.h"    // Konzolni korisnicki interfejs
#include "trougao.h" // Trougao (Bice ih jos...)
#include <stdio.h>
#include <stdbool.h> // Prirodnije je raditi sa true/false nego sa 1/0

const int WIDTH = 640;
const int HEIGHT = 480;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool Initialize(void);
void Update(float);
void Shutdown(void);

int main(int argc, char *args[])
{
    atexit(Shutdown); // :)

    // Inicijalizacija pocetnih parametara
    if (!Initialize())
    {
        exit(1);
    }

    // Update() funkcija, deltaTime i obrada eventova
    bool run = true;
    while (run)
    {
        Uint32 lastTick = SDL_GetTicks();
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) // Obrada eventova, isto kao u SFMLu
        {
            switch (ev.type)
            {
                case SDL_QUIT: // Event kliktanja na X dugme
                {
                    run = false;
                    break;
                }
            }
        }
        // deltaTime (koji iz nekog razloga stvara probleme...)
        Uint32 curTick = SDL_GetTicks();
        Uint32 diff = curTick - lastTick;
        float elapsed = diff / 1000.0f;
        Update(elapsed);
        lastTick = curTick;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
// ⚓
// Inicijalne operacije: videti dokumentaciju
bool Initialize(void)
{
    // Niz instrukcija za sekvencionalno izvrsavanje operacija nad geometrijom
    static bool instrukcije[20];
    // Za pocetak, sve na false: videti dokumentaciju
    for(int i = 0; i < 20; i++)
    {
        instrukcije[i] = false;
    }
    // Inicijalizacija SDL-a: Prozor i SDL_Renderer
    window = SDL_CreateWindow("Geo554", 1000, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    // Bitovski AND operator? ... Videti dokumentaciju.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Init(SDL_INIT_EVERYTHING); // Ukljucivanje svih SDL podsistema
    if (window == NULL)
    {
        printf("Greska prilikom otvaranja prozora za skicu: %s\n", SDL_GetError());
        return false;
    }

    logo();
    start();
    getchar();
    int izbor = selekcija();


    return true;
}

void Update(float elapsed)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // "Clear Color"
    SDL_RenderClear(renderer);


    updateTrougao(renderer, elapsed);

    SDL_RenderPresent(renderer);
}
void Shutdown(void)
{
    // Moze se desiti greska pre inicijalizacije windowa i renderera,
    // zato valja proveriti za svaki slucaj.
    printc("Dovidjenja!\n",S_CRVENA);
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}
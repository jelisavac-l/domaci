#include "trougao.h"

void translacijaX(SDL_FPoint *P, SDL_FPoint Dest, float dT)
{
    if(P->x < Dest.x)
    {
        P->x += SPEED;
    }
    else if(P->x > Dest.x)
    {
        P->x -= SPEED;
    }
}

void updateTrougao(SDL_Renderer* renderer, float dT)
{
    /*
    Niz instrukcija (videti main.c):
    1. Ostrougli tr.
    2. Pravougli tr.
    3. Tupoguli tr.
    */
    

    // Jednostavna animacija (4 sata citanja dokumentacije kasnije...)    
    if(SDL_RenderGeometry(renderer, NULL, tr, 3, NULL, 0) < 0 )
    {
        SDL_Log("%s\n", SDL_GetError());
        printc("ERR\n", CRVENA);
    }

}
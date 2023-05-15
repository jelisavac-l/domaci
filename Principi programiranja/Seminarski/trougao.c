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
    bool instrukcije[3] = {true, false, false};
    if(instrukcije[0])
    {
        translacijaX(&tr[0].position, {640.0f, 0.0f}, dT);
        instrukcije[0] = false; // Zavrsena operacija 0
    }
    

    // Jednostavna animacija (4 sata citanja dokumentacije kasnije...)    
    if( SDL_RenderGeometry(renderer, NULL, tr, 3, NULL, 0) < 0 )
    {
        SDL_Log("%s\n", SDL_GetError());
        printc("ERR\n", CRVENA);
    }

}
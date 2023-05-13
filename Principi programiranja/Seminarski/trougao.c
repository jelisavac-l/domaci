#include "trougao.h"
void updateTrougao(SDL_Renderer* renderer, float dT)
{
    // Jednostavna animacija (4 sata citanja dokumentacije kasnije...)
    static float smer = 1.0f;
    if(tr[0].position.x > 640.0f)
    {
        tr[0].position.x = 634.0f;
        smer = -smer;
    }
    if(tr[0].position.x < 0.0f)
    {
        tr[0].position.x = 1.5f;
        smer *= -1;
    }
    tr[0].position.x += smer; // Bez dT dok ne shvatim gde koci....
    if( SDL_RenderGeometry(renderer, NULL, tr, 3, NULL, 0) < 0 )
    {
        SDL_Log("%s\n", SDL_GetError());
        printc("ERR\n", CRVENA);
    }

}
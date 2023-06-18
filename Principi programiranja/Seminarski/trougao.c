#include "trougao.h"

// Koliko bi ovo bilo samo jednostavnije u C++ sa klasama, polimorfizmom za sve ove funkcije i nasledjivanjem..


// Verovatno postoji "elegantnije" resenje...
void translacija(SDL_FPoint *P, SDL_FPoint Dest, float dT, bool* korak, bool* anim)
{
    *anim = true;
    bool dx = false, dy = false;
    if(P->x < Dest.x)
    {
        P->x += SPEED;
    }
    else if(P->x > Dest.x)
    {
        P->x -= SPEED;
    }
    else dx = true;
    if(P->y < Dest.y) 
    {
        P->y += SPEED;
    }
    else if(P->y > Dest.y)
    {
        P->y -= SPEED;
    }
    else dy = true;

    if(dx == true && dy == true) {
        *anim = false;
        *korak = false;
    }    

    /*
        Kada se zavrsi translacija po X osi, dx postaje true
        Kada se zavrsi translacija po Y osi, dy postaje true
        Kada se obe operacije zavrse, korak koji poziva funkciju
        postaje false, i vise se ta translacija ne izvrsava
    */
}

void promenaBojeTr(SDL_Vertex *tr, SDL_Color *nizBoja, bool* instrukcije, bool* anim)
{
    *anim = true;
    for(int i = 0; i < 3; i++) {
        tr[i].color = nizBoja[i];
    }
    *instrukcije = false;
    *anim = false;
}

void updateTrougao(SDL_Renderer* renderer, float dT, bool* instrukcije, bool* anim)
{
    /*
    Niz instrukcija (videti main.c):
    DEF. Ostrougli tr.
    0. Pravougli tr.
    1. Tupoguli tr.
    */


    // Mozda for? Sta ako je potrebno vrsiti operaciju nad nekom drugom tackom???
    if(instrukcije[0]) {
        translacija(&tr[0].position, {640.0f, 0.0f}, dT, &instrukcije[0], anim);
    }
    if(instrukcije[1]) {
        translacija(&tr[0].position, {320.0f, 240.0f}, dT, &instrukcije[1], anim);
    }
    if(instrukcije[2]) {
        translacija(&tr[0].position, {320.0f, 0.0f}, dT, &instrukcije[2], anim);
    }
    if(instrukcije[3]) {
        promenaBojeTr(tr, FULL_RED, &instrukcije[3], anim);
    }
    if(instrukcije[4]) {
        promenaBojeTr(tr, FULL_GREEN, &instrukcije[4], anim);
    }
    if(instrukcije[5]) {
        promenaBojeTr(tr, FULL_BLUE, &instrukcije[5], anim);
    }
    
    if(SDL_RenderGeometry(renderer, NULL, tr, 3, NULL, 0) < 0 )
    {
        SDL_Log("%s\n", SDL_GetError());
        printc("ERR\n", CRVENA);
    }

}
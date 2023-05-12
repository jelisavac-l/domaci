#ifndef TROUGAO_H
#define TROUGAO_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "kki.h"

static SDL_Vertex tackeTrougla[3]=
{
    {
        { 320,0}, // Prva Tacka
        { 255, 0, 0, 0xFF }, // Prva Boja
        { 0.f, 0.f }
    },
    {
        { 0, 480 },
        { 0,255,0, 0xFF },
        { 0.f, 0.f }
    },
    {
        { 640, 480},
        { 0,0,255, 0xFF },
        { 0.f, 0.f }
    }
};


void initTrougao();
void updateTrougao(SDL_Renderer* renderer);

#endif
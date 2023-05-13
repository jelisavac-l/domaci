#ifndef TROUGAO_H
#define TROUGAO_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "kki.h"

static SDL_Color bojeTrougla[3] =
    {
        {255, 0, 0, 0xFF},
        {0, 255, 0, 0xFF},
        {0, 0, 255, 0xFF},
    };

static SDL_FPoint tackeTrougla[3] = 
    {
        {320.0f,0.0f},
        {0.0f,480.0f},
        {640.0f, 480.0f}
    };

static SDL_Vertex tr[3] =
{
    {
        tackeTrougla[0], // Prva Tacka
        bojeTrougla[0],
        { 0.f, 0.f }
    },
    {
        tackeTrougla[1],
        bojeTrougla[1],
        { 0.f, 0.f }
    },
    {
        tackeTrougla[2],
        bojeTrougla[2],
        { 0.f, 0.f }
    }
};


void initTrougao();
void updateTrougao(SDL_Renderer* renderer, float dT);

#endif
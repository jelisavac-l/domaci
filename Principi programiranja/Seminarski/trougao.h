#ifndef TROUGAO_H
#define TROUGAO_H

#define SPEED 4.0f
#define COLOR_SPEED 5
#define POMOCNA 200.0f

#include <stdio.h>
#include "SDL2/SDL.h"
#include "kki.h"
#include "geometrija.h"

static SDL_Color FULL_RED[3] = {{255, 0, 255, 0xFF}, {255, 0, 255, 0xFF}, {255, 0, 255, 0xFF}};
static SDL_Color FULL_GREEN[3] = {{0, 255, 0, 0xFF}, {0, 255, 0, 0xFF}, {0, 255, 0, 0xFF}};
static SDL_Color FULL_BLUE[3] = {{0, 0, 255, 0xFF}, {0, 0, 255, 0xFF}, {0, 0, 255, 0xFF}};

static char tekstovi[3][80 + 1] = 
{
    "Lorem ipsum dolor sit amet",
    "Optimum pati quod est emendare non possis",
    "Semper paratus",
};

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

void initTrougao(); // Incijalne 
void izvrsiKorak(bool korak);
void translacija(SDL_FPoint *P, SDL_FPoint Dest, float dT, bool* korak, bool* anim);
void promenaBojeTr(SDL_Vertex *tr, SDL_Color *nizBoja, bool* instrukcije, bool *anim);
void updateTrougao(SDL_Renderer* renderer, float dT, bool* instrukcije, bool* anim);

#endif
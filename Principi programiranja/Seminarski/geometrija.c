#include "geometrija.h"

float rastojanje(SDL_FPoint A, SDL_FPoint B)
{
    // Pogledati dokumentaciju: Euklidsko rastojanje
    float dx = A.x - B.x;
    float dy = A.y - B.y;
    return sqrtf(powf(dx, 2) + powf(dy, 2));
}

SDL_FPoint sredina(SDL_FPoint A, SDL_FPoint B)
{
    // Pogledati dokumentaciju: Sredina duzi
    SDL_FPoint res;
    res.x = (A.x + B.x) / 2;
    res.y = (A.y + B.y) / 2;
    return res;
}
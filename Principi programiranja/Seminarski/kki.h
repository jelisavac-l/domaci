#ifndef KKI_H
#define KKI_H

#include <windows.h>
#include <stdio.h>

// Boje✨ (learn.microsoft.com)

#define CRNA 0x00
#define PLAVA 0x01
#define ZELENA 0x02
#define AQUA 0x03
#define CRVENA 0x04
#define LJUBICASTA 0x05
#define ZUTA 0x06
#define BELA 0x07
#define SIVA 0x08
#define S_PLAVA 0x09
#define S_ZELENA 0x0A
#define S_AQUA 0x0B
#define S_CRVENA 0x0C
#define S_LJUBICASTA 0x0D
#define S_ZUTA 0x0E
#define S_BELA 0x0F

const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // Dodeliti vrednost prilikom inicijalizacije zbog ISO

void printc(const char* output, int color);   // Stampanje u boji
void start();
void logo();
void linijaPoLinija(const char* path);
int selekcija();


#endif
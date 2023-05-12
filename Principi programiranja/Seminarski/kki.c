#include "kki.h"
#include <stdio.h>

void printc(const char* output, int color) 
{
    SetConsoleTextAttribute(h, color);
    printf(output);
    SetConsoleTextAttribute(h, BELA);
}

void start()
{   
    printf("Univerzitet u Beogradu,\n");
    printc("Fakultet organizacionih nauka\n\n", S_LJUBICASTA);
    printf("Seminarski rad iz predmeta ");
    printc("Principi programiranja\n", S_ZELENA);
    printf("Tema: ");
    printc("N/A\n", S_ZELENA);
    printf("Student: ");
    printc("Luka Jelisavac (2022-0554)\n", S_ZELENA);
    printf("Mentor: ");
    printc("prof. dr Sasa D. Lazarevic\n", S_ZELENA);
}

void logo()
{
    FILE *fptr;
    fptr = fopen("fonASCII.txt", "r");
    char linija[80 + 1];
    while(fgets(linija, 81, fptr))
    {
        printf("%s", linija);
    }
    printf("\n\n");
    fclose(fptr);
}

void linijaPoLinija(const char* path)
{
    FILE *fptr;
    fptr = fopen(path, "r");
    char linija[80 + 1];
    while(fgets(linija, 81, fptr))
    {
        printf("%s", linija);
        getchar();
    }
    fclose(fptr);
}
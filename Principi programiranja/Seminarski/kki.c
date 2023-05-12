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

int selekcija()
{
    int sel;
    printf("Odaberite jedno od ponudjenih:\n");
    printc("### TEORIJA ###\n", S_ZUTA);
    printf("[1] Trougao\n");
    printf("[N/A] Trougao: jednakostranicni\n");
    printf("[N/A] Trougao: jednakokraki\n");
    printf("[N/A] Trougao: pravougli\n\n");

    // printf("[5] Cetvorougao\n");
    // printf("[6] Cetvorougao: kvadrat\n");
    // printf("[7] Cetvorougao: pravougaonik\n");
    // printf("[8] Cetvorougao: romb\n");
    // printf("[9] Cetvorougao: paralelogram\n");
    // printf("[10] Cetvorougao: trapez\n");
    // printf("[11] Cetvorougao: deltoid\n");

    printc("### KALKULATOR ###\n", S_ZUTA);
    printf("[N/A] Trougao\n");
    printf("[N/A] Trougao: jednakostranicni\n");
    printf("[N/A] Trougao: jednakokraki\n");
    printf("[N/A] Trougao: pravougli\n");

    // printf("[16] Cetvorougao\n");
    // printf("[17] Cetvorougao: pravougaonik\n");
    // printf("[18] Cetvorougao: romb\n");
    // printf("[19] Cetvorougao: paralelogram\n");
    // printf("[20] Cetvorougao: trapez\n");
    // printf("[21] Cetvorougao: deltoid\n");        
    printc("[0] Kraj rada\n", SIVA);
    scanf("%d", sel);
    return sel;
}
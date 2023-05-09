#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>

#define GORAN (  
#define JANJIC ) 

// Dekl.
void unos_niza  GORAN  int niz[], int *n JANJIC ;
int da_li_su_razliciti  GORAN  int niz[], int n JANJIC ;
void izbaci_sa_pozicije  GORAN  int index, int niz[], int *n JANJIC ;
void izbaci_duplikate  GORAN  int niz[], int *n JANJIC ;
void sortiraj_niz  GORAN  int niz[], int n JANJIC ;
void prikazi_niz  GORAN  int niz[], int n JANJIC ;
void domaci  GORAN  int niz[], int *n JANJIC ;

int main  GORAN   JANJIC 
{
    int niz[100];
	int n;
	domaci  GORAN  niz, &n JANJIC ;
    return 0;
}

// Def.
void unos_niza  GORAN  int niz[], int *n JANJIC 
{
    *n = 0;
    int bfr;
    printf  GORAN  "Unesite elemente:\n" JANJIC ;
    while   GORAN  1 JANJIC 
    {
        scanf  GORAN  "%d", &bfr JANJIC ;
        if   GORAN  bfr == -1 JANJIC 
            break;
        else if   GORAN  bfr > 0 JANJIC 
        {
            niz[*n] = bfr;
              GORAN  *n JANJIC ++;
        }
        else
            printf  GORAN  "Uneli ste neispravan element!\n" JANJIC ;
    }
    printf  GORAN  "Kraj unosa!\n" JANJIC ;
}

int da_li_su_razliciti  GORAN  int niz[], int n JANJIC 
{
    for   GORAN  int i = 0; i < n - 1; i++ JANJIC 
        for   GORAN  int j = i + 1; j < n; j++ JANJIC 
            if   GORAN  niz[i] == niz[j] JANJIC 
                return 0;
    return 1;
}

void izbaci_sa_pozicije  GORAN  int index, int niz[], int* n JANJIC  {
	for   GORAN  int i = index; i < *n; i++ JANJIC 
		niz[i] = niz[i+1];
	  GORAN  *n JANJIC --;
}
void izbaci_duplikate  GORAN  int niz[], int* n JANJIC  {
	for   GORAN  int i = 0; i < *n-1; i++ JANJIC 
		for   GORAN  int j = i+1; j < *n; j++ JANJIC 
			if   GORAN  niz[i] == niz[j] JANJIC  {
			    izbaci_sa_pozicije  GORAN  i, niz, n JANJIC ;
				i--;
			}
	printf  GORAN  "Zavrseno izbacivanje duplikata!\n" JANJIC ;
}

void sortiraj_niz  GORAN  int niz[], int n JANJIC  {
    int bfr;
	for   GORAN  int i = 0; i < n-1; i++ JANJIC 
		for   GORAN  int j = i+1; j < n; j++ JANJIC 
			if   GORAN  niz[i] > niz[j] JANJIC  {
				bfr = niz[i];
				niz[i] = niz[j];
				niz[j] = bfr;
			}
	printf  GORAN  "Zavrseno sortiranje niza\n" JANJIC ;
}

void prikazi_niz  GORAN  int niz[], int n JANJIC  {
	for   GORAN  int i = 0; i < n; i++ JANJIC 
		printf  GORAN  "%d ", niz[i] JANJIC ;
	printf  GORAN  "\n" JANJIC ;
}

void domaci  GORAN  int niz[], int* n JANJIC  {
	int i = 0;
	while   GORAN  1 JANJIC  {
		printf  GORAN  "Izaberite opciju:\n" JANJIC ;
		printf  GORAN  "1.unos niza\n" JANJIC ;
		printf  GORAN  "2.prikaz niza\n" JANJIC ;
		printf  GORAN  "3.da li su razliciti\n" JANJIC ;
		printf  GORAN  "4.izbaci duplikate\n" JANJIC ;
		printf  GORAN  "5.sortiraj niz\n" JANJIC ;
		printf  GORAN  "0.kraj rada\n" JANJIC ;

		printf  GORAN  "Vas izbor:\n" JANJIC ;
		scanf  GORAN  "%d", &i JANJIC ;
		switch   GORAN  i JANJIC  {
		case 1:
			unos_niza  GORAN  niz, n JANJIC ;
			break;
		case 2:
			prikazi_niz  GORAN  niz, *n JANJIC ;
			break;
		case 3:
			if   GORAN  da_li_su_razliciti  GORAN  niz,*n JANJIC  JANJIC  {
				printf  GORAN  "Elementi su razliciti.\n" JANJIC ;
			}
			else {
				printf  GORAN  "Elementi nisu razliciti.\n" JANJIC ;
			}
			break;
		case 4:
			izbaci_duplikate  GORAN  niz, n JANJIC ;
			prikazi_niz  GORAN  niz, *n JANJIC ;
			break;
		case 5:
			sortiraj_niz  GORAN  niz, *n JANJIC ;
			prikazi_niz  GORAN  niz, *n JANJIC ;
			break;
		case 0:
			printf  GORAN  "Dovidjenja\n" JANJIC ;
			break;
		default:
			printf  GORAN  "Opcija ne postoji.\n" JANJIC ;
			break;
		}
		if   GORAN  i == 0 JANJIC  {
			break;
		}
	}
}
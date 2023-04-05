#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>

void prikazi_fibonaci(int n);
void konverzija();
int brojCifara(int n);
int validacija(int br1, int br2);
void kreiraj_brojeve(int br1, int br2, int* izlaz1, int* izlaz2);


int main(void)
{
    // 1. zadatak
	prikazi_fibonaci(30);
	printf("\n");

	// // 2. zadatak
	konverzija();
    printf("\n");

    // 3. zadatak
    int izlaz1, izlaz2;
    kreiraj_brojeve(5555, 3333, &izlaz1, &izlaz2);
    getchar();
    return 0;
}

void prikazi_fibonaci(int n)
{
    int prethodni = 0, trenutni = 1, sledeci = trenutni + prethodni;
    printf("%d %d ", prethodni, trenutni);

    while (sledeci < n)
    {
        printf("%d ", sledeci);
        prethodni = trenutni;
        trenutni = sledeci;
        sledeci = trenutni + prethodni;
    }
}

void konverzija()
{
    char izbor, nastaviti;
    float pre, posle;
    do
    {
        printf("Izaberite:\nUnesite F za konverziju iz Farenhajta u Celzijus\nUnesite C za konverziju iz Celzijusa u Farenhajt\n");
        scanf("%c", &izbor);
        getchar();
        switch (izbor)
        {
        case 'F': case 'f': 
            {
                printf("Unesite vrednost\n");
                scanf("%f", &pre);
                getchar();
                posle = (pre - 32) / 1.8;
                printf("%.2fF = %.2fC\n", pre, posle);
                break;
            }

        case 'C': case 'c':
            {
                printf("Unesite vrednost\n");
                scanf("%f", &pre);
                getchar();
                posle = pre * 1.8 + 32;
                printf("%.2fC = %.2fF\n", pre, posle);
                break;
            }
        
        default:
            printf("Unesen je neispravan karakter! Pokusajte ponovo.\n");
            break;
        }

        printf("Da li zelite ponovo da izvrsite konverziju? (d/n)\n");
        scanf("%c", &nastaviti);
        getchar();
        if (nastaviti == 'n') {
			printf("Dovidjenja");
		} 
        else if(nastaviti != 'd')
        {
            printf("Shvaticemo to kao da...\n");
        }
        
    } while (nastaviti != 'n');   
}

int brojCifara(int n)
{
    int rezultat = 0;
    while (n > 0)
    {
        rezultat++;
        n /= 10;
    }
    return rezultat;
}
int validacija(int br1, int br2)
{
    if(brojCifara(br1) == brojCifara(br2)) return 1;
    else return 0;
}

// Prva ideja, ima (dosta) mesta za optimiziaciju...
void kreiraj_brojeve(int br1, int br2, int* izlaz1, int* izlaz2)
{
    *izlaz1 = 0;
    *izlaz2 = 0;
    if(!validacija(br1, br2))
    {
        printf("Validacija neuspesna!\n");
        return;
    }
    int brCif = brojCifara(br1), niz1[10], niz2[10], i = 0;
    while (br1 > 0)
    {
        niz1[i] = br1 % 10;
        br1 = br1 / 10;
        i++;
    }
    i = 0; 
    while (br2 > 0)
    {
        niz2[i] = br2 % 10;
        br2 = br2 / 10;
        i++;
    }
    for(i = 0; i < brCif; i=i+2)
    {
        *izlaz1 += pow(10, i) * niz1[i];
        *izlaz2 += pow(10, i) * niz2[i];
    }
    for(i = 1; i < brCif; i=i+2)
    {
        *izlaz1 += pow(10, i) * niz2[i];
        *izlaz2 += pow(10, i) * niz1[i];
    }

    // Proveriti gde je greska, sledeca linija drzi vodu. (Na izlazu se dobijaju brojevi za 1 manji od ocekivanog)
    // * Odstupanje varira zavisno od broja cifara generisanih brojeva 
    // ** Greska se desava samo kada je kod kompajliran GCC kompajlerom
    // VS C/C++ Compiler daje tacno resenje...
    // programiz.com compiler daje tacno resenje...
    // Do kompajlera je 🙃
    
    printf("Kreirani brojevi: %d i %d", *izlaz1, *izlaz2);
}

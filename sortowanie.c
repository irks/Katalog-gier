#include "struktury.h"
#include "sortowanie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct gra *pocz;
extern struct gra *koniec;

void zamiana_elementow(struct gra *gra1) {

    if (gra1->nast == NULL)
        return;
    struct gra * tmp;

    tmp = (struct gra *)malloc(sizeof(struct gra));

    *tmp=*gra1;

    if (gra1->poprz !=NULL) {
        gra1->poprz = gra1->nast;
        tmp->poprz->nast=tmp->nast;
        gra1->nast->poprz=tmp->poprz;
    }
    else { //gra1 pierwszym elementem
        gra1->nast->poprz=NULL;
        pocz=gra1->nast;
        gra1->poprz=tmp->nast;
    }

    if (tmp->nast->nast != NULL) {
        gra1->nast=tmp->nast->nast;
        tmp->nast->nast->poprz=gra1;
        gra1->poprz->nast=gra1;
    }
    else {
        gra1->poprz->nast=gra1;
        gra1->nast=NULL;
        koniec=gra1;
        }

    free(tmp);
    return;
};

void sortowanie(void) {
    int wybor, licznik=1, i=0, j=0;
    struct gra * aktualny = pocz;
    struct gra * poprzedni =NULL;
    printf("\nPo jakim pole rekordu chcesz posortować dane?\n\n");
    printf("================================================\n");
    printf("1. ID (kolejnosc stworzenia)     2. Tytul\n");
    printf("3. Producent                     4. Nosnik\n");
    printf("5. Cena                          6. Platforma\n");
    printf("7. Gatunek                       8. Wroc do menu\n");
    printf("================================================\n");
    scanf("%d", &wybor);
	system("clear");
    while(getchar() != '\n')
        continue;
    while(aktualny->nast != NULL) {
        aktualny = aktualny->nast;
        licznik++;
    }
    switch(wybor) {
        case 1:
            for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if ((aktualny->id > aktualny->nast->id))
                        zamiana_elementow(aktualny);
                    else
                        aktualny=aktualny->nast;
                }
            }
            break;
        case 2:
            for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if (strcmp(aktualny->tytul,aktualny->nast->tytul) > 0)
                        zamiana_elementow(aktualny);
                    else
                        aktualny = aktualny->nast;
                }
            }
            break;
        case 3:
            for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if (strcmp(aktualny->producent,aktualny->nast->producent) > 0)
                        zamiana_elementow(aktualny);
                    else
                        aktualny = aktualny->nast;
                }
            }
            break;
        case 4:
            for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if (strcmp(aktualny->nosnik,aktualny->nast->nosnik) > 0)
                        zamiana_elementow(aktualny);
                    else
                        aktualny = aktualny->nast;
                }
            }
            break;
        case 5:
            for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if ((aktualny->cena) > (aktualny->nast->cena))
                        zamiana_elementow(aktualny);
                    else
                        aktualny = aktualny->nast;
                }
            }
            break;
        case 6:
            for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if (strcmp(aktualny->platforma,aktualny->nast->platforma) > 0)
                        zamiana_elementow(aktualny);
                    else
                        aktualny = aktualny->nast;
                }
            }
            break;
        case 7:
	    for(i=0; i<licznik-1; i++) {
                aktualny=pocz;
                for(j=0; j<licznik-1-i;j++) {
                    if (strcmp(aktualny->gatunek,aktualny->nast->gatunek) > 0)
                        zamiana_elementow(aktualny);
                    else
                        aktualny = aktualny->nast;
                }
            }
            break;
        case 8:
            break;
        default:
            puts("\nPodaj numer z listy!");
            break;
    }
};



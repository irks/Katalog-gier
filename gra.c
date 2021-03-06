#include "struktury.h"
#include "gra.h"
#include "gatunek.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern struct gra *pocz;
extern struct gra *koniec;

struct gra * stworz_element(void) {
    struct gra *tmp;

    if ((tmp = (struct gra *)malloc(sizeof(struct gra))) != NULL)
    {
        tmp->poprz = koniec;
        if (koniec != NULL)
            koniec->nast = tmp;
        tmp->nast = NULL;
        koniec = tmp;
        if (pocz == NULL)
            pocz = tmp;
        tmp->id = (id_max(pocz) + 1);
    }
    return tmp;
};

int id_max(struct gra *pocz) {
    struct gra *aktualny;
    int tmp_id;
    if (pocz->nast == NULL) {
        tmp_id = 0;
        return tmp_id; }
    aktualny = pocz;
    tmp_id = (aktualny->id);
    while (aktualny->nast != NULL) {

        if (aktualny->id > tmp_id)
            tmp_id = aktualny->id;
        aktualny = aktualny->nast;
   }
    return tmp_id;
};


void usun_element(struct gra *do_usuniecia) {
    if (do_usuniecia == NULL) // gdy nie istnieje
        return;
    if (do_usuniecia->poprz == NULL && do_usuniecia->nast==NULL) {
        pocz = NULL;
        koniec = NULL;
        free(do_usuniecia);
        return;
        }
    if (do_usuniecia->poprz != NULL)
        do_usuniecia->poprz->nast = do_usuniecia->nast;
    else { //usuwany jest pierwszy element
        do_usuniecia->nast->poprz = NULL;
        pocz = do_usuniecia->nast;
    }
    if (do_usuniecia->nast != NULL )
        do_usuniecia->nast->poprz = do_usuniecia->poprz;
    else {//usuwany jest ostatni element
        do_usuniecia->poprz->nast = NULL;
        koniec = do_usuniecia->poprz;
    }
    free(do_usuniecia);
}; //usun element

void wyczysc_baze(void) {
    if (pocz == NULL)
        return;
    struct gra *biezacy;
    biezacy = pocz;

    while(1) {
        if (biezacy->nast == NULL) {
            usun_element(biezacy);
            break;
        }
        else {
            biezacy=biezacy->nast;
            usun_element(biezacy->poprz);
        }

    }
    return;
};

void wczytywanie(void) {
    char c;
    struct gra *nowy;
    char wejscie[MAX];
    puts("\nPodaj tytul gry (pusty wiersz powoduje powrot do menu):");
    while (gets(wejscie) != NULL && wejscie[0] != '\0' && wejscie[0] != '\t' && wejscie[0] != ' ' && wejscie[0] != '\n') {
       nowy = stworz_element();
       strncpy(nowy->tytul, wejscie, MAX);
       puts("\nPodaj producenta gry:");
       gets(wejscie);
       while(wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ')
            gets(wejscie);
       strncpy(nowy->producent, wejscie, MAX);       
       interfejs_gatunek(nowy);

       puts("\nPodaj nosnik:");
       gets(wejscie);
       while(wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ')
            gets(wejscie);
       strncpy(nowy->nosnik, wejscie, MAX);       
       puts("\nPodaj cene:");
	while((scanf("%f", &nowy->cena))!=1) {
		while(getchar() != '\n')
            		continue;
		puts("Cena musi byc liczba, podaj cene jeszcze raz!");
	}
       while(getchar() != '\n')
            continue;
       puts("\nPodaj platforme:");
       gets(wejscie);
       while(wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ')
            gets(wejscie);
       strncpy(nowy->platforma, wejscie, MAX);       
       puts("\nPodaj nastepny tytul gry (pusty wiersz powoduje powrot do menu):");
    }
}

void edycja(struct gra * do_edycji) {
    char c;
    char wejscie[MAX];
    if (do_edycji == NULL) // gdy nie istnieje
        return;
    puts("\nPodaj tytul gry (pusty wiersz powoduje powrot do menu):");

    if (gets(wejscie) != NULL && wejscie[0] != '\0' && wejscie[0] != '\t' && wejscie[0] != ' ' && wejscie[0] != '\n') {
       strncpy(do_edycji->tytul, wejscie, MAX);
       puts("\nPodaj producenta gry:");
       gets(wejscie);
       while(wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ')
            gets(wejscie);
       strncpy(do_edycji->producent, wejscie, MAX);       
       interfejs_gatunek(do_edycji);

       puts("\nPodaj nosnik:");
       gets(wejscie);
       while(wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ')
            gets(wejscie);
       strncpy(do_edycji->nosnik, wejscie, MAX);       
       puts("\nPodaj cene:");
	while((scanf("%f", &do_edycji->cena))!=1) {
		while(getchar() != '\n')
            		continue;
		puts("Cena musi byc liczba, podaj cene jeszcze raz!");
	}
       while(getchar() != '\n')
            continue;
       puts("\nPodaj platforme:");
       gets(wejscie);
       while(wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ')
            gets(wejscie);
       strncpy(do_edycji->platforma, wejscie, MAX);       
    }
    puts("\nZaktualizowano dane\n");
};

void wyswietl(void) {
    struct gra *biezacy;
    if (pocz == NULL) {
        puts("\n\nBaza jest pusta\n");
        return;
    }
    biezacy = pocz;
    printf("\n\n\nID    Tytul                                     Gatunek                        Producent                       Nosnik          Cena       Platforma \n");
    while (biezacy != NULL ) {
        printf("%-5d %-40s  %-30s %-30s  %-15s %-8.2f   %-s\n", biezacy->id, biezacy->tytul, biezacy->gatunek, biezacy->producent,biezacy->nosnik, biezacy->cena, biezacy->platforma);
        biezacy = biezacy->nast;
    }
};


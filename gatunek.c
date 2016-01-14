#include "struktury.h"
#include "gatunek.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct gatunek *poczatek;

void interfejs_gatunek(struct gra *nowy) {
    char wejscie[MAX];
    int id_gatunku, menu_gatunku;
    while(1) {
       printf("\n========================================================================================\n");
       printf("1. Wyswietl liste mozliwych do wyboru gatunkow\n");
       printf("2. Wybierz gatunek dla gry (podajac numer id danego gatunku)\n");
       printf("3. Stworz nowy gatunek\n");
       printf("4. Edytuj nazwe gatunku (podajac numer id danego gatunku)\n");
       printf("5. Usun gatunek (podajac numer id danego gatunku)\n");
       printf("========================================================================================\n");
       scanf("%d", &menu_gatunku);
       system("clear");
       while(getchar() != '\n')
            continue;
       switch(menu_gatunku) {
            case 1:
                wyswietl_gatunki();
                break;
            case 2:
               if (poczatek == NULL) {
                    puts("\nNie ma zadnych gatunkow do wyboru, musisz najpierw dodac gatunek");
                    break;
                }
               puts("\nPodaj id gatunku dla gry(wpisz 0 aby wrocic do menu gatunku):");
               scanf("%d", &id_gatunku);
               while(getchar() != '\n')
                    continue;
		if(id_gatunku == 0)
			break;
               if ((dodaj_gatunek_do_gry(id_gatunku, nowy))==0)
                    break;
               return;

            case 3:
                puts("\nPodaj gatunek (pusty wiersz powoduje powrot do menu gatunku):");

		if (fgets(wejscie,MAX,stdin)==NULL || wejscie[0]=='\0' || wejscie[0]=='\t' || wejscie[0]==' ' && wejscie[0] != '\n')
                	break;
                stworz_gatunek(wejscie);
                break;
            case 4:
                puts("\nPodaj id gatunku do edycji:");
                scanf("%d", &id_gatunku);
                while(getchar() != '\n')
                    continue;
                edytuj_gatunek(id_gatunku);
                break;
            case 5:
                puts("\nPodaj id gatunku do usuniecia:");
                scanf("%d", &id_gatunku);
                while(getchar() != '\n')
                    continue;
                usun_gatunek(id_gatunku);
                break;
            default:
                puts("\nPodaj cyfre odpowiadajaca danej instrukcji");
                break;
       }
    }
}

int id_max_gatunek(struct gatunek *poczatek) {
    struct gatunek *aktualny;
    int tmp_id;
    if (poczatek->nast == NULL) {
        tmp_id = 0;
        return tmp_id; }
    aktualny = poczatek;
    tmp_id = (aktualny->id);
    while (aktualny->nast != NULL) {
        if (aktualny->id > tmp_id)
            tmp_id = aktualny->id;
        aktualny = aktualny->nast;
   }
    return tmp_id;
};

void wyswietl_gatunki(void) {
    struct gatunek *biezacy;
    if (poczatek == NULL) {
        puts("\nBrak gatunkow\n");
        return;
    }
    biezacy = poczatek;
    printf("\nID    Gatunek\n");
    while(biezacy != NULL) {
        printf("%-5d %-30s\n", biezacy-> id, biezacy->nazwa);
        biezacy = biezacy->nast;
    }
};

void stworz_gatunek(char *tab) {
    struct gatunek *nowy;

    if ((nowy = (struct gatunek*)malloc(sizeof(struct gatunek))) != NULL) {
        if (poczatek == NULL)
            poczatek = nowy;
        else {
            struct gatunek *tmp = poczatek;

            while (tmp->nast != NULL)
                tmp = tmp->nast;
            tmp->nast = nowy;
            nowy->nast = NULL;
        }
        strcpy(nowy->nazwa, tab);
        nowy->id = id_max_gatunek(poczatek)+1;
    }
    return;
};

void usun_gatunek(int id_gat_do_usun) {
    if (poczatek == NULL) {
        puts("Brak gatunkow do wyboru!");
        return;
    }
    struct gatunek *biezacy;
    struct gatunek *poprzedni = NULL;
    biezacy = poczatek;
    while (biezacy->id != id_gat_do_usun) {
        poprzedni= biezacy;
        biezacy = biezacy->nast;
        if (biezacy == NULL) {
            puts("Nie ma takiego elementu");
            return;
        }
    }
    if (biezacy==poczatek) {
        poczatek = biezacy->nast;
    }
    else {
        if (biezacy->nast == NULL)
            biezacy->nast = NULL;
        else
            poprzedni->nast = biezacy->nast;

    }
    free(biezacy);
}

void edytuj_gatunek(int id_gat_do_edyc) {
    if (poczatek == NULL) {
        puts("Brak gatunkow do wyboru!");
        return;
    }
    struct gatunek *biezacy;
    biezacy = poczatek;
    while (biezacy->id != id_gat_do_edyc) {
        biezacy = biezacy->nast;
        if (biezacy == NULL) {
            puts("Nie ma takiego elementu");
            return;
        }
    }
    char wejscie[MAX];
    puts("Podaj nowa nazwe gatunku ktory edytujesz(pusty wiersz powoduje powrot do menu gatunku):");
    if (fgets(wejscie,MAX,stdin) != NULL && wejscie[0] != '\0' && wejscie[0] != '\t' && wejscie[0] != ' ' && wejscie[0] != '\n') {
        strcpy(biezacy->nazwa, wejscie);
    	puts("\nZaktualizowano dane\n");
	}
};

int dodaj_gatunek_do_gry(int id_gatunku, struct gra *nowy) {
    if (poczatek == NULL)
        return 0;
    struct gatunek *biezacy;
    biezacy = poczatek;
    while (biezacy->id != id_gatunku) {
        biezacy = biezacy->nast;
        if (biezacy == NULL) {
            puts("Nie ma takiego elementu");
            return 0;
        }
    }
    strcpy(nowy->gatunek,biezacy->nazwa);

}


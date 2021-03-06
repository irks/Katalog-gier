//Katalog gier, projekt 3
//Ireneusz Wróbel, Informatyka, grupa 5

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struktury.h"
#include "gra.h"
#include "gatunek.h"
#include "sortowanie.h"
#include "odczyt_z_pliku.h"
#include "zapis_do_pliku.h"

struct gatunek *poczatek = NULL;
struct gra *pocz= NULL;
struct gra *koniec= NULL;




void main(void) {
    FILE *w_otworz;
    FILE *w_zapisz;
    int wybor, delete_id, edit_id;
    struct gra *biezacy;
    char nazwa[MAX]; //nazwa pliku do odczytu
    if (pocz == NULL) {
    	stworz_gatunek("RPG");
    	stworz_gatunek("Strategia");
   	 stworz_gatunek("Sportowa");
   	 stworz_gatunek("Zręcznościowa");
    	stworz_gatunek("TPP");
	}
	system("clear");
	printf("\nKatalog gier\nIreneusz Wrobel, grupa 5\n\n");
while(1) {
    printf("\nCo chcesz zrobić?\n");
    printf("========================================================================================\n");
    printf("1. Dodac nowe elementy     2. Usunac element\n");
    printf("3. Edytowac element        4. Posortowac baze\n");
    printf("5. Wyczyscic baze          6. Zapisac baze do pliku\n");
    printf("7. Wyswietlic baze         8. Wczytać baze z pliku(aktualna baza zostanie wyczyszczona!)\n");
    printf("9. Wyjsc z programu\n");
    printf("========================================================================================\n");

    puts("Musisz podac liczbe odpowiadajaca danemu dzialaniu\n");
    scanf("%d", &wybor);
    system("clear");
    while(getchar() != '\n')
        continue;
    switch(wybor) {
        case 1:
            wczytywanie();
            break;
        case 2:
            puts("\nPodaj id elementu ktory chcesz usunac:");
            scanf("%d", &delete_id);
            while(getchar() != '\n')
                continue;
            if (pocz == NULL) {
                puts("\nBaza jest pusta!");
                break; }
            biezacy = pocz;
            while (biezacy->id != delete_id) {
                biezacy = biezacy->nast;
                if (biezacy == NULL) {
                    puts("\nNie ma takiego elementu");
                    break;
                }
            }
            usun_element(biezacy);
            break;
        case 3:
            puts("\nPodaj id elementu ktory chcesz edytowac:");
            scanf("%d", &edit_id);
            while(getchar() != '\n')
                continue;
            if (pocz == NULL) {
                puts("\nBaza jest pusta!");
                break;
            }
            biezacy = pocz;
            while (biezacy->id != edit_id) {
                biezacy = biezacy->nast;
                if (biezacy == NULL) {
                    puts("\nNie ma takiego elementu");
                    break;
                }
            }
            edycja(biezacy);
            break;
        case 4:
            if (pocz == NULL) {
                puts("\nBaza jest pusta!");
                break;
            }
            if (pocz->nast == NULL) {
                puts("\nW bazie jest tylko jeden element, sortowanie niemozliwe");
                break;
            }
            sortowanie();
            break;
        case 5:
            wyczysc_baze();
            puts("\nWyczyszczono baze");
            break;
        case 6:
            puts("\nPodaj nazwe pliku");
            scanf("%s", nazwa);
            if ((w_zapisz = fopen(nazwa, "w"))==NULL) {
                printf("\nNie mogę otworzyć pliku %s do zapisu!", nazwa);
                break;
            }

            if (pocz == NULL)
                break;
            biezacy = pocz;
            while(biezacy != NULL) {
                fprintf(w_zapisz,"%d ",biezacy->id);
                fprintf(w_zapisz,"%s ",podlogi(biezacy->tytul));
		fprintf(w_zapisz,"%s ",podlogi(biezacy->gatunek));
                fprintf(w_zapisz,"%s ",podlogi(biezacy->producent));
                fprintf(w_zapisz,"%s ",podlogi(biezacy->nosnik));
                fprintf(w_zapisz,"%.2f ",biezacy->cena);
                fprintf(w_zapisz,"%s\n",podlogi(biezacy->platforma));
                biezacy=biezacy->nast;
            }

            fclose(w_zapisz);
            break;

        case 7:
            wyswietl();
            break;
        case 8:
            puts("\nPodaj nazwe pliku");
            scanf("%s", nazwa);
            while(getchar() != '\n')
                continue;
            if ((w_otworz = fopen(nazwa, "r")) == NULL) {
                printf("\nNie mozna otworzyc %s", nazwa);
                break;
            }
            int pomocniczy;
            wyczysc_baze();
            fscanf(w_otworz,"%d",&pomocniczy);
            while(feof(w_otworz)==0) {
                biezacy = stworz_element();
                biezacy->id=pomocniczy;
                strcpy(biezacy->tytul,usun_podlogi(w_otworz));
                strcpy(biezacy->gatunek,usun_podlogi(w_otworz));
                strcpy(biezacy->producent,usun_podlogi(w_otworz));
                strcpy(biezacy->nosnik,usun_podlogi(w_otworz));
                fscanf(w_otworz, "%f", &(biezacy->cena));
                strcpy(biezacy->platforma,usun_podlogi(w_otworz));
                fscanf(w_otworz,"%d",&pomocniczy);
            }

            fclose(w_otworz);
            break;
        case 9:
            exit(EXIT_SUCCESS);
            break;
        default:
            puts("\nPodaj liczbe odpowiadajaca danemu dzialaniu!\n");
            break;
	}
    }
    return;
}

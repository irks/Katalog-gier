#include "odczyt_z_pliku.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 50

char pom_do_odczytywania[MAX];

char* usun_podlogi(FILE *w_otworz) {
    int j;
    fscanf(w_otworz, "%s", pom_do_odczytywania);
    for(j=0; j<=MAX;j++) {
        if (*(pom_do_odczytywania+j) == '\0')
        break;
        if (*(pom_do_odczytywania+j) == '_')
           *(pom_do_odczytywania+j) = ' ';
    }
    return pom_do_odczytywania;

};

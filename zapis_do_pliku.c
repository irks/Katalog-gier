#include "zapis_do_pliku.h"
#include <stdlib.h>
#include <string.h>
#define MAX 50

char pom_do_zapisywania[MAX];

char* podlogi(char *tab) {
    int j;
    strcpy(pom_do_zapisywania, tab);
    for(j=0; j<=MAX;j++) {
        if (*(pom_do_zapisywania+j) == '\0')
        break;
        if (*(pom_do_zapisywania+j) == ' ')
           *(pom_do_zapisywania+j) = '_';
    }
    return pom_do_zapisywania;
};

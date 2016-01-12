#define MAX 50
#include "struktury.h"


#ifndef GATUNEK_H
#define GATUNEK_H

int id_max_gatunek(struct gatunek *);
void wyswietl_gatunki(void);
void stworz_gatunek(char *);
void usun_gatunek(int);
void edytuj_gatunek(int);
void interfejs_gatunek(struct gra *);
int dodaj_gatunek_do_gry(int, struct gra *);

#endif



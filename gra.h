#define MAX 50
#include "struktury.h"
#ifndef GRA_H
#define GRA_H

int id_max(struct gra *);
void usun_element(struct gra *);
void wyczysc_baze(void);
void wczytywanie(void);
void edycja(struct gra *);
void wyswietl(void);
struct gra * stworz_element(void);

#endif


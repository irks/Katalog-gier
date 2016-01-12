#define MAX 50

#ifndef STRUKTURY_H
#define STRUKTURY_H

struct gra {
    int id;
    char tytul[MAX];
    char producent[MAX];
    char gatunek[MAX];
    float cena;
    char platforma[MAX];
    char nosnik[MAX];
    struct gra *poprz, *nast;
};

struct gatunek {
    int id;
    char nazwa[MAX];
    struct gatunek *nast;
};

#endif


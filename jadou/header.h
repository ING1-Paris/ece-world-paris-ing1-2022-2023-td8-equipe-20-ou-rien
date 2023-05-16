#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#include "stdio.h"
#include "allegro.h"
#include "time.h"

#define NELEM 10

typedef struct jeu_cible_s {
    int pos_x[NELEM],pos_y[NELEM];
    int dep_x[NELEM],dep_y[NELEM];
    int score;
    int balle_tir;
    BITMAP *cible;
    clock_t clock_bouge_cible;
    SAMPLE *gagnee;
    SAMPLE *perdue;
    clock_t temps_restant;
    BITMAP *gagne_image;
    BITMAP *perdue_image;
    SAMPLE *tir_pistolet;
} jeu_cible_t;

jeu_cible_t creer_partie(void);


#endif //PROJET_HEADER_H

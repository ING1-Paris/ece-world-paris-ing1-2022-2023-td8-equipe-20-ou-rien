#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#include <allegro.h>
#include <time.h>
#include <stdio.h>

#define NELEM 10

typedef struct jeu_ballon_s {
    int posx[NELEM],posy[NELEM];
    int depx[NELEM],depy[NELEM];
    clock_t temps_depop[NELEM];
    int score;
    int balle_tire;
    BITMAP *ballon;
    clock_t clock_bouge_ballon;
    SAMPLE *gagnee;
    SAMPLE *perdue;
    clock_t temps_restant;
    BITMAP *gagne_image;
    BITMAP *perdue_image;
    SAMPLE *ballon_pop;
    BITMAP *fond;
    BITMAP *ballon2;
} jeu_ballon_t;

jeu_ballon_t creer_partie(void);
void ballon_deplace(jeu_ballon_t *jeu, int rayon);
void ballon_toucher(jeu_ballon_t *jeu, int i);
void gagne_ou_perdue(jeu_ballon_t jeu);

#endif //PROJET_HEADER_H

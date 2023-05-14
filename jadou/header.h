#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#include "stdio.h"
#include "allegro.h"
#include "time.h"

typedef struct Joueur1{
    int pose_x1, pose_y1;
    int pose_x2, pose_y2;
    int pose_x3, pose_y3;
    int pose_x4, pose_y4;
    int pose_x5, pose_y5;
    int pose_x6, pose_y6;
    int pose_x7, pose_y7;
    int pose_x8, pose_y8;
}Joueur1;

typedef struct Joueur2{
    int pose_x1, pose_y1;
    int pose_x2, pose_y2;
    int pose_x3, pose_y3;
    int pose_x4, pose_y4;
    int pose_x5, pose_y5;
    int pose_x6, pose_y6;
    int pose_x7, pose_y7;
    int pose_x8, pose_y8;
}Joueur2;

BITMAP *charger_image(const char *image);

void jeu(BITMAP *background, BITMAP *ballon, BITMAP *stand_de_tir, Joueur1 ballon1, Joueur2 ballon2);


BITMAP *charger_ballon1(BITMAP *ballon);
BITMAP *charger_ballon2(BITMAP *ballon);
BITMAP *charger_ballon3(BITMAP *ballon);
BITMAP *charger_ballon4(BITMAP *ballon);
BITMAP *charger_ballon5(BITMAP *ballon);
BITMAP *charger_ballon6(BITMAP *ballon);

void afficherBallonStatique1(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique2(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique3(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique4(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique5(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique6(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique7(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique8(BITMAP* background, BITMAP* ballon_affichage, Joueur1 ballon);
void afficherBallonStatique11(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique12(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique13(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique14(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique15(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique16(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique17(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);
void afficherBallonStatique18(BITMAP* background, BITMAP* ballon_affichage, Joueur2 ballon);

#endif //PROJET_HEADER_H

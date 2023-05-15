#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#include "stdio.h"
#include "allegro.h"
#include "time.h"

typedef struct Joueur1{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    int x5, y5;
    int x6, y6;
    int x7, y7;
    int x8, y8;
}Joueur1;

typedef struct Joueur2{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int x4, y4;
    int x5, y5;
    int x6, y6;
    int x7, y7;
    int x8, y8;
}Joueur2;

BITMAP *chargeImage(const char *image);

void jeu(BITMAP *background, BITMAP *ballon, BITMAP *tir, Joueur1 ballon1, Joueur2 ballon2);


BITMAP* chargeBallon1(BITMAP* ballon);
BITMAP* chargeBallon2(BITMAP* ballon);
BITMAP* chargeBallon3(BITMAP* ballon);
BITMAP* chargeBallon4(BITMAP* ballon);
BITMAP* chargeBallon5(BITMAP* ballon);
BITMAP* chargeBallon6(BITMAP* ballon);

void afficheBallonStat1(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat2(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat3(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat4(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat5(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat6(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat7(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat8(BITMAP* background, BITMAP* afficheBallon, Joueur1 ballon);
void afficheBallonStat11(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat22(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat33(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat44(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat55(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat66(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat77(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);
void afficheBallonStat88(BITMAP* background, BITMAP* afficheBallon, Joueur2 ballon);

void afficheBallonMob1(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob2(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob3(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob4(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob5(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob6(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob7(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob8(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob11(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob22(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob33(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob44(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob55(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob66(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob77(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);
void afficheBallonMob88(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c);



#endif //PROJET_HEADER_H

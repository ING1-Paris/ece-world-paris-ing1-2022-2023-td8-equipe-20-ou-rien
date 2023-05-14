//
// Created by mathe on 24/04/2023.
//
#include "allegro.h"

#ifndef PROJET_FONCTION_ALLEGRO_H
#define PROJET_FONCTION_ALLEGRO_H

void initiation();
BITMAP * importeImage(char *nomDeFichier);
SAMPLE * importeSon(char *nomDeFichier);
void fill_bitmap(BITMAP *bmp, int color,int posX,int posY);
#endif //PROJET_FONCTION_ALLEGRO_H

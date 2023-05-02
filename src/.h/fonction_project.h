//
// Created by mathe on 24/04/2023.
//
#include "allegro.h"
#include "fonction_allegro.h"
#include "fonction_utile.h"

#ifndef PROJET_FONCTION_SETTINGS_H
#define PROJET_FONCTION_SETTINGS_H

typedef struct joueur
{
    int posX,posY;
    int depX,DepY;
    char nom[500];
    int skin;
    int indice;
    int direction;
    int BoolMvmt;
}t_joueur;

void fill_bitmap(BITMAP *bmp, int color,int posX,int posY);
void menu(int *BoolMenu,int *BoolSettings, int *BoolPlay);
void animationDebut();
void playMap(int *BoolMenu, int *BoolSettings, int *BoolPlay);

#endif //PROJET_FONCTION_SETTINGS_H

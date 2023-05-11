//
// Created by mathe on 08/05/2023.
//
#include "stdlib.h"
#include "stdio.h"
#include "allegro.h"
#include "fonction_allegro.h"

#ifndef PROJET_FONCTION_GAME_FIGHTER_H
#define PROJET_FONCTION_GAME_FIGHTER_H

typedef struct joueurFight
{
    int posX,posY;
    int nbVie;
    int tx,ty;
    int direction;
    int BoolMvmt,BoolTouche;
    int skin;
    int indice;
}t_joueurFight;

void FightPlay();

#endif //PROJET_FONCTION_GAME_FIGHTER_H

//
// Created by mathe on 24/04/2023.
//
#include "allegro.h"
#include "fonction_allegro.h"
#include "fonction_utile.h"
#include "fonction_game_snake.h"
#include "fonction_game_fighter.h"
#include "header.h"

#ifndef PROJET_FONCTION_SETTINGS_H
#define PROJET_FONCTION_SETTINGS_H

typedef struct joueur
{
    int posX,posY;
    int depX,DepY;
    char nom[15];
    int skin;
    int indice;
    int direction;
    int BoolMvmt;
    int BoolTour;
    int nbTicket;
    int loaded;
    int Map;
}t_joueur;

typedef struct train
{
    int posX,posY;
    int depX,DepY;
    int direction;
    int BoolMvmt;
}t_train;
int menu(int *BoolMenu,int *BoolSettings, int *BoolPlay);
void animationDebut();
void playMap(int *BoolMenu, int *BoolSettings, int *BoolPlay, int choiceMenu);
void saveGame(char entire_path[], t_joueur *joueur1, t_joueur *joueur2, int statSnake,float statFight,int statBallon, int fpsStat, int taupeStat);
void loadGame(char entire_path[], t_joueur *joueur1, t_joueur *joueur2, int *statSnake,float *statFight,int *statBallon, int *fpsStat, int *taupeStat);
char detectKey(void);
void clearString(char *string, int n);
void destroyBitmapArray(BITMAP **bmp, int n, int start);
int startGameMole(void);

#endif //PROJET_FONCTION_SETTINGS_H

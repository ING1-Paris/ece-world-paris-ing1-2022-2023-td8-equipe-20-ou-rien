#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#include <allegro.h>

typedef struct mole_s {
    int isDisplay;
    BITMAP **sprite;
    clock_t clockAnim;
    clock_t timeBeforeDepop;
    clock_t timeBeforeSpawn;
    int indexAnim;
    int depop, spawn;
    int hit;
} mole_t;

typedef struct gameMole_s {
    BITMAP *buffer;
    BITMAP *background;
    BITMAP *sky1;
    BITMAP *sky2;
    int skyX1, skyX2, skyX3, skyX4;
    clock_t clockSky;
    mole_t **mole;
    BITMAP **weapon;
    int indexWeapon;
    clock_t clockAnimWeapon;
    int attacking;
    int score;
    clock_t timer;
    SAMPLE *whackSound;
} gameMole_t;

void drawSky(gameMole_t *game);

void displayWeapon(gameMole_t *game);
void animWeapon(gameMole_t *game);
BITMAP **fillSprite(char *filepath, int nbSprite, int w, int h);

void checkPtrNull(void *ptr, char *string);

gameMole_t *createGame(int nbMole);
int startGame(void);

void freeGameMole(gameMole_t *game);

#endif //PROJET_HEADER_H
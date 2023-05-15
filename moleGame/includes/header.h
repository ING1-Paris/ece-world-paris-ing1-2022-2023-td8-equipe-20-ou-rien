#ifndef HEADER_H
    #define HEADER_H
#include "./struct.h"

#define WINDOW_W 800
#define WINDOW_H 600

void drawSky(gameMole_t *game);

void displayWeapon(gameMole_t *game);
void animWeapon(gameMole_t *game);
void fillWeapon(gameMole_t *game, int nbSprite, int w, int h);

void checkPtrNull(void *ptr, char *string);

gameMole_t *createGame(int nbMole);
void startGame(void);

void freeGame(gameMole_t *game);

#endif /* HEADER_H */
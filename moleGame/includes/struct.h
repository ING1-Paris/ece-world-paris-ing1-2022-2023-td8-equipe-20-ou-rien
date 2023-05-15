#ifndef STRUCT_H
    #define STRUCT_H

#include <allegro.h>

typedef struct mole_s {
    int isDisplay;
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
} gameMole_t;

#endif /* STRUCT_H */
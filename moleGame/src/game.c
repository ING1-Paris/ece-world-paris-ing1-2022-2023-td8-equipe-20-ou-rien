#include <stdlib.h>
#include <allegro.h>
#include <stdio.h>
#include "../includes/header.h"

gameMole_t *createGame(int nbMole)
{
    gameMole_t *game = malloc(sizeof(gameMole_t));

    checkPtrNull(game, "Exit Failure: malloc failed");
    game->buffer = create_bitmap(SCREEN_W, SCREEN_H);
    checkPtrNull(game->buffer, "Exit Failure: buffer creation failed");

    game->mole = malloc(sizeof(mole_t *) * (nbMole + 1));
    checkPtrNull(game->mole, "Exit Failure: malloc failed");
    for (int i = 0; i < nbMole; i++) {
        game->mole[i] = malloc(sizeof(mole_t));
        checkPtrNull(game->mole[i], "Exit Failure: malloc failed");
        game->mole[i]->isDisplay = 0;
    }
    game->mole[nbMole] = NULL;

    fillWeapon(game, 8, 113, 97);
    game->background = load_bitmap("./assets/mole/background.bmp", NULL);
    checkPtrNull(game->background, "Exit Failure: loading background bitmap failed");
    game->sky1 = load_bitmap("./assets/mole/sky.bmp", NULL);
    checkPtrNull(game->sky1, "Exit Failure: loading sky bitmap failed");
    game->sky2 = load_bitmap("./assets/mole/sky2.bmp", NULL);
    checkPtrNull(game->sky2, "Exit Failure: loading sky bitmap failed");

    game->skyX1 = 0;
    game->skyX2 = 0;
    game->skyX3 = SCREEN_W;
    game->skyX4 = SCREEN_W;
    game->clockSky = clock();
    game->score = 0;
    game->attacking = 0;
    game->timer = clock();

    return game;
}

void displayTimer(gameMole_t *game)
{
    char string[5];

    sprintf(string, "%d", 30 - (clock() - game->timer) / 1000);
    textout_ex(game->buffer, font, "temps:", 30, 30, makecol(0, 0, 0), -1);
    textout_ex(game->buffer, font, string, 80, 30, makecol(0, 0, 0), -1);
}

void displayScore(gameMole_t *game)
{
    char string[5];

    sprintf(string, "%d", game->score);
    textout_ex(game->buffer, font, "score:", SCREEN_W - 140, 30, makecol(0, 0, 0), -1);
    textout_ex(game->buffer, font, string, SCREEN_W - 60, 30, makecol(0, 0, 0), -1);

}

void startGame(void)
{
    BITMAP *buffer;
    gameMole_t *game = createGame(6);

    while (!key[KEY_ESC]) {
        clear_to_color(game->buffer, makecol(141, 199, 236));
        drawSky(game);
        stretch_sprite(game->buffer, game->background, 0, 0, SCREEN_W, SCREEN_H);
        
        displayTimer(game);
        displayScore(game);
        animWeapon(game);
        displayWeapon(game);

        blit(game->buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    freeGame(game);
}
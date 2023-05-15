#include <stdlib.h>
#include <allegro.h>
#include "../includes/header.h"

void freeGame(gameMole_t *game)
{
    for (int i = 0; game->mole[i] != NULL; i++)
        free(game->mole[i]);
    free(game->mole);
    for (int i = 0; game->weapon[i] != NULL; i++)
        destroy_bitmap(game->weapon[i]);
    free(game->weapon);
    destroy_bitmap(game->sky1);
    destroy_bitmap(game->sky2);
    destroy_bitmap(game->buffer);
    free(game);
}
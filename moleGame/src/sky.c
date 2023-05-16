#include <allegro.h>
#include "../includes/header.h"

void drawSky(gameMole_t *game)
{
    if (clock() - game->clockSky >= 40) {
        game->skyX1 -= 2;
        game->skyX2--;
        game->skyX3 -= 2;
        game->skyX4--;
        game->clockSky = clock();
        if (game->skyX1 + SCREEN_W <= 0)
            game->skyX1 = SCREEN_W;
        if (game->skyX2 + SCREEN_W <= 0)
            game->skyX2 = SCREEN_W;
        if (game->skyX3 + SCREEN_W <= 0)
            game->skyX3 = SCREEN_W;
        if (game->skyX4 + SCREEN_W <= 0)
            game->skyX4 = SCREEN_W;
    }
    stretch_sprite(game->buffer, game->sky2, game->skyX2, 0, game->sky2->w, game->sky2->h);
    stretch_sprite(game->buffer, game->sky2, game->skyX4, 0, game->sky2->w, game->sky2->h);
    draw_sprite(game->buffer, game->sky1, game->skyX1, 0);
    draw_sprite(game->buffer, game->sky1, game->skyX3, 0);
}
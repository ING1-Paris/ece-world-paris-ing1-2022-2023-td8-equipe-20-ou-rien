#include <stdlib.h>
#include <allegro.h>
#include "../includes/header.h"

void displayWeapon(gameMole_t *game)
{
    stretch_sprite(game->buffer, game->weapon[game->indexWeapon], mouse_x - game->weapon[game->indexWeapon]->w, mouse_y - game->weapon[game->indexWeapon]->h, game->weapon[game->indexWeapon]->w * 2, game->weapon[game->indexWeapon]->h * 2);
}

void fillWeapon(gameMole_t *game, int nbSprite, int w, int h)
{
    BITMAP *tmp = load_bitmap("./assets/mole/weapon.bmp", NULL);

    checkPtrNull(tmp, "Exit Failure: loading weapon bitmap failed");
    game->weapon = malloc(sizeof(BITMAP *) * (nbSprite + 1));
    checkPtrNull(game->weapon, "Exit Failure: malloc failed");

    for (int i = 0; i < nbSprite; i++) {
        game->weapon[i] = create_bitmap(w, h);
        checkPtrNull(game->weapon[i], "Exit Failure: bitmap creation failed");
        stretch_blit(tmp, game->weapon[i], i * w, 0, w, h, 0, 0, w, h);
    }
    game->weapon[nbSprite] = NULL;
}

void animWeapon(gameMole_t *game)
{    
    if (mouse_b & 1 && !game->attacking)
        game->attacking = 1;

    if (game->weapon[game->indexWeapon + 1] != NULL && clock() - game->clockAnimWeapon >= 45 && game->attacking) {
        game->clockAnimWeapon = clock();
        game->indexWeapon++;
    } else if (game->weapon[game->indexWeapon + 1] == NULL) {
        game->attacking = 0;
        game->indexWeapon = 0;
    }
}
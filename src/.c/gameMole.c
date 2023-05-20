#include <allegro.h>
#include <stdlib.h>
#include <winalleg.h>
#include <stdio.h>
#include "../.h/moleHeader.h"

void checkPtrNull(void *ptr, char *string);

void freeGameMole(gameMole_t *game)
{
    for (int i = 0; game->mole[i] != NULL; i++) {
        for (int j = 0; game->mole[i]->sprite[j] != NULL; j++)
            destroy_bitmap(game->mole[i]->sprite[j]);
        free(game->mole[i]);
    }
    free(game->mole);
    for (int i = 0; game->weapon[i] != NULL; i++)
        destroy_bitmap(game->weapon[i]);
    free(game->weapon);
    destroy_bitmap(game->sky1);
    destroy_bitmap(game->sky2);
    destroy_sample(game->whackSound);
    destroy_bitmap(game->buffer);
    free(game);
}

void displayWeapon(gameMole_t *game)
{
    stretch_sprite(game->buffer, game->weapon[game->indexWeapon], mouse_x - game->weapon[game->indexWeapon]->w / 2, mouse_y - game->weapon[game->indexWeapon]->h, game->weapon[game->indexWeapon]->w * 2, game->weapon[game->indexWeapon]->h * 2);
}

BITMAP **fillSprite(char *filepath, int nbSprite, int w, int h)
{
    BITMAP *tmp = load_bitmap(filepath, NULL);
    BITMAP **sprite = malloc(sizeof(BITMAP *) * (nbSprite + 1));

    checkPtrNull(tmp, "Exit Failure: loading weapon bitmap failed");
    checkPtrNull(sprite, "Exit Failure: malloc failed");

    for (int i = 0; i < nbSprite; i++) {
        sprite[i] = create_bitmap(w, h);
        checkPtrNull(sprite[i], "Exit Failure: bitmap creation failed");
        stretch_blit(tmp, sprite[i], i * w, 0, w, h, 0, 0, w, h);
    }
    sprite[nbSprite] = NULL;
    destroy_bitmap(tmp);

    return sprite;
}

void animWeapon(gameMole_t *game)
{    
    if (mouse_b & 1 && !game->attacking) {
        game->attacking = 1;
        play_sample(game->whackSound, 200, 128, 1000, 0);
    }
    if (game->weapon[game->indexWeapon + 1] != NULL && clock() - game->clockAnimWeapon >= 45 && game->attacking) {
        game->clockAnimWeapon = clock();
        game->indexWeapon++;
    } else if (game->weapon[game->indexWeapon + 1] == NULL) {
        game->attacking = 0;
        game->indexWeapon = 0;
    }
}

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

gameMole_t *createGameMole(int nbMole)
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
        game->mole[i]->isDisplay = rand() % 2;
        // game->mole[i]->isDisplay = 1;
        game->mole[i]->sprite = fillSprite("../assets/mole/mole.bmp", 4, 130, 104);
        game->mole[i]->clockAnim = clock();
        game->mole[i]->timeBeforeDepop = 0;
        game->mole[i]->timeBeforeSpawn = clock();
        game->mole[i]->indexAnim = 0;
        game->mole[i]->hit = 0;
    }
    game->mole[nbMole] = NULL;

    game->weapon = fillSprite("../assets/mole/weapon.bmp", 8, 113, 97);
    game->background = load_bitmap("../assets/mole/background.bmp", NULL);
    checkPtrNull(game->background, "Exit Failure: loading background bitmap failed");
    game->sky1 = load_bitmap("../assets/mole/sky.bmp", NULL);
    checkPtrNull(game->sky1, "Exit Failure: loading sky bitmap failed");
    game->sky2 = load_bitmap("../assets/mole/sky2.bmp", NULL);
    checkPtrNull(game->sky2, "Exit Failure: loading sky bitmap failed");
    game->whackSound = load_wav("../assets/mole/sound/whack.wav");
    checkPtrNull(game->whackSound, "Exit Failure: loading whack sound failed");

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

void displayScoreMole(gameMole_t *game)
{
    char string[5];

    sprintf(string, "%d", game->score);
    textout_ex(game->buffer, font, "score:", SCREEN_W - 140, 30, makecol(0, 0, 0), -1);
    textout_ex(game->buffer, font, string, SCREEN_W - 60, 30, makecol(0, 0, 0), -1);

}

void displayMole(gameMole_t *game)
{
    clock_t currentClock = clock();

    for (int i = 0; game->mole[i] != NULL; i++) {
        if (game->mole[i]->isDisplay) {
            if (currentClock - game->mole[i]->clockAnim >= 120 && !game->mole[i]->timeBeforeDepop) {
                game->mole[i]->clockAnim = currentClock;
                if (game->mole[i]->sprite[game->mole[i]->indexAnim + 1] != NULL) {
                    game->mole[i]->indexAnim++;
                } else if (!game->mole[i]->timeBeforeDepop) {
                    game->mole[i]->timeBeforeDepop = currentClock;
                    game->mole[i]->depop = rand() % (1000 - 200) + 200;
                }
            }
            if (game->mole[i]->timeBeforeDepop != 0 && currentClock - game->mole[i]->timeBeforeDepop >= game->mole[i]->depop) {               
                if (game->mole[i]->indexAnim - 1 < 0 && currentClock - game->mole[i]->clockAnim >= 110) {                    
                    game->mole[i]->isDisplay = 0;
                    game->mole[i]->timeBeforeDepop = 0;
                    game->mole[i]->indexAnim = 0;
                    game->mole[i]->timeBeforeSpawn = currentClock;
                    game->mole[i]->spawn = rand() % (5000 - 1500) + 1500;
                } else if (currentClock - game->mole[i]->clockAnim >= 110) {
                    game->mole[i]->indexAnim--;
                    game->mole[i]->clockAnim = clock();
                }
            }
            draw_sprite(game->buffer, game->mole[i]->sprite[game->mole[i]->indexAnim], 100 + i * 150, 450);
        } else if (currentClock - game->mole[i]->timeBeforeSpawn >= game->mole[i]->spawn) {
            game->mole[i]->isDisplay = 1;
            game->mole[i]->hit = 0;
        }
    }
}

void hitMole(gameMole_t *game)
{
    for (int i = 0; game->mole[i] != NULL; i++) {
        if (game->mole[i]->isDisplay) {
            if (mouse_b & 1 && !game->mole[i]->hit && (mouse_x >= 100 + i * 150 && mouse_x <= 100 + i * 150 + game->mole[i]->sprite[0]->w) && (mouse_y >= 450 && mouse_y <= 450 + game->mole[i]->sprite[0]->h)) {
                game->mole[i]->isDisplay = 0;
                game->mole[i]->timeBeforeDepop = 0;
                game->mole[i]->indexAnim = 0;
                game->mole[i]->timeBeforeSpawn = clock();
                game->mole[i]->spawn = rand() % (5000 - 1500) + 1500;
                game->mole[i]->hit = 1;
                game->score++;
            }
        }
    }
}

int startGameMole(void)
{
    BITMAP *buffer;
    gameMole_t *game = createGameMole(4);
    int score;

    PlaySound("../assets/mole/sound/musicMole.wav", NULL, SND_ASYNC | SND_LOOP);
    while (!key[KEY_ESC]) {
        clear_to_color(game->buffer, makecol(141, 199, 236));

        drawSky(game);
        stretch_sprite(game->buffer, game->background, 0, 0, SCREEN_W, SCREEN_H);
        displayMole(game);
        hitMole(game);
        displayTimer(game);
        displayScoreMole(game);
        animWeapon(game);
        displayWeapon(game);

        if (30 - (clock() - game->timer) / 1000 <= 0)
            break;
        blit(game->buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    PlaySound(NULL, NULL, SND_ASYNC | SND_LOOP);
    score = game->score;
    freeGameMole(game);

    return score;
}
#ifndef HEADER_H
    #define HEADER_H

#define PI 3.14159265358979323846
#define SIZE 64


#include <stdbool.h>
#include <allegro.h>
#include <time.h>

typedef struct gun_s {
    BITMAP ***sprite;
    SAMPLE *shootSound;
    SAMPLE *reloadSound;
    int dps;
    int nbShoot;
    int currentShoot;
    int reload;
    int shooting;
    int offset;
    int typeOffset;
} gun_t;

typedef struct player_s {
    gun_t **guns;
    int indexGun;
    int indexSpriteGun;
    int speedAnim;
    int currentAnim;
    float angle;
    int screenX;
    int screenY;
    int mapX;
    int mapY;
    int life;
    float sensitivity;
    bool isWalked;
    int posMapX;
    int posMapY;
    float posxCase;
    float posyCase;
    int screenDist;
    int shooting;
    time_t timeHeal;
    time_t timeAttackedHeal;
    int score;
} player_t;

typedef struct npc_s {
    int life;
    int points;
    time_t tempoAttack;
    int maxStep;
    int nbStep;
    int maxLife;
    int speed;
    int dps;
    int attacking;
    int walking;
    int indexSprite;
    int tempoAnim;
    int IndexAnim;
    int typeSprite;
    int x;
    int y;
    int screenX;
    int screenY;
    int dead;
    int playerSeen;
    int agro;
} npc_t;

typedef struct game3d_s {
    int row;
    int col;
    int oldMouseX;
    int indexSaveData;
    BITMAP *buffer;
    BITMAP *sky;
    BITMAP *pauseBanner;
    BITMAP **texture;
    BITMAP ****oppsAnim;
    BITMAP *munLogo;
    player_t *player;
    npc_t opps[56];
    int allDist[374];
    int allPosTexture[374];
    char allTypeWall[374];
    int allPos[374];
    int badPosX[56];
    int badPosY[56];
    char **map;
    int skyX;
    int skyX2;
    int midScreenW;
    int midScreenH;
    int volume;
    int nbNpc;
}game3d_t;


int fonction_labyrinth(void);
void pauseMenu(game3d_t *game);

void generateSpawnCoord(game3d_t *game, int *x, int *y);

void animOpps(npc_t *opps, BITMAP ****anim);
void loadOpps(game3d_t *game);
void calcSprite(game3d_t *game, int index);

void displayTarget(game3d_t *game);
void displayMiniMap(game3d_t *game);
void displaySky(game3d_t *game);
void display3D(game3d_t *game);
void displayLife(game3d_t *game);
void displayScore(game3d_t *game);

game3d_t *createGame(void);
int gameLoop(void);

void quickSort(int arr[], int label1[], char label2[], int label3[], int left, int right);

gun_t **loadGuns(gun_t **guns);
void displayGun(game3d_t *game);

void movePlayer(game3d_t *game);
player_t *createPlayer(void);
void playerHeal(game3d_t *game);

void raycasting(game3d_t *game);

char **loadMap(char *filepath, int *row, int *col);

void checkPtrNull(void *ptr, char *error);

void freeArray(char **array);
void freePlayer(player_t *player);
void freeGame(game3d_t *game);

#endif /*HEADER_H*/
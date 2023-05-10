#include <allegro.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

void animOpps(npc_t *opps, BITMAP ****anim)
{
    if (opps->tempoAnim >= 27 && anim[opps->typeSprite][opps->IndexAnim][opps->indexSprite + 1] != NULL) {
        opps->tempoAnim = 0;
        if ((opps->walking && opps->IndexAnim == 0) || opps->IndexAnim) {
            opps->indexSprite++;
            if (opps->IndexAnim == 1 && !opps->attacking)
                opps->attacking = 1;
        }
    } else if (anim[opps->typeSprite][opps->IndexAnim][opps->indexSprite + 1] == NULL && !opps->dead) {
        // if (opps->dead) { // death
        //     opps->dead = 0;
        //     opps->life = opps->maxLife;
        //     opps->IndexAnim = 0;
        //     opps->attacking = 0;
        /*} else*/ 
        if (opps->IndexAnim == 1) {
            if (anim[opps->typeSprite][opps->IndexAnim][opps->indexSprite + 1] == NULL) {
                opps->IndexAnim = 0;
                opps->attacking = 0;
                opps->tempoAttack = time(NULL);
            }
        }
        opps->tempoAnim = 0;
        opps->indexSprite = 0;
    } else
        opps->tempoAnim++;
}

BITMAP ***loadOneOpps(FILE *fp, game3d_t *game, int typeOpps, BITMAP ***animOpps, int nbOpps)
{
    char filepath[30];
    BITMAP *tmpBitmap;
    int w, h;
    int nbWalk, nbAttack, nbDeath;
    int x, y;
    int life, dps, speed;

    fscanf(fp, "%s", filepath);
    tmpBitmap = load_bitmap(filepath, NULL);
    fscanf(fp, "%d", &w);
    fscanf(fp, "%d", &h);
    fscanf(fp, "%d", &nbWalk);
    fscanf(fp, "%d", &nbAttack);
    fscanf(fp, "%d", &nbDeath);
    
    checkPtrNull(tmpBitmap, "Exit Failure: sprite file monster not found\n");
    animOpps = malloc(sizeof(BITMAP **) * 4);
    checkPtrNull(animOpps, "Exit Failure: malloc failed\n");
    animOpps[3] = NULL;
    int arr[] = {nbWalk, nbAttack, nbDeath};

    for (int i = 0; i < 3; i++) {
        animOpps[i] = malloc(sizeof(BITMAP *) * (arr[i] + 1));
        checkPtrNull(animOpps[i], "Exit Failure: malloc failed\n");
        animOpps[i][arr[i]] = NULL;
        x = 0;
        y = i * h;
        for (int j = 0; j < arr[i]; j++) {
            animOpps[i][j] = create_bitmap(w, h);
            stretch_blit(tmpBitmap, animOpps[i][j], x, y, w, h, 0, 0, w, h);
            x += w;
            if (x >= tmpBitmap->w) {
                x = 0;
                y += h;
            }
        }
    }

    fscanf(fp, "%d", &life);
    fscanf(fp, "%d", &dps);
    fscanf(fp, "%d", &speed);

    for (int i = (30 / nbOpps) * typeOpps; i < (30 / nbOpps) * (typeOpps + 1); i++) {
        game->opps[i].life = life;
        game->opps[i].dps = dps;
        game->opps[i].speed = speed;
        game->opps[i].IndexAnim = 0;
        game->opps[i].indexSprite = 0;
        game->opps[i].maxLife = game->opps[i].life;
        game->opps[i].dead = 0;
        game->opps[i].attacking = 0;
        game->opps[i].maxStep = 3;
        game->opps[i].nbStep = 0;
        game->opps[i].tempoAttack = time(NULL);
        game->opps[i].walking = 0;
        game->opps[i].playerSeen = 0;
        game->opps[i].agro = 0;
        game->opps[i].typeSprite = typeOpps;
    }

    return animOpps;
}

void loadOpps(game3d_t *game)
{
    FILE *fp = fopen("./conf/opps.conf", "r");
    int nbOpps;
    int x, y;

    checkPtrNull(fp, "Exit Failure: ./conf/opps.conf opening failed\n");
    fscanf(fp, "%d", &nbOpps);
    game->oppsAnim = malloc(sizeof(BITMAP ***) * (nbOpps + 1));
    game->oppsAnim[nbOpps] = NULL;
    for (int i = 0; i < nbOpps; i++) {
        game->oppsAnim[i] = loadOneOpps(fp, game, i, game->oppsAnim[i], nbOpps);
        
    }
    fclose(fp);

    for (int i = 0; i < 30; i++) {
        game->badPosX[i] = 0;
        game->badPosY[i] = 0;
    }

    for (int i = 0; i < 30; i++) {
        generateSpawnCoord(game, &x, &y);
        game->badPosX[i] = x * SIZE + 20;
        game->badPosY[i] = y * SIZE + 20;
        game->opps[i].x = x * SIZE + 20;
        game->opps[i].y = y * SIZE + 20;
    }   
}

int playerIsSeen(game3d_t *game, double angle, int index)
{
    int oppsCaseX = game->opps[index].x / 64;
    int oppsCaseY = game->opps[index].y / 64;
    int oppsVert = 0, oppsHor = 0;
    float x_vert, y_vert;
    float y_hor, x_hor;
    int tile_vert_x, tile_vert_y;
    int tile_hor_x, tile_hor_y;
    float dx, dy;
    float depth_vert, delta_depth;
    int ox = game->player->screenX;
    int oy = game->player->screenY;
    float depth_hor;

    if (oppsCaseX == game->player->mapX && oppsCaseY == game->player->mapY)
        return 1;

    if (game->opps[index].x < game->player->screenX)
        angle = PI + angle;
    if (angle < 0)
        angle = PI * 2 + angle;

    float sin_a = -sin(angle);
    float cos_a = cos(angle);

    // Horizontals
    if (sin_a >= 0) {
        y_hor = (game->player->posMapY * 64) + 64;
        dy = 64;
    } else {
        y_hor = (game->player->posMapY * 64) - 0.0064;
        dy = -64;
    }

    depth_hor = (y_hor - oy) / sin_a;
    x_hor = ox + depth_hor * cos_a;

    delta_depth = dy / sin_a;
    dx = delta_depth * cos_a;

    while (1) {
        tile_hor_x = (int)(x_hor) / 64;
        tile_hor_y = (int)(y_hor) / 64;
        if (tile_hor_x < 0)
            tile_hor_x = 0;
        else if (tile_hor_x > game->col)
            tile_hor_x = game->col;
        if (tile_hor_y > game->row)
            tile_hor_y = game->row;
        else if (tile_hor_y < 0)
            tile_hor_y = 0;
        if (tile_hor_x == oppsCaseX && tile_hor_y == oppsCaseY) {
            oppsHor = 1;
            break;
        }
        if ((game->map[tile_hor_y][tile_hor_x] != '*'))
            break;
        x_hor += dx;
        y_hor += dy;
        depth_hor += delta_depth;
    }

    // Vericals
    if (cos_a > 0) {
        x_vert = (game->player->posMapX * 64) + 64;
        dx = 64;
    } else {
        x_vert = (game->player->posMapX * 64) - 0.0064;
        dx = -64;
    }

    delta_depth = dx / cos_a;
    depth_vert = (x_vert - ox) / cos_a;

    y_vert = oy + depth_vert * sin_a;
    dy = delta_depth * sin_a;
    while (1) {
        tile_vert_x = (int)(x_vert) / 64;
        tile_vert_y = (int)(y_vert) / 64;
        if (tile_vert_y < 0)
            tile_vert_y = 0;
        else if (tile_vert_y > game->row)
            tile_vert_y = game->row;
        if (tile_vert_x > game->col)
            tile_vert_x = game->col;
        else if (tile_vert_x < 0)
            tile_vert_x = 0;
        if (tile_vert_y == oppsCaseY && tile_vert_x == oppsCaseX) {
            oppsVert = 1;
            break;
        }
        if (game->map[tile_vert_y][tile_vert_x] != '*')
            break;

        x_vert += dx;
        y_vert += dy;
        depth_vert += delta_depth;
    }

    if (depth_vert < depth_hor) {
        if (!game->opps[index].agro && oppsVert)
            game->opps[index].agro = 1;
        return oppsVert;
    } else {
        if (!game->opps[index].agro && oppsHor)
            game->opps[index].agro = 1;
        return oppsHor;
    }
}

int collideBetweenOpps(game3d_t *game, int x, int y, int index)
{
    for (int i = 0; i < game->nbNpc; i++) {
        if (i != index && (x >= game->opps[i].x - 10 && x <= game->opps[i].x + 10) && (y >= game->opps[i].y - 10 && y <= game->opps[i].y + 10) && game->opps[i].IndexAnim != 2)
            return 1;
    }
    return 0;
}

void moveOpps(game3d_t *game, npc_t *opps, player_t *player, double angleMonster, char **map, int index)
{
    double posX, posY;
    int checkX, checkY;

    if (opps->x < player->screenX) {
        posX = opps->speed * cos(angleMonster);
        posY = -opps->speed * sin(angleMonster);
    } else {
        posX = -opps->speed * cos(angleMonster);
        posY = opps->speed * sin(angleMonster);
    }
    checkX = opps->x + posX;
    checkY = opps->y + posY;

    if (map[(int)(checkY + posY * 3) / 64][(int)(checkX + posX * 3) / 64] == '*' && opps->nbStep == opps->maxStep && opps->IndexAnim != 2 && !collideBetweenOpps(game, checkX, checkY, index) && opps->IndexAnim != 2 && (opps->playerSeen || opps->agro)) {
        if ((checkX >= player->screenX + 30 || checkX <= player->screenX - 30) && (checkY >= player->screenY + 30 || checkY <= player->screenY - 30)) {
            opps->x += round(posX);
            opps->y += round(posY);
            opps->walking = 1;
        } else if (abs(posY) <= 0.1 && abs(posY) >= 0 && (checkX >= player->screenX + 30 || checkX <= player->screenX - 30)) {
            opps->x += round(posX);
            opps->walking = 1;
        } else if (abs(posX) <= 0.1 && abs(posX) >= 0.0000 && (checkY >= player->screenY + 30 || checkY <= player->screenY - 30)) {
            opps->y += round(posY);
            opps->walking = 1;
        } else if (time(NULL) - opps->tempoAttack >= 1) {
            opps->IndexAnim = 1;
            opps->walking = 0;
        }
        opps->nbStep = 0;
    } else if (opps->nbStep < opps->maxStep)
        opps->nbStep++;
}

void calcSprite(game3d_t *game, int index)
{
    double dx = game->opps[index].x - game->player->screenX;
    double dy = -(game->opps[index].y - game->player->screenY);
    double angleMonster = atan(dy / dx);
    double angleRight = game->player->angle - ((60.00 * 0.0175) / 2.00);
    double angleLeft = game->player->angle + ((60.00 * 0.0175) / 2.00);
    double alpha;
    int nbVec, dist;
    int projWidth, projHeight;
    BITMAP *sprite = game->oppsAnim[game->opps[index].typeSprite][game->opps[index].IndexAnim][game->opps[index].indexSprite];
    
    game->opps[index].playerSeen = playerIsSeen(game, angleMonster, index);
    moveOpps(game, &game->opps[index], game->player, angleMonster, game->map, index);

    if (game->opps[index].x < game->player->screenX)
        angleMonster = PI + angleMonster;
    if (angleMonster < 0)
        angleMonster = PI * 2 + angleMonster;
    
    if (angleRight < 0)
        angleRight = PI * 2 + angleRight;
    if (angleLeft > 2 * PI)
        angleLeft -= 2 * PI;

    if ((angleMonster <= angleLeft && angleMonster >= angleRight && angleRight < angleLeft) || (((angleMonster <= angleLeft && angleMonster >= 0) || angleMonster >= angleRight)) && angleRight > angleLeft) {
        
        alpha = game->player->angle - angleMonster;
        if (alpha < -5.5)
            alpha += 2 * PI;
        else if (alpha > 5.5)
            alpha -= 2 * PI;

        if (((alpha <= 0.1 && alpha >= 0) || (alpha >= -0.1 && alpha <= 0)) && game->player->shooting && game->opps[index].playerSeen && !game->opps[index].dead) { // si le joueur shoot sur l'ennemie
            game->opps[index].life -= game->player->guns[game->player->indexGun]->dps;
            game->player->shooting = 0;
            if (game->opps[index].life <= 0) { // si le bot meurt
                game->opps[index].IndexAnim = 2;
                game->opps[index].dead = 1;
                game->opps[index].life = 0;
            }
        }

        nbVec = round(alpha / 0.004375);
        game->allDist[game->indexSaveData] = sqrt(dx * dx + dy * dy); // hypothenus
        game->allPosTexture[game->indexSaveData] = -game->opps[index].typeSprite - 1;
        game->allPos[game->indexSaveData] = nbVec;
        game->allTypeWall[game->indexSaveData] = index;
        game->indexSaveData++;
    }
}
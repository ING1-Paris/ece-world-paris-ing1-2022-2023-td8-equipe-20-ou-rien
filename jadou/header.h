#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#include "stdio.h"
#include "allegro.h"
#include "time.h"

typedef struct player1 {
    int pose_x1, pose_y1;
    int pose_x2, pose_y2;
    int pose_x3, pose_y3;
    int pose_x4, pose_y4;
    int pose_x5, pose_y5;
    int pose_x6, pose_y6;
    int pose_x7, pose_y7;
    int pose_x8, pose_y8;
}player1;

typedef struct player2 {
    int pose_x1, pose_y1;
    int pose_x2, pose_y2;
    int pose_x3, pose_y3;
    int pose_x4, pose_y4;
    int pose_x5, pose_y5;
    int pose_x6, pose_y6;
    int pose_x7, pose_y7;
    int pose_x8, pose_y8;
}player2;

BITMAP *charger_image(const char *image);


#endif //PROJET_HEADER_H

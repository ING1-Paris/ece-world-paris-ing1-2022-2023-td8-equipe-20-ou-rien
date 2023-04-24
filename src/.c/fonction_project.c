//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"

void menu(int *BoolMenu,int *BoolSettings, int *BoolPlay,int frame,BITMAP *fond[51],BITMAP *buffer)
{
    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);
        frame++;
        if(frame>49)
        {
            frame=1;
        }
        stretch_blit(fond[frame],buffer,0,0,fond[frame]->w,fond[frame]->h,0,0,SCREEN_W,SCREEN_H);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
}

//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"

void menu(int *BoolMenu,int *BoolSettings, int *BoolPlay)
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char nomDeFichier[5000];
    int frame=1;
    BITMAP *fond[181];
    for(int i=1;i<180;i++)
    {
        sprintf(nomDeFichier,"../image/image fond menu/frame-%d.bmp",i);
        fond[i]= importeImage(nomDeFichier);
    }
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);
        frame++;
        if(frame>179)
        {
            frame=1;
        }
        stretch_blit(fond[frame],buffer,0,0,fond[frame]->w,fond[frame]->h,0,0,SCREEN_W,SCREEN_H);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
}

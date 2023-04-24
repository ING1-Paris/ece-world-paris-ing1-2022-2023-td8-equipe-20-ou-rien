//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"
#define DEP 5

void fill_bitmap(BITMAP *bmp, int color) {
    int x, y;
    for (y = 0; y < bmp->h; y++) {
        for (x = 0; x < bmp->w; x++) {
            if(getpixel(bmp,x,y)!= makecol(255,0,255))
            {
                putpixel(bmp, x, y, color);
            }
        }
    }
}

void animationDebut()
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *slogan= importeImage("../image/image utile/slogan 2.bmp");
    BITMAP *company= importeImage("../image/image utile/company project.bmp");
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(company, makecol(i,i,i));
        draw_sprite(buffer,company,0,0);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(10);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(slogan, makecol(i,i,i));
        draw_sprite(buffer,slogan,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(20);
    }
}
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
    int x=0;
    int y=0;
    BITMAP *fond[181];
    for(int i=1;i<180;i++)
    {
        sprintf(nomDeFichier,"../image/image fond menu/frame-%d.bmp",i);
        fond[i]= importeImage(nomDeFichier);
    }
    BITMAP *PLAY= importeImage("../image/image ecriture/PLAY.bmp");
    BITMAP *SETTINGS= importeImage("../image/image ecriture/SETTINGS.bmp");
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);
        frame++;
        if(frame>179)
        {
            frame=1;
        }
        if(key[KEY_R])
        {
            y-=DEP;
        }
        if(key[KEY_F])
        {
            y+=DEP;
        }
        if(key[KEY_D])
        {
            x-=DEP;
        }
        if(key[KEY_G])
        {
            x+=DEP;
        }
        if(x>SCREEN_W)
        {
            x=SCREEN_W;
        }
        if(x<0)
        {
            x=0;
        }
        if(y>SCREEN_H)
        {
            y=SCREEN_H;
        }
        if(y<0)
        {
            y=0;
        }
        printf("%d | %d\n",x,y);
        stretch_blit(fond[frame],buffer,0,0,fond[frame]->w,fond[frame]->h,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(buffer,PLAY,275,175);
        draw_sprite(buffer,SETTINGS,170,270);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(25);
    }
}

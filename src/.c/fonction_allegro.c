//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_allegro.h"
#include "allegro.h"
#include "stdio.h"
#define SCREENW 800
#define SCREENH 600


///fonction allegro

void initiation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
    show_mouse(screen);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
}

BITMAP * importeImage(char *nomDeFichier)
{
    BITMAP *imageARendre= load_bitmap(nomDeFichier,NULL);
    if(!imageARendre)
    {
        allegro_message("ne peut pas ouvrir %s",nomDeFichier);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return imageARendre;
}

SAMPLE * importeSon(char *nomDeFichier)
{
    SAMPLE *sonARendre= load_sample(nomDeFichier);
    if(!sonARendre)
    {
        allegro_message("ne peut pas ouvrir %s",nomDeFichier);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return sonARendre;
}

void fill_bitmap(BITMAP *bmp, int color,int posX,int posY) {

    for (posY=0; posY < bmp->h; posY++) {
        for (posX=0; posX < bmp->w; posX++) {
            if(getpixel(bmp,posX,posY)!= makecol(255,0,255))
            {
                putpixel(bmp, posX, posY, color);
            }
        }
    }
}
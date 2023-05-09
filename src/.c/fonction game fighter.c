//
// Created by mathe on 08/05/2023.
//

#include "../.h/fonction game fighter.h"

void FightPlay()
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("prblm gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char NomDeFichier[900];
    BITMAP *skin1Attack1[6];
    BITMAP *skin1Attack2[6];
    BITMAP *skin1Charge[14];
    BITMAP *skin1Dead[8];
    BITMAP *skin1Fireball[9];
    BITMAP *skin1FlameJet[16];
    BITMAP *skin1Hurt[4];
    BITMAP *skin1Idle[8];
    BITMAP *skin1Jump[10];
    BITMAP *skin1Run[9];
    BITMAP *skin1Walk[7];
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Attack1/frame-%d.bmp",i);
        skin1Attack1[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Attack2/frame-%d.bmp",i);
        skin1Attack2[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<13;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Charge/frame-%d.bmp",i);
        skin1Charge[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Dead/frame-%d.bmp",i);
        skin1Dead[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Fireball/frame-%d.bmp",i);
        skin1Fireball[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<15;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/flame jet/frame-%d.bmp",i);
        skin1FlameJet[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<4;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/hurt/frame-%d.bmp",i);
        skin1Hurt[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/idle/frame-%d.bmp",i);
        skin1Idle[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<10;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/idle/frame-%d.bmp",i);
        skin1Jump[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/idle/frame-%d.bmp",i);
        skin1Run[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/idle/frame-%d.bmp",i);
        skin1Walk[i]= importeImage(NomDeFichier);
    }

}

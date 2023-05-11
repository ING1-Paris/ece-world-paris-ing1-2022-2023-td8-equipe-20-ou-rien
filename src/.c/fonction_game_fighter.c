//
// Created by mathe on 08/05/2023.
//

#include "../.h/fonction_game_fighter.h"
#define DEP 5


t_joueurFight *creerJoueurFight(int indice){

    t_joueurFight *JoueurAretourner= malloc(sizeof (t_joueurFight));
    JoueurAretourner->indice=indice;
    JoueurAretourner->BoolMvmt=0;
    JoueurAretourner->skin=1;
    JoueurAretourner->posX=SCREEN_W/2;
    JoueurAretourner->posY=SCREEN_H/2;
    JoueurAretourner->direction=1;
    JoueurAretourner->tx=80;
    JoueurAretourner->ty=80;
    JoueurAretourner->BoolTouche=0;
    return JoueurAretourner;
}

void actualiserPosJoueur(t_joueurFight *Joueur)
{
    if(!Joueur->BoolMvmt)
    {
        return;
    }
    else
    {
        if(Joueur->direction==1)
        {
            Joueur->posX+=DEP;
        }
        else
        {
            Joueur->posX-=DEP;
        }
    }
}

int getGesture(t_joueurFight *Joueur)
{
    if(Joueur->indice)
    {
        if(key[KEY_RIGHT])
        {
            Joueur->direction=1;
            Joueur->BoolMvmt=1;
            return 1;
        }
        else if(key[KEY_LEFT])
        {
            Joueur->direction=0;
            Joueur->BoolMvmt=1;
            return 2;
        }
        else if(key[KEY_UP])
        {
            Joueur->BoolMvmt=1;
            return 3;
        }
        else if(key[KEY_0])
        {
            Joueur->BoolMvmt=0;
            return 4;
        }
        else if(key[KEY_1])
        {
            Joueur->BoolMvmt=0;
            return 5;
        }
        else if(key[KEY_2])
        {
            Joueur->BoolMvmt=0;
            return 6;
        }
        else if(key[KEY_3])
        {
            Joueur->BoolMvmt=0;
            return 7;
        }
        else
        {
            Joueur->BoolMvmt=0;
            return 0;
        }
    }
}


void drawPlayer(t_joueurFight *Joueur,int frame,
                BITMAP *buffer,
                BITMAP**skin1Attack1,
                BITMAP**skin1Attack2,
                BITMAP**skin1Charge,
                BITMAP**skin1Dead,
                BITMAP**skin1FireBall,
                BITMAP**skin1FlameJet,
                BITMAP**skin1Idle,
                BITMAP**skin1Jump,
                BITMAP**skin1Walk,
                BITMAP**skin1Run,
                BITMAP **skin2Attack1,
                BITMAP **skin2Attack2,
                BITMAP **skin2Charge1,
                BITMAP **skin2Charge2,
                BITMAP **skin2Dead,
                BITMAP **skin2Magic_arrow,
                BITMAP **skin2Magic_sphere,
                BITMAP **skin2Hurt,
                BITMAP **kin2Idle,
                BITMAP **skin2Jump,
                BITMAP **skin2Run,
                BITMAP **skin2Walk)
{
    if(Joueur->skin==1)
    {
        if(getGesture(Joueur)==0)
        {
            frame++;
            if(frame>7)
            {
                frame=1;
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1Idle[frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1Idle[frame],Joueur->posX,Joueur->posY);
            }
        }
        else if(getGesture(Joueur)==1)
        {
            frame++;
            if(frame>6)
            {
                frame=1;
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1Walk[frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1Walk[frame],Joueur->posX,Joueur->posY);
            }
        }

    }

}

void FightPlay()
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("prblm gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char NomDeFichier[900];
    //skin1
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
    for(int i=1;i<7;i++)
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
        sprintf(NomDeFichier,"../image/image fighter/skin1/jump/frame-%d.bmp",i);
        skin1Jump[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/run/frame-%d.bmp",i);
        skin1Run[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/walk/frame-%d.bmp",i);
        skin1Walk[i]= importeImage(NomDeFichier);
    }

    //skin2
    BITMAP *skin2Attack1[8];
    BITMAP *skin2Attack2[9];
    BITMAP *skin2Charge1[12];
    BITMAP *skin2Charge2[6];
    BITMAP *skin2Dead[4];
    BITMAP *skin2Magic_arrow[6];
    BITMAP *skin2Magic_sphere[16];
    BITMAP *skin2Hurt[4];
    BITMAP *skin2Idle[8];
    BITMAP *skin2Jump[8];
    BITMAP *skin2Run[8];
    BITMAP *skin2Walk[7];
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Attack1/frame-%d.bmp",i);
        skin2Attack1[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Attack2/frame-%d.bmp",i);
        skin2Attack2[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<12;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Charge1/frame-%d.bmp",i);
        skin2Charge1[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<6;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Charge2/frame-%d.bmp",i);
        skin2Charge2[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<4;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Dead/frame-%d.bmp",i);
        skin2Dead[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<6;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Magic_arrow/frame-%d.bmp",i);
        skin2Magic_arrow[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<16;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Magic_sphere/frame-%d.bmp",i);
        skin2Magic_sphere[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<4;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/hurt/frame-%d.bmp",i);
        skin2Hurt[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/idle/frame-%d.bmp",i);
        skin2Idle[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/jump/frame-%d.bmp",i);
        skin2Jump[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/run/frame-%d.bmp",i);
        skin2Run[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/walk/frame-%d.bmp",i);
        skin2Walk[i]= importeImage(NomDeFichier);
    }

    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(30);
    }
}

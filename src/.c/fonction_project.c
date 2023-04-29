//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#define DEP 5

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
    BITMAP *Nom1= importeImage("../image/image ecriture/nom projet-1.bmp");
    BITMAP *Nom2= importeImage("../image/image ecriture/nom projet-2.bmp");
    BITMAP *Nom3= importeImage("../image/image ecriture/nom projet-3.bmp");
    BITMAP *Nom4= importeImage("../image/image ecriture/nom projet-4.bmp");
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    SAMPLE *sonfond= importeSon("../son/INTRO MATHEO.wav");
    clear_bitmap(buffer);
    play_sample(sonfond,255,128,1000,TRUE);
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(company, makecol(i,i,i),0,0);
        draw_sprite(buffer,company,0,0);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(slogan, makecol(i,i,i),0,0);
        draw_sprite(buffer,slogan,5,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom1, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom1,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom2, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom2,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom3, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom3,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom4, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom4,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    stop_sample(sonfond);
    destroy_sample(sonfond);
    destroy_bitmap(slogan);
    destroy_bitmap(company);
    destroy_bitmap(Nom1);
    destroy_bitmap(Nom2);
    destroy_bitmap(Nom3);
    destroy_bitmap(Nom4);
}

int cliqueSurMenu(BITMAP *PLAY)
{
    if((mouse_x>275&&mouse_x<275+PLAY->w)&&(mouse_y>310&&mouse_y<310+PLAY->h)&&mouse_b==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int ecritureSurJeux(BITMAP **EnsembleLettre)
{
    if(key[KEY_A])
    {
        return 16;
    }
    else if(key[KEY_B])
    {
        return 2;
    }
    else if(key[KEY_C])
    {
        return 3;
    }
    else if(key[KEY_D])
    {
        return 4;
    }
    else if(key[KEY_E])
    {
        return 5;
    }
    else if(key[KEY_F])
    {
        return 6;
    }
    else if(key[KEY_G])
    {
        return 7;
    }
    else if(key[KEY_H])
    {
        return 8;
    }
    else if(key[KEY_I])
    {
        return 8;
    }
    else if(key[KEY_J])
    {
        return 9;
    }
    else if(key[KEY_K])
    {
        return 10;
    }
    else if(key[KEY_L])
    {
        return 11;
    }
    else if(key[KEY_M])
    {
        return 12;
    }
    else if(key[KEY_N])
    {

        return 13;
    }
    else if(key[KEY_O])
    {

        return 14;
    }
    else if(key[KEY_P])
    {

        return 15;
    }
    else if(key[KEY_Q])
    {

        return 1;
    }
    else if(key[KEY_R])
    {
        return 17;
    }
    else if(key[KEY_S])
    {
        return 18;
    }
    else if(key[KEY_T])
    {
        return 19;
    }
    else if(key[KEY_U])
    {

        return 21;
    }
    else if(key[KEY_V])
    {

        return 22;
    }
    else if(key[KEY_W])
    {

        return 23;
    }
    else if(key[KEY_X])
    {

        return 24;
    }
    else if(key[KEY_Y])
    {

        return 25;
    }
    else if(key[KEY_Z])
    {

        return 26;
    }
    else
    {
        return 0;
    }
}

void enregistrerNomJoueur(BITMAP**EnsembleLettre,BITMAP *buffer,char *NomJoueurARendre,int indice)
{
    int nb=0,tableauLettre[10],Bool=1;
    char NomDeJoueur[10];
    for(int i=0;i<10;i++)
    {
        tableauLettre[i]=0;
        NomDeJoueur[i]=' ';
    }

    while(!key[KEY_ENTER])
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        textout_ex(buffer,font,"Choisissez votre nom: Joueur",SCREEN_W/2-100,200, makecol(255,0,0),-1);
        textprintf_ex(buffer,font,530,200, makecol(255,0,0),-1,"%d",indice);
        if(keypressed()&&Bool!=1)
        {
            Bool=1;
        }
        else
        {
            Bool=0;
        }
        if(Bool) {
            tableauLettre[nb]= ecritureSurJeux(EnsembleLettre);
            nb++;
            if(nb>9)
            {
                nb=0;
            }
        }
        for(int i=0;i<10;i++)
        {

                NomDeJoueur[i]=(char)(96+tableauLettre[i]);
                draw_sprite(buffer,EnsembleLettre[tableauLettre[i]],nb*100,400);
                printf("lol\n");
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}

t_joueur *creerJoueur(BITMAP **EnsembleLettre,BITMAP * buffer,int indice)
{
    t_joueur *joueurArendre= malloc(sizeof (t_joueur));
    joueurArendre->posX=0;
    joueurArendre->posY=0;
    joueurArendre->DepY=5;
    joueurArendre->depX=5;
    joueurArendre->indice=indice;
    enregistrerNomJoueur(EnsembleLettre,buffer,joueurArendre->nom,indice);
    printf("%s\n",joueurArendre->nom);
    return joueurArendre;
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
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    SAMPLE *bruitVille= importeSon("../son/son bruit ville.wav");
    SAMPLE *bruitPluie= importeSon("../son/STORM_Pluie et orage.wav");
    SAMPLE *musiqueEasterEgg= importeSon("../son/son musique fond menu.wav");
    play_sample(bruitVille, 235, 128, 1000, TRUE);
    play_sample(bruitPluie,255,128,1000,TRUE);
    play_sample(musiqueEasterEgg,150,145,1000,TRUE);
    show_mouse(screen);
    while(!cliqueSurMenu(PLAY))
    {
        clear_bitmap(buffer);
        frame++;
        if(frame>179)
        {
            frame=1;
        }
        if((mouse_x>275&&mouse_x<275+PLAY->w)&&(mouse_y>310&&mouse_y<310+PLAY->h))
        {
            fill_bitmap(PLAY, makecol(255,0,0),0,0);
        }
        else
        {
            fill_bitmap(PLAY, makecol(255,255,255),0,0);
        }
        stretch_blit(fond[frame],buffer,0,0,fond[frame]->w,fond[frame]->h,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(buffer,PLAY,275,345);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(28);
    }
    stop_sample(bruitVille);
    stop_sample(bruitPluie);
    stop_sample(musiqueEasterEgg);
    destroy_sample(bruitVille);
    destroy_sample(bruitPluie);
    destroy_sample(musiqueEasterEgg);
    destroy_bitmap(PLAY);
    for(int i=1;i<180;i++)
    {
        destroy_bitmap(fond[i]);
    }
    *BoolPlay=1;
    *BoolMenu=0;
    *BoolSettings=0;
}


void playMap(int *BoolMenu, int *BoolSettings, int *BoolPlay)
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char *NomDeFichier= malloc(sizeof (char ));
    BITMAP *fondMap= importeImage("../image/image play map/carte projet allegro ing1.bmp");
    BITMAP *EnsembleLettre[26];
    for(int i=0;i<26;i++)
    {
        sprintf(NomDeFichier,"../image/image ecriture/alphabet/%d.bmp",i);
        EnsembleLettre[i]= importeImage(NomDeFichier);
    }
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    t_joueur *joueur1= creerJoueur(EnsembleLettre,buffer,1);

    while (!key[KEY_ESC])
    {
        clear_bitmap(buffer);
        blit(fondMap,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    *BoolPlay=0;
    *BoolMenu=1;
    *BoolSettings=0;
    rest(500);
}




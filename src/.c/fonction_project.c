//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"
#define DEP 5
int verifierPosGauche(t_maille *snake)
{
    if(snake->posX-snake->tx==snake->next->posX)
    {
        printf("a gauche\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int verifierPosDroite(t_maille *snake)
{
    if(snake->posX+snake->tx==snake->next->posX)
    {
        printf("a droite\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int verifierPosHaut(t_maille *snake)
{
    if(snake->posY-snake->ty==snake->next->posY)
    {
        printf("en haut\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int verifierPosBas(t_maille *snake)
{
    if(snake->posY+snake->ty==snake->next->posY)
    {
        printf("en bas\n");
        return 1;
    }
    else
    {
        return 0;
    }
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

void drawPartSnake(t_maille *snakePartie,BITMAP *buffer, BITMAP *tete[3], BITMAP * corps[3],BITMAP *queue[3],int indice)
{
    if(indice==0)
    {
        if(snakePartie->direction==1)
        {
            draw_sprite_h_flip(buffer,tete[2],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==2)
        {

            draw_sprite(buffer,tete[2],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==3)
        {

            draw_sprite(buffer,tete[1],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==4)
        {

            draw_sprite_v_flip(buffer,tete[1],snakePartie->posX,snakePartie->posY);
        }
    }
    else if(snakePartie->next==NULL)
    {
        if(snakePartie->direction==1)
        {
            draw_sprite_h_flip(buffer,queue[2],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==2)
        {

            draw_sprite(buffer,queue[2],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==3)
        {

            draw_sprite(buffer,queue[1],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==4)
        {

            draw_sprite_v_flip(buffer,queue[1],snakePartie->posX,snakePartie->posY);
        }
    }
    else
    {
        if(snakePartie->direction==1)
        {
            draw_sprite(buffer,corps[1],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==2)
        {

            draw_sprite_h_flip(buffer,corps[1],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==3)
        {

            draw_sprite_h_flip(buffer,corps[2],snakePartie->posX,snakePartie->posY);
        }
        else if(snakePartie->direction==4)
        {

            draw_sprite_h_flip(buffer,corps[2],snakePartie->posX,snakePartie->posY);
        }
    }
}

void drawAllSnake(t_liste *snake,BITMAP *buffer, BITMAP *tete[3], BITMAP * corps[3],BITMAP *queue[3])
{
    int indice=0;
    t_maille *mailletmp=snake->premier;
    while (mailletmp!=NULL)
    {
        drawPartSnake(mailletmp,buffer,tete,corps,queue,indice);
        mailletmp=mailletmp->next;
        indice++;
    }
}

int GetDirectionSnake(t_liste *snake)
{
    if(key[KEY_UP])
    {
        return 3;
    }
    else if(key[KEY_DOWN])
    {
        return 4;
    }
    else if(key[KEY_RIGHT])
    {
        return 2;
    }
    else if(key[KEY_LEFT])
    {
        return 1;
    }
    else
    {
        return snake->premier->direction;
    }
}

void mouvmentSnakePartie(t_maille * snake)
{
    if(snake->direction==1)
    {
        snake->posX-=DEP;
    }
    if(snake->direction==2)
    {
        snake->posX+=DEP;
    }
    if(snake->direction==3)
    {
        snake->posY-=DEP;
    }
    if(snake->direction==4)
    {
        snake->posY+=DEP;
    }
}

void mouvementAllSnake(t_liste *snake)
{
    if(snake->premier->posX>SCREEN_W||snake->premier->posX<0||snake->premier->posY>SCREEN_W||snake->premier->posY<0)
    {
        return;
    }
    t_maille *mailleTmp=snake->premier;
    mouvmentSnakePartie(mailleTmp);
    while(mailleTmp->next!=NULL)
    {
        mailleTmp= mailleTmp->next;
    }
    while(mailleTmp->before!=NULL)
    {
        mailleTmp->posX=mailleTmp->before->posX+mailleTmp->tx;
        mailleTmp->posY=mailleTmp->before->posY;
        mailleTmp= mailleTmp->before;
    }
}



void actualiserDirectionSnake(t_liste *snake)
{
    t_maille *mailletmp=snake->premier;
    verifierPosGauche(mailletmp);
    verifierPosDroite(mailletmp);
    verifierPosHaut(mailletmp);
    verifierPosBas(mailletmp);
    while(mailletmp->next!=NULL)
    {
        mailletmp= mailletmp->next;
    }
    if(GetDirectionSnake(snake)==1&&snake->premier->direction!=2)
    {
        snake->premier->direction=1;
    }
    if(GetDirectionSnake(snake)==2&&snake->premier->direction!=1)
    {
        snake->premier->direction=2;
    }
    if(GetDirectionSnake(snake)==3&&snake->premier->direction!=4)
    {
        snake->premier->direction=3;
    }
    if(GetDirectionSnake(snake)==4&&snake->premier->direction!=3)
    {
        snake->premier->direction=4;
    }
}

void actualiserDirectionSnakeCorps(t_liste *snake)
{
    t_maille *mailletmp=snake->premier;
    while(mailletmp->next!=NULL)
    {
        mailletmp= mailletmp->next;
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
    play_sample(musiqueEasterEgg,100,128,1000,TRUE);
    play_sample(bruitVille, 235, 128, 1000, TRUE);
    play_sample(bruitPluie,255,128,1000,TRUE);
    show_mouse(screen);
    while(!key[KEY_ESC])
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
}


void Snake()
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    set_color_depth(desktop_color_depth());
    char nomDeFichier[5000];
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *tete[3];
    int bool=0;
    for(int i=1;i<3;i++)
    {
        sprintf(nomDeFichier,"../image/image snake/tete/frame-%d.bmp",i);
        tete[i]= importeImage(nomDeFichier);
    }
    BITMAP *corps[3];
    for(int i=1;i<3;i++)
    {

        sprintf(nomDeFichier,"../image/image snake/corps/frame-%d.bmp",i);
        corps[i]= importeImage(nomDeFichier);
    }
    BITMAP *queue[3];
    for(int i=1;i<3;i++)
    {

        sprintf(nomDeFichier,"../image/image snake/queue/frame-%d.bmp",i);
        queue[i]= importeImage(nomDeFichier);
    }
    //BITMAP *fond= importeImage("");
    //BITMAP *pomme= importeImage("");
    t_liste *snake=creation();
    for(int i=0;i<5;i++)
    {
        ajouter_maillonEnModePile(snake);
    }
    enlever_maillon(snake);
    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);
        mouvementAllSnake(snake);
        actualiserDirectionSnake(snake);
        drawAllSnake(snake,buffer,tete,corps,queue);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(28);
    }
}

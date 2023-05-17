//
// Created by mathe on 28/04/2023.
//

#include "../.h/fonction_game_snake.h"
#include "allegro.h"
#include "stdio.h"
#define DEP 5

int verifierPosGauche(t_maille *snake,t_maille *snakeAVerfier)
{
    if(snake->posX==snakeAVerfier->posX+snake->tx)
    {
        printf("a gauche: %d | %d:\n",snake->posX-snake->tx,snakeAVerfier->posX);
        return 1;
    }
    else
    {
        printf("a gauche: %d | %d:\n",snake->posX-snake->tx,snakeAVerfier->posX);
        return 0;
    }
}

int verifierPosDroite(t_maille *snake,t_maille *snakeAVerfier)
{
    if(snake->posX+snake->tx==snakeAVerfier->posX)
    {
        printf("a droite %d | %d:\n",snake->posX+snake->tx,snakeAVerfier->posX);
        return 1;
    }
    else
    {
        return 0;
    }
}

int verifierPosHaut(t_maille *snake,t_maille *snakeAVerfier)
{
    if(snake->posY==snakeAVerfier->posY+snakeAVerfier->ty&&snake->posX==snakeAVerfier->posX)
    {
        printf("en haut %d | %d:\n",snake->posY-snake->ty,snakeAVerfier->posY);
        return 1;
    }
    else
    {
        return 0;
    }
}

int verifierPosBas(t_maille *snake,t_maille *snakeAVerfier)
{
    if(snake->posY+snake->ty==snakeAVerfier->posY&&snake->posX==snakeAVerfier->posX)
    {
        printf("en bas %d | %d:\n",snake->posY+snake->ty,snakeAVerfier->posY);
        return 1;
    }
    else
    {
        return 0;
    }
}


void drawPomme(t_pomme *pomme,BITMAP *imagePomme,BITMAP*buffer)
{
    draw_sprite(buffer,imagePomme,pomme->posX,pomme->posY);
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

int GetDirectionSnake(t_liste *snake,int nbIteration)
{
    if(key[KEY_UP]) {
        if (nbIteration == 12) {
            return 3;
        }
    }
    else if(key[KEY_DOWN]) {
        if (nbIteration == 12) {
            return 4;
        }
    }
    else if(key[KEY_RIGHT]) {
        if (nbIteration == 12) {
            return 2;
        }
    }
    else if(key[KEY_LEFT])
    {
        if(nbIteration==12) {
            return 1;
        }
    }
    else
    {
        return -1;
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

int detectionDefaite(t_liste *snake)
{
    t_maille  *mailletmp=snake->premier->next;
    if(snake->premier->posX>SCREEN_W||snake->premier->posX<0||snake->premier->posY>SCREEN_H||snake->premier->posY<0)
    {
        return 1;
    }
    while(mailletmp!=NULL)
    {

        if(snake->premier->posX>=mailletmp->posX&&snake->premier->posX<=mailletmp->posX+20&&snake->premier->direction==1&&snake->premier->posY>=mailletmp->posY&&snake->premier->posY<=mailletmp->posY+20&&(mailletmp->direction==3||mailletmp->direction==4))
        {
            printf("%d<%d<%d| %d<%d<%d\n",mailletmp->posX,snake->premier->posX,mailletmp->posX+20,mailletmp->posY,snake->premier->posY,(mailletmp->posY+20));
            return 1;
        }


        if(snake->premier->posX+snake->premier->tx>mailletmp->posX&&snake->premier->posX<mailletmp->posX+20&&snake->premier->direction==2&&snake->premier->posY>mailletmp->posY&&snake->premier->posY<mailletmp->posY+20&&(mailletmp->direction==3||mailletmp->direction==4))
        {
            printf("%d<%d<%d| %d<%d<%d\n",mailletmp->posX,snake->premier->posX,mailletmp->posX+20,mailletmp->posY,snake->premier->posY,(mailletmp->posY+20));
            return 1;
        }


        if(snake->premier->posY<mailletmp->posY+60&&snake->premier->posY>mailletmp->posY&&snake->premier->direction==3&&snake->premier->posX>mailletmp->posX&&snake->premier->posX<mailletmp->posX+60&&(mailletmp->direction==1||mailletmp->direction==2))
        {
            printf("%d>%d>%d| %d<%d<%d\n",mailletmp->posY+60,snake->premier->posY,mailletmp->posY,mailletmp->posX,snake->premier->posX,(mailletmp->posX+60));
            return 1;
        }

        if(snake->premier->posY+50>mailletmp->posY&&snake->premier->posY+snake->premier->ty<mailletmp->posY+30&&snake->premier->direction==4&&snake->premier->posX>mailletmp->posX&&snake->premier->posX<mailletmp->posX+50&&(mailletmp->direction==1||mailletmp->direction==2))
        {
            printf("%d<%d<%d| %d<%d<%d\n",mailletmp->posY,snake->premier->posY+snake->premier->ty,mailletmp->posY+30,mailletmp->posX,snake->premier->posX,(mailletmp->posX+50));
            return 1;
        }
        mailletmp=mailletmp->next;
    }
    return 0;
}

void mouvementAllSnake(t_liste *snake, int *nbIteration)
{
    if(snake->premier->posX>SCREEN_W||snake->premier->posX<0||snake->premier->posY>SCREEN_W||snake->premier->posY<0)
    {
        return;
    }
    t_maille *mailleTmp=snake->premier->next;
    *nbIteration=(*nbIteration+1)%13;
    mouvmentSnakePartie(snake->premier);
    while(mailleTmp!=NULL)
    {
        mouvmentSnakePartie(mailleTmp);
        mailleTmp= mailleTmp->next;
    }
}


void actualiserDirectionSnakeCorps(t_liste *snake,int *posXEnregistre,int *posYEnregistre,int nb)
{
    t_maille *mailletmp=snake->premier->next;
    while(mailletmp!=NULL)
    {
        for(int i=0;i<nb;i++)
        {
            if(mailletmp->posX==posXEnregistre[i]&&mailletmp->posY==posYEnregistre[i])
            {
                mailletmp->direction=mailletmp->before->direction;
            }
        }

        mailletmp= mailletmp->next;
    }
}

void actualiserDirectionSnake(t_liste *snake,int *posXEnregistre, int *posYEnregistre,int *nb, int nbIteration)
{
    int nbTmp=*nb;
    t_maille *mailletmp=snake->premier;
    while(mailletmp->next!=NULL)
    {
        mailletmp= mailletmp->next;
    }
    if(GetDirectionSnake(snake,nbIteration)==1&&snake->premier->direction!=2)
    {
        snake->premier->direction=1;
        posXEnregistre[nbTmp]=snake->premier->posX;
        posYEnregistre[nbTmp]=snake->premier->posY;
        nbTmp++;
    }
    if(GetDirectionSnake(snake,nbIteration)==2&&snake->premier->direction!=1)
    {
        snake->premier->direction=2;
        posXEnregistre[nbTmp]=snake->premier->posX;
        posYEnregistre[nbTmp]=snake->premier->posY;
        nbTmp++;
    }
    if(GetDirectionSnake(snake,nbIteration)==3&&snake->premier->direction!=4)
    {

        snake->premier->direction=3;
        posXEnregistre[nbTmp]=snake->premier->posX;
        posYEnregistre[nbTmp]=snake->premier->posY;
        nbTmp++;
    }
    if(GetDirectionSnake(snake,nbIteration)==4&&snake->premier->direction!=3)
    {
        snake->premier->direction=4;
        posXEnregistre[nbTmp]=snake->premier->posX;
        posYEnregistre[nbTmp]=snake->premier->posY;
        nbTmp++;
    }
    actualiserDirectionSnakeCorps(snake,posXEnregistre,posYEnregistre,nbTmp);
    *nb=nbTmp;
}

void animationDefaite(BITMAP*buffer, BITMAP *defaite, BITMAP*teteMort[3],BITMAP*fond,BITMAP *pomme,BITMAP *corps[3],BITMAP *queue[3],t_liste *snake,t_pomme *structPomme)
{
    for(int i=0;i<30;i++)
    {
        clear_bitmap(buffer);
        stretch_blit(fond,buffer,0,0,fond->w,fond->h,0,0,SCREEN_W,SCREEN_H);
        drawAllSnake(snake,buffer,teteMort,corps,queue);
        drawPomme(structPomme,pomme,buffer);
        draw_sprite(buffer,defaite,150,200);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(30);
    }
    rest(500);
}

int detectPommeManger(t_pomme *pomme,t_liste *snake)
{
    if(snake->premier->direction==1&&(snake->premier->posX>pomme->posX&&snake->premier->posX<pomme->posX+pomme->tx)&&(snake->premier->posY+(snake->premier->ty)/2>=pomme->posY&&snake->premier->posY+(snake->premier->ty)/2<=pomme->posY+70))
    {
        return 1;
    }
    if(snake->premier->direction==2&&(snake->premier->posX+snake->premier->tx>pomme->posX&&snake->premier->posX+snake->premier->tx<pomme->posX+pomme->tx)&&(snake->premier->posY+(snake->premier->ty)/2>=pomme->posY&&snake->premier->posY+(snake->premier->ty)/2<=pomme->posY+70))
    {
        return 1;
    }
    if(snake->premier->direction==3&&(snake->premier->posY>=pomme->posY&&snake->premier->posY<=pomme->posY+pomme->ty)&&(snake->premier->posX+(snake->premier->tx)/2>=pomme->posX&&snake->premier->posX+(snake->premier->tx)/2<=pomme->posX+70))
    {
        return 1;
    }
    if(snake->premier->direction==4&&(snake->premier->posY+snake->premier->ty>=pomme->posY&&snake->premier->posY+snake->premier->ty<=pomme->posY+pomme->ty)&&(snake->premier->posX+(snake->premier->tx)/2>=pomme->posX&&snake->premier->posX+(snake->premier->tx)/2<=pomme->posX+70))
    {
        return 1;
    }
    return 0;
}

int detectPommeSurSerpentX(t_liste* liste,t_pomme *pomme)
{
    t_maille *mailletmp=liste->premier;
    while (mailletmp!=NULL)
    {
        if(pomme->posX>mailletmp->posX&&pomme->posX<mailletmp->posX+mailletmp->tx)
        {
            return 1;
        }
        mailletmp=mailletmp->next;
    }
    return 0;
}

int detectPommeSurSerpentY(t_liste* liste,t_pomme *pomme)
{
    t_maille *mailletmp=liste->premier;
    while (mailletmp!=NULL)
    {
        if(pomme->posY>mailletmp->posY&&pomme->posY<mailletmp->posY+mailletmp->ty)
        {
            return 1;
        }
        mailletmp=mailletmp->next;
    }
    return 0;
}

void mangePomme(t_liste *snake, t_pomme*pomme,int *score)
{
    if(detectPommeManger(pomme,snake))
    {
        *score=*score+1;
        pomme->posY=rand()%SCREEN_H-30;
        while (pomme->posY<15||pomme->posY%5!=0|| detectPommeSurSerpentY(snake,pomme))
        {
            pomme->posY=rand()%SCREEN_H-30;
        }
        pomme->posX=rand()%SCREEN_W-30;
        while (pomme->posX%5!=0||pomme->posX<15|| detectPommeSurSerpentX(snake,pomme))
        {
            pomme->posX=rand()%SCREEN_W-30;
        }
        ajouter_maillonEnModePile(snake);

    }
}

t_pomme *creerPomme()
{
    t_pomme *pommeARendre= malloc(sizeof (t_pomme));
    pommeARendre->posY=rand()%SCREEN_H-30;
    while (pommeARendre->posY<15||pommeARendre->posY%5!=0)
    {
        pommeARendre->posY=rand()%SCREEN_H-30;
    }
    pommeARendre->posX=rand()%SCREEN_W-30;
    while (pommeARendre->posX%5!=0||pommeARendre->posX<15)
    {
        pommeARendre->posX=rand()%SCREEN_W-30;
    }
    pommeARendre->tx=30;
    pommeARendre->ty=33;
    pommeARendre->nb++;
    return pommeARendre;
}

int Snake()
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    set_color_depth(desktop_color_depth());
    char nomDeFichier[5000];
    char tmpString[20];
    int posXEnregistreTourne[256],posYEnregistreTourne[256];
    int nbIteration=0;
    int nbDeTourne=0;
    int score=0;
    int pano=0;
    int depPano=1;
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *tete[3];
    BITMAP *corps[3];
    BITMAP *queue[3];
    BITMAP *teteMort[3];
    for(int i=0;i<256;i++)
    {
        posXEnregistreTourne[i]=0;
        posYEnregistreTourne[i]=0;
    }
    for(int i=1;i<3;i++)
    {
        sprintf(nomDeFichier,"../image/image snake/tete/frame-%d.bmp",i);
        tete[i]= importeImage(nomDeFichier);
    }
    for(int i=1;i<3;i++)
    {

        sprintf(nomDeFichier,"../image/image snake/corps/frame-%d.bmp",i);
        corps[i]= importeImage(nomDeFichier);
    }
    for(int i=1;i<3;i++)
    {

        sprintf(nomDeFichier,"../image/image snake/queue/frame-%d.bmp",i);
        queue[i]= importeImage(nomDeFichier);
    }
    for(int i=1;i<3;i++)
    {

        sprintf(nomDeFichier,"../image/image snake/tete mort/frame-%d.bmp",i);
        teteMort[i]= importeImage(nomDeFichier);
    }
    BITMAP *fond= importeImage("../image/image snake/fond/fond snake.bmp");
    BITMAP *pomme= importeImage("../image/image snake/pomme/pomme snake.bmp");
    BITMAP *Defaite= importeImage("../image/image ecriture/defaite.bmp");
    t_pomme *pomme1=creerPomme();
    t_liste *snake=creation();
    SAMPLE * musicfond= importeSon("../son/test music.wav");
    for(int i=0;i<3;i++)
    {
        ajouter_maillonEnModePile(snake);
    }
    lock_sample(musicfond);
    play_sample(musicfond,130,128,1000,TRUE);
    while(1)
    {
        pano+=depPano;
        if(pano>255||pano<0)
        {
            depPano=-depPano;
        }
        adjust_sample(musicfond,130,pano,1000,TRUE);
        clear_bitmap(buffer);
        stretch_blit(fond,buffer,0,0,fond->w,fond->h,0,0,SCREEN_W,SCREEN_H);
        mouvementAllSnake(snake,&nbIteration);
        actualiserDirectionSnake(snake,posXEnregistreTourne,posYEnregistreTourne,&nbDeTourne,nbIteration);
        drawAllSnake(snake,buffer,tete,corps,queue);
        drawPomme(pomme1,pomme,buffer);
        mangePomme(snake,pomme1,&score);
        textout_ex(buffer,font,"score: ",100,50, makecol(255,255,255),-1);
        sprintf(tmpString,"%d",score);
        textout_ex(buffer,font,tmpString,150,50, makecol(255,255,255),-1);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if(detectionDefaite(snake))
        {
            animationDefaite(buffer,Defaite,teteMort,fond,pomme,corps,queue,snake,pomme1);
            break;
        }
        rest(30);
    }
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    stop_sample(musicfond);
    return score;
}

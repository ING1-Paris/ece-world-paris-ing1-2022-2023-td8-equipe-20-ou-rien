//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"
#include "time.h"
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

        if(snake->premier->posX<mailletmp->posX&&snake->premier->posX>mailletmp->posX-20&&snake->premier->direction==1&&snake->premier->posY>mailletmp->posY&&snake->premier->posY<mailletmp->posY+20&&(mailletmp->direction==3||mailletmp->direction==4))
        {
            printf("%d>%d>%d| %d<%d<%d\n",mailletmp->posX,snake->premier->posX,mailletmp->posX-10,mailletmp->posY,snake->premier->posY,(mailletmp->posY+20));
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

void animationDefaite()
{

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

void mangePomme(t_liste *snake, t_pomme*pomme,int *score)
{
    if(detectPommeManger(pomme,snake))
    {
        *score=*score+1;
        pomme->posY=rand()%SCREEN_H-30;
        while (pomme->posY<15||pomme->posY%5!=0)
        {
            pomme->posY=rand()%SCREEN_H-30;
        }
        pomme->posX=rand()%SCREEN_W-30;
        while (pomme->posX%5!=0||pomme->posX<15)
        {
            pomme->posX=rand()%SCREEN_W-30;
        }
        ajouter_maillonEnModePile(snake);

    }
}

void drawPomme(t_pomme *pomme,BITMAP *imagePomme,BITMAP*buffer)
{
    draw_sprite(buffer,imagePomme,pomme->posX,pomme->posY);
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
    int posXEnregistreTourne[256],posYEnregistreTourne[256];
    int nbIteration=0;
    int nbDeTourne=0;
    int score=0;
    int pano=0;
    int depPano=1;
    srand(time(NULL));
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
    t_pomme *pomme1=creerPomme();
    t_liste *snake=creation();
    SAMPLE * musicfond= importeSon("../son/test music.wav");
    for(int i=0;i<3;i++)
    {
        ajouter_maillonEnModePile(snake);
    }
    lock_sample(musicfond);
    play_sample(musicfond,130,128,1000,TRUE);
    while(!key[KEY_ESC])
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
        if(key[KEY_L])
        {
            ajouter_maillonEnModePile(snake);
        }
        drawPomme(pomme1,pomme,buffer);
        mangePomme(snake,pomme1,&score);
        textout_ex(buffer,font,"score: ",100,50, makecol(255,255,255),-1);
        textprintf_ex(buffer,font,150,50, makecol(255,255,255),-1,"%d",score);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if(detectionDefaite(snake))
        {
            drawAllSnake(snake,buffer,teteMort,corps,queue);

        }
        rest(30);
    }
    stop_sample(musicfond);
}

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

void testAlphabet(BITMAP **EnsembleLettre,BITMAP *buffer)
{
    for(int i=0;i<27;i++)
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        draw_sprite(buffer,EnsembleLettre[i],SCREEN_W/2,SCREEN_H/2);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(1000);
    }
}


void testChiffre(BITMAP **EnsembleChiffre,BITMAP *buffer)
{
    for(int i=0;i<10;i++)
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        draw_sprite(buffer,EnsembleChiffre[i],SCREEN_W/2,SCREEN_H/2);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(1000);
    }
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

void enregistrerNomJoueur(BITMAP**EnsembleLettre,BITMAP *buffer,char *NomJoueurARendre,int indice,BITMAP **EnsembleChiffre)
{
    int Bool=1;
    char *tabNom= initTableauChar(25);
    char verifChar=0;
    int nbDansTab=0;
    while(!key[KEY_ENTER])
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        textout_ex(buffer,font,"veuillez donner un nom au joueur :",100,200, makecol(255,0,0),-1);
        draw_sprite(buffer,EnsembleChiffre[indice],400,150);
        if(key[KEY_DEL]&&nbDansTab!=0)
        {
            tabNom[nbDansTab]=0;
            nbDansTab--;
            rest(100);
        }
        if(keypressed())
        {
            verifChar=(char)readkey();
            if(verifChar>=97&&verifChar<=122||verifChar>='A'&&verifChar<='Z')
            {
                if(nbDansTab==0)
                {
                    tabNom= initTableauChar(25);
                }
                Bool=0;
                tabNom[nbDansTab]=(char)verifChar;
                nbDansTab++;
                if(nbDansTab>25)
                {
                    break;
                }
            }
        }
        for(int i=0;i<nbDansTab;i++)
        {
            if(tabNom[i]>=97&&tabNom[i]<=122)
            {
                draw_sprite(buffer,EnsembleLettre[(tabNom[i]-96)],i*100,400);
            }
            if(tabNom[i]>=65&&tabNom[i]<=90)
            {
                draw_sprite(buffer,EnsembleLettre[(tabNom[i]-64)],i*100,400);
            }
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    strcpy(NomJoueurARendre,tabNom);
}

t_joueur *creerJoueur(BITMAP **EnsembleLettre,BITMAP * buffer,int indice,BITMAP **EnsembleChiffre)
{
    t_joueur *joueurArendre= malloc(sizeof (t_joueur));
    joueurArendre->posX=0;
    joueurArendre->posY=0;
    joueurArendre->DepY=5;
    joueurArendre->depX=5;
    joueurArendre->indice=indice;
    enregistrerNomJoueur(EnsembleLettre,buffer,joueurArendre->nom,indice,EnsembleChiffre);
    while (joueurArendre->nom[0]==0)
    {
        enregistrerNomJoueur(EnsembleLettre,buffer,joueurArendre->nom,indice,EnsembleChiffre);
    }
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
    BITMAP *EnsembleLettre[27];
    for(int i=0;i<27;i++)
    {
        sprintf(NomDeFichier,"../image/image ecriture/alphabet/%d.bmp",i);
        EnsembleLettre[i]= importeImage(NomDeFichier);
    }
    BITMAP *EnsembleChiffre[11];
    for(int i=0;i<10;i++)
    {
        sprintf(NomDeFichier,"../image/image ecriture/chiffre/%d.bmp",i);
        EnsembleChiffre[i]= importeImage(NomDeFichier);
    }
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    //testAlphabet(EnsembleLettre,buffer);
    //testChiffre(EnsembleChiffre,buffer);
    t_joueur *joueur1= creerJoueur(EnsembleLettre,buffer,1,EnsembleChiffre);
    t_joueur *joueur2= creerJoueur(EnsembleLettre,buffer,2,EnsembleChiffre);

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




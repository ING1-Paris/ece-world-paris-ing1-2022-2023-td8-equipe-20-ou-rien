//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_utile.h"
#include "allegro.h"
#include "stdio.h"

void destroyBitmapArray(BITMAP **bmp, int n, int start)
{
    for (int i = start; i < n; i++)
        destroy_bitmap(bmp[i]);
}

void ajouter_maillonEnModePile(t_liste *liste)
{
    t_maille *maillon=liste->premier;
    if(liste->nb==1)
    {
        t_maille *nouvelleMaille= malloc(sizeof (t_maille));
        nouvelleMaille->direction=maillon->direction;
        nouvelleMaille->posX=maillon->posX+maillon->tx;
        nouvelleMaille->posY=maillon->posY;
        nouvelleMaille->tx=60;
        nouvelleMaille->ty=60;
        nouvelleMaille->next=NULL;
        nouvelleMaille->before=maillon;
        maillon->next=nouvelleMaille;
        liste->nb++;
        return;
    }
    else
    {
        while(maillon->next!=NULL)
        {
            maillon=maillon->next;
        }
        t_maille *nouvelleMaille= malloc(sizeof (t_maille));
        nouvelleMaille->direction=maillon->direction;
        if(nouvelleMaille->direction==1)
        {
            nouvelleMaille->posX=maillon->posX+maillon->tx;
            nouvelleMaille->posY=maillon->posY;
        }
        if(nouvelleMaille->direction==2)
        {
            nouvelleMaille->posX=maillon->posX-maillon->tx;
            nouvelleMaille->posY=maillon->posY;
        }
        if(nouvelleMaille->direction==3)
        {
            nouvelleMaille->posX=maillon->posX;
            nouvelleMaille->posY=maillon->posY+maillon->ty;
        }
        if(nouvelleMaille->direction==4)
        {
            nouvelleMaille->posX=maillon->posX;
            nouvelleMaille->posY=maillon->posY-maillon->ty;
        }
        nouvelleMaille->tx=60;
        nouvelleMaille->ty=60;
        nouvelleMaille->next=NULL;
        nouvelleMaille->before=maillon;
        maillon->next=nouvelleMaille;
        liste->nb++;
    }
}

t_liste * creation()
{
    t_liste *liste= malloc(sizeof (t_liste));
    liste->premier= malloc(sizeof (t_maille));
    liste->premier->before=NULL;
    liste->premier->posX=SCREEN_W/2;
    liste->premier->posY=SCREEN_H/2;
    liste->premier->tx=60;
    liste->premier->ty=60;
    liste->premier->direction=1;
    liste->nb=1;
    liste->premier->next=NULL;
    return liste;
}


void enlever_maillon(t_liste *liste)
{
    if(liste->nb==0)
    {
        printf("Impossible file vide\n");
        return;
    }
    else
    {
        t_maille *maillon=liste->premier;
        while (maillon->next->next!=NULL)
        {
            maillon=maillon->next;
        }
        maillon->next=NULL;
        liste->nb--;
        return;
    }
}


void afficherListe(t_liste *liste)
{
    if(liste->nb==0)
    {
        printf("rien dans la liste\n");
        return;
    }
    t_maille *maillon=liste->premier;
    while(maillon!=NULL)
    {
        printf("%d %d\n",maillon->posX,maillon->posY);
        maillon=maillon->next;
    }
}

char * initTableauChar(int taille)
{
    char *tab= malloc(sizeof (char)*taille);
    for(int i=0;i<taille;i++)
    {
        tab[i]=0;
    }
    return tab;
}
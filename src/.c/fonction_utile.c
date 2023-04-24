//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_utile.h"
#include "allegro.h"
#include "stdio.h"

void ajouter_maillonEnModePile(t_liste *liste)
{
    int dataRajout;
    if(liste->nb==15)
    {
        printf("impossible liste deja remplie\n");
        return ;
    }
    else
    {
        t_maille *maillon=liste->premier;
        if(liste->nb==1)
        {
            t_maille *nouvelleMaille= malloc(sizeof (t_maille));
            nouvelleMaille->direction=maillon->direction;
            nouvelleMaille->posX=0;
            nouvelleMaille->posY=0;
            nouvelleMaille->next=NULL;
            maillon->next=nouvelleMaille;
            liste->nb++;
            return;
        }
        while(maillon->next->next!=NULL)
        {
            maillon=maillon->next;
        }
        t_maille *nouvelleMaille= malloc(sizeof (t_maille));
        nouvelleMaille->direction=maillon->direction;
        nouvelleMaille->posX=0;
        nouvelleMaille->posY=0;
        nouvelleMaille->next=NULL;
        maillon->next->next=nouvelleMaille;
        liste->nb++;
        return;
    }
}

t_liste * creation()
{
    t_liste *liste= malloc(sizeof (t_liste));
    liste->premier= malloc(sizeof (t_maille));
    liste->premier->posX=SCREEN_W/2;
    liste->premier->posY=SCREEN_H/2;
    liste->premier->tx;
    liste->premier->ty;
    liste->premier->direction=0;
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
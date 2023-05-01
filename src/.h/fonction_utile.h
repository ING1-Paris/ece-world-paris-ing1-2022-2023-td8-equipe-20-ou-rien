//
// Created by mathe on 24/04/2023.
//

#ifndef PROJET_FONCTION_UTILE_H
#define PROJET_FONCTION_UTILE_H


typedef struct maille
{
    int posX,posY,tx,ty,direction;
    struct maille *next;
    struct maille *before;
}t_maille;

typedef struct pomme
{
    int posX,posY;
    int tx,ty;
    int nb;
}t_pomme;

typedef struct liste
{
    t_maille * premier;
    int nb;
}t_liste;

void ajouter_maillonEnModePile(t_liste *liste);
t_liste * creation();
void enlever_maillon(t_liste *liste);
void afficherListe(t_liste *liste);
char * initTableauChar(int taille);


#endif //PROJET_FONCTION_UTILE_H

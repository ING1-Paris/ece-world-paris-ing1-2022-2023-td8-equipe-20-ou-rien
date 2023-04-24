//
// Created by mathe on 24/04/2023.
//

#ifndef PROJET_FONCTION_UTILE_H
#define PROJET_FONCTION_UTILE_H

typedef struct maille
{
    int posX,posY,tx,ty,direction;
    struct maille *next;
}t_maille;

typedef struct liste
{
    t_maille * premier;
    int nb;
}t_liste;

void ajouter_maillonEnModePile(t_liste *liste);
t_liste * creation();
void enlever_maillon(t_liste *liste);
void afficherListe(t_liste *liste);


#endif //PROJET_FONCTION_UTILE_H
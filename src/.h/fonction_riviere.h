//
// Created by petit on 15/05/2023.
//

#ifndef PROJET_FONCTION_RIVIERE_H
#define PROJET_FONCTION_RIVIERE_H

typedef struct pingouin_s {
    BITMAP ***anim;
    int tempo_anim;
    int index_anim;
    int index_sprite;
    int flip;
    int x;
    int y;
}pingouin;

void defilement_map_verticale(BITMAP *decor, BITMAP *buffer,int vitesse_verticale);
void premiere_riviere(BITMAP *spritebanquise, BITMAP *buffer, BITMAP *spriteourspolaire, int vitesse_verticale, int vitesse_horizontale);
int fonction_riviere();

#endif //PROJET_FONCTION_RIVIERE_H

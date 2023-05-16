#include "header.h"

jeu_cible_t creer_partie(void)
{
    jeu_cible_t jeu;

    jeu.cible = load_bitmap("../cible.bmp", NULL);
    jeu.gagne_image = load_bitmap("../gagne.bmp", NULL);
    jeu.perdue_image = load_bitmap("../perdue.bmp", NULL);
    jeu.gagnee = load_wav("../winJade.wav");
    jeu.perdue = load_wav("../loseJade.wav");
    jeu.tir_pistolet = load_wav("../shoot.wav");
    jeu.clock_bouge_cible = clock();
    jeu.temps_restant = clock();
    jeu.balle_tir = 0;
    if (jeu.cible == NULL) {
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    jeu.score = 0;
    for (int i = 0; i < NELEM; i++){
        jeu.pos_x[i]=rand()%(SCREEN_W-2*jeu.cible->w/6)+jeu.cible->w/6;
        jeu.pos_y[i]=rand()%(SCREEN_H-2*jeu.cible->w/6)+jeu.cible->w/6;

        do
        {
            jeu.dep_x[i]=rand()%21-10;
            jeu.dep_y[i]=rand()%21-10;
        } while (jeu.dep_x[i]==0 || jeu.dep_y[i]==0);
    }
    return jeu;
}

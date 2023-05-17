#include "header.h"

jeu_ballon_t creer_partie(void)
{
    jeu_ballon_t jeu;

    jeu.ballon = load_bitmap("../ballon.bmp", NULL);
    jeu.ballon2 = load_bitmap("../ballon2.bmp", NULL);
    jeu.gagne_image = load_bitmap("../gagne.bmp", NULL);
    jeu.perdue_image = load_bitmap("../perdue.bmp", NULL);
    jeu.gagnee = load_wav("../winJade.wav");
    jeu.perdue = load_wav("../loseJade.wav");
    jeu.ballon_pop = load_wav("../ballonPop.wav");
    jeu.fond = load_bitmap("../fondJade.bmp", NULL);
    jeu.clock_bouge_ballon = clock();
    jeu.temps_restant = clock();
    jeu.balle_tire = 0;
    if (jeu.ballon == NULL) {
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    jeu.score = 0;
    for (int i = 0; i < NELEM; i++){
        jeu.posx[i]=rand()%(530 - 240) + 240;
        jeu.posy[i]=rand()%(500 - 100) + 100;
        jeu.temps_depop[i] = 0;

        do
        {
            jeu.depx[i]=rand()%21-10;
            jeu.depy[i]=rand()%21-10;
        } while (jeu.depx[i]==0 || jeu.depy[i]==0);
    }
    return jeu;
}


void ballon_deplace(jeu_ballon_t *jeu, int rayon)
{
    if (clock() - jeu->clock_bouge_ballon >= 30) {
        for (int i = 0; i<NELEM; i++){
            if (jeu->posx[i] != -10) {
                if ( (jeu->posx[i]-rayon<222 && jeu->depx[i]<222) || (jeu->posx[i]+rayon>540 && jeu->depx[i]>0) )
                    jeu->depx[i]=-jeu->depx[i];
                if ( (jeu->posy[i]-rayon<80 && jeu->depy[i]<80) || (jeu->posy[i]+rayon>500 && jeu->depy[i]>0) )
                    jeu->depy[i]=-jeu->depy[i];

                jeu->posx[i]=jeu->posx[i]+jeu->depx[i];
                jeu->posy[i]=jeu->posy[i]+jeu->depy[i];
            }
        }
        jeu->clock_bouge_ballon = clock();
    }
}


void ballon_toucher(jeu_ballon_t *jeu, int i)
{
    if (!jeu->balle_tire && mouse_b & 1 && (mouse_x >= jeu->posx[i] && mouse_x <= jeu->posx[i] + jeu->ballon->w / 3) && (mouse_y >= jeu->posy[i] && mouse_y <= jeu->posy[i] + jeu->ballon->h / 3)) {
        jeu->temps_depop[i] = clock();
        jeu->score++;
        jeu->balle_tire = 1;
        play_sample(jeu->ballon_pop, 200, 128, 1000, 0);
    }
    if (jeu->balle_tire && !(mouse_b & 1))
        jeu->balle_tire = 0;
}

void gagne_ou_perdue(jeu_ballon_t jeu)
{
    if (jeu.score == NELEM) {
        clear_to_color(screen, makecol(0, 0, 0));
        play_sample(jeu.gagnee, 200, 128, 1000, 0);
        draw_sprite(screen, jeu.gagne_image, 0, 0);
        rest(2000);
        allegro_exit();
        exit(0);
    } else if (jeu.score != NELEM && 15 - (jeu.temps_restant / 1000) == 0) {
        clear_to_color(screen, makecol(0, 0, 0));
        play_sample(jeu.perdue, 200, 128, 1000, 0);
        draw_sprite(screen, jeu.perdue_image, 0, 0);
        rest(3000);
        allegro_exit();
        exit(0);
    }
}
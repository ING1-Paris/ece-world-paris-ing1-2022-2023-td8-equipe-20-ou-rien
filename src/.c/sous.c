#include "../.h/headerJade.h"

jeu_ballon_t creer_partie(void)
{
    jeu_ballon_t jeu;

    jeu.viseur = load_bitmap("../jadou/viseurBallon.bmp", NULL);
    jeu.ballon = load_bitmap("../jadou/ballon.bmp", NULL);
    jeu.ballon2 = load_bitmap("../jadou/ballon2.bmp", NULL);
    jeu.gagne_image = load_bitmap("../jadou/gagne.bmp", NULL);
    jeu.perdue_image = load_bitmap("../jadou/perdue.bmp", NULL);
    jeu.gagnee = load_wav("../jadou/winJade.wav");
    jeu.perdue = load_wav("../jadou/loseJade.wav");
    jeu.ballon_pop = load_wav("../jadou/ballonPop.wav");
    jeu.fond = load_bitmap("../jadou/fondJade.bmp", NULL);
    jeu.clock_bouge_ballon = clock();
    jeu.temps_restant = clock();
    jeu.balle_tire = 0;
    if (jeu.ballon == NULL) {
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    jeu.score = 0;
    for (int i = 0; i < NELEM; i++){
        jeu.posx[i]=rand()%(530 - 290) + 290;
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
    if (!jeu->balle_tire && mouse_b & 1 && (mouse_x >= jeu->posx[i] && mouse_x <= jeu->posx[i] + jeu->ballon->w / 3) && (mouse_y >= jeu->posy[i] && mouse_y <= jeu->posy[i] + jeu->ballon->h / 3) && !jeu->temps_depop[i]) {
        jeu->temps_depop[i] = clock();
        jeu->score++;
        jeu->balle_tire = 1;
        play_sample(jeu->ballon_pop, 200, 128, 1000, 0);
    }
    if (jeu->balle_tire && !(mouse_b & 1))
        jeu->balle_tire = 0;
}

int gagne_ou_perdue(jeu_ballon_t jeu, clock_t time_remove)
{
    if (jeu.score == NELEM)
    {
        rest(800);
        clear_to_color(screen, makecol(0, 0, 0));
        play_sample(jeu.gagnee, 200, 128, 1000, 0);
        draw_sprite(screen, jeu.gagne_image, 0, 0);
        rest(2000);
        return 1;
    }
    else if (jeu.score != NELEM && 10 - ((jeu.temps_restant - time_remove) / 1000) == 0) {
        clear_to_color(screen, makecol(0, 0, 0));
        play_sample(jeu.perdue, 200, 128, 1000, 0);
        draw_sprite(screen, jeu.perdue_image, 0, 0);
        rest(3000);
        return 1;
    }
    return 0;
}

void free_jeu_ballon(jeu_ballon_t jeu)
{
    destroy_sample(jeu.ballon_pop);
    destroy_sample(jeu.perdue);
    destroy_sample(jeu.gagnee);
    destroy_bitmap(jeu.ballon2);
    destroy_bitmap(jeu.ballon);
    destroy_bitmap(jeu.gagne_image);
    destroy_bitmap(jeu.perdue_image);
    destroy_bitmap(jeu.viseur);
}

int jeu_ballon()
{
    BITMAP *page = create_bitmap(SCREEN_W,SCREEN_H);
    char scoreString[5];
    jeu_ballon_t jeu = creer_partie();
    int score;
    clock_t time_remove = clock();

    while (1)
    {
        clear_bitmap(page);
        stretch_sprite(page, jeu.fond, 0, 0, SCREEN_W, SCREEN_H);
        ballon_deplace(&jeu, jeu.ballon->w / 6);
        for (int i = 0; i < NELEM; i++) {
            ballon_toucher(&jeu, i);
            if (jeu.temps_depop[i] == 0)
                stretch_sprite(page, jeu.ballon, jeu.posx[i], jeu.posy[i], jeu.ballon->w / 3, jeu.ballon->h / 3);
            else if (clock() - jeu.temps_depop[i] <= 150)
                stretch_sprite(page, jeu.ballon2, jeu.posx[i], jeu.posy[i], jeu.ballon->w / 3, jeu.ballon->h / 3);
            else
                jeu.posx[i] = -100;
        }
        jeu.temps_restant = clock();

        sprintf(scoreString, "%d", 10 - ((jeu.temps_restant - time_remove) / 1000));
        textout_ex(page, font, "temps restant:", SCREEN_W - 200, SCREEN_H - 30, makecol(255, 255, 255), -1);
        textout_ex(page, font, scoreString, SCREEN_W - 30, SCREEN_H - 30, makecol(255, 255, 255), -1);

        sprintf(scoreString, "%d", jeu.score);
        textout_ex(page, font, "Score:", 30, SCREEN_H - 30, makecol(255, 255, 255), -1);
        textout_ex(page, font, scoreString, 90, SCREEN_H - 30, makecol(255, 255, 255), -1);
        stretch_sprite(page, jeu.viseur, mouse_x - jeu.viseur->w / 16, mouse_y - jeu.viseur->h / 16, jeu.viseur->w / 8, jeu.viseur->h / 8);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        if(gagne_ou_perdue(jeu, time_remove))
            break;
    }
    score = jeu.score;
    free_jeu_ballon(jeu);
    destroy_bitmap(page);
    return score;
}

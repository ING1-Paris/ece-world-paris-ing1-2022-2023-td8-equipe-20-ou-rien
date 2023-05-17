#include "header.h"

int main()
{
    BITMAP *page;
    char scoreString[5];
    jeu_ballon_t jeu;
    int shoot = 0;

    srand(time(NULL));

    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_NONE, "");

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    page=create_bitmap(SCREEN_W,SCREEN_H);
    jeu = creer_partie();

    show_mouse(screen);
    while (!key[KEY_ESC])
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
        gagne_ou_perdue(jeu);

        sprintf(scoreString, "%d", 15 - (jeu.temps_restant / 1000));
        textout_ex(page, font, "temps restant:", SCREEN_W - 200, SCREEN_H - 30, makecol(255, 255, 255), -1);
        textout_ex(page, font, scoreString, SCREEN_W - 30, SCREEN_H - 30, makecol(255, 255, 255), -1);

        sprintf(scoreString, "%d", jeu.score);
        textout_ex(page, font, "Score:", 30, SCREEN_H - 30, makecol(255, 255, 255), -1);
        textout_ex(page, font, scoreString, 90, SCREEN_H - 30, makecol(255, 255, 255), -1);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }
    allegro_exit();
    return 0;
}
END_OF_MAIN();



#include <time.h>
#include <allegro.h>
#include "../.h/header.h"

int fonction_labyrinth(void)
{
    int score;
    BITMAP *buffer;

    srand(time(NULL));
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_NONE, "");

    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    set_alpha_blender();

    score = gameLoop();
   
    /*

        Pour Matteo:

        Tu transformes ce main en une fonction qui va lancer mon jeu.
        Elle retournera le score définie plus haut.
        Je pense qu'avant le rendu final j'apporterais quelques modif enore.
        
    */

    allegro_exit();
    return 0;
}
#include <time.h>
#include <allegro.h>
#include "../.h/header.h"

int fonction_labyrinth(void)
{
    int score;
    BITMAP *buffer;
    install_sound(DIGI_AUTODETECT, MIDI_NONE, "");
    set_alpha_blender();
    score = gameLoop();
   
    /*

        Pour Matteo:

        Tu transformes ce main en une fonction qui va lancer mon jeu.
        Elle retournera le score définie plus haut.
        Je pense qu'avant le rendu final j'apporterais quelques modif enore.
        
    */
    return score;
}
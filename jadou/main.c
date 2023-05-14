#include "header.h"

int fonction_affichage(){
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);





    }
    allegro_exit();
    return 0;
}






int main (){
    Joueur1 ballon1;
    Joueur2 ballon2;

    BITMAP *ballon = NULL;
    BITMAP *stand_de_tir = NULL;
    BITMAP *background;

    while (!key[KEY_ESC]){
        if (key[KEY_R])
            jeu(background, ballon, stand_de_tir, ballon1, ballon2);
    }

    allegro_exit();
    return 0;
}END_OF_MAIN();


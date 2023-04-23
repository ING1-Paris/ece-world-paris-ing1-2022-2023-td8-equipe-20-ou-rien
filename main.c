#include <stdio.h>
#include "allegro.h"


///fonction allegro

void initiation()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
    show_mouse(screen);
}

BITMAP * importeImage(char *nomDeFichier)
{
    BITMAP *imageARendre= load_bitmap(nomDeFichier,NULL);
    if(!imageARendre)
    {
        allegro_message("ne peut pas ouvrir");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return imageARendre;
}

int main(void) {
    printf("Hello World!\n");
    return 0;
}
END_OF_MAIN()

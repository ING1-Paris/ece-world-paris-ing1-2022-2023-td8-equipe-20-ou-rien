#include <time.h>
#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/header.h"

int main(void)
{
    allegro_init();

    srand(time(NULL));
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "./");

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, WINDOW_W, WINDOW_H, 0, 0) != 0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    set_trans_blender(40, 40, 255, 255);

    startGame(); // game loop

    allegro_exit();
    return 0;
}
END_OF_MAIN();
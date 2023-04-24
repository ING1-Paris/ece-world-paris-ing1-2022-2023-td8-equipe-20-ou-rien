#include <stdio.h>
#include "allegro.h"
#include "../.h/fonction_allegro.h"

int main(void) {
    initiation();
    BITMAP *fond[52];
    char nomDeFichier[5000];
    for(int i=1;i<50;i++)
    {
        sprintf(nomDeFichier,"../image/frame-%d.bmp",i);
        fond[i]= importeImage(nomDeFichier);
    }
    while(!key[KEY_ESC]){}
    allegro_exit();
    return 0;
}
END_OF_MAIN()

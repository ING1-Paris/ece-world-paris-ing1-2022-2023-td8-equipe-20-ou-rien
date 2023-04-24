#include <stdio.h>
#include "allegro.h"
#include "../.h/fonction_allegro.h"
#include "../.h/fonction_project.h"

int main(void) {
    initiation();
    char nomDeFichier[5000];
    int frame=1;
    int BoolMenu=TRUE,BoolSettings=FALSE,BoolPlay=FALSE;
    BITMAP *fond[52];
    for(int i=1;i<50;i++)
    {
        sprintf(nomDeFichier,"../image/frame-%d.bmp",i);
        fond[i]= importeImage(nomDeFichier);
    }
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    if(BoolMenu)
    {
        menu(&BoolMenu,&BoolSettings,&BoolPlay,frame,fond,buffer);
    }
    allegro_exit();
    return 0;
}
END_OF_MAIN()

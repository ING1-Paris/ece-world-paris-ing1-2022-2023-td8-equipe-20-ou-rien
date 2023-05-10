#include <stdio.h>
#include "allegro.h"
#include "../.h/fonction_allegro.h"
#include "../.h/fonction_project.h"
#include "../.h/fonction game snake.h"

///bonjour

int main(void) {
    initiation();
    int BoolMenu=TRUE,BoolSettings=FALSE,BoolPlay=FALSE;
    //animationDebut();
    rest(30);
    while (!key[KEY_ESC])
    {
        if(BoolMenu)
        {
            menu(&BoolMenu,&BoolSettings,&BoolPlay);
        }
        if(BoolPlay)
        {
            playMap(&BoolMenu,&BoolSettings,&BoolPlay);
            Snake();
        }
    }
    allegro_exit();
    return 0;
}
END_OF_MAIN()

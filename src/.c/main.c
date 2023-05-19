#include <stdio.h>
#include "allegro.h"
#include "../.h/fonction_allegro.h"
#include "../.h/fonction_project.h"
#include "../.h/fonction_game_snake.h"
#include "../.h/fonction_game_fighter.h"
#include "../.h/fonction_riviere.h"
#include "../.h/header.h"
#include "time.h"
#include "stdlib.h"

///bonjour

int main(void) {
    srand(time(NULL));
    initiation();
    int BoolMenu=TRUE,BoolQuit=FALSE,BoolPlay=FALSE;
    int choiceMenu=0;
    //animationDebut();
    rest(30);
    float statTest=0;
    while (!key[KEY_ESC])
    {
        if(BoolMenu)
        {
            choiceMenu=menu(&BoolMenu,&BoolQuit,&BoolPlay);
        }
        if(BoolPlay)
        {
            //gameLoop();
             playMap(&BoolMenu,&BoolQuit,&BoolPlay,choiceMenu);
            //Snake();
            //fonction_riviere();
            //FightPlay(&statTest);

        }
        if(BoolQuit)
        {
            break;
        }
    }
    allegro_exit();
    return 0;
    //commentaire
}
END_OF_MAIN()
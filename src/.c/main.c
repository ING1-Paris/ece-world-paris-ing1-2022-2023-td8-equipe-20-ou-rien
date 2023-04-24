#include <stdio.h>
#include "allegro.h"
#include "../.h/fonction_allegro.h"
#include "../.h/fonction_project.h"

int main(void) {
    initiation();
    int BoolMenu=TRUE,BoolSettings=FALSE,BoolPlay=FALSE;
    if(BoolMenu)
    {
        menu(&BoolMenu,&BoolSettings,&BoolPlay);
    }
    allegro_exit();
    return 0;
}
END_OF_MAIN()

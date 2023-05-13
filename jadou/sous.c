#include "header.h"

BITMAP *charger_image(const char *image) {
    BITMAP *bitmap= load_bitmap(image, NULL);
    if (!bitmap){
        allegro_message("Problème lors du chargement de l'image");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return bitmap;
}




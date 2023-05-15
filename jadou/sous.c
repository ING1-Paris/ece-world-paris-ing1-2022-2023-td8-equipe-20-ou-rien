#include "header.h"

BITMAP *chargeImage(const char *image) {
    BITMAP *bitmap= load_bitmap(image, NULL);
    if (!bitmap){
        allegro_message("Problème lors du chargement de l'image");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return bitmap;
}

void jeu(BITMAP *background, BITMAP *ballon, BITMAP *tir, Joueur1 ballon1, Joueur2 ballon2) {

    BITMAP *chargeBallon1(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 44, 36, 23, 21);
        return petit_ballon;
    }
    BITMAP *chargeBallon2(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 130, 29, 37, 37);
        return petit_ballon;
    }
    BITMAP *chargeBallon3(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 220, 22, 47, 48);
        return petit_ballon;
    }

    BITMAP *chargeBallon4(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 306, 19, 57, 53);
        return petit_ballon;
    }
    BITMAP *chargeBallon5(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 24, 97, 61, 55);
        return petit_ballon;
    }
    BITMAP *chargeBallon6(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 117, 96, 66, 63);
        return petit_ballon;
    }

    BITMAP *chargeBallon7(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 117, 96, 66, 63);
        return petit_ballon;
    }

    BITMAP *chargeBallon8(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 117, 96, 66, 63);
        return petit_ballon;
    }

    void afficheBallonStat1(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x1, ballon.y1);
    }
    void afficheBallonStat2(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x2, ballon.y2);
    }
    void afficheBallonStat3(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x3, ballon.y3);
    }
    void afficheBallonStat4(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x4, ballon.y4);
    }
    void afficheBallonStat5(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x5, ballon.y5);
    }
    void afficheBallonStat6(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x6, ballon.y6);
    }
    void afficheBallonStat7(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x7, ballon.y7);
    }
    void afficheBallonStat8(BITMAP *background, BITMAP *afficheBallon, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x8, ballon.y8);
    }
    void afficheBallonStat11(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x1, ballon.y1);
    }
    void afficheBallonStat22(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x2, ballon.y2);
    }
    void afficheBallonStat33(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x3, ballon.y3);
    }
    void afficheBallonStat44(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x4, ballon.y4);
    }
    void afficheBallonStat55(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x5, ballon.y5);
    }
    void afficheBallonStat66(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x6, ballon.y6);
    }
    void afficheBallonStat77(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x7, ballon.y7);
    }
    void afficheBallonStat88(BITMAP *background, BITMAP *afficheBallon, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.x8, ballon.y8);
    }

    void afficheBallonMob1(BITMAP *background, BITMAP *afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c) {
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1) {
            draw_sprite(background, ballon_affichage, ballon->x1, ballon->y1);
            if (ballon->x1 > *a - 50 && ballon->x1 < *a + 50 && ballon->y1 > *b - 50 && ballon->y1 < *b + 50) {
                ballon->x1 = ballon->x1 + dx;
                ballon->y1 = ballon->y1 + dy;
            } else {
                ballon->x1 = *a;
                ballon->y1 = *b;
            }
        }
    }

    void afficheBallonMob2(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x2, ballon->y2);
            if(ballon->x2 > *a - 50 && ballon->x2 < *a + 50 && ballon->y2 > *b - 50 && ballon->y2 < *b + 50) {
                ballon->x2 = ballon->x2 + dx;
                ballon->y2 = ballon->y2 + dy;
            }
            else {
                ballon->x2 = *a;
                ballon->y2 = *b;
            }
        }
    }
    void afficheBallonMob3(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x3, ballon->y3);
            if(ballon->x3 > *a - 50 && ballon->x3 < *a + 50 && ballon->y3 > *b - 50 && ballon->y3 < *b + 50) {
                ballon->x3 = ballon->x3 + dx;
                ballon->y3 = ballon->y3 + dy;
            }
            else {
                ballon->x3 = *a;
                ballon->y3 = *b;
            }
        }
    }
    void afficheBallonMob4(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x4, ballon->y4);
            if(ballon->x4 > *a - 50 && ballon->x4 < *a + 50 && ballon->y4 > *b - 50 && ballon->y4 < *b + 50) {
                ballon->x4 = ballon->x4 + dx;
                ballon->y4 = ballon->y4 + dy;
            }
            else {
                ballon->x4 = *a;
                ballon->y4 = *b;
            }
        }
    }
    void afficheBallonMob5(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x5, ballon->y5);
            if(ballon->x5 > *a - 50 && ballon->x5 < *a + 50 && ballon->y5 > *b - 50 && ballon->y5 < *b + 50) {
                ballon->x5 = ballon->x5 + dx;
                ballon->y5 = ballon->y5 + dy;
            }
            else {
                ballon->x5 = *a;
                ballon->y5 = *b;
            }
        }
    }
    void afficheBallonMob6(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x6, ballon->y6);
            if(ballon->x6 > *a - 50 && ballon->x6 < *a + 50 && ballon->y6 > *b - 50 && ballon->y6 < *b + 50) {
                ballon->x6 = ballon->x6 + dx;
                ballon->y6 = ballon->y6 + dy;
            }
            else {
                ballon->x6 = *a;
                ballon->y6 = *b;
            }
        }
    }
    void afficheBallonMob7(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x7, ballon->y7);
            if(ballon->x7 > *a - 50 && ballon->x7 < *a + 50 && ballon->y7 > *b - 50 && ballon->y7 < *b + 50) {
                ballon->x7 = ballon->x7 + dx;
                ballon->y7 = ballon->y7 + dy;
            }
            else {
                ballon->x7 = *a;
                ballon->y7 = *b;
            }
        }
    }
    void afficheBallonMob8(BITMAP* background, BITMAP* afficheBallon, Joueur1 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x8, ballon->y8);
            if(ballon->x8 > *a - 50 && ballon->x8 < *a + 50 && ballon->y8 > *b - 50 && ballon->y8 < *b + 50) {
                ballon->x8 = ballon->x8 + dx;
                ballon->y8 = ballon->y8 + dy;
            }
            else {
                ballon->x8 = *a;
                ballon->y8 = *b;
            }
        }
    }

    void afficheBallonMob11(BITMAP *background, BITMAP *afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c) {
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1) {
            draw_sprite(background, ballon_affichage, ballon->x1, ballon->y1);
            if (ballon->x1 > *a - 50 && ballon->x1 < *a + 50 && ballon->y1 > *b - 50 &&
                ballon->y1 < *b + 50) {
                ballon->x1 = ballon->x1 + dx;
                ballon->y1 = ballon->y1 + dy;
            } else {
                ballon->x1 = *a;
                ballon->y1 = *b;
            }
        }
    }

    void afficheBallonMob22(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x2, ballon->y2);
            if(ballon->x2 > *a - 50 && ballon->x2 < *a + 50 && ballon->y2 > *b - 50 && ballon->y2 < *b + 50) {
                ballon->x2 = ballon->x2 + dx;
                ballon->y2 = ballon->y2 + dy;
            }
            else {
                ballon->x2 = *a;
                ballon->y2 = *b;
            }
        }
    }
    void afficheBallonMob33(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x3, ballon->y3);
            if(ballon->x3 > *a - 50 && ballon->x3 < *a + 50 && ballon->y3 > *b - 50 && ballon->y3 < *b + 50) {
                ballon->x3 = ballon->x3 + dx;
                ballon->y3 = ballon->y3 + dy;
            }
            else {
                ballon->x3 = *a;
                ballon->y3 = *b;
            }
        }
    }
    void afficheBallonMob44(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x4, ballon->y4);
            if(ballon->x4 > *a - 50 && ballon->x4 < *a + 50 && ballon->y4 > *b - 50 && ballon->y4 < *b + 50) {
                ballon->x4 = ballon->x4 + dx;
                ballon->y4 = ballon->y4 + dy;
            }
            else {
                ballon->x4 = *a;
                ballon->y4 = *b;
            }
        }
    }
    void afficheBallonMob55(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x5, ballon->y5);
            if(ballon->x5 > *a - 50 && ballon->x5 < *a + 50 && ballon->y5 > *b - 50 && ballon->y5 < *b + 50) {
                ballon->x5 = ballon->x5 + dx;
                ballon->y5 = ballon->y5 + dy;
            }
            else {
                ballon->x5 = *a;
                ballon->y5 = *b;
            }
        }
    }
    void afficheBallonMob66(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x6, ballon->y6);
            if(ballon->x6 > *a - 50 && ballon->x6 < *a + 50 && ballon->y6 > *b - 50 && ballon->y6 < *b + 50) {
                ballon->x6 = ballon->x6 + dx;
                ballon->y6 = ballon->y6 + dy;
            }
            else {
                ballon->pose_x6 = *a;
                ballon->pose_y6 = *b;
            }
        }
    }
    void afficheBallonMob77(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x7, ballon->y7);
            if(ballon->x7 > *a - 50 && ballon->x7 < *a + 50 && ballon->y7 > *b - 50 && ballon->y7 < *b + 50) {
                ballon->x7 = ballon->x7 + dx;
                ballon->y7 = ballon->y7 + dy;
            }
            else {
                ballon->x7 = *a;
                ballon->y7 = *b;
            }
        }
    }
    void afficheBallonMob88(BITMAP* background, BITMAP* afficheBallon, Joueur2 *ballon, const int *a, const int *b, const int *c){
        int dx= rand()% (30) -15;
        int dy= rand()% (30) -15;
        if(*c==1){
            draw_sprite(background, ballon_affichage, ballon->x8, ballon->y8);
            if(ballon->x8 > *a - 50 && ballon->x8 < *a + 50 && ballon->y8 > *b - 50 && ballon->y8 < *b + 50) {
                ballon->x8 = ballon->x8 + dx;
                ballon->y8 = ballon->y8 + dy;
            }
            else {
                ballon->x8 = *a;
                ballon->y8 = *b;
            }
        }
    }




}

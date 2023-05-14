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

void jeu(BITMAP *background, BITMAP *ballon, BITMAP *stand_de_tir, Joueur1 ballon1, Joueur2 ballon2) {

    BITMAP *charger_ballon1(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 44, 36, 23, 21);
        return petit_ballon;
    }
    BITMAP *charger_ballon2(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 130, 29, 37, 37);
        return petit_ballon;
    }
    BITMAP *charger_ballon3(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 220, 22, 47, 48);
        return petit_ballon;
    }

    BITMAP *charger_ballon4(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 306, 19, 57, 53);
        return petit_ballon;
    }
    BITMAP *charger_ballon5(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 24, 97, 61, 55);
        return petit_ballon;
    }
    BITMAP *charger_ballon6(BITMAP *ballon) {
        BITMAP *petit_ballon = create_sub_bitmap(ballon, 117, 96, 66, 63);
        return petit_ballon;
    }

    void afficherBallonStatique1(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x1, ballon.pose_y1);
    }
    void afficherBallonStatique2(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x2, ballon.pose_y2);
    }
    void afficherBallonStatique3(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x3, ballon.pose_y3);
    }
    void afficherBallonStatique4(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x4, ballon.pose_y4);
    }
    void afficherBallonStatique5(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x5, ballon.pose_y5);
    }
    void afficherBallonStatique6(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x6, ballon.pose_y6);
    }
    void afficherBallonStatique7(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x7, ballon.pose_y7);
    }
    void afficherBallonStatique8(BITMAP *background, BITMAP *ballon_affichage, Joueur1 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x8, ballon.pose_y8);
    }
    void afficherBallonStatique11(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x1, ballon.pose_y1);
    }
    void afficherBallonStatique12(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x2, ballon.pose_y2);
    }
    void afficherBallonStatique13(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x3, ballon.pose_y3);
    }
    void afficherBallonStatique14(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x4, ballon.pose_y4);
    }
    void afficherBallonStatique15(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x5, ballon.pose_y5);
    }
    void afficherBallonStatique16(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x6, ballon.pose_y6);
    }
    void afficherBallonStatique17(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x7, ballon.pose_y7);
    }
    void afficherBallonStatique18(BITMAP *background, BITMAP *ballon_affichage, Joueur2 ballon) {
        draw_sprite(background, ballon_affichage, ballon.pose_x8, ballon.pose_y8);
    }

}

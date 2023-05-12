#include <allegro.h>
#include <stdio.h>

typedef struct pingouin_s {
    BITMAP ***anim;
    int tempo_anim;
    int index_anim;
    int index_sprite;
    int flip;
    int x;
    int y;
}pingouin;

void defilement_map_verticale(BITMAP *decor, BITMAP *buffer,int vitesse_verticale) {

    blit(decor, buffer, 0, decor->h - vitesse_verticale- SCREEN_H, (SCREEN_W - decor->w) /2, 0, decor->w, SCREEN_H);

    if(vitesse_verticale>=900)
        blit(decor, buffer, 0, decor->h - 900 - SCREEN_H, (SCREEN_W - decor->w) /2, 0, decor->w, SCREEN_H);

}

void premiere_riviere(BITMAP *spritebanquise, BITMAP *buffer, BITMAP *spriteourspolaire, int vitesse_verticale, int vitesse_horizontale){

    draw_sprite(buffer, spritebanquise, 0 - vitesse_horizontale, 230 + vitesse_horizontale );

    draw_sprite(buffer, spritebanquise, SCREEN_W-spritebanquise->w + vitesse_horizontale, 100 + vitesse_verticale);

    draw_sprite(buffer, spritebanquise, 0 - vitesse_horizontale, -40 + vitesse_verticale );

    draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /6, 160 + vitesse_horizontale );
    draw_sprite(buffer, spriteourspolaire, 5*(SCREEN_W-spriteourspolaire->w) /6, 160 + vitesse_horizontale );

    draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /2, 30 + vitesse_horizontale );


}

void deuxieme_riviere(BITMAP *spritebanquise, BITMAP *buffer, BITMAP *spriteourspolaire, BITMAP *decor, int vitesse_verticale, int vitesse_horizontale){

    if(vitesse_verticale >= 423 && vitesse_verticale <=900){

        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -505 + vitesse_verticale );

        draw_sprite(buffer, spritebanquise,  -900+vitesse_horizontale, -650 + vitesse_verticale );

        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -720 + vitesse_verticale );

        draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /6,  vitesse_verticale-580 );
        draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /2,  vitesse_verticale -580);
        draw_sprite(buffer, spriteourspolaire, 5*(SCREEN_W-spriteourspolaire->w) /6,  vitesse_verticale-580 );

    }
    if(vitesse_verticale>=900) {
        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -505 + 900);

        draw_sprite(buffer, spritebanquise, -900 + vitesse_horizontale, -650 + 900);

        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -720 + 900);

        draw_sprite(buffer, spriteourspolaire, (SCREEN_W - spriteourspolaire->w) / 6, 900 - 580);
        draw_sprite(buffer, spriteourspolaire, (SCREEN_W - spriteourspolaire->w) / 2, 900 - 580);
        draw_sprite(buffer, spriteourspolaire, 5 * (SCREEN_W - spriteourspolaire->w) / 6, 900 - 580);
    }
}

void decoration(BITMAP *buffer, BITMAP *spritemorse, BITMAP *spritearbre, BITMAP *spritetronc,BITMAP *spritemap, int  vitesse_verticale){

    draw_sprite(buffer, spritemorse, 600, 400 + vitesse_verticale );
    draw_sprite(buffer, spritetronc, 50,   300+vitesse_verticale );
    draw_sprite(buffer, spritemap, 0,   -400+vitesse_verticale );

    if(vitesse_verticale>=900){

        draw_sprite(buffer, spritemorse, 600, 400 + 900 );
        draw_sprite(buffer, spritetronc, 50,   300 + 900 );
        draw_sprite(buffer, spritemap, 0,   -400 + 900 );

    }


}

void checkPtrNull(void *ptr, char *str)
{
    if (ptr == NULL) {
        printf("%s\n", str);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

pingouin *creer_pingouin(void)
{
    char chemin[] = "../a.bmp";
    pingouin *ping = malloc(sizeof(pingouin));

    checkPtrNull(ping, "Exit Failure: malloc failed\n");
    ping->anim = malloc(sizeof(BITMAP **) * (2 + 1));
    checkPtrNull(ping->anim, "Exit Failure: malloc failed");
    ping->anim[2] = NULL;
    for (int i = 0; i < 2; i++) {
        ping->anim[i] = malloc(sizeof(BITMAP *) * (3 + 1));
        checkPtrNull(ping->anim[i], "Exit Failure: malloc failed");
        ping->anim[i][3] = NULL;
        for (int j = 0; j < 3; j++) {
            ping->anim[i][j] = load_bitmap(chemin, NULL);
            checkPtrNull(ping->anim[i][j], "Exit Failure: creating bitmap failed");
            chemin[3] += 1;
        }
    }
    ping->x = 350;
    ping->y = 450;
    ping->index_anim = 0;
    ping->index_sprite = 0;
    ping->flip = 0;
    ping->tempo_anim = 0;

    return ping;
}

void anim_pingouin(pingouin *ping, int *tempo_marche)
{
    if (key[KEY_UP]) {
        if (*tempo_marche == 2) {
            *tempo_marche = 0;
            ping->y--;
        } else
            *tempo_marche += 1;
        ping->index_anim = 0;
        ping->flip = 0;
    } else if (key[KEY_DOWN]) {
        if (*tempo_marche == 2) {
            *tempo_marche = 0;
            ping->y++;
        } else
            *tempo_marche += 1;
        ping->flip = 0;
        ping->index_anim = 0;
    } else if (key[KEY_LEFT]) {
        if (*tempo_marche == 2) {
            *tempo_marche = 0;
            ping->x--;
        } else
            *tempo_marche += 1;
        ping->flip = 1;
        ping->index_anim = 1;
    } else if (key[KEY_RIGHT]) {
        if (*tempo_marche == 2) {
            *tempo_marche = 0;
            ping->x++;
        } else
            *tempo_marche += 1;
        ping->flip = 0;
        ping->index_anim = 1;
    }
}

void affiche_pingouin(pingouin *ping, BITMAP *buffer)
{
    if (ping->anim[ping->index_anim][ping->index_sprite + 1] != NULL && ping->tempo_anim == 40) {
        ping->index_sprite++;
        ping->tempo_anim = 0;
    } else if (ping->anim[ping->index_anim][ping->index_sprite + 1] == NULL && ping->tempo_anim == 40) {
        ping->index_sprite = 0;
        ping->tempo_anim = 0;
    } else
        ping->tempo_anim++;
    if (!ping->flip)
        draw_sprite(buffer, ping->anim[ping->index_anim][ping->index_sprite], ping->x, ping->y);
    else
        draw_sprite_h_flip(buffer, ping->anim[ping->index_anim][ping->index_sprite], ping->x, ping->y);
}

int defaite(pingouin *ping){

    if (ping->y >= 600 || ping->x <=-100 || ping->x >= 800)
        return 1;
    return 0;

};
/*
int tomber_dans_eau(pingouin *ping){

    if(ping->y >=296 && ping->y <= 637)
        return 1;
    return 0;

}
*/

int fonction_affichage() {

    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP *decor;
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);

    BITMAP *pinguoin0;
    BITMAP *pinguoin1;
    BITMAP *pinguoin2;
    BITMAP *spritebanquise;
    BITMAP *spriteourspolaire;

    //decor
    BITMAP *spritemorse;
    BITMAP *spritearbre;
    BITMAP *spritetronc;
    BITMAP *spritemap;

    decor=load_bitmap("../mapprojetneige.bmp",NULL);
    if (!decor)
    {
        allegro_message("pas pu trouver mapprojetneige.bmp");
        exit(EXIT_FAILURE);
    }

    spritebanquise=load_bitmap("../spritebanquise.bmp",NULL);
    if (!spritebanquise)
    {
        allegro_message("pas pu trouver banquise.bmp");
        exit(EXIT_FAILURE);
    }

    spriteourspolaire=load_bitmap("../spriteourspolaire.bmp",NULL);
    if (!spriteourspolaire)
    {
        allegro_message("pas pu trouver spriteourspolaire.bmp");
        exit(EXIT_FAILURE);
    }

    spritemorse=load_bitmap("../spritemorse.bmp",NULL);
    if (!spritemorse)
    {
        allegro_message("pas pu trouver spritemorse.bmp");
        exit(EXIT_FAILURE);
    }

    spritetronc=load_bitmap("../spritetronc.bmp",NULL);
    if (!spritetronc)
    {
        allegro_message("pas pu trouver spritetronc.bmp");
        exit(EXIT_FAILURE);
    }

    spritemap=load_bitmap("../spritemap.bmp",NULL);
    if (!spritemap)
    {
        allegro_message("pas pu trouver spritemap.bmp");
        exit(EXIT_FAILURE);
    }

    int vitesse_verticale=0;
    int vitesse_horizontale=0;
    int saut=30;

    int cptimg=0;
    int tmpimg=3;
    int positiony=450;
    int positionx=350;

    int tempo_riviere = 0;
    int tempo_marche = 0;
    int vitesse = 1;
    pingouin *ping = creer_pingouin();

    while (!key[KEY_ESC]) {

        clear_bitmap(buffer);

        defilement_map_verticale(decor, buffer, vitesse_verticale);

        decoration( buffer, spritemorse, spritearbre, spritetronc, spritemap, vitesse_verticale);

        premiere_riviere( spritebanquise, buffer, spriteourspolaire, vitesse_verticale, vitesse_horizontale);

        deuxieme_riviere(spritebanquise, buffer, spriteourspolaire, decor, vitesse_verticale, vitesse_horizontale);


        if (defaite(ping)) {
            allegro_exit();
            return 0;
        }

        /*if (tomber_dans_eau(ping)) {
            allegro_exit();
            return 0;
        }*/
        printf("%d\n",ping->y-vitesse_verticale);
        if (tempo_riviere == 5) {
            if (vitesse_verticale < 900) {
                vitesse_verticale += vitesse;
                ping->y += 1;
            }
            vitesse_horizontale += vitesse;
            tempo_riviere = 0;
        } else
            tempo_riviere++;

        anim_pingouin(ping, &tempo_marche);
        affiche_pingouin(ping, buffer);

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    }
    allegro_exit();
    return 0;
}

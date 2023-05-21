#include <allegro.h>
#include <stdio.h>
#include "../.h/fonction_riviere.h"

void defilement_map_verticale(BITMAP *decor, BITMAP *buffer,int vitesse_verticale) {

    blit(decor, buffer, 0, decor->h - vitesse_verticale- SCREEN_H, (SCREEN_W - decor->w) /2, 0, decor->w, SCREEN_H);

    if(vitesse_verticale>=900)
        blit(decor, buffer, 0, decor->h - 900 - SCREEN_H, (SCREEN_W - decor->w) /2, 0, decor->w, SCREEN_H);

}

void premiere_riviere(BITMAP *spritebanquise, BITMAP *buffer, BITMAP *spriteourspolaire, int vitesse_verticale, int vitesse_horizontale){

    draw_sprite(buffer, spritebanquise, 0 - vitesse_horizontale, 240 + vitesse_horizontale );

    draw_sprite(buffer, spritebanquise, SCREEN_W-spritebanquise->w + vitesse_horizontale, 100 + vitesse_verticale);

    draw_sprite(buffer, spritebanquise, 0 - vitesse_horizontale, -35 + vitesse_verticale );

    draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /6, 155 + vitesse_horizontale );
    draw_sprite(buffer, spriteourspolaire, 5*(SCREEN_W-spriteourspolaire->w) /6, 155 + vitesse_horizontale );
    draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /2, 20 + vitesse_horizontale );


}

void deuxieme_riviere(BITMAP *spritebanquise, BITMAP *buffer, BITMAP *spriteourspolaire, int vitesse_verticale, int vitesse_horizontale){

    if(vitesse_verticale >= 423 && vitesse_verticale <=900){

        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -505 + vitesse_verticale );

        draw_sprite(buffer, spritebanquise,  -900+vitesse_horizontale, -650 + vitesse_verticale );

        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -720 + vitesse_verticale );

        draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /6,  vitesse_verticale-590 );
        draw_sprite(buffer, spriteourspolaire, (SCREEN_W-spriteourspolaire->w) /2,  vitesse_verticale -590);
        draw_sprite(buffer, spriteourspolaire, 5*(SCREEN_W-spriteourspolaire->w) /6,  vitesse_verticale-590 );

    }
    if(vitesse_verticale>=900) {
        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -505 + 900);

        draw_sprite(buffer, spritebanquise, -900 + vitesse_horizontale, -650 + 900);

        draw_sprite(buffer, spritebanquise, 400 - vitesse_horizontale, -720 + 900);

        draw_sprite(buffer, spriteourspolaire, (SCREEN_W - spriteourspolaire->w) / 6, 900 - 590);
        draw_sprite(buffer, spriteourspolaire, (SCREEN_W - spriteourspolaire->w) / 2, 900 - 590);
        draw_sprite(buffer, spriteourspolaire, 5 * (SCREEN_W - spriteourspolaire->w) / 6, 900 - 590);
    }
}

void decoration(BITMAP *buffer, BITMAP *spritemorse, BITMAP *spritetronc, BITMAP *spritemap, BITMAP *phoque, BITMAP *phoque1, pingouin *ping, int  vitesse_verticale){

    draw_sprite(buffer, spritemorse, 600, 400 + vitesse_verticale );
    draw_sprite(buffer, spritetronc, 50,   300+vitesse_verticale );
    draw_sprite(buffer, spritemap, 0,   -400+vitesse_verticale );

    if(ping->y - vitesse_verticale > -835) {
        draw_sprite(buffer, phoque, 10, -880 + vitesse_verticale);
    }

    if(ping->y - vitesse_verticale <= -835)
        draw_sprite(buffer, phoque1, 10, -880 + vitesse_verticale);

    //draw_sprite(buffer, phoque1, 10, -880 + vitesse_verticale);

}

void checkPtrNullfonctionRiviere(void *ptr, char *str)
{
    if (ptr == NULL) {
        printf("%s\n", str);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}

pingouin *creer_pingouin(void)
{
    char chemin[] = "../robin/a.bmp";
    pingouin *ping = malloc(sizeof(pingouin));

    checkPtrNullfonctionRiviere(ping, "Exit Failure: malloc failed\n");
    ping->anim = malloc(sizeof(BITMAP **) * (2 + 1));
    checkPtrNullfonctionRiviere(ping->anim, "Exit Failure: malloc failed");
    ping->anim[2] = NULL;
    for (int i = 0; i < 2; i++) {
        ping->anim[i] = malloc(sizeof(BITMAP *) * (3 + 1));
        checkPtrNullfonctionRiviere(ping->anim[i], "Exit Failure: malloc failed");
        ping->anim[i][3] = NULL;
        for (int j = 0; j < 3; j++) {
            ping->anim[i][j] = load_bitmap(chemin, NULL);
            checkPtrNullfonctionRiviere(ping->anim[i][j], "Exit Failure: creating bitmap failed");
            chemin[9] += 1;
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

void anim_pingouin(pingouin *ping, int *tempo_marche, int vitesse_verticale)
{

    if (key[KEY_UP]) {
        if(*tempo_marche == 3 && ping->y-vitesse_verticale <= -157 && ping->y-vitesse_verticale >= -470 && (ping->x <= 340 || ping->x >= 390)) {
            ping->y = ping->y;
        }else if (*tempo_marche == 3) {
            *tempo_marche = 0;
            ping->y--;
            if(ping->y-vitesse_verticale==-157)
                ping->y=ping->y;
        } else
            *tempo_marche += 1;
        ping->index_anim = 0;
        ping->flip = 0;
    } else if (key[KEY_DOWN]) {
        if (*tempo_marche == 3 && ping->y-vitesse_verticale <= -157 && ping->y-vitesse_verticale >= -470 && (ping->x <= 340 || ping->x >= 390)) {
            ping->y = ping->y;
        }else if (*tempo_marche == 3 ) {
            *tempo_marche = 0;
            ping->y++;
        } else
            *tempo_marche += 1;
        ping->flip = 0;
        ping->index_anim = 0;
    } else if (key[KEY_LEFT]) {
        if (*tempo_marche == 3 && ping->y-vitesse_verticale <= -157 && ping->y-vitesse_verticale >= -470 && ping->x == 341 ) {
            ping->x=ping->x;
        } else if (*tempo_marche == 3 ) {
            *tempo_marche = 0;
            ping->x--;
        } else
            *tempo_marche += 1;
        ping->flip = 1;
        ping->index_anim = 1;
    } else if (key[KEY_RIGHT]) {
        if (*tempo_marche == 3 && ping->y-vitesse_verticale <= -157 && ping->y-vitesse_verticale >= -470 && ping->x == 389 ) {
            ping->x=ping->x;
        } else if (*tempo_marche == 3 ) {
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
    if (ping->anim[ping->index_anim][ping->index_sprite + 1] != NULL && ping->tempo_anim == 90) {
        ping->index_sprite++;
        ping->tempo_anim = 0;
    } else if (ping->anim[ping->index_anim][ping->index_sprite + 1] == NULL && ping->tempo_anim == 90) {
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

}

int tomber_dans_eau(BITMAP *buffer, pingouin *ping){

    int i;
    int pixel_courant, pixel_prochain;
    int r, g, b;
    int r2, g2, b2;

    if(KEY_UP) {
        for (i = ping->x + 30; i < ping->x + 70; i++) {
            pixel_courant = getpixel(buffer, i, ping->y + 95);
            pixel_prochain = getpixel(buffer, i, ping->y + 65);
            r = getr(pixel_courant);
            g = getg(pixel_courant);
            b = getb(pixel_courant);
            r2 = getr(pixel_prochain);
            g2 = getg(pixel_prochain);
            b2 = getb(pixel_prochain);
            if ((r == 162 && g == 225 && b == 253) && (r2 == 162 && g2 == 225 && b2 == 253))
                return 1;
            return 0;
        }
    }
    if(KEY_DOWN) {
        for (i = ping->x + 30; i < ping->x + 70; i++) {
            pixel_courant = getpixel(buffer, i, ping->y + 95);
            pixel_prochain = getpixel(buffer, i, ping->y + 125);
            r = getr(pixel_courant);
            g = getg(pixel_courant);
            b = getb(pixel_courant);
            r2 = getr(pixel_prochain);
            g2 = getg(pixel_prochain);
            b2 = getb(pixel_prochain);
            if ((r == 162 && g == 225 && b == 253) && (r2 == 162 && g2 == 225 && b2 == 253))
                return 1;
            return 0;
        }
    }
    if(KEY_RIGHT) {
        for (i = ping->x + 30; i < ping->x + 70; i++) {
            pixel_courant = getpixel(buffer, ping->x + 50, i);
            pixel_prochain = getpixel(buffer, ping->x + 80, i);
            r = getr(pixel_courant);
            g = getg(pixel_courant);
            b = getb(pixel_courant);
            r2 = getr(pixel_prochain);
            g2 = getg(pixel_prochain);
            b2 = getb(pixel_prochain);
            if ((r == 162 && g == 225 && b == 253) && (r2 == 162 && g2 == 225 && b2 == 253))
                return 1;
            return 0;
        }
    }
    if(KEY_LEFT) {
        for (i = ping->x + 30; i < ping->x + 70; i++) {
            pixel_courant = getpixel(buffer, ping->x - 50, i);
            pixel_prochain = getpixel(buffer, ping->x - 80, i);
            r = getr(pixel_courant);
            g = getg(pixel_courant);
            b = getb(pixel_courant);
            r2 = getr(pixel_prochain);
            g2 = getg(pixel_prochain);
            b2 = getb(pixel_prochain);
            if ((r == 162 && g == 225 && b == 253) && (r2 == 162 && g2 == 225 && b2 == 253))
                return 1;
            return 0;
        }
    }

}

int fonction_riviere() {

    clock_t debut,fin;
    float temp_final;
    BITMAP *decor;
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    char string[5];

    BITMAP *spritebanquise;
    BITMAP *spriteourspolaire;

    //decor
    BITMAP *spritemorse;
    BITMAP *spritetronc;
    BITMAP *spritemap;
    BITMAP *phoque;
    BITMAP *phoque1;

    BITMAP *pingouinvictoire1;
    BITMAP *pingouinvictoire2;
    BITMAP *ecranvictoire;
    BITMAP *ecrandefaite;

    decor=load_bitmap("../robin/mapprojetneige.bmp",NULL);
    if (!decor)
    {
        allegro_message("pas pu trouver mapprojetneige.bmp");
        exit(EXIT_FAILURE);
    }

    spritebanquise=load_bitmap("../robin/spritebanquise1.bmp",NULL);
    if (!spritebanquise)
    {
        allegro_message("pas pu trouver banquise.bmp");
        exit(EXIT_FAILURE);
    }

    spriteourspolaire=load_bitmap("../robin/spriteourspolaire.bmp",NULL);
    if (!spriteourspolaire)
    {
        allegro_message("pas pu trouver spriteourspolaire.bmp");
        exit(EXIT_FAILURE);
    }

    spritemorse=load_bitmap("../robin/spritemorse.bmp",NULL);
    if (!spritemorse)
    {
        allegro_message("pas pu trouver spritemorse.bmp");
        exit(EXIT_FAILURE);
    }

    spritetronc=load_bitmap("../robin/spritetronc.bmp",NULL);
    if (!spritetronc)
    {
        allegro_message("pas pu trouver spritetronc.bmp");
        exit(EXIT_FAILURE);
    }

    spritemap=load_bitmap("../robin/spritemap.bmp",NULL);
    if (!spritemap)
    {
        allegro_message("pas pu trouver spritemap.bmp");
        exit(EXIT_FAILURE);
    }

    phoque=load_bitmap("../robin/phoque.bmp",NULL);
    if (!phoque)
    {
        allegro_message("pas pu trouver spritemap.bmp");
        exit(EXIT_FAILURE);
    }

    phoque1=load_bitmap("../robin/phoque1.bmp",NULL);
    if (!phoque1)
    {
        allegro_message("pas pu trouver spritemap.bmp");
        exit(EXIT_FAILURE);
    }

    pingouinvictoire1=load_bitmap("../robin/sprritepinguoinvictoire1.bmp",NULL);
    if (!pingouinvictoire1)
    {
        allegro_message("pas pu trouver ingouinvictoire1.bmp");
        exit(EXIT_FAILURE);
    }

    pingouinvictoire2=load_bitmap("../robin/sprritepinguoinvictoire2.bmp",NULL);
    if (!pingouinvictoire2)
    {
        allegro_message("pas pu trouver pingouinvictoire2.bmp");
        exit(EXIT_FAILURE);
    }

    ecranvictoire=load_bitmap("../robin/ecranvictoire.bmp",NULL);
    if (!ecranvictoire)
    {
        allegro_message("pas pu trouver ecranvictoire.bmp");
        exit(EXIT_FAILURE);
    }

    ecrandefaite=load_bitmap("../robin/défaite.bmp",NULL);
    if (!ecrandefaite)
    {
        allegro_message("pas pu trouver ecrandefaite.bmp");
        exit(EXIT_FAILURE);
    }

    int vitesse_verticale=0;
    int vitesse_horizontale=0;
    int tempo_riviere = 0;
    int tempo_marche = 0;
    int vitesse = 1;
    pingouin *ping = creer_pingouin();

    int Fin =0;
    debut=clock();

    while (!key[KEY_ESC]) {

        if (ping->y - vitesse_verticale > -850) {

            clear_bitmap(buffer);

            defilement_map_verticale(decor, buffer, vitesse_verticale);

            decoration(buffer, spritemorse, spritetronc, spritemap, phoque, phoque1, ping, vitesse_verticale);

            premiere_riviere(spritebanquise, buffer, spriteourspolaire, vitesse_verticale, vitesse_horizontale);

            deuxieme_riviere(spritebanquise, buffer, spriteourspolaire, vitesse_verticale, vitesse_horizontale);

            if (tomber_dans_eau(buffer, ping)) {
                clear_to_color(ping->anim[ping->index_anim][ping->index_sprite],makecol(255, 0, 255));
                blit(ecrandefaite, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(1500);
                break;
            }

            if (defaite(ping)) {
                clear_to_color(ping->anim[ping->index_anim][ping->index_sprite],makecol(255, 0, 255));
                blit(ecrandefaite, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                rest(1500);
                break;
            }

            if (tempo_riviere == 10) {

                if (vitesse_verticale < 900) {
                    vitesse_verticale += vitesse;
                    ping->y += 1;
                }

                if (ping->y <= 200 + vitesse_verticale && ping->y >= 140 + vitesse_verticale)
                    ping->x--;
                if (ping->y <= 60 + vitesse_verticale && ping->y >= 0 + vitesse_verticale)
                    ping->x++;
                if (ping->y <= -75 + vitesse_verticale && ping->y >= -135 + vitesse_verticale)
                    ping->x--;

                if (ping->y <= -545 + vitesse_verticale && ping->y >= -605 + vitesse_verticale)
                    ping->x--;
                if (ping->y <= -690 + vitesse_verticale && ping->y >= -750 + vitesse_verticale)
                    ping->x++;
                if (ping->y <= -760 + vitesse_verticale && ping->y >= -820 + vitesse_verticale)
                    ping->x--;

                vitesse_horizontale += vitesse;
                tempo_riviere = 0;
            } else
                tempo_riviere++;
            anim_pingouin(ping, &tempo_marche, vitesse_verticale);
            affiche_pingouin(ping, buffer);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }
        else {

            blit(ecranvictoire, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            draw_sprite(buffer, pingouinvictoire1, SCREEN_W / 2 - pingouinvictoire1->w / 2, 50);

            if(Fin == 0){
                fin = clock();
                Fin=1;
            }

            temp_final = (float) (fin - debut)/CLOCKS_PER_SEC;
            sprintf(string, "%.3f secondes", temp_final);
            textout_ex(buffer, font, string, 410, 440, makecol(0, 0, 0), -1);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            rest(1500);
            break;
        }
    }
    return temp_final;
}
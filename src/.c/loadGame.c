#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <allegro.h>
#include "../.h/fonction_project.h"

void display_all_save(char *filepath, BITMAP *buffer) // affiche toutes les sauvegardes enregistré
{
    DIR *dir = opendir(filepath); // le dossier demandé
    struct dirent *dp;
    short no_file = 0;
    int indexDisplay = 0;

    checkPtrNull(dir, "Exit Failure: Opening of save directory failed.");
    dp = readdir(dir); // lit le premier élément dans le dossier demandé

    while (dp != NULL) {
        if (dp->d_name[0] != '.') {
            textout_ex(buffer, font, dp->d_name, 230 + (indexDisplay % 3) * 150, 200 + (indexDisplay / 3) * 50, makecol(255, 255, 255), -1);
            no_file = 1;
            indexDisplay++;
        }
        dp = readdir(dir); // passe à l'élément suivant
    }
    closedir(dir);

    if (!no_file) // si aucune sauvegarde n'est trouvé
        textout_ex(buffer, font, "Aucunes sauvegardes enregistrées", 200, 200, makecol(255, 255, 255), -1);
}

void clearString(char *string, int n)
{
    for (int i = 0; i < n; i++)
        string[i] = '\0';
}

void loadGame(char entire_path[], t_joueur *joueur1, t_joueur *joueur2)
{
    BITMAP *load = load_bitmap("../image/image ecriture/load.bmp", NULL);
    struct stat st = {0};
    char *save_name = malloc(sizeof(char) * 30);
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int alreadyExist = 0;
    char keyPressed;
    int indexPath = 0;
    int keyAlreadyPress = 0;

    checkPtrNull(load, "Exit Failure: loading bitmap 'load' failed");
    clearString(save_name, 30);
    show_mouse(screen);
    while (1) {
        clear_bitmap(buffer);
        draw_sprite(buffer, load, 280, 30);
        textout_ex(buffer, font, "Parties disponible :", 320, 150, makecol(255, 255, 255), -1);
        display_all_save("../save/", buffer);

        keyPressed = detectKey();

        if (keyPressed > 0) {
            if (!keyAlreadyPress)
                keyAlreadyPress = 1;
        } else if (!keyPressed && keyAlreadyPress == 2) {
            keyAlreadyPress = 0;
        }

        if (keyAlreadyPress != 2) {
            if (keyPressed > 1) { // touche pressé
                save_name[indexPath] = keyPressed;
                if (indexPath + 1 != 30)
                    indexPath++;
            } else if (keyPressed == 1) { // si backspace pressé
                save_name[indexPath] = '\0';
                if (indexPath - 1 >= 0)
                    indexPath--;
                save_name[indexPath] = '\0';
            }
        }
        rect(buffer, 275, 495, 523, 515, makecol(255, 255, 255));
        textout_ex(buffer, font, save_name, 280, 500, makecol(255, 255, 255), -1);
        strcpy(entire_path, "../save/");
        strcat(entire_path, save_name);
        if (indexPath != 0 && stat(entire_path, &st) == -1) { // vérifie si la sauvegarde n'existe pas déjà
            textout_ex(buffer, font, "N'existe pas", 360, 450, makecol(255, 0, 0), -1);
        } else {
            if (indexPath != 0 && key[KEY_ENTER]) {
                FILE *fp = fopen(entire_path, "r");
                checkPtrNull(fp, "Exit Failure: opening save file failed");
                fread(joueur1, sizeof(t_joueur), 1, fp);
                fread(joueur2, sizeof(t_joueur), 1, fp);
                joueur1->loaded = 1;
                joueur2->loaded = 1;
                fclose(fp);
                free(save_name);
                destroy_bitmap(buffer);
                destroy_bitmap(load);
                return;
            }
        }

        if (keyAlreadyPress)
            keyAlreadyPress = 2;
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}

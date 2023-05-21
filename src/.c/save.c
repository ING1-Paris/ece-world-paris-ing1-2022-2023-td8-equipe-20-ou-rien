#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <allegro.h>
#include "../.h/fonction_project.h"

char detectKey(void)
{
    for (int i = 1; i < 27; i++)
        if (key[i])
            return i + 96;
    for (int i = 27; i < 37; i++)
        if (key[i])
            return i - 26 + 47;
    if (key[KEY_BACKSPACE])
        return 1;
    return 0;
}

void writeSave(char path[], t_joueur *joueur1, t_joueur *joueur2, int statSnake,float statFight,int statBallon, int fpsStat, int taupeStat, int riviereStat)
{
    FILE *fp = fopen(path, "w");

    checkPtrNull(fp, "Exit Failure: save file creation failed");

    fwrite(joueur1, sizeof(t_joueur), 1, fp);
    fwrite(joueur2, sizeof(t_joueur), 1, fp);
    fprintf(fp, "\n%d\n", statSnake);
    fprintf(fp, "%f\n", statFight);
    fprintf(fp, "%d\n", statBallon);
    fprintf(fp, "%d\n", fpsStat);
    fprintf(fp, "%d\n", taupeStat);
    fprintf(fp, "%d\n", riviereStat);
    fclose(fp);
}

void saveGame(char entire_path[], t_joueur *joueur1, t_joueur *joueur2, int statSnake,float statFight,int statBallon, int fpsStat, int taupeStat, int riviereStat) // créer le dossier de la sauvegarde voulu
{
    struct stat st = {0};
    char *save_name = malloc(sizeof(char) * 30);
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int alreadyExist = 0;
    char keyPressed;
    int indexPath = 0;
    int keyAlreadyPress = 0;
    BITMAP *save = load_bitmap("../image/image ecriture/save.bmp", NULL);

    checkPtrNull(save_name, "Exit Failure: malloc failed");
    checkPtrNull(save, "Exit Failure: loading bitmap 'save' failed");
    clearString(save_name, 30);
    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        draw_sprite(buffer, save, 280, 30);
        textout_ex(buffer, font, "Saisissez le nom de la sauvegarde:", 270, 300, makecol(255, 255, 255), -1);
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

        rect(buffer, 275, 345, 523, 365, makecol(255, 255, 255));
        textout_ex(buffer, font, save_name, 280, 350, makecol(255, 255, 255), -1);

        strcpy(entire_path, "../save/");
        strcat(entire_path, save_name);

        if (indexPath != 0 && stat(entire_path, &st) == -1) { // vérifie si la sauvegarde n'existe pas déjà
            if (key[KEY_ENTER]) {
                writeSave(entire_path, joueur1, joueur2, statSnake,statFight,statBallon, fpsStat, taupeStat, riviereStat);
                return;
            }
            alreadyExist = 0;
        } else {
            alreadyExist = 1;
        }

        if (alreadyExist && indexPath > 0)
            textout_ex(buffer, font, "existe déjà", 360, 400, makecol(255, 0, 0), -1);
        if (keyAlreadyPress)
            keyAlreadyPress = 2;

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    free(save_name);
    destroy_bitmap(buffer);
}
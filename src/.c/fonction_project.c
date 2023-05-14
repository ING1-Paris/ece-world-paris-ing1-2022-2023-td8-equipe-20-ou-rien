//
// Created by mathe on 24/04/2023.
//

#include "../.h/fonction_project.h"
#include "allegro.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
#define DEP 5

//gestion of menu

void fill_bitmap(BITMAP *bmp, int color,int posX,int posY) {

    for (posY=0; posY < bmp->h; posY++) {
        for (posX=0; posX < bmp->w; posX++) {
            if(getpixel(bmp,posX,posY)!= makecol(255,0,255))
            {
                putpixel(bmp, posX, posY, color);
            }
        }
    }
}
int cliqueSurMenu(BITMAP *PLAY)
{
    if((mouse_x>275&&mouse_x<275+PLAY->w)&&(mouse_y>310&&mouse_y<310+PLAY->h)&&mouse_b==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void animationDebut()
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *slogan= importeImage("../image/image utile/slogan 2.bmp");
    BITMAP *company= importeImage("../image/image utile/company project.bmp");
    BITMAP *Nom1= importeImage("../image/image ecriture/nom projet-1.bmp");
    BITMAP *Nom2= importeImage("../image/image ecriture/nom projet-2.bmp");
    BITMAP *Nom3= importeImage("../image/image ecriture/nom projet-3.bmp");
    BITMAP *Nom4= importeImage("../image/image ecriture/nom projet-4.bmp");
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    SAMPLE *sonfond= importeSon("../son/INTRO MATHEO.wav");
    clear_bitmap(buffer);
    play_sample(sonfond,255,128,1000,TRUE);
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(company, makecol(i,i,i),0,0);
        draw_sprite(buffer,company,0,0);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(slogan, makecol(i,i,i),0,0);
        draw_sprite(buffer,slogan,5,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom1, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom1,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom2, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom2,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom3, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom3,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    for(int i=0;i<255;i+=5)
    {
        clear_bitmap(buffer);
        fill_bitmap(Nom4, makecol(i,i,i),0,0);
        draw_sprite(buffer,Nom4,0,SCREEN_H/2-100);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(50);
    }
    stop_sample(sonfond);
    destroy_sample(sonfond);
    destroy_bitmap(slogan);
    destroy_bitmap(company);
    destroy_bitmap(Nom1);
    destroy_bitmap(Nom2);
    destroy_bitmap(Nom3);
    destroy_bitmap(Nom4);
}

void testAlphabet(BITMAP **EnsembleLettre,BITMAP *buffer)
{
    for(int i=0;i<27;i++)
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        draw_sprite(buffer,EnsembleLettre[i],SCREEN_W/2,SCREEN_H/2);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(1000);
    }
}
void testChiffre(BITMAP **EnsembleChiffre,BITMAP *buffer)
{
    for(int i=0;i<10;i++)
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        draw_sprite(buffer,EnsembleChiffre[i],SCREEN_W/2,SCREEN_H/2);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(1000);
    }
}

void menu(int *BoolMenu,int *BoolSettings, int *BoolPlay)
{
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char nomDeFichier[5000];
    int frame=1;
    int x=0;
    int y=0;
    BITMAP *fond[181];
    for(int i=1;i<180;i++)
    {
        sprintf(nomDeFichier,"../image/image fond menu/frame-%d.bmp",i);
        fond[i]= importeImage(nomDeFichier);
    }
    BITMAP *PLAY= importeImage("../image/image ecriture/PLAY.bmp");
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    SAMPLE *bruitVille= importeSon("../son/son bruit ville.wav");
    SAMPLE *bruitPluie= importeSon("../son/STORM_Pluie et orage.wav");
    SAMPLE *musiqueEasterEgg= importeSon("../son/son musique fond menu.wav");
    play_sample(bruitVille, 235, 128, 1000, TRUE);
    play_sample(bruitPluie,255,128,1000,TRUE);
    play_sample(musiqueEasterEgg,150,145,1000,TRUE);
    show_mouse(screen);
    while(!cliqueSurMenu(PLAY))
    {
        clear_bitmap(buffer);
        frame++;
        if(frame>179)
        {
            frame=1;
        }
        if((mouse_x>275&&mouse_x<275+PLAY->w)&&(mouse_y>310&&mouse_y<310+PLAY->h))
        {
            fill_bitmap(PLAY, makecol(255,0,0),0,0);
        }
        else
        {
            fill_bitmap(PLAY, makecol(255,255,255),0,0);
        }
        stretch_blit(fond[frame],buffer,0,0,fond[frame]->w,fond[frame]->h,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(buffer,PLAY,275,345);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(28);
    }
    stop_sample(bruitVille);
    stop_sample(bruitPluie);
    stop_sample(musiqueEasterEgg);
    destroy_sample(bruitVille);
    destroy_sample(bruitPluie);
    destroy_sample(musiqueEasterEgg);
    destroy_bitmap(PLAY);
    for(int i=1;i<180;i++)
    {
        destroy_bitmap(fond[i]);
    }
    *BoolPlay=1;
    *BoolMenu=0;
    *BoolSettings=0;
}

//player gestion and map gestion
void enregistrerNomJoueur(BITMAP**EnsembleLettre,BITMAP *buffer,char *NomJoueurARendre,int indice,BITMAP **EnsembleChiffre,BITMAP **fondNameSkin)
{
    int Bool=1;
    int framefond=1;
    char *tabNom= initTableauChar(25);
    char verifChar=0;
    int nbDansTab=0;
    while(!key[KEY_ENTER])
    {
        clear_bitmap(buffer);
        framefond++;
        if(framefond>47)
        {
            framefond=1;
        }
        stretch_blit(fondNameSkin[framefond],buffer,0,0,fondNameSkin[framefond]->w,fondNameSkin[framefond]->h,0,0,SCREEN_W,SCREEN_H);
        textout_ex(buffer,font,"veuillez donner un nom au joueur :",100,200, makecol(0,0,0),-1);
        draw_sprite(buffer,EnsembleChiffre[indice],400,150);
        if(key[KEY_DEL]&&nbDansTab!=0)
        {
            tabNom[nbDansTab]=0;
            nbDansTab--;
            rest(100);
        }
        if(keypressed())
        {
            verifChar=(char)readkey();
            if(verifChar>=97&&verifChar<=122||verifChar>='A'&&verifChar<='Z')
            {
                if(nbDansTab==0)
                {
                    tabNom= initTableauChar(25);
                }
                Bool=0;
                tabNom[nbDansTab]=(char)verifChar;
                nbDansTab++;
                if(nbDansTab>25)
                {
                    break;
                }
            }
        }
        for(int i=0;i<nbDansTab;i++)
        {
            if(tabNom[i]>=97&&tabNom[i]<=122)
            {
                draw_sprite(buffer,EnsembleLettre[(tabNom[i]-96)],i*100,400);
            }
            if(tabNom[i]>=65&&tabNom[i]<=90)
            {
                draw_sprite(buffer,EnsembleLettre[(tabNom[i]-64)],i*100,400);
            }
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(70);
    }
    strcpy(NomJoueurARendre,tabNom);
}

int chooseSkin(BITMAP *buffer,BITMAP **skinChoose1,BITMAP **skinChoose2,BITMAP **skinChoose3,BITMAP **EnsembleChiffre,BITMAP **fondNameSkin)
{
    int BoolSortie=0;
    int frame=1;
    int framefond=1;
    char *NomDeFichier=NULL;
    show_mouse(screen);
    while(1)
    {
        clear_bitmap(buffer);
        frame++;
        framefond++;
        if(framefond>47)
        {
            framefond=1;
        }
        if(frame>4)
        {
            frame=1;
        }
        stretch_blit(fondNameSkin[framefond],buffer,0,0,fondNameSkin[framefond]->w,fondNameSkin[framefond]->h,0,0,SCREEN_W,SCREEN_H);
        textout_ex(buffer,font,"Choisissez votre skin:",100,200, makecol(0,0,0),-1);
        if(mouse_x>100&&mouse_x<100+skinChoose1[frame]->w&&mouse_y>400&&mouse_y<400+skinChoose1[frame]->h)
        {
            rectfill(buffer,100,400,100+skinChoose1[frame]->w,400+skinChoose1[frame]->h, makecol(0,0,0));
            if(mouse_b==1)
            {
                return 1;
            }
        }
        if(mouse_x>300&&mouse_x<300+skinChoose2[frame]->w&&mouse_y>410&&mouse_y<410+skinChoose2[frame]->h)
        {
            rectfill(buffer,300,410,300+skinChoose2[frame]->w,410+skinChoose2[frame]->h, makecol(0,0,0));
            if(mouse_b==1)
            {
                return 2;
            }
        }
        if(mouse_x>500&&mouse_x<500+skinChoose3[frame]->w&&mouse_y>410&&mouse_y<410+skinChoose3[frame]->h)
        {
            rectfill(buffer,500,410,500+skinChoose2[frame]->w,410+skinChoose2[frame]->h, makecol(0,0,0));
            if(mouse_b==1)
            {
                return 3;
            }
        }
        draw_sprite(buffer,skinChoose1[frame],100,400);
        draw_sprite(buffer,skinChoose2[frame],300,410);
        draw_sprite(buffer,skinChoose3[frame],500,410);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(70);
    }
}

t_joueur *creerJoueur(BITMAP **EnsembleLettre,BITMAP * buffer,int indice,BITMAP **EnsembleChiffre,BITMAP **skinChoose1,BITMAP **skinChoose2,BITMAP **skinChoose3,BITMAP **fondNameSkin)
{
    t_joueur *joueurArendre= malloc(sizeof (t_joueur));
    joueurArendre->posX=0;
    joueurArendre->posY=0;
    joueurArendre->DepY=5;
    joueurArendre->depX=5;
    joueurArendre->indice=indice;
    joueurArendre->direction=1;
    joueurArendre->BoolMvmt=0;
    joueurArendre->BoolTour=0;
    enregistrerNomJoueur(EnsembleLettre,buffer,joueurArendre->nom,indice,EnsembleChiffre,fondNameSkin);
    while (joueurArendre->nom[0]==0)
    {
        enregistrerNomJoueur(EnsembleLettre,buffer,joueurArendre->nom,indice,EnsembleChiffre,fondNameSkin);
    }
    printf("%s\n",joueurArendre->nom);
    joueurArendre->skin=chooseSkin(buffer,skinChoose1,skinChoose2,skinChoose3,EnsembleChiffre,fondNameSkin);
    printf("%d\n",joueurArendre->skin);
    return joueurArendre;
}

t_train *creerTrain()
{
    t_train *TrainARendre= malloc(sizeof (t_train));
    TrainARendre->posY=160;
    TrainARendre->posX=-4000;
    TrainARendre->direction=1;
    TrainARendre->DepY=10;
    TrainARendre->depX=10;
    return TrainARendre;
}

void actualiserTrain(t_train *train)
{
    train->posX+=train->depX;
    if(train->posX>6000)
    {
        train->posX=-4000;
    }
}

int verifFinAnimationFin(t_joueur *joueur)
{
    if(joueur->posY<30)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int verfDebutAnimation(t_joueur *joueur)
{
    if(joueur->posY>SCREEN_H-60)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void actualiserMvmtJoueur(t_joueur *joueur)
{
    if(key[KEY_RIGHT])
    {
        joueur->posX+=joueur->depX;
        joueur->direction=1;
        joueur->BoolMvmt=1;
    }
    else if(key[KEY_LEFT])
    {
        joueur->posX-=joueur->depX;
        joueur->direction=2;
        joueur->BoolMvmt=1;
    }
    else if(key[KEY_DOWN])
    {
        joueur->posY+=joueur->DepY;
        joueur->direction=4;
        joueur->BoolMvmt=1;
    }
    else if(key[KEY_UP])
    {
        joueur->posY-=joueur->DepY;
        joueur->direction=3;
        joueur->BoolMvmt=1;
    }
    else
    {
        joueur->BoolMvmt=0;
    }

}

void drawJoueur(t_joueur *joueur,BITMAP *skin1MvmtDown[5],BITMAP *skin1MvmtUp[5],BITMAP *skin1MvmtCoter[5], BITMAP *skin2MvmtDown[5],BITMAP *skin2MvmtUp[5],BITMAP *skin2MvmtCoter[5],BITMAP *skin3MvmtDown[5],BITMAP *skin3MvmtUp[5],BITMAP *skin3MvmtCoter[5],BITMAP *buffer,int frame)
{
    //skin 1
    if(joueur->skin==1)
    {
        if(joueur->direction==1)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite_h_flip(buffer,skin1MvmtCoter[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1MvmtCoter[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==2)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin1MvmtCoter[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin1MvmtCoter[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==3)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin1MvmtUp[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin1MvmtUp[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==4)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin1MvmtDown[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin1MvmtDown[1],joueur->posX,joueur->posY);
            }

        }
    }
    //skin 2
    if(joueur->skin==2)
    {
        if(joueur->direction==1)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite_h_flip(buffer,skin2MvmtCoter[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2MvmtCoter[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==2)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin2MvmtCoter[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin2MvmtCoter[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==3)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin2MvmtUp[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin2MvmtUp[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==4)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin2MvmtDown[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin2MvmtDown[1],joueur->posX,joueur->posY);
            }

        }
    }
    if(joueur->skin==3)
    {
        if(joueur->direction==1)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite_h_flip(buffer,skin3MvmtCoter[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin3MvmtCoter[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==2)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin3MvmtCoter[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin3MvmtCoter[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==3)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin3MvmtUp[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin3MvmtUp[1],joueur->posX,joueur->posY);
            }

        }
        if(joueur->direction==4)
        {
            if(joueur->BoolMvmt)
            {
                draw_sprite(buffer,skin3MvmtDown[frame],joueur->posX,joueur->posY);
            }
            else
            {
                draw_sprite(buffer,skin3MvmtDown[1],joueur->posX,joueur->posY);
            }

        }
    }
}

void animationDebutMap(t_joueur *joueur1,t_joueur *joueur2,BITMAP *skin1MvmtDown[5],BITMAP *skin1MvmtUp[5],BITMAP *skin1MvmtCoter[5], BITMAP *skin2MvmtDown[5],BITMAP *skin2MvmtUp[5],BITMAP *skin2MvmtCoter[5],BITMAP *skin3MvmtDown[5],BITMAP *skin3MvmtUp[5],BITMAP *skin3MvmtCoter[5],BITMAP *buffer,int frame)
{
    t_train *train=creerTrain();
    if(joueur1->BoolTour==0)
    {
        joueur2->posY=SCREEN_H-50;
        joueur2->posX=380;
        joueur1->posY=SCREEN_H-30;
        joueur1->posX=380;
    }
    else
    {
        joueur1->posY=SCREEN_H-50;
        joueur1->posX=380;
        joueur2->posY=SCREEN_H-30;
        joueur2->posX=380;
    }

    joueur1->direction=3;
    joueur1->BoolMvmt=1;

    joueur2->direction=3;
    joueur2->BoolMvmt=1;
    //image pour la map
    int iteration=0;
    BITMAP *Train= importeImage("../image/image play map/animation debut/train/train.bmp");
    BITMAP *gare = importeImage("../image/image play map/animation debut/batiment sur train/gare.bmp");
    BITMAP *batimentSurTrain= importeImage("../image/image play map/animation debut/batiment sur train/batimentSurTrain.bmp");
    BITMAP *batiementSurJoueur= importeImage("../image/image play map/animation debut/batiement sur joueur/image pont.bmp");
    BITMAP *map= importeImage("../image/image play map/animation debut/map/map.bmp");
    while(1)
    {
        clear_bitmap(buffer);
        blit(map,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        if(iteration==6)
        {
            frame++;
            if(frame>4)
            {
                frame=1;
            }
            if(joueur1->BoolTour==0)
            {
                joueur2->posY-=joueur2->DepY;
            }
            else
            {
                joueur1->posY-=joueur1->DepY;
            }

        }
        if(joueur1->BoolTour==0)
        {
            joueur1->posX=joueur2->posX;
            joueur1->posY=joueur2->posY+30;
        }
        else
        {
            joueur2->posX=joueur1->posX;
            joueur2->posY=joueur1->posY+30;
        }
        if(joueur1->BoolTour)
        {
            drawJoueur(joueur1,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame);
            drawJoueur(joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame);
        }
        else
        {
            drawJoueur(joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame);
            drawJoueur(joueur1,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame);

        }
        actualiserTrain(train);
        draw_sprite(buffer,Train,train->posX,train->posY);
        draw_sprite(buffer,batimentSurTrain,601,100);
        draw_sprite(buffer,gare,287,132);
        draw_sprite(buffer,batiementSurJoueur,366,651);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        iteration+=1;
        iteration%=7;
        if(verifFinAnimationFin(joueur1))
        {
            break;
        }
        rest(10);
    }
    destroy_bitmap(Train);
    destroy_bitmap(gare);
    destroy_bitmap(batimentSurTrain);
    destroy_bitmap(batiementSurJoueur);
    destroy_bitmap(map);
}

int verifJoueurCollision(t_joueur *joueur,BITMAP *sousBuffer)
{
    if(joueur->direction==1)
    {
        if(getpixel(sousBuffer,joueur->posX+1+30,joueur->posY+40)!= makecol(255,0,255))
        {
            joueur->posX-=joueur->depX;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(joueur->direction==2)
    {
        if(getpixel(sousBuffer,joueur->posX-1,joueur->posY+40)!= makecol(255,0,255))
        {
            joueur->posX+=joueur->depX;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(joueur->direction==3)
    {
        if(getpixel(sousBuffer,joueur->posX,joueur->posY-1)!= makecol(255,0,255))
        {
            joueur->posY+=joueur->DepY;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(joueur->direction==4)
    {
        if(getpixel(sousBuffer,joueur->posX,joueur->posY+1+40)!= makecol(255,0,255))
        {
            joueur->posY-=joueur->DepY;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void snakeMap(t_joueur *joueur1,t_joueur *joueur2,BITMAP *skin1MvmtDown[5],BITMAP *skin1MvmtUp[5],BITMAP *skin1MvmtCoter[5], BITMAP *skin2MvmtDown[5],BITMAP *skin2MvmtUp[5],BITMAP *skin2MvmtCoter[5],BITMAP *skin3MvmtDown[5],BITMAP *skin3MvmtUp[5],BITMAP *skin3MvmtCoter[5],BITMAP *buffer,int frame,int *Map)
{
    if(*Map==-1)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=SCREEN_H-50;
            joueur1->posX=380;
            joueur2->posY=SCREEN_H-30;
            joueur2->posX=380;
        }
        else
        {
            joueur2->posY=SCREEN_H-50;
            joueur2->posX=380;
            joueur1->posY=SCREEN_H-30;
            joueur1->posX=380;
        }
        joueur1->direction=3;
        joueur2->direction=3;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    else if(*Map==0)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=70;
            joueur1->posX=380;
            joueur2->posY=50;
            joueur2->posX=380;
        }
        else
        {
            joueur2->posY=70;
            joueur2->posX=380;
            joueur1->posY=50;
            joueur1->posX=380;
        }
        joueur1->direction=4;
        joueur2->direction=4;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    int x=0,y=0;
    //image pour la map
    int iteration=0;
    BITMAP *map= importeImage("../image/image play map/snake/image map/map snake.bmp");
    BITMAP *sousMap= importeImage("../image/image play map/snake/image map/sous map snake.bmp");
    BITMAP *portailBas= importeImage("../image/image play map/snake/batiment/portailBas.bmp");
    BITMAP *mur= importeImage("../image/image play map/snake/batiment/mur.bmp");
    BITMAP *abreRanger= importeImage("../image/image play map/snake/batiment/arbreRanger.bmp");
    BITMAP *abreCarre= importeImage("../image/image play map/snake/batiment/arbreCarre.bmp");
    BITMAP *sousbuffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(1)
    {
        clear_bitmap(buffer);
        clear_bitmap(sousbuffer);
        blit(map, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(sousMap,sousbuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        if(iteration==6)
        {
            frame++;
            if(frame>4)
            {
                frame=1;
            }
            if(joueur1->BoolTour)
            {
                if(!verifJoueurCollision(joueur1,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur1);
                }
            }
            else
            {
                if(!verifJoueurCollision(joueur2,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur2);
                }
            }
        }
        if(joueur1->BoolTour)
        {
            if((joueur1->posX==625&&joueur1->posY==305))
            {
                textout_ex(buffer,font,"Entrer ?",625,295, makecol(255,0,0),-1);
                if(key[KEY_ENTER])
                {
                    Snake();
                }
            }
            if((joueur1->posX==150&&joueur1->posY==175))
            {
                textout_ex(buffer,font,"Entrer ?",150,165, makecol(255,0,0),-1);
                if(key[KEY_ENTER])
                {
                    FightPlay();
                }
            }
            if(verifFinAnimationFin(joueur1))
            {
                *Map=1;
                break;
            }

        }
        if(joueur2->BoolTour)
        {
            if((joueur2->posX==625&&joueur2->posY==305))
            {
                textout_ex(buffer,font,"Entrer ?",625,295, makecol(255,0,0),-1);
                if(key[KEY_ENTER])
                {
                    Snake();
                }
            }
            if((joueur2->posX==150&&joueur2->posY==175))
            {
                textout_ex(buffer,font,"Entrer ?",150,165, makecol(255,0,0),-1);
                if(key[KEY_ENTER])
                {
                    FightPlay();
                }
            }
            if(verifFinAnimationFin(joueur2))
            {
                *Map=1;
                break;
            }
        }
        if(joueur1->BoolTour)
        {
            drawJoueur(joueur1, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        else
        {
            drawJoueur(joueur2, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        rectfill(sousbuffer,joueur1->posX,joueur1->posY,joueur1->posX+30,joueur1->posY+40, makecol(255,0,0));
        draw_sprite(buffer,portailBas,371,763);
        draw_sprite(buffer,mur,0,213);
        draw_sprite(buffer,abreCarre,624,430);
        draw_sprite(buffer,abreRanger,410,0);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        iteration += 1;
        iteration %= 7;
        rest(10);
    }
    destroy_bitmap(portailBas);
    destroy_bitmap(map);
    destroy_bitmap(mur);
    destroy_bitmap(abreRanger);
    destroy_bitmap(abreCarre);
    destroy_bitmap(sousbuffer);
    destroy_bitmap(sousMap);
}

void BallonMap(t_joueur *joueur1,t_joueur *joueur2,BITMAP *skin1MvmtDown[5],BITMAP *skin1MvmtUp[5],BITMAP *skin1MvmtCoter[5], BITMAP *skin2MvmtDown[5],BITMAP *skin2MvmtUp[5],BITMAP *skin2MvmtCoter[5],BITMAP *skin3MvmtDown[5],BITMAP *skin3MvmtUp[5],BITMAP *skin3MvmtCoter[5],BITMAP *buffer,int frame,int *Map)
{
    if(*Map==2)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=SCREEN_H-80;
            joueur1->posX=380;
            joueur2->posY=SCREEN_H-80;
            joueur2->posX=380;
        }
        else
        {
            joueur2->posY=SCREEN_H-80;
            joueur2->posX=380;
            joueur1->posY=SCREEN_H-80;
            joueur1->posX=380;
        }
        joueur1->direction=3;
        joueur2->direction=3;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    else if(*Map==-3)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=70;
            joueur1->posX=380;
            joueur2->posY=50;
            joueur2->posX=380;
        }
        else
        {
            joueur2->posY=70;
            joueur2->posX=380;
            joueur1->posY=50;
            joueur1->posX=380;
        }
        joueur1->direction=4;
        joueur2->direction=4;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    int x=0,y=0;
    //image pour la map
    int iteration=0;
    BITMAP *map= importeImage("../image/image play map/image ballon/Map/mapJade.bmp");
    BITMAP *sousMap= importeImage("../image/image play map/image ballon/Map/sousMapJade.bmp");
    BITMAP *portailBas= importeImage("../image/image play map/snake/batiment/portailBas.bmp");
    BITMAP *sousbuffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(1)
    {
        clear_bitmap(buffer);
        clear_bitmap(sousbuffer);
        blit(map, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(sousMap,sousbuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        if(iteration==6)
        {
            frame++;
            if(frame>4)
            {
                frame=1;
            }
            if(joueur1->BoolTour)
            {
                if(!verifJoueurCollision(joueur1,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur1);
                }
            }
            else
            {
                if(!verifJoueurCollision(joueur2,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur2);
                }
            }
        }
        if(joueur1->BoolTour)
        {
            printf("%d %d\n",joueur1->posX,joueur1->posY);
            if((joueur1->posX==210&&joueur1->posY==330))
            {
                textout_ex(buffer,font,"Entrer ?",210,320, makecol(255,0,0),-1);
            }
            if((joueur1->posX==605&&joueur1->posY==70))
            {
                textout_ex(buffer,font,"Entrer ?",605,60, makecol(255,0,0),-1);
            }
            if(verifFinAnimationFin(joueur1))
            {
                *Map=3;
                break;
            }
            if(verfDebutAnimation(joueur1))
            {
                *Map=-2;
                break;
            }

        }
        if(joueur2->BoolTour)
        {
            printf("%d %d\n",joueur2->posX,joueur2->posY);
            if((joueur2->posX==210&&joueur2->posY==330))
            {
                textout_ex(buffer,font,"Entrer ?",210,320, makecol(255,0,0),-1);
            }
            if((joueur2->posX==605&&joueur2->posY==70))
            {
                textout_ex(buffer,font,"Entrer ?",605,60, makecol(255,0,0),-1);
            }
            if(verfDebutAnimation(joueur2))
            {
                *Map=-2;
                break;
            }
            if(verifFinAnimationFin(joueur2))
            {
                *Map=3;
                break;
            }
        }
        if(joueur1->BoolTour)
        {
            drawJoueur(joueur1, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        else
        {
            drawJoueur(joueur2, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        rectfill(sousbuffer,joueur1->posX,joueur1->posY,joueur1->posX+30,joueur1->posY+40, makecol(255,0,0));
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        iteration += 1;
        iteration %= 7;
        rest(10);
    }
    destroy_bitmap(portailBas);
    destroy_bitmap(map);
    destroy_bitmap(sousbuffer);
    destroy_bitmap(sousMap);
}


void ninjaMap(t_joueur *joueur1,t_joueur *joueur2,BITMAP *skin1MvmtDown[5],BITMAP *skin1MvmtUp[5],BITMAP *skin1MvmtCoter[5], BITMAP *skin2MvmtDown[5],BITMAP *skin2MvmtUp[5],BITMAP *skin2MvmtCoter[5],BITMAP *skin3MvmtDown[5],BITMAP *skin3MvmtUp[5],BITMAP *skin3MvmtCoter[5],BITMAP *buffer,int frame,int *Map)
{
    if(*Map==1)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=SCREEN_H-80;
            joueur1->posX=380;
            joueur2->posY=SCREEN_H-80;
            joueur2->posX=380;
        }
        else
        {
            joueur2->posY=SCREEN_H-80;
            joueur2->posX=380;
            joueur1->posY=SCREEN_H-80;
            joueur1->posX=380;
        }
        joueur1->direction=3;
        joueur2->direction=3;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    else if(*Map==-2)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=50;
            joueur1->posX=380;
            joueur2->posY=30;
            joueur2->posX=380;
        }
        else
        {
            joueur2->posY=50;
            joueur2->posX=380;
            joueur1->posY=30;
            joueur1->posX=380;
        }
        joueur1->direction=4;
        joueur2->direction=4;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    int x=0,y=0;
    //image pour la map
    int iteration=0;
    BITMAP *map= importeImage("../image/image play map/image ninja/image map/map.bmp");
    BITMAP *sousMap= importeImage("../image/image play map/image ninja/image map/sousMap.bmp");
    BITMAP *arbre= importeImage("../image/image play map/image ninja/batiment/abre1.bmp");
    BITMAP *sousbuffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(1)
    {
        clear_bitmap(buffer);
        clear_bitmap(sousbuffer);
        blit(map, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(sousMap,sousbuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        if(iteration==6)
        {
            frame++;
            if(frame>4)
            {
                frame=1;
            }
            if(joueur1->BoolTour)
            {
                if(!verifJoueurCollision(joueur1,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur1);
                }
            }
            else
            {
                if(!verifJoueurCollision(joueur2,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur2);
                }
            }
        }
        if(joueur1->BoolTour)
        {
            if((joueur1->posX==295&&joueur1->posY==440))
            {
                textout_ex(buffer,font,"Entrer ?",295,430, makecol(255,0,0),-1);
            }
            if((joueur1->posX==225&&joueur1->posY==135))
            {
                textout_ex(buffer,font,"Entrer ?",225,125, makecol(255,0,0),-1);
            }
            if(verfDebutAnimation(joueur1))
            {
                *Map=0;
                break;
            }
            if(verifFinAnimationFin(joueur1))
            {
                *Map=2;
                break;
            }

        }
        if(joueur2->BoolTour)
        {
            if((joueur2->posX==295&&joueur2->posY==440))
            {
                textout_ex(buffer,font,"Entrer ?",295,430, makecol(255,0,0),-1);
            }
            if((joueur2->posX==225&&joueur2->posY==135))
            {
                textout_ex(buffer,font,"Entrer ?",225,125, makecol(255,0,0),-1);
            }
            if(verfDebutAnimation(joueur2))
            {
                *Map=0;
                break;
            }
            if(verifFinAnimationFin(joueur2))
            {
                *Map=2;
                break;
            }
        }
        if(joueur1->BoolTour)
        {
            drawJoueur(joueur1, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        else
        {
            drawJoueur(joueur2, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        draw_sprite(buffer,arbre,39,193);
        rectfill(sousbuffer,joueur1->posX,joueur1->posY,joueur1->posX+30,joueur1->posY+40, makecol(255,0,0));
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        iteration += 1;
        iteration %= 7;
        rest(10);
    }
}


void RiviereMap(t_joueur *joueur1,t_joueur *joueur2,BITMAP *skin1MvmtDown[5],BITMAP *skin1MvmtUp[5],BITMAP *skin1MvmtCoter[5], BITMAP *skin2MvmtDown[5],BITMAP *skin2MvmtUp[5],BITMAP *skin2MvmtCoter[5],BITMAP *skin3MvmtDown[5],BITMAP *skin3MvmtUp[5],BITMAP *skin3MvmtCoter[5],BITMAP *buffer,int frame,int *Map)
{
    if(*Map==3)
    {
        if(joueur1->BoolTour)
        {
            joueur1->posY=SCREEN_H-80;
            joueur1->posX=390;
            joueur2->posY=SCREEN_H-80;
            joueur2->posX=390;
        }
        else
        {
            joueur2->posY=SCREEN_H-80;
            joueur2->posX=390;
            joueur1->posY=SCREEN_H-80;
            joueur1->posX=390;
        }
        joueur1->direction=3;
        joueur2->direction=3;
        joueur1->BoolMvmt=0;
        joueur2->BoolMvmt=0;
    }
    int x=0,y=0;
    //image pour la map
    int iteration=0;
    BITMAP *map= importeImage("../image/image play map/image riviere/maprobin.bmp");
    BITMAP *sousMap= importeImage("../image/image play map/image riviere/SousMap.bmp");
    BITMAP *portailBas= importeImage("../image/image play map/snake/batiment/portailBas.bmp");
    BITMAP *sousbuffer= create_bitmap(SCREEN_W,SCREEN_H);
    while(1)
    {
        clear_bitmap(buffer);
        clear_bitmap(sousbuffer);
        blit(map, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(sousMap,sousbuffer,0,0,0,0,SCREEN_W,SCREEN_H);
        if(iteration==6)
        {
            frame++;
            if(frame>4)
            {
                frame=1;
            }
            if(joueur1->BoolTour)
            {
                if(!verifJoueurCollision(joueur1,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur1);
                }
            }
            else
            {
                if(!verifJoueurCollision(joueur2,sousbuffer))
                {
                    actualiserMvmtJoueur(joueur2);
                }
            }
        }
        if(joueur1->BoolTour)
        {
            printf("%d %d\n",joueur1->posX,joueur1->posY);
            if((joueur1->posX==130&&joueur1->posY==325))
            {
                textout_ex(buffer,font,"Entrer ?",130,315, makecol(255,0,0),-1);
            }
            if(verifFinAnimationFin(joueur1))
            {
                textout_ex(buffer,font,"Quitter ?",455,10, makecol(255,0,0),-1);
            }
            if(verfDebutAnimation(joueur1))
            {
                *Map=-3;
                break;
            }

        }
        if(joueur2->BoolTour)
        {
            printf("%d %d\n",joueur2->posX,joueur2->posY);
            if((joueur2->posX==210&&joueur2->posY==330))
            {
                textout_ex(buffer,font,"Entrer ?",210,320, makecol(255,0,0),-1);
            }
            if((joueur2->posX==605&&joueur2->posY==70))
            {
                textout_ex(buffer,font,"Entrer ?",605,60, makecol(255,0,0),-1);
            }
            if(verfDebutAnimation(joueur2))
            {
                *Map=-3;
                break;
            }
            if(verifFinAnimationFin(joueur2))
            {
                textout_ex(buffer,font,"Quitter ?",455,10, makecol(255,0,0),-1);
            }
        }
        if(joueur1->BoolTour)
        {
            drawJoueur(joueur1, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        else
        {
            drawJoueur(joueur2, skin1MvmtDown, skin1MvmtUp, skin1MvmtCoter, skin2MvmtDown, skin2MvmtUp, skin2MvmtCoter,skin3MvmtDown, skin3MvmtUp, skin3MvmtCoter, buffer, frame);
        }
        rectfill(sousbuffer,joueur1->posX,joueur1->posY,joueur1->posX+30,joueur1->posY+40, makecol(255,0,0));
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        iteration += 1;
        iteration %= 7;
        rest(10);
    }
    destroy_bitmap(portailBas);
    destroy_bitmap(map);
    destroy_bitmap(sousbuffer);
    destroy_bitmap(sousMap);
}

int animationTourJoueur(BITMAP* buffer,BITMAP**EnsembleChiffre)
{
    int Bool=0;

    int TourJoueur;
    for(int i=0;i<100;i++)
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,SCREEN_W,SCREEN_H, makecol(255,255,255));
        textout_centre_ex(buffer,font,"Au tour du Joueur:",SCREEN_W/2-40,200, makecol(255,0,0),-1);
        if(i<75)
        {
            TourJoueur=rand()%2;
            if(Bool)
            {
                draw_sprite(buffer,EnsembleChiffre[2],SCREEN_W/2-40,400);
            }
            else
            {

                draw_sprite(buffer,EnsembleChiffre[1],SCREEN_W/2-40,400);
            }
            Bool++;
            Bool%=2;
        }
        else
        {
            if(TourJoueur)
            {
                draw_sprite(buffer,EnsembleChiffre[1],SCREEN_W/2-40,400);
            }
            else
            {
                draw_sprite(buffer,EnsembleChiffre[2],SCREEN_W/2-40,400);
            }
        }

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100);
    }
    return TourJoueur;
}


void playMap(int *BoolMenu, int *BoolSettings, int *BoolPlay)
{
    int Tour;
    int Map=3;
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,800,0,0)!=0)
    {
        allegro_message("problem gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char *NomDeFichier= malloc(sizeof (char ));

    //ecriture
    BITMAP *EnsembleLettre[27];
    BITMAP *EnsembleChiffre[11];
    for(int i=0;i<27;i++)
    {
        sprintf(NomDeFichier,"../image/image ecriture/alphabet/%d.bmp",i);
        EnsembleLettre[i]= importeImage(NomDeFichier);
    }
    for(int i=0;i<10;i++)
    {
        sprintf(NomDeFichier,"../image/image ecriture/chiffre/%d.bmp",i);
        EnsembleChiffre[i]= importeImage(NomDeFichier);
    }

    //skin 1
    BITMAP *Skin1Choose[5];
    BITMAP *skin1MvmtDown[5];
    BITMAP *skin1MvmtUp[5];
    BITMAP *skin1MvmtCoter[5];
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 1/moove down/frame-%d.bmp",i);
        skin1MvmtDown[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 1/moove up/frame-%d.bmp",i);
        skin1MvmtUp[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 1/moove coter/frame-%d.bmp",i);
        skin1MvmtCoter[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 1/choose skin/frame-%d.bmp",i);
        Skin1Choose[i]= importeImage(NomDeFichier);
    }

    //skin 2
    BITMAP *Skin2Choose[5];
    BITMAP *skin2MvmtDown[5];
    BITMAP *skin2MvmtUp[5];
    BITMAP *skin2MvmtCoter[5];
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 2/moove down/frame-%d.bmp",i);
        skin2MvmtDown[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 2/moove up/frame-%d.bmp",i);
        skin2MvmtUp[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 2/moove coter/frame-%d.bmp",i);
        skin2MvmtCoter[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 2/choose skin/frame-%d.bmp",i);
        Skin2Choose[i]= importeImage(NomDeFichier);
    }

    //skin 3
    BITMAP *Skin3Choose[5];
    BITMAP *skin3MvmtDown[5];
    BITMAP *skin3MvmtUp[5];
    BITMAP *skin3MvmtCoter[5];
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 3/moove down/frame-%d.bmp",i);
        skin3MvmtDown[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 3/moove up/frame-%d.bmp",i);
        skin3MvmtUp[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 3/moove coter/frame-%d.bmp",i);
        skin3MvmtCoter[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image personnage/skin 3/choose skin/frame-%d.bmp",i);
        Skin3Choose[i]= importeImage(NomDeFichier);
    }


    //image fond choose name and skin
    BITMAP *fondNameSkin[48];
    for(int i=1;i<48;i++)
    {
        sprintf(NomDeFichier,"../image/image play map/image fond choose skin and name/frame-%d.bmp",i);
        fondNameSkin[i]= importeImage(NomDeFichier);
    }

    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    //testAlphabet(EnsembleLettre,buffer);
    //testChiffre(EnsembleChiffre,buffer);
    t_joueur *joueur1= creerJoueur(EnsembleLettre,buffer,1,EnsembleChiffre,Skin1Choose,Skin2Choose,Skin3Choose,fondNameSkin);
    t_joueur *joueur2= creerJoueur(EnsembleLettre,buffer,2,EnsembleChiffre,Skin1Choose,Skin2Choose,Skin3Choose,fondNameSkin);

    int frame=1;
    Tour= animationTourJoueur(buffer,EnsembleChiffre);
    if(Tour)
    {
        joueur1->BoolTour=1;
        joueur2->BoolTour=0;
    }
    else
    {
        joueur2->BoolTour=1;
        joueur1->BoolTour=0;
    }
    //animationDebutMap(joueur1,joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame);
    while (!key[KEY_ESC])
    {
        if(Map==0||Map==-1)
        {
            snakeMap(joueur1,joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame,&Map);
        }
        else if(Map==1||Map==-2)
        {
            ninjaMap(joueur1,joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame,&Map);
        }
        else if(Map==2||Map==-3)
        {
            BallonMap(joueur1,joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame,&Map);
        }
        else if(Map==3)
        {
            RiviereMap(joueur1,joueur2,skin1MvmtDown,skin1MvmtUp,skin1MvmtCoter,skin2MvmtDown,skin2MvmtUp,skin2MvmtCoter,skin3MvmtDown,skin3MvmtUp,skin3MvmtCoter,buffer,frame,&Map);
        }
    }
    rest(500);
    *BoolPlay=0;
    *BoolMenu=1;
    *BoolSettings=0;
}


/*
 *   if(key[KEY_UP]){
            y--;
        }
        if(key[KEY_DOWN]){
            y++;
        }
        if(key[KEY_LEFT]){
            x--;
        }
        if(key[KEY_RIGHT]){
            x++;
        }
        printf("%d %d\n",x,y);
 */
//
// Created by mathe on 08/05/2023.
//

#include "../.h/fonction_game_fighter.h"
#include "time.h"
#define DEP 5

void destroyBitmapArray(BITMAP **bmp, int n, int start);

int chooseSkinFight(BITMAP *buffer,int indice)
{
    char NomDeFichier[100];
    BITMAP *chooseSkin1[8];
    int frame1=1,frame2=1;
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/chooseSkin/frame-%d.bmp",i);
        chooseSkin1[i]= importeImage(NomDeFichier);
    }
    BITMAP *chooseSkin2[9];
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/chooseSkin/frame-%d.bmp",i);
        chooseSkin2[i]= importeImage(NomDeFichier);
    }
    show_mouse(screen);
    while(1)
    {
        frame1++;
        frame2++;
        if(frame1>7)
        {
            frame1=1;
        }
        if(frame2>8)
        {
            frame2=1;
        }
        clear_bitmap(buffer);
        textout_ex(buffer,font,"Choisissez un skin pour le joueur: ",100,100, makecol(255,0,0),-1);
        if(indice==1)
        {
            textout_ex(buffer,font,"1",400,100, makecol(255,0,0),-1);
        }
        else
        {
            textout_ex(buffer,font,"2",400,100, makecol(255,0,0),-1);
        }
        if(mouse_x>0&&mouse_x<400)
        {
            rectfill(buffer,0,200,400,600, makecol(255,255,255));
            if(mouse_b==1)
            {
                destroyBitmapArray(chooseSkin1, 8, 1);
                destroyBitmapArray(chooseSkin2, 9, 1);
                return 1;
            }
        }
        if(mouse_x>400&&mouse_x<800)
        {
            rectfill(buffer,400,200,800,600, makecol(255,255,255));
            if(mouse_b==1)
            {
                destroyBitmapArray(chooseSkin1, 8, 1);
                destroyBitmapArray(chooseSkin2, 9, 1);
                return 2;
            }
        }
        draw_sprite(buffer,chooseSkin1[frame1],0,200);
        draw_sprite(buffer,chooseSkin2[frame2],400,200);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100);
    }
}

t_joueurFight *creerJoueurFight(int indice,BITMAP *buffer){

    t_joueurFight *JoueurAretourner= malloc(sizeof (t_joueurFight));
    JoueurAretourner->indice=indice;
    JoueurAretourner->BoolMvmt=0;
    JoueurAretourner->skin= chooseSkinFight(buffer,indice);
    if(indice==1)
    {
        JoueurAretourner->posX=0;
    }
    else
    {
        JoueurAretourner->posX=SCREEN_W-80;
    }
    JoueurAretourner->posY=SCREEN_H-200;
    JoueurAretourner->direction=1;
    JoueurAretourner->tx=80;
    JoueurAretourner->ty=80;
    JoueurAretourner->BoolTouche=0;
    JoueurAretourner->BoolJump=0;
    JoueurAretourner->nbVie=100;
    return JoueurAretourner;
}

void actualiserPosJoueur(t_joueurFight *Joueur)
{
        if(Joueur->BoolJump)
        {
            Joueur->posY-=3*DEP;
        }
        if(Joueur->BoolMvmt)
        {
            if(Joueur->direction==1)
            {
                Joueur->posX+=DEP;
            }
            else
            {
                Joueur->posX-=DEP;
            }
        }
}

int getGesture(t_joueurFight *Joueur)
{
    if(Joueur->indice==1)
    {
        if(key[KEY_D])
        {
            if(key[KEY_W])
            {
                Joueur->BoolJump=1;
                return 3;
            }
            Joueur->direction=1;
            Joueur->BoolMvmt=1;
            Joueur->BoolJump=0;
            return 1;
        }
        else if(key[KEY_A])
        {
            if(key[KEY_W])
            {
                Joueur->BoolJump=1;
                return 3;
            }
            Joueur->direction=0;
            Joueur->BoolMvmt=1;
            Joueur->BoolJump=0;
            return 2;
        }
        else if(key[KEY_W])
        {
            Joueur->BoolJump=1;
            return 3;
        }
        else if(key[KEY_F])
        {
            Joueur->BoolMvmt=0;
            return 4;
        }
        else if(key[KEY_T])
        {
            Joueur->BoolMvmt=0;
            return 5;
        }
        else if(key[KEY_Y])
        {
            Joueur->BoolMvmt=0;
            return 6;
        }
        else if(key[KEY_U])
        {
            Joueur->BoolMvmt=0;
            return 7;
        }
        else
        {
            Joueur->BoolMvmt=0;
            Joueur->BoolJump=0;
            return 0;
        }
    }
    if(Joueur->indice==2)
    {
        if(key[KEY_RIGHT])
        {
            if(key[KEY_UP])
            {
                Joueur->BoolJump=1;
                return 3;
            }
            Joueur->direction=1;
            Joueur->BoolMvmt=1;
            Joueur->BoolJump=0;
            return 1;
        }
        else if(key[KEY_LEFT])
        {
            if(key[KEY_UP])
            {
                Joueur->BoolJump=1;
                return 3;
            }
            Joueur->direction=0;
            Joueur->BoolMvmt=1;
            Joueur->BoolJump=0;
            return 2;
        }
        else if(key[KEY_UP])
        {
            Joueur->BoolJump=1;
            return 3;
        }
        else if(key[KEY_0_PAD])
        {
            Joueur->BoolMvmt=0;
            return 4;
        }
        else if(key[KEY_1_PAD])
        {
            Joueur->BoolMvmt=0;
            return 5;
        }
        else if(key[KEY_2_PAD])
        {
            Joueur->BoolMvmt=0;
            return 6;
        }
        else if(key[KEY_3_PAD])
        {
            Joueur->BoolMvmt=0;
            return 7;
        }
        else
        {
            Joueur->BoolMvmt=0;
            Joueur->BoolJump=0;
            return 0;
        }
    }
}

void animationVictoire(BITMAP *buffer,t_joueurFight *JoueurVictoire,float tempsRealise)
{
    for(int i=0;i<40;i++)
    {
        clear_bitmap(buffer);
        rectfill(buffer,0,0,0,0, makecol(255,255,255));
        textout_ex(buffer,font,"Le grand gagnant est le Joueur :",300,300, makecol(255,0,0),-1);
        textprintf_centre_ex(buffer,font,570,300, makecol(255,0,0),-1,"%d",JoueurVictoire->indice);
        textout_ex(buffer,font,"Avec un temps réalisé de  :",300,400, makecol(255,0,0),-1);
        textprintf_centre_ex(buffer,font,570,400, makecol(255,0,0),-1,"%f",tempsRealise);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(30);
    }
}

int verifJoueurToucher(t_joueurFight *joueur1, t_joueurFight *joueur2,int gesture)
{
    if(joueur1->skin==1)
    {
        if(gesture==1)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-50&&joueur1->posX<joueur2->posX+50&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
        if(gesture==2)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-100&&joueur1->posX<joueur2->posX+100&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
        if(gesture==3)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-250&&joueur1->posX<joueur2->posX+250&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
        if(gesture==4)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-100&&joueur1->posX<joueur2->posX+100&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
    }
    if(joueur1->skin==2)
    {
        if(gesture==1)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-50&&joueur1->posX<joueur2->posX+50&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
        if(gesture==2)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-100&&joueur1->posX<joueur2->posX+100&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
        if(gesture==3)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-250&&joueur1->posX<joueur2->posX+250&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
        if(gesture==4)
        {
            if((joueur1->direction==1 && (joueur1->posX < joueur2->posX)) || (joueur1->direction==0 && (joueur1->posX > joueur2->posX)))
            {
                if(joueur1->posX>joueur2->posX-250&&joueur1->posX<joueur2->posX+250&&joueur1->posY==joueur2->posY)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int drawCharge(t_joueurFight *joueurFight,BITMAP *buffer,BITMAP ** Skin1Charge,BITMAP ** Skin2Charge1,BITMAP ** Skin2Charge2,int gesture)
{
    if(joueurFight->skin==1)
    {
        if(joueurFight->direction==1)
        {
            for(int i=1;i<13;i++)
            {
                draw_sprite(buffer,Skin1Charge[i],joueurFight->posX+(i*20),joueurFight->posY);
            }
        }
        if(joueurFight->direction==0)
        {
            for(int i=1;i<13;i++)
            {
                draw_sprite_h_flip(buffer,Skin1Charge[i],joueurFight->posX-(i*20),joueurFight->posY);
            }
        }
    }
    if(joueurFight->skin==2)
    {
        if(gesture==1)
        {
            if(joueurFight->direction==1)
            {
                for(int i=1;i<13;i++)
                {
                    draw_sprite(buffer,Skin2Charge1[i],joueurFight->posX+(i*20),joueurFight->posY);
                }
            }
            if(joueurFight->direction==0)
            {
                for(int i=1;i<13;i++)
                {
                    draw_sprite_h_flip(buffer,Skin2Charge1[i],joueurFight->posX-(i*20),joueurFight->posY);
                }
            }
        }
        if(gesture==2)
        {
            if(joueurFight->direction==1)
            {
                for(int i=1;i<7;i++)
                {
                    draw_sprite(buffer,Skin2Charge2[i],joueurFight->posX+(i*30),joueurFight->posY+10);
                }
            }
            if(joueurFight->direction==0)
            {
                for(int i=1;i<7;i++)
                {
                    draw_sprite_h_flip(buffer,Skin2Charge2[i],joueurFight->posX-(i*30),joueurFight->posY+10);
                }
            }
        }

    }
}


void drawPlayer(t_joueurFight *Joueur,t_joueurFight *Joueur1,int *frame,
                SAMPLE *skin1Attack1Son,
                SAMPLE *skin1Attack2Son,
                SAMPLE *skin2Attack1Son,
                SAMPLE *skin2Attack2Son,
                SAMPLE *skin1Charge1Son,
                SAMPLE *skin1Charge2Son,
                SAMPLE *skin2Charge1Son,
                SAMPLE *skin2Charge2Son,
                BITMAP *buffer,
                BITMAP**skin1Attack1,
                BITMAP**skin1Attack2,
                BITMAP**skin1Charge,
                BITMAP**skin1Dead,
                BITMAP**skin1FireBall,
                BITMAP**skin1FlameJet,
                BITMAP**skin1Idle,
                BITMAP**skin1Jump,
                BITMAP**skin1Walk,
                BITMAP **skin2Attack1,
                BITMAP **skin2Attack2,
                BITMAP **skin2Charge1,
                BITMAP **skin2Charge2,
                BITMAP **skin2Dead,
                BITMAP **skin2Magic_arrow,
                BITMAP **skin2Magic_sphere,
                BITMAP **skin2Hurt,
                BITMAP **skin2Idle,
                BITMAP **skin2Jump,
                BITMAP **skin2Run,
                BITMAP **skin2Walk)
{

    if(Joueur->skin==1)
    {
        if(getGesture(Joueur)==0)
        {
            *frame+=1;
            if(*frame>7)
            {
                *frame=1;
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1Idle[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1Idle[*frame],Joueur->posX,Joueur->posY);
            }
        }
        else if(getGesture(Joueur)==1)
        {
            *frame+=1;
            if(*frame>6)
            {
                *frame=1;
            }
                draw_sprite(buffer,skin1Walk[*frame],Joueur->posX,Joueur->posY);

        }
        else if(getGesture(Joueur)==2)
        {
            *frame+=1;
            if(*frame>6)
            {
                *frame=1;
            }
            draw_sprite_h_flip(buffer,skin1Walk[*frame],Joueur->posX,Joueur->posY);
        }
        else if(getGesture(Joueur)==3)
        {
            *frame+=1;
            if(*frame>9)
            {
                *frame=1;
                Joueur->BoolJump=0;
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1Jump[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1Jump[*frame],Joueur->posX,Joueur->posY);
            }
        }
        else if(getGesture(Joueur)==4)
        {
            *frame+=1;
            if(*frame>4)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin1Attack1Son,255,128,1000,FALSE);
                if(verifJoueurToucher(Joueur,Joueur1,1)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=3;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=3;
                    }
                }
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1Attack1[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1Attack1[*frame],Joueur->posX,Joueur->posY);
            }
            rest(20);
        }
        else if(getGesture(Joueur)==5)
        {
            *frame+=1;
            if(*frame>4)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin1Attack2Son,255,128,1000,FALSE);
                if(verifJoueurToucher(Joueur,Joueur1,2)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=1;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=1;
                    }
                }
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1Attack2[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1Attack2[*frame],Joueur->posX,Joueur->posY);
            }
            rest(10);
        }
        else if(getGesture(Joueur)==6)
        {
            *frame+=1;

            if(*frame>8)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin1Charge1Son,255,128,1000,FALSE);
                drawCharge(Joueur,buffer,skin1Charge,skin2Charge1,skin2Charge2,1);
                if(verifJoueurToucher(Joueur,Joueur1,3)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=2;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=2;
                    }
                }
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1FireBall[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1FireBall[*frame],Joueur->posX,Joueur->posY);
            }
            rest(10);
        }
        else if(getGesture(Joueur)==7)
        {
            *frame+=1;
            if(*frame>7)
            {
                play_sample(skin1Charge2Son,255,128,1000,FALSE);
            }
            if(*frame>14)
            {
                *frame=1;
                Joueur->BoolJump=0;
                if(verifJoueurToucher(Joueur,Joueur1,4)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=5;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=5;
                    }
                }
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin1FlameJet[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin1FlameJet[*frame],Joueur->posX,Joueur->posY);
            }
            rest(10);
        }

    }
    if(Joueur->skin==2)
    {
        if(getGesture(Joueur)==0)
        {
            *frame+=1;
            if(*frame>8)
            {
                *frame=1;
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin2Idle[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2Idle[*frame],Joueur->posX,Joueur->posY);
            }
        }
        else if(getGesture(Joueur)==1)
        {
            *frame+=1;
            if(*frame>7)
            {
                *frame=1;
            }
            draw_sprite(buffer,skin2Walk[*frame],Joueur->posX,Joueur->posY);

        }
        else if(getGesture(Joueur)==2)
        {
            *frame+=1;
            if(*frame>7)
            {
                *frame=1;
            }
            draw_sprite_h_flip(buffer,skin2Walk[*frame],Joueur->posX,Joueur->posY);
        }
        else if(getGesture(Joueur)==3)
        {
            *frame+=1;
            if(*frame>8)
            {
                *frame=1;
                Joueur->BoolJump=0;
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin2Jump[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2Jump[*frame],Joueur->posX,Joueur->posY);
            }
        }
        else if(getGesture(Joueur)==4)
        {
            *frame+=1;
            if(*frame>7)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin2Attack1Son,255,128,1000,FALSE);
                if(verifJoueurToucher(Joueur,Joueur1,1)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=3;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=3;
                    }
                }
            }
            Joueur->posY-=20;
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin2Attack1[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2Attack1[*frame],Joueur->posX,Joueur->posY);
            }
            Joueur->posY+=20;
        }
        else if(getGesture(Joueur)==5)
        {
            *frame+=1;
            if(*frame>9)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin2Attack2Son,255,128,1000,FALSE);
                if(verifJoueurToucher(Joueur,Joueur1,2)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=1;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=1;
                    }
                }
            }
            Joueur->posY-=20;
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin2Attack2[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2Attack2[*frame],Joueur->posX,Joueur->posY);
            }
            Joueur->posY+=20;
        }
        else if(getGesture(Joueur)==6)
        {
            *frame+=1;
            if(*frame>6)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin2Charge1Son,255,128,1000,FALSE);
                drawCharge(Joueur,buffer,skin1Charge,skin2Charge1,skin2Charge2,2);
                if(verifJoueurToucher(Joueur,Joueur1,3)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=2;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=2;
                    }
                }
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin2Magic_arrow[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2Magic_arrow[*frame],Joueur->posX,Joueur->posY);
            }
            rest(10);
        }
        else if(getGesture(Joueur)==7)
        {
            *frame+=1;
            if(*frame>16)
            {
                *frame=1;
                Joueur->BoolJump=0;
                play_sample(skin2Charge2Son,255,128,1000,FALSE);
                drawCharge(Joueur,buffer,skin1Charge,skin2Charge1,skin2Charge2,1);
                if(verifJoueurToucher(Joueur,Joueur1,4)==1)
                {
                    if(Joueur->indice==1)
                    {
                        Joueur1->nbVie-=5;
                    }
                    if(Joueur->indice==2)
                    {
                        Joueur1->nbVie-=5;
                    }
                }
            }
            if(Joueur->direction==1)
            {
                draw_sprite(buffer,skin2Magic_sphere[*frame],Joueur->posX,Joueur->posY);
            }
            else
            {
                draw_sprite_h_flip(buffer,skin2Magic_sphere[*frame],Joueur->posX,Joueur->posY);
            }
            rest(10);
        }

    }

}

int verifGravite(t_joueurFight *joueurFight,BITMAP *buffer)
{
    if(getpixel(buffer,joueurFight->posX,joueurFight->posY+joueurFight->ty+1)!= makecol(255,0,255))
    {
        joueurFight->posY=490;
        return 1;
    }
    return 0;
}

int verifCollision(t_joueurFight *joueurFight,BITMAP *buffer)
{
    if(joueurFight->direction==1)
    {
        if(getpixel(buffer,joueurFight->posX+joueurFight->tx+1,joueurFight->posY)!= makecol(255,0,255))
        {
            return 1;
        }
    }
    else if(joueurFight->direction==0)
    {
        if(getpixel(buffer,joueurFight->posX-1,joueurFight->posY)!= makecol(255,0,255))
        {
            return 1;
        }
    }
    return 0;
}

int FightPlay(float *statARendre)
{
    char NomDeFichier[100];
    clock_t debut,fin;
    //skin1
    BITMAP *skin1Attack1[6];
    BITMAP *skin1Attack2[6];
    BITMAP *skin1Charge[14];
    BITMAP *skin1Dead[8];
    BITMAP *skin1Fireball[9];
    BITMAP *skin1FlameJet[16];
    BITMAP *skin1Hurt[4];
    BITMAP *skin1Idle[8];
    BITMAP *skin1Jump[10];
    BITMAP *skin1Run[9];
    BITMAP *skin1Walk[7];
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Attack1/frame-%d.bmp",i);
        skin1Attack1[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<5;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Attack2/frame-%d.bmp",i);
        skin1Attack2[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<13;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Charge/frame-%d.bmp",i);
        skin1Charge[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Dead/frame-%d.bmp",i);
        skin1Dead[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/Fireball/frame-%d.bmp",i);
        skin1Fireball[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<15;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/flame jet/frame-%d.bmp",i);
        skin1FlameJet[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<4;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/hurt/frame-%d.bmp",i);
        skin1Hurt[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/idle/frame-%d.bmp",i);
        skin1Idle[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<10;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/jump/frame-%d.bmp",i);
        skin1Jump[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/run/frame-%d.bmp",i);
        skin1Run[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin1/walk/frame-%d.bmp",i);
        skin1Walk[i]= importeImage(NomDeFichier);
    }

    //skin2
    BITMAP *skin2Attack1[8];
    BITMAP *skin2Attack2[10];
    BITMAP *skin2Charge1[13];
    BITMAP *skin2Charge2[7];
    BITMAP *skin2Dead[4];
    BITMAP *skin2Magic_arrow[7];
    BITMAP *skin2Magic_sphere[17];
    BITMAP *skin2Hurt[4];
    BITMAP *skin2Idle[9];
    BITMAP *skin2Jump[9];
    BITMAP *skin2Run[8];
    BITMAP *skin2Walk[8];
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Attack1/frame-%d.bmp",i);
        skin2Attack1[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<10;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Attack2/frame-%d.bmp",i);
        skin2Attack2[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<13;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Charge1/frame-%d.bmp",i);
        skin2Charge1[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Charge2/frame-%d.bmp",i);
        skin2Charge2[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<4;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Dead/frame-%d.bmp",i);
        skin2Dead[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<7;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Magic_arrow/frame-%d.bmp",i);
        skin2Magic_arrow[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<17;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/Magic_sphere/frame-%d.bmp",i);
        skin2Magic_sphere[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<4;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/hurt/frame-%d.bmp",i);
        skin2Hurt[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/idle/frame-%d.bmp",i);
        skin2Idle[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<9;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/jump/frame-%d.bmp",i);
        skin2Jump[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/run/frame-%d.bmp",i);
        skin2Run[i]= importeImage(NomDeFichier);
    }
    for(int i=1;i<8;i++)
    {
        sprintf(NomDeFichier,"../image/image fighter/skin2/walk/frame-%d.bmp",i);
        skin2Walk[i]= importeImage(NomDeFichier);
    }
    SAMPLE *bruitDeFond= importeSon("../son/sonFondFighter.wav");
    play_sample(bruitDeFond,200,128,1000,TRUE);
    BITMAP *buffer= create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *sousBuffer= create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *fondMap= importeImage("../image/image fighter/fond/fond map fighter.bmp");
    BITMAP *sousfondMap= importeImage("../image/image fighter/fond/sous map fighter.bmp");
    SAMPLE *skin1Charge1Son= importeSon("../son/skin1Charge1.wav");
    SAMPLE *skin1Charge2Son= importeSon("../son/skin1Charge2.wav");
    SAMPLE *skin2Charge2Son= importeSon("../son/skin2Charge2.wav");
    SAMPLE *skin2Charge1Son= importeSon("../son/son skin2 charge1.wav");
    SAMPLE *skin1Attack1Son= importeSon("../son/skin1Attack1.wav");
    SAMPLE *skin1Attack2Son= importeSon("../son/skin1Attack2.wav");
    SAMPLE *skin2Attack1Son= importeSon("../son/skin2Attack1.wav");
    SAMPLE *skin2Attack2Son= importeSon("../son/skin2Attack2.wav");
    t_joueurFight *Joueur1= creerJoueurFight(1,buffer);
    rest(100);
    t_joueurFight *Joueur2 = creerJoueurFight(2,buffer);
    int frame1=1;
    int frame2=1;
    float tempsRealise;
    int playerWin;
    debut=clock();
    while(1)
    {
        clear_bitmap(buffer);
        clear_bitmap(sousBuffer);
        stretch_blit(fondMap,buffer,0,0,fondMap->w,fondMap->h,0,0,SCREEN_W,SCREEN_H);
        stretch_blit(sousfondMap,sousBuffer,0,0,sousfondMap->w,sousfondMap->h,0,0,SCREEN_W,SCREEN_H);
        if(!verifGravite(Joueur1,sousBuffer))
        {
            Joueur1->posY+=2*DEP;
        }
        if(!verifGravite(Joueur2,sousBuffer))
        {
            Joueur2->posY+=2*DEP;
        }
        if(!verifCollision(Joueur1,sousBuffer))
        {
            actualiserPosJoueur(Joueur1);
        }
        if(!verifCollision(Joueur2,sousBuffer))
        {
            actualiserPosJoueur(Joueur2);
        }
        drawPlayer(Joueur1,Joueur2,&frame1,skin1Attack1Son,skin1Attack2Son,skin2Attack1Son,skin2Attack2Son,skin1Charge1Son,skin1Charge2Son,skin2Charge1Son,skin2Charge2Son,buffer,skin1Attack1,skin1Attack2,skin1Charge,skin1Dead,skin1Fireball,skin1FlameJet,skin1Idle,skin1Jump,skin1Walk,skin2Attack1,skin2Attack2,skin2Charge1,skin2Charge2,skin2Dead,skin2Magic_arrow,skin2Magic_sphere,skin2Hurt,skin2Idle,skin2Jump,skin2Run,skin2Walk);
        drawPlayer(Joueur2,Joueur1,&frame2,skin1Attack1Son,skin1Attack2Son,skin2Attack1Son,skin2Attack2Son,skin1Charge1Son,skin1Charge2Son,skin2Charge1Son,skin2Charge2Son,buffer,skin1Attack1,skin1Attack2,skin1Charge,skin1Dead,skin1Fireball,skin1FlameJet,skin1Idle,skin1Jump,skin1Walk,skin2Attack1,skin2Attack2,skin2Charge1,skin2Charge2,skin2Dead,skin2Magic_arrow,skin2Magic_sphere,skin2Hurt,skin2Idle,skin2Jump,skin2Run,skin2Walk);
        rectfill(sousBuffer,Joueur1->posX,Joueur1->posY,Joueur1->posX+Joueur1->tx,Joueur1->posY+Joueur1->ty, makecol(0,0,0));
        rectfill(sousBuffer,Joueur2->posX,Joueur2->posY,Joueur2->posX+Joueur1->tx,Joueur2->posY+Joueur2->ty, makecol(255,0,0));
        textout_ex(buffer,font,"Vie Joueur 1:",70,20, makecol(255,255,255),-1);
        textout_ex(buffer,font,"Vie Joueur 2:",500,20, makecol(255,255,255),-1);
        rectfill(buffer,200,10,200+Joueur1->nbVie,40, makecol(255,0,0));
        rectfill(buffer,630,10,630+Joueur2->nbVie,40, makecol(255,0,0));
        rect(buffer,200,10,300,40, makecol(0,0,0));
        rect(buffer,630,10,730,40, makecol(0,0,0));
        if(Joueur1->nbVie<0)
        {
            fin=clock();
            tempsRealise=(float )(fin-debut)/CLOCKS_PER_SEC;
            animationVictoire(buffer,Joueur2,tempsRealise);
            *statARendre=tempsRealise;
            stop_sample(bruitDeFond);
            playerWin = 2;
            break;
        }
        if(Joueur2->nbVie<0)
        {
            fin=clock();
            tempsRealise=(float )(fin-debut)/CLOCKS_PER_SEC;
            animationVictoire(buffer,Joueur1,tempsRealise);
            *statARendre=tempsRealise;
            stop_sample(bruitDeFond);
            playerWin = 1;
            break;
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(100);
    }
    destroy_sample(bruitDeFond);
    destroy_sample(skin1Charge1Son);
    destroy_sample(skin1Charge2Son);
    destroy_sample(skin2Charge2Son);
    destroy_sample(skin2Charge1Son);
    destroy_sample(skin1Attack1Son);
    destroy_sample(skin1Attack2Son);
    destroy_sample(skin2Attack1Son);
    destroy_sample(skin2Attack2Son);
    destroy_bitmap(buffer);
    destroy_bitmap(sousBuffer);
    destroy_bitmap(fondMap);
    destroy_bitmap(sousfondMap);
    destroyBitmapArray(skin2Attack1, 8, 1);
    destroyBitmapArray(skin2Attack2, 10, 1);
    destroyBitmapArray(skin2Charge1, 13, 1);
    destroyBitmapArray(skin2Charge2, 7, 1);
    destroyBitmapArray(skin2Dead, 4, 1);
    destroyBitmapArray(skin2Magic_arrow, 7, 1);
    destroyBitmapArray(skin2Magic_sphere, 17, 1);
    destroyBitmapArray(skin2Hurt, 4, 1);
    destroyBitmapArray(skin2Idle, 9, 1);
    destroyBitmapArray(skin2Jump, 9, 1);
    destroyBitmapArray(skin2Run, 8, 1);
    destroyBitmapArray(skin2Walk, 8, 1);
    free(Joueur1);
    free(Joueur2);
    destroyBitmapArray(skin1Attack1, 5, 1);
    destroyBitmapArray(skin1Attack2, 5, 1);
    destroyBitmapArray(skin1Charge, 13, 1);
    destroyBitmapArray(skin1Dead, 7, 1);
    destroyBitmapArray(skin1Fireball, 8, 1);
    destroyBitmapArray(skin1FlameJet, 15, 1);
    destroyBitmapArray(skin1Hurt, 3, 1);
    destroyBitmapArray(skin1Idle, 7, 1);
    destroyBitmapArray(skin1Jump, 9, 1);
    destroyBitmapArray(skin1Run, 8, 1);
    destroyBitmapArray(skin1Walk, 6, 1);
    return playerWin;
}
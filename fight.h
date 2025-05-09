#ifndef _FIGHT
#define _FIGHT
#include "head.h"
#include "personnages.h"
#define NAME 20

//
typedef struct{ //Equipe de 4 personnages
    Personnage tab[4];
}Equipe_quatre;

void fight(Equipe_quatre * equipea, Equipe_quatre * equipeb,SDL_Renderer *ren, Perso_select archive_etat, Game_state * etat, Perso_select selection, Game_state equipe, TTF_Font *font);
int verification(Equipe_quatre a);
int randtc();

typedef enum{
    Slt_atk,
    Slt_Adversaire,
    Slt_Fight,
}Fight_state;

#endif
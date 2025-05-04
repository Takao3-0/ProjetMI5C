#ifndef _FIGHT
#define _FIGHT
#include "head.h"
#include "personnages.h"
#define NAME 20

//
typedef struct{ //Equipe de 4 personnages
    Personnage tab[4];
}Equipe_quatre;

void fight(Equipe_quatre * equipea, Equipe_quatre * equipeb);
int verification(Equipe_quatre a);
int randtc();

#endif
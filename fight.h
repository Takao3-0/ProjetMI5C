#ifndef FIGHT_H
#define FIGHT_H
#include "head.h"
#include "personnages.h"
#define NAME 20

//
typedef struct{ //Equipe de 4 personnages
    Personnage tab[4];
    char name[NAME];
}Equipe_quatre;

typedef struct{ //Equipe de 2 personnages seulement pour la version d'essais du programme, supprimé en version final.
    Personnage tab[2];
    char name[NAME];
}Equipe_deux;

void fight(Equipe_quatre * equipea, Equipe_quatre * equipeb);

#endif
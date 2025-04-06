#include "head.h"
#ifndef PERSONNAGES_H
#define SIZE 40

typedef struct {
    char nom[SIZE];  //Nom de la capacité
    char description[SIZE]; //Description de la capacité
    int damage; //exprimé en % 
    int type; //type de la capacité
    int cd; //cooldown
}Capa;

typedef struct {
    char name[SIZE]; //nom de personnage
    int pv; //pv du personnages
    int pvmax; //pv maximum (pour limiter en cas de soins)
    int atk; //atk du personnage (elle est fixe) mais c'est pas elle qui determine les dégats infligé
    int def; //defense du personnage
    int tc; //taux critique du personnage (exprimé en %)
    int dc; //multiplicateur de degat en cas de coup critique (en %)
    Capa listedescapacites[4]; //les capacites du perso
}Personnage;

#endif



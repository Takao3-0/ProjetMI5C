#ifndef PERSONNAGES_H
#define PERSONNAGES_H
#include "head.h"
#define PERSONNAGEQ 15 //nombre de personnage dans le jeu

#define COMPO 40

typedef struct {
    char nom[COMPO];  // Nom de la capacité
    char description[COMPO]; // Description de la capacité
    int damage; // Exprimé en %
    int type; // Type de la capacité
    int cd; // Cooldown
} Capa;

typedef struct {
    char name[COMPO]; // Nom du personnage
    int pv; // PV du personnage
    int pvmax; // PV maximum (pour limiter en cas de soins)
    int atk; // Attaque du personnage (fixe)
    int def; // Défense du personnage
    int tc; // Taux critique (exprimé en %)
    int dc; // Multiplicateur de dégât en cas de coup critique (exprimé en %)
    int type; //Type élémentaire par lequel le personnage actuel est appliqué
    int rarete; //rareté du personnage 4 étoiles ou 5 étoiles 
    Capa listedescapacites[4]; // Les capacités du perso
} Personnage;

Personnage * extract(void);

#endif




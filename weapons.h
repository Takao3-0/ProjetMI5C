#ifndef WEAPONS_H
#define WEAPONS_H
#include "head.h"
#include "personnages.h"
#include "createursquad.h"
#define ARMEQ 7


//Les substats sont donné sous forme de %
typedef struct{
    int pv; // PV du personnage
    int atk; // Attaque du personnage (fixe)
    int def; // Défense du personnage
    int tc; // Taux critique (exprimé en %)
    int dc; // Multiplicateur de dégât en cas de coup critique (exprimé en %)
}Substat_w;

typedef struct{
    char name[35];
    int attaque;
    Substat_w substat_w;
    int type; //correspond au type d'arme (lance épee etc...)
}Weapons;

Weapons * extract_weapons(void);

#endif

/*
Fonctionnement des substat : 
    Elle vaudrons toutes 0 saus 1 qui aura une valeur. Une fois l'arme attaché a un personnage,
    les statistiques de ce dernier prendrons en compte ses statistique + celle de l'arme. Il aura
    donc un bonus de degat + un bonus sur une stat. selon l'arme.
*/
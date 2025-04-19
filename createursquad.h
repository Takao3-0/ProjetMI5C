#ifndef CREATEURSQUAD_H
#define CREATEURSQUAD_H
#include "head.h"
#include "personnages.h"
#include "fight.h"
#define SQUADASSEMBLEUR 4 //Constante pour le nombre de personnage dans l'équipe


Equipe_deux * assembleur_squad_deux(Personnage * tablist, int num);
Equipe_quatre * assembleur_squad_quatre(Personnage *tablist, int num);


#endif
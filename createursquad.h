#ifndef _CREATEURSQUAD
#define _CREATEURSQUAD
#include "head.h"
#include "personnages.h"
#include "fight.h"
#define SQUADASSEMBLEUR 4 //Constante pour le nombre de personnage dans l'équipe


void Assembleur_equipe(Equipe_quatre *equipea, Personnage *tablist, Game_state *etat, Perso_select *archive_etat, Position pos, SDL_Event e, Game_state *equipe);


#endif
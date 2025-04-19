#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "head.h"
#include "personnages.h"
#include "createursquad.h"

#define SIZELINE 148

void mainscreen();
void selectplayer(Personnage *tabperso);
void selectname(int num);
void selectplayerv2(Personnage * tablist2, int num, Equipe_quatre * a);
void secondscreen();
void mainscreenerror();
void screenerror();
void procedure_mere_affichage_fight(Equipe_quatre *a, Equipe_quatre *b, int tour, Personnage *attaquant, Personnage *defenseur, int atk, int crit, int degat, int cle, int elmt, int react);
void affichage_element(Personnage *defenseur,int degat, int elmt);


#endif
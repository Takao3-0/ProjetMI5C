#ifndef _AFFICHAGE
#define _AFFICHAGE

#include "head.h"
#include "textures.h"
#include "createursquad.h"

void affichage(SDL_Renderer *ren, Perso_select archive_etat, Game_state * etat, Perso_select selection, Equipe_quatre equipea, Game_state equipe, TTF_Font *font);
void affichage_attaque(Personnage attaquant, SDL_Renderer *ren, TTF_Font *font);
void affichage_fight(SDL_Renderer *ren, Game_state * etat, Equipe_quatre atk, Equipe_quatre def, Game_state equipe, TTF_Font *font, Personnage attaquant, int tour);
void convert_texte(const char *texte, TTF_Font *font, SDL_Renderer *ren, int x, int y);


#endif

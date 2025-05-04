#ifndef _HEAD
#define _HEAD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>

//Importation des couleurs 

#define ROUGE "\033[31m"
#define VERT "\033[32m"
#define JAUNE "\033[33m"
#define BLEU "\033[34m"
#define RESET "\033[0m"
#define ROSE "\x1b[38;5;201m"
#define VIOLET "\x1b[38;5;135m"
#define ORANGE "\x1b[38;5;208m"
#define BLEUC "\x1b[38;5;117m"
#define BLEUF "\x1b[38;5;19m"


//Couleur pour le dégrade
#define ORANGE_CLAIR      "\x1b[38;5;214m"
#define ORANGE_TRES_CLAIR "\x1b[38;5;220m"
#define BLEU_CLAIR         "\x1b[38;5;123m"
#define BLEU_CLAIR2        "\x1b[38;5;147m"
#define VIOLET_CLAIR       "\x1b[38;5;177m"
#define VIOLET_CLAIR2      "\x1b[38;5;141m"
#define VIOLET_TRES_CLAIR    "\x1b[38;5;183m"

//Etat de jeux
typedef enum {
    MENU,   // écran de base
    MENUP,  // écran principal du jeux (l'image sera à modifier (ajouter des elmts))
    FIN,
    ARCHIVE,
    EQUIPE,
    SELECTION,
} Game_state;

typedef enum {
    VIDE,
    CRIONA,
    GLACIUS,
    TERROREX,
    VULCAIN,
    CALYRA,
    AQUALIS,
    NOVA,
    ARCANISTE,
    VOLTIX,
    IRONAPSOL,
} Perso_select;

typedef enum {
    P1,
    P2,
    P3,
    P4,
} Position;

typedef struct {
    const char  *name;      // par exemple "Criona"
    SDL_Texture *tex;       // la texture chargée
} Perso;

// une « slot » à l’écran
typedef struct {
    int x;  // position du coin supérieur gauche
    int y;     
    int w; 
    int h;     
} Slot;


#endif

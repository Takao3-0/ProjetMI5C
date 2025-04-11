#include "head.h"
#define NAMESTAT 20

typedef struct {
    char name_stat[NAMESTAT];
    int id; //identifiant de la statistique.
    int value;    
}Mainstat;

typedef struct {
    char name_stat[NAMESTAT];
    int id; //identifiant de la statistique.
    int value;    
}Substat;

typedef struct {
    int type;
    Mainstat mainstat;
    Substat tabsubstat[4];
} artefact;


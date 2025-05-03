#ifndef ASSEMBLEURBOSS_H
#define ASSEMBLEURBOSS_H

#include "head.h"
#include "fightboss.h"
#include "personnages.h"
#include "createursquad.h"
#define LVLQ 2

typedef struct{
    int name;
    int id_adversaire;
    int r1;
    int r2;
}Boss_config;

typedef struct{
    Boss_config Config;
    Equipe_quatre equipe;
    Boss boss;
}Assemblage;
#endif 
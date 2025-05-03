#ifndef FIGHTBOSS_H
#define FIGHTBOOS_H

#include "head.h"
#include "personnages.h"
#include "key.h"
#include "createursquad.h"
#include "fight.h"
#include "assembleurboss.h"
#define BOSSQ 5

typedef struct{
    char name[20];
    int damage;
    int type;
    int cd;
    int cd_init;
}Capacite;

typedef struct{
    char name[20];
    int pv;
    int attaque;
    int defense;
    int type;
    int identifiant;
    Capacite listecb[4];
}Boss;


Boss * extract_boss(void);
Config_lvl * extract_lvl(void);
void fight_boss(Boss * atboss, Config_lvl * configlvl, Equipe_quatre * equipe);

#endif
#include "fightboss.h"


int verification_type2(Personnage * attaquant, Boss *defenseur, int capa, int * degat);

int damage1(Personnage attaquant, Boss * defenseur,int capa, int *crit, int *elmt){ 
    int critique = randtc(); 
    int degats = 0;  //Dégats réelement infligés.
    if (critique <= attaquant.tc){ //Cas ou l'attaquant effectue un coup critique.
        printf(ROSE"COUP CRITIQUE!\n"RESET);
        degats = (((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->defense))*(attaquant.dc/100.0);
        printf("Les degats avant verification elementaire sont : %d\n",degats);
        *elmt = verification_type2(&attaquant, defenseur, capa,&degats);
        if (*elmt == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
            printf(ORANGE"Le type de %s est alors %d"RESET,defenseur->name, defenseur->type);
        }
        *crit = 1;
    } else {
        degats = ((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->defense);
        printf("Les degats avant verification elementaire sont : %d\n",degats);
        *elmt = verification_type2(&attaquant, defenseur, capa, &degats);
        if (*elmt == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
            printf(ORANGE"Le type de %s, est alors %d"RESET,defenseur->name, defenseur->type);
        }
        *crit = 0;
    }
    return degats; //On return de force un entier, plus simple de travailler avec des entier dans le contexte du jeu.
}

int verification_type2(Personnage * attaquant, Boss *defenseur, int capa, int * degat){ //on supprime la partie décimale de façon a avoir une meilleur expérience de jeu
    int somme = attaquant->listedescapacites[capa].type + defenseur->type;
    printf("    La reaction elementaire est d'identifiant %d\n"
    "    Les degats pris en compte sont %d\n"
    ROUGE"   Somme a pris en parametre : %d + %d\n"RESET
    ,somme, *degat,attaquant->listedescapacites[capa].type, defenseur->type);
    switch (somme){
        case 11:
            printf(ORANGE"EVAPORATION\n"RESET); //Hydro + Pyro
            defenseur->type = 0;
            * degat *= 1.5;
            return 11;
        case 110:
            printf(ORANGE"SURGARGE\n"RESET); //Pyro + Electro
            defenseur->type = 0;
            * degat *= 1.3;
            return 110;
        case 101:
            printf(VIOLET"ELECTROCUTION\n"RESET); //Electro + Hydro
            defenseur->type = 0;
            * degat *= 1.5;
            return 101;
        case 1010:
            printf(BLEUC"FONTE\n"RESET); //Pyro + Cryo
            defenseur->type = 0;
            * degat *= 2;
            return 1010;
        case 1001:
            printf(BLEUF"GEL"RESET); //Cryo + Hydro
            defenseur->type = 0;
            return 1001;
        case 1100:
            printf(VIOLET"SUPRACONDUCTION\n"RESET); //Electro + Cryo
            defenseur->type = 0;
            * degat *= 1.3;
            return 1100;
        default:
            printf(BLEU"Pas de reaction elementaire qu'un seul élément est actif.\n"RESET);
            return 0;
    }
}


Boss * extract_boss(void){
    FILE * fic=NULL;
    fic=fopen("boss.txt", "r");
    Boss * listeboss = malloc(BOSSQ * sizeof(Boss));
    if (fic!=NULL){
        Boss boss;
        char chaine[60];
        for (int i=0; i<BOSSQ; i++){
            if(fgets(chaine,50,fic)!= NULL){
                printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d;%d;%d", 
                boss.name,
                &boss.attaque,
                &boss.defense,
                &boss.type,
                &boss.identifiant);
            printf("Nom du boss : %s\n", boss.name);  //à terme ces printfs disparaiterons.
            printf("Attaque de base du boss : %d\n", boss.attaque); 
            printf("Défense du boss : %d\n", boss.defense); 
            for (int j=0;j<4;j++){
                fgets(chaine,60,fic);
                printf(VIOLET"%s\n"RESET,chaine);
                sscanf(chaine, "%[^;];%d;%d;%d",
                    boss.listecb[j].name,
                    &boss.listecb[j].damage,
                    &boss.listecb[j].type,
                    &boss.listecb[j].cd_init);
                printf(ROUGE"Capacité numéro %d:\n"RESET  //à terme ce printf disparaitera.
                    "NAME : %s\n"
                    "DMG : %d\n"
                    "TYPE : %d\n"
                    "CD : %d\n",
                    j+1,
                    boss.listecb[j].name,
                    boss.listecb[j].damage,
                    boss.listecb[j].type,
                    boss.listecb[j].cd_init);
            }    
            fgets(chaine,50,fic);
            listeboss[i] = boss;
        }
        fclose(fic);
        return listeboss;
    } else {
        printf("Echec d'ouverture\n");
    }
    return 0;
}


void general_fight(Personnage * attaquant, Boss * defenseur){
    int atk=0;
    printf("Quelle attaque utiliser parmi la liste suivante ?\n");
    for (int i=0;i<4;i++){
        printf("%s",attaquant->listedescapacites[i].nom);
    }
    do {
        atk = better_scan_int(1,4);
    } while (atk == 0);
    printf("Attaque selectionné %s", attaquant->listedescapacites[atk-1].nom);
    int dmg = damage1(*attaquant,defenseur,atk,0,0);
    defenseur->pv -= dmg;
    printf("%s se voit infligé %d pv, il a donc %d pv\n",defenseur->name, dmg, defenseur->pv);
    

}


void fight_boss(Boss * atboss, Equipe_quatre * equipe){
    int lvl = selectlvl(); //lvl correspond à l'identifiant du niveau
    int cible = 0;
    int damage = 0;
    int compteur_de_tour = 1;
    do {
        if (compteur_de_tour % 2 == 0){ //Equipe joueur qui attaque (l'équipe joueur attaque en premier)
            //utilisation d'une fonction 'fight' générale à tout les tour d'équipe.

        } else { //Le bot qui joue
            int adversaire = 0;
            int attaque = 0;
            int scoredmg = 0;
            int scorehp = 10000;
            int dmg;
            for (int i=0; i<4; i++){
                int scoretemp = equipe->tab[i].atk * (1.0 + (equipe->tab[i].tc / 100.0) * ((equipe->tab[i].dc / 100.0) - 1.0));
                printf(VERT"DPS moyen de %s : %d\n"RESET,equipe->tab[i].name,scoretemp);
                if (scoretemp > scoredmg){
                    scoredmg = scoretemp;
                    adversaire = i; 
                }
            }
            printf("Adversaire sélectionné : %s, avec un dps moyen de %d\n",equipe->tab[adversaire].name,scoredmg);
            for (int j=0; j<4; j++){
                if (atboss->listecb[j].cd == 0){ //Donc on peut utiliser cette capacité
                    damage = ((atboss->attaque*atboss->listecb[j].damage) * atboss->attaque) / (atboss->attaque + equipe->tab[adversaire].def);
                    int scoretemp = equipe->tab[adversaire].pv / damage; //correspond au nombre de coup qu'il faut pour le tuer 
                    printf("Il faut %d tour pour tuer %s avec l'attaque %s\n",scoretemp, equipe->tab[adversaire].name, atboss->listecb[j].name);
                    if (scorehp > scoretemp ){
                        scorehp = scoretemp;
                        attaque = j;  
                    }
                }
            }
            printf("Attaque retenue %s, avec score de %d\n",atboss->listecb[attaque].name, scorehp);
            equipe->tab[adversaire].pv -= ((atboss->attaque*atboss->listecb[attaque].damage) * atboss->attaque) / (atboss->attaque + equipe->tab[adversaire].def);
            printf("%s a donc %d pv", equipe->tab[adversaire].name, equipe->tab[adversaire].pv);  
        }

    } while (verification(*equipe) != 4);



}
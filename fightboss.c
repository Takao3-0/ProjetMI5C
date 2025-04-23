#include "fightboss.h"
#define LVLQ 2


Boss * extract_boss(void){
    FILE * fic=NULL;
    fic=fopen("boss.txt", "r");
    Boss * listeboss = malloc(BOSSQ * sizeof(Boss));
    if (fic!=NULL){
        Boss boss;
        char chaine[60];
        for (int i=0; i<BOSSQ; i++){
            if(fgets(chaine,50,fic)!= NULL){
                //printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d;%d;%d", 
                boss.name,
                &boss.attaque,
                &boss.defense,
                &boss.type,
                &boss.identifiant);
            printf("Nom recupere : %s\n", boss.name);  //à terme ces printfs disparaiterons.
            printf("Attaque de base de l'arme : %d\n", boss.attaque); 
            printf("Type d'arme : %d\n", boss.defense); 
            for (int j=0;j<4;j++){
                fgets(chaine,60,fic);
                //printf(VIOLET"%s\n"RESET,chaine);
                sscanf(chaine, "%[^;];%d;%d;%d",
                    boss.listecb[j].name,
                    &boss.listecb[j].damage,
                    &boss.listecb[j].type,
                    &boss.listecb[j].cd_init);
                printf(ROUGE"Substat arme:\n"RESET  //à terme ce printf disparaitera.
                    "PV : %d\n"
                    "ATK : %d\n"
                    "DEF : %d\n"
                    "TC : %d\n"
                    "DC : %d\n",
                    boss.listecb[j].name,
                    &boss.listecb[j].damage,
                    &boss.listecb[j].type);
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

int selectlvl(){
    int lvl;
    do {
        lvl = better_scan_int(1,9);    
    } while (lvl == 0);
    return lvl;
}

typedef struct{
    char name; //nom u level ???
    int id_lvl;
    int id_adversaire;
    int r1;  //récompense n°1 et 2
    int r2;
} Config_lvl;

Config_lvl * extract_lvl(){
    FILE * fic=NULL;
    fic=fopen("lvlboss.txt", "r");
    Config_lvl * configlvl = malloc(LVLQ * sizeof(Config_lvl));
    if (fic!=NULL){
        Config_lvl lvl;
        char chaine[60];
        for (int i=0; i<LVLQ; i++){
            if(fgets(chaine,50,fic)!= NULL){
                //printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d;%d;%d", 
                lvl.name,
                &lvl.id_lvl,
                &lvl.id_adversaire,
                &lvl.r1,
                &lvl.r2);
            /*printf("Nom recupere : %s\n", boss.name);  //à terme ces printfs disparaiterons.
            printf("Attaque de base de l'arme : %d\n", boss.attaque); 
            printf("Type d'arme : %d\n", boss.defense); */  
            fgets(chaine,50,fic);
            configlvl[i] = lvl;
        }
        fclose(fic);
        return configlvl;
    } else {
        printf("Echec d'ouverture\n");
    }
    return 0;
}

int select_cible(Equipe_quatre *cible){

}


void fight_boss(Boss * atboss, Config_lvl * configlvl, Equipe_quatre * equipe){
    int lvl = selectlvl(); //lvl correspond à l'identifiant du niveau
    int cible = 0;
    int damage = 0;
    Config_lvl lvlselect = configlvl[lvl];
    int compteur_de_tour = 1;
    do {
        if (compteur_de_tour % 2 == 0){ //Equipe joueur qui attaque (l'équipe joueur attaque en premier)
            //utilisation d'une fonction 'fight' générale à tout les tour d'équipe.

        } else { //Le bot qui joue
            int adversaire = 0;
            int scoredmg = 0;
            int scorehp = 0;
            for (int i=0; i<4; i++){
                int scoretemp = equipe->tab[i].atk * (1.0 + (equipe->tab[i].tc / 100.0) * ((equipe->tab[i].dc / 100.0) - 1.0));
                if (scoretemp > scoredmg){
                    scoredmg = scoretemp;
                    adversaire = i; 
                }
                for (int j=0; j<4; j++){

                    damage = ((atboss->attaque*atboss->listecb[j].damage) * atboss->attaque) / (atboss->attaque + equipe->tab[i].def);
                    scorehp = equipe->tab[i].pv / damage; //correspond au nombre de coup qu'il faut pour le tuer 
                }




            }

        }

    } while (verification(*equipe) != 4);



}
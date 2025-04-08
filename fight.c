#include "head.h"
#include "fight.h"
#include "personnages.h"

//Ce porgramme porte sur les fight entre vrai utilisateur, pas d'IA disponible

int randtc(){
    int crit = 0;
    return crit = rand() % 100 + 1;
}

void afficher_round(int count, char equipe[]){
    printf(VIOLET"Tour numero :"VERT" %d\n"ROUGE"L'equipe: "JAUNE"%s"ROUGE" a la main \n"RESET,count,equipe);
}

int verification_type(Personnage *attaquant, Personnage *defenseur, int capa, int * degat);

int damage(Personnage attaquant, Personnage * defenseur,int capa){ 
    int rturn; 
    int crit = randtc(); 
    int degats = 0;  //Dégats réelement infligés.
    printf(JAUNE"Statistiques prise en compte\n"RESET
    ROSE"Atk :%d\n"
    "Damage %d\n"
    "Def %d\n"RESET
    , attaquant.atk, attaquant.listedescapacites[capa].damage, defenseur->def);
    if (crit <= attaquant.tc){ //Cas ou l'attaquant effectue un coup critique.
        printf(ROSE"COUP CRITIQUE!\n"RESET);
        degats = (((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->def))*(attaquant.dc/100.0);
        printf("Les degats avant verification elementaire sont : %d\n",degats);
        rturn = verification_type(&attaquant, defenseur, capa,&degats);
        if (rturn == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
        }
    } else {
        degats = ((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->def);
        printf("Les degats avant verification elementaire sont : %d\n",degats);
        rturn = verification_type(&attaquant, defenseur, capa, &degats);
        if (rturn == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
        }
    }
    return degats; //On return de force un entier, plus simple de travailler avec des entier dans le contexte du jeu.
}

int equipe_morte(Equipe_deux equipe){  //on utilisera cette fonction des lors qu'on aura des equipe a plusieurs 4 perso
    if (equipe.tab[0].pv <=0 && equipe.tab[1].pv <=0){
        return 1;
    } else {
        return 0;
    }
}

/* int choisircible(Equipe_deux persoattaquant, Equipe_deux persodefenseur, int capa, int selectatk, int selectdef){
    Personnage atk,def;
    switch (selectdef){
        case 1: //cas ou l'adversaire n°1 est choisi
            return damage(persoattaquant.tab[selectatk-1], persodefenseur.tab[selectdef], capa);
        case 2:
            break;
    }
    return 1;
} */


int verification_type(Personnage * attaquant, Personnage *defenseur, int capa, int * degat){ //on supprime la partie décimale de façon a avoir une meilleur expérience de jeu
    int somme = attaquant->listedescapacites[capa].type + defenseur->type;
    printf("    La reaction elementaire est d'identifiant %d\n"
    "    Les degats pris en compte sont %d\n"
    ,somme, *degat);
    switch (somme){
        case 11:
            printf(ORANGE"EVAPORATION\n"RESET); //Hydro + Pyro
            defenseur->type = 0;
            * degat *= 1.5;
            return 1;
        case 110:
            printf(ORANGE"SURGARGE\n"RESET); //Pyro + Electro
            defenseur->type = 0;
            * degat *= 1.3;
            return 1;
        case 101:
            printf(VIOLET"ELECTROCUTION\n"RESET); //Electro + Hydro
            defenseur->type = 0;
            * degat *= 1.5;
            return 1;
        case 1010:
            printf(BLEUC"FONTE\n"RESET); //Pyro + Cryo
            defenseur->type = 0;
            * degat *= 2;
            return 1;
        case 1001:
            printf(BLEUF"GEL"RESET); //Cryo + Hydro
            defenseur->type = 0;
            return 1;
        case 1100:
            printf(VIOLET"SUPRACONDUCTION\n"RESET); //Electro + Cryo
            defenseur->type = 0;
            * degat *= 1.3;
            return 1;
        default:
            printf(BLEU"Pas de reaction elementaire puisque aucun element est actif.\n"RESET);
            return 0;
    }
}

void fight(Equipe_deux *equipea, Equipe_deux *equipeb){ //Fonction mère de la gestion du combat
    int compteur_de_tour = 0;
    int clé = 0;
    int degat = 0;
    int atk =0;
    int adversaire = 0;
    srand(time(NULL));
    Equipe_deux equipe_a;
    Equipe_deux equipe_b;
    int equipeA, equipeB; //variable qui gere si les equipes sont morte
    //Equipe_quatre composition_a;  //ligne à activer en version final.
    //Equipe_quatre composition_b;
    do {
        if (compteur_de_tour % 2 == 0){
            afficher_round(compteur_de_tour + 1,equipea->name);
        } else {
            afficher_round(compteur_de_tour + 1,equipeb->name);
        }
        for (int i=0;i<2;i++){  //2 variable 
            if (compteur_de_tour % 2 == 0){ //Equipe A qui attaque
                printf("%s attaque en %d.\n", equipea->tab[i].name,i+1);
                printf(VERT"A vous de choisir votre attaque parmis la liste suivante : \n"RESET);
                for (int j=0;j<4;j++){
                    printf("    %s (%d)\n"
                    "        Damage de l'attaque %d\n"
                    , equipea->tab[i].listedescapacites[j].nom, j+1, equipea->tab[i].listedescapacites[j].damage);
                }
                do {
                    scanf("%d",&atk);
                } while (atk < 1 || atk > 4);
                printf(BLEU"Attaque selectionne : %s\n"RESET
                    VERT"Sur quel adversaire attaquer?\n"RESET,equipea->tab[i].listedescapacites[atk-1].nom);
                    printf("    Les adversaires disponibles sont : \n"
                        "       %s (%d)"
                        "       %s (%d)\n"
                        , equipeb->tab[0].name,1, equipeb->tab[1].name,2);
                do {
                    scanf("%d",&adversaire);
                } while (adversaire <1 || adversaire > 2); //2 variable
                degat = damage(equipea->tab[i], &equipeb->tab[adversaire-1],atk-1);
                //degat = verification_type(&equipea->tab[i], &equipeb->tab[adversaire-1], atk-1, degat);
                equipeb->tab[adversaire-1].pv -= degat;
                printf(ROUGE"L'adversaire se voit inflige %d degats\n"RESET
                    BLEU"Il reste %d pv a %s\n"RESET
                    ,degat,equipeb->tab[adversaire-1].pv, equipeb->tab[adversaire-1].name);
                printf(BLEUC"Le defenseur %s est affecte par l'element %d\n"RESET,equipeb->tab[adversaire-1].name, equipeb->tab[adversaire-1].type);
            } else { //Equipe B qui attaque
                printf("%s attaque en %d.\n", equipeb->tab[i].name,i+1);
                printf(VERT"A vous de choisir votre attaque parmis la liste suivante : \n"RESET);
                for (int j=0;j<4;j++){
                    printf("    %s (%d)\n"
                        "        Damage de l'attaque %d\n"
                        , equipeb->tab[i].listedescapacites[j].nom,j+1, equipeb->tab[i].listedescapacites[j].damage);
                }
                do {
                    scanf("%d",&atk);
                } while (atk < 1 || atk > 4);
                printf(BLEU"Attaque selectionne : %s\n"RESET
                VERT"Sur quel adversaire attaquer?\n"RESET,equipeb->tab[i].listedescapacites[atk-1].nom);
                printf("    Les adversaires disponibles sont : \n"
                "       %s (%d)"
                "       %s (%d)\n"
                , equipea->tab[0].name,1, equipea->tab[1].name,2);
                do {
                    scanf("%d",&adversaire);
                } while (adversaire <1 || adversaire > 2); //2 variable
                degat = damage(equipeb->tab[i], &equipea->tab[adversaire-1],atk-1);
                //degat = verification_type(&equipeb->tab[i], &equipea->tab[adversaire-1], atk-1, degat);
                equipea->tab[adversaire-1].pv -= degat;
                printf(ROUGE"L'adversaire se voit inflige %d degats\n"RESET
                    BLEU"Il reste %d pv a %s\n"RESET
                    ,degat,equipea->tab[adversaire-1].pv, equipea->tab[adversaire-1].name);
                printf(BLEUC"Le defenseur %s est affecte par l'element %d\n"RESET,equipea->tab[adversaire-1].name, equipea->tab[adversaire-1].type);
            }

        }
        printf(VIOLET"Cle de sortie : 789\n"RESET); //Partie du programme permettant d'arrêter le jeu sans terminer la partie
        scanf("%d",&clé);
        if (clé == 789){
            equipea->tab[0].pv = 0;
            equipea->tab[1].pv = 0;
        }
        compteur_de_tour++;
    } while ((equipea->tab[0].pv > 0 || equipea->tab[1].pv > 0) && (equipeb->tab[0].pv > 0 || equipeb->tab[1].pv > 0));

}


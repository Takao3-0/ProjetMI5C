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

int damage(Personnage attaquant, Personnage * defenseur,int capa){  
    int crit = randtc(); 
    int degats = 0;  //Dégats réelement infligés.
    printf(JAUNE"Statistiques prise en compte\n"RESET
    ROSE"Atk :%d\n"
    "Damage %d\n"
    "Def %d\n"RESET
    , attaquant.atk, attaquant.listedescapacites[capa].damage, defenseur->def);
    if (crit <= attaquant.tc){ //Cas ou l'attaquant effectue un coup critique.
        printf(ROSE"COUP CRITIQUE!\n"RESET);
        degats = (((attaquant.atk*attaquant.listedescapacites[capa].damage)*attaquant.atk)/(attaquant.atk+defenseur->def))*(attaquant.dc/100);
        defenseur->type = attaquant.listedescapacites[capa].type;
    } else {
        degats = ((attaquant.atk*attaquant.listedescapacites[capa].damage)*attaquant.atk)/(attaquant.atk+defenseur->def);
        defenseur->type = attaquant.listedescapacites[capa].type;
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


int verification_type(Personnage * attaquant, Personnage *defenseur, int capa, int degat){ //on supprime la partie décimale de façon a avoir une meilleur expérience de jeu
    int somme = attaquant->listedescapacites[capa].type + defenseur->type;
    switch (somme){
        case 11:
            printf("Eau + Feu\n");
            defenseur->type = 0;
            return degat * 1.5;
        case 110:
            printf("Feu + Electro\n");
            defenseur->type = 0;
            return degat * 1.3;
        case 101:
            printf("Electro + Eau\n");
            defenseur->type = 0;
            return degat * 1.5;
        case 1010:
            printf("Feu + Cryo\n");
            defenseur->type = 0;
            return degat * 2;
        case 1001:
            printf("Givre + Eau");
            defenseur->type = 0;
            return degat;
        case 1100:
            printf("Electro + Givre\n");
            defenseur->type = 0;
            return degat * 1.3;
        default:
            return degat;
    }
}

void fight(Equipe_deux *equipea, Equipe_deux *equipeb){ //Fonction mère de la gestion du combat
    int compteur_de_tour = 0;
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
                    printf("    %s\n", equipea->tab[i].listedescapacites[j].nom);
                }
                do {
                    scanf("%d",&atk);
                } while (atk < 1 || atk > 4);
                printf(BLEU"Sur quel adversaire attaquer\n"RESET);
                printf("Les adversaires disponibles sont : %s (%d) et %s (%d)\n", equipeb->tab[0].name,1, equipeb->tab[1].name,2);
                do {
                    scanf("%d",&adversaire);
                } while (adversaire <1 || adversaire > 2); //2 variable
                degat = damage(equipea->tab[i], &equipeb->tab[adversaire-1],atk);
                degat = verification_type(&equipea->tab[i], &equipeb->tab[adversaire-1], atk, degat);
                equipeb->tab[adversaire-1].pv -= degat;
                printf(ROUGE"L'adversaire se voit inflige %d degats\n"RESET
                    BLEU"Il reste %d pv a %s\n"RESET
                    ,degat,equipeb->tab[adversaire-1].pv, equipeb->tab[adversaire-1].name);
            } else { //Equipe B qui attaque
                printf("%s attaque en %d.\n", equipeb->tab[i].name,i+1);
                printf(VERT"A vous de choisir votre attaque parmis la liste suivante : \n"RESET);
                for (int j=0;j<4;j++){
                    printf("    %s\n", equipeb->tab[i].listedescapacites[j].nom);
                }
                do {
                    scanf("%d",&atk);
                } while (atk < 1 || atk > 4);
                printf(BLEU"Sur quel adversaire attaquer\n"RESET);
                printf("Les adversaires disponibles sont : %s (%d) et %s (%d)\n", equipea->tab[0].name,1, equipea->tab[1].name,2);
                do {
                    scanf("%d",&adversaire);
                } while (adversaire <1 || adversaire > 2); //2 variable
                degat = damage(equipeb->tab[i], &equipea->tab[adversaire-1],atk);
                degat = verification_type(&equipeb->tab[i], &equipea->tab[adversaire-1], atk, degat);
                equipea->tab[adversaire-1].pv -= degat;
                printf(ROUGE"L'adversaire se voit inflige %d degats\n"RESET
                    BLEU"Il reste %d pv a %s\n"RESET
                    ,degat,equipea->tab[adversaire-1].pv, equipea->tab[adversaire-1].name);
            }

        }
        compteur_de_tour++;
    } while ((equipea->tab[0].pv > 0 || equipea->tab[1].pv > 0) && (equipeb->tab[0].pv > 0 || equipeb->tab[1].pv > 0));

}


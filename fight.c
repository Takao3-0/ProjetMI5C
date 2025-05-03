#include "head.h"
#include "fight.h"
#include "personnages.h"
#include "affichage.h"

//Ce porgramme porte sur les fight entre vrai utilisateur, pas d'IA disponible

int randtc(){
    int crit = 0;
    return crit = rand() % 100 + 1;
}

int verification_type(Personnage *attaquant, Personnage *defenseur, int capa, int * degat);

int damage(Personnage attaquant, Personnage * defenseur,int capa, int *crit, int *elmt){ 
    int critique = randtc(); 
    int degats = 0;  //Dégats réelement infligés.
    if (critique <= attaquant.tc){ //Cas ou l'attaquant effectue un coup critique.
        printf(ROSE"COUP CRITIQUE!\n"RESET);
        degats = (((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->def))*(attaquant.dc/100.0);
        printf("Les degats avant verification elementaire sont : %d\n",degats);
        *elmt = verification_type(&attaquant, defenseur, capa,&degats);
        if (*elmt == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
            printf(ORANGE"Le type de %s est alors %d"RESET,defenseur->name, defenseur->type);
        }
        *crit = 1;
    } else {
        degats = ((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->def);
        printf("Les degats avant verification elementaire sont : %d\n",degats);
        *elmt = verification_type(&attaquant, defenseur, capa, &degats);
        if (*elmt == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
            printf(ORANGE"Le type de %s, est alors %d"RESET,defenseur->name, defenseur->type);
        }
        *crit = 0;
    }
    return degats; //On return de force un entier, plus simple de travailler avec des entier dans le contexte du jeu.
}

int equipe_morte(Equipe_quatre equipe){  //on utilisera cette fonction des lors qu'on aura des equipe a plusieurs 4 perso
    if (equipe.tab[0].pv <=0 && equipe.tab[1].pv <=0){
        return 1;
    } else {
        return 0;
    }
}


int verification_type(Personnage * attaquant, Personnage *defenseur, int capa, int * degat){ //on supprime la partie décimale de façon a avoir une meilleur expérience de jeu
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

int verification(Equipe_quatre a){
    int rturn = 0;
    for (int i=0; i<4; i++){
        if (a.tab[i].pv <= 0){
            rturn++; 
        }
    }
    return rturn;
}



/*

Déroule d'un fight
    - On demande à l'utilisateur de choisir une capacité parmis celle disponible [1]
    - Ensuite il doit choisir sur quel adversaire attaquer. On met un message pour comfirmer l'attaque choisi [2]
    - Enfin affichage de résultat incluant ; Crit, RE, Damage final [3]

*/

// Boucle principale de combat entre deux équipes de deux personnages
void fight(Equipe_quatre *equipea, Equipe_quatre *equipeb){ //Fonction mère de la gestion du combat
    int compteur_de_tour = 0;
    int clé = 0;
    int degat = 0;
    int atk = 0;
    int adversaire = 0;
    int crit = 0;
    int elmt = 0;              // type élémentaire final
    srand(time(NULL));
    Equipe_quatre equipe_a; 
    Equipe_quatre equipe_b;

    do {
        for (int i = 0; i < 4; ++i) {  // 2 personnages par équipe
            if (compteur_de_tour % 2 == 0) { // Equipe A qui attaque

                procedure_mere_affichage_fight(equipea, equipeb,
                                                compteur_de_tour,
                                                &equipea->tab[i], &equipeb->tab[i],
                                                0, 0, 0, 1, 0,0);
                do { scanf("%d", &atk); }
                while (atk < 1 || atk > 4);

                procedure_mere_affichage_fight(equipea, equipeb,
                                                compteur_de_tour,
                                                &equipea->tab[i], &equipeb->tab[i],
                                                atk, 0, 0, 2, 0,0);
                do { scanf("%d", &adversaire); }
                while (adversaire < 1 || adversaire > 4);

                crit = 0;
                elmt  = 0;
                degat = damage(equipea->tab[i],
                               &equipeb->tab[adversaire - 1],
                               atk - 1,
                               &crit, &elmt);
                equipeb->tab[adversaire - 1].pv -= degat;
                printf("Valeur de elm %d\n",elmt);
                procedure_mere_affichage_fight(equipea, equipeb,
                                                compteur_de_tour,
                                                &equipea->tab[i], &equipeb->tab[adversaire - 1],
                                                atk, crit, degat, 3, equipeb->tab[adversaire-1].type,elmt);

            } else { // Equipe B qui attaque

                procedure_mere_affichage_fight(equipea, equipeb,
                                                compteur_de_tour,
                                                &equipeb->tab[i], &equipea->tab[i],
                                                0, 0, 0, 1, 0,0);
                do { scanf("%d", &atk); }
                while (atk < 1 || atk > 4);

                procedure_mere_affichage_fight(equipea, equipeb,
                                                compteur_de_tour,
                                                &equipeb->tab[i], &equipea->tab[i],
                                                atk, 0, 0, 2, 0,0);
                do { scanf("%d", &adversaire); }
                while (adversaire < 1 || adversaire > 4);

                crit = 0;
                elmt  = 0;
                degat = damage(equipeb->tab[i],
                               &equipea->tab[adversaire - 1],
                               atk - 1,
                               &crit, &elmt);
                equipea->tab[adversaire - 1].pv -= degat;
                procedure_mere_affichage_fight(equipea, equipeb,
                                                compteur_de_tour,
                                                &equipeb->tab[i], &equipea->tab[adversaire - 1],
                                                atk, crit, degat, 3, equipea->tab[adversaire-1].type,elmt);
            }
        }

        printf(VIOLET "Cle de sortie : 789" RESET);
        scanf("%d", &clé);
        if (clé == 789) {
            equipea->tab[0].pv = equipea->tab[1].pv = 0;
        }
        ++compteur_de_tour;
    } while ((verification(equipe_a)!= 4 || verification(equipe_b)!=4));
}






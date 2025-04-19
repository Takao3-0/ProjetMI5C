#include "affichage.h"
#include "head.h"
#include "personnages.h"
#include "artefact.h"
#include "createursquad.h"

void replace(){

}

void mainscreen(){
    FILE *menu = fopen("asset/mainmenu.txt", "r");
    if (menu == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne), menu) != NULL) {
        printf("%s", ligne); 
    }
    fclose(menu);
}

void mainscreenerror(){
    int i=0;
    FILE *menu = fopen("asset/mainmenuerreur.txt", "r");
    if (menu == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne), menu) != NULL) {
        i++;
        printf("%s", ligne);
        if(i==20){
            printf("│                                                   "ROUGE"Erreur dans la saisie veuillez recommencer !"RESET
                "                                                   │\n");
        } 
    }
    printf("\n");
    fclose(menu);
}

void screenerror(){
    int i=0;
    FILE *menu = fopen("asset/menuerreur1.txt", "r");
    if (menu == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne), menu) != NULL) {
        i++;
        printf("%s", ligne);
        if(i==20){
            printf("│                                     "ROUGE"Vous n'avez pas d'equipe definie. Veuillez d'abord en composer une ▶[4]."RESET
                "                                     │\n");
        } 
    }
    printf("\n");
    fclose(menu);
}

void selectplayer(Personnage * tablist){  //pas sur de l'utiliser 
    FILE *perso = fopen("asset/gamestart.txt", "r");
    if (perso == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne1[SIZELINE];
    while (fgets(ligne1, sizeof(ligne1),perso)) {
        if (strstr(ligne1, "@pv01")){
            char *pos = strstr(ligne1, "@pv01");
            if (pos != NULL) {
                int len = pos - ligne1; 
                printf("%.*s", len, ligne1);
            }
            printf("%d",tablist[0].pv);
            char *apres = pos + strlen("@pv01");
            printf("%s", apres);
        } else if (strstr(ligne1, "@atk")){
            char *pos1 = strstr(ligne1, "@atk");
            int len1 = pos1 - ligne1;
            printf("%.*s", len1, ligne1);
            printf("%d",tablist[0].atk);
            char *apres = pos1 + strlen("@atk");
            printf("%s", apres);
        }
        else {
            printf("%s", ligne1);    
        }
    }
    printf("\n");
    fclose(perso);
}

void selectname(int num){
    int i=0;
    FILE *perso = fopen("asset/createname.txt", "r");
    if (perso == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne1[SIZELINE];
    while (fgets(ligne1, sizeof(ligne1),perso) != NULL) {
        i++;
        printf("%s", ligne1);
        if(i==20){
            printf("│                                         "BLEU"Avant de commencer veuillez choisir le nom de l'equipe numero %d!"RESET
                "                                         │\n",num);
        }
    }
    printf("\n");
    fclose(perso);    
}


void selectplayerv2(Personnage *tablist2, int num, Equipe_quatre *a){
    int i=0;
    int f=0;
    int z = 0;
    FILE *perso = fopen("asset/select.txt", "r");
    if (perso == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne1[SIZELINE];
    char temp[20];
    while (fgets(ligne1, sizeof(ligne1),perso) != NULL) {
        if (strstr(ligne1, "┌──────────────────────────┐")){
            printf("│ ┌──────────────────────────┐ ┌──────────────────────────┐ ┌──────────────────────────┐ ┌──────────────────────────┐ ┌──────────────────────────┐ │", ligne1);
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%d", tablist2[j].rarete);
                i = strlen(temp);
                printf("│ │ Rarete : %d etoile", tablist2[j].rarete,j+1);
                for (int h=0; h<9-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(9-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%s", tablist2[j].name);
                i = strlen(temp);
                printf("│ │ Nom : %s", tablist2[j].name);
                for (int h=0; h<19-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(19-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%d", tablist2[j].pv);
                i = strlen(temp);
                printf("│ │ PV : %d", tablist2[j].pv);
                for (int h=0; h<20-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(20-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%d", tablist2[j].atk);
                i = strlen(temp);
                printf("│ │ Attaque : %d", tablist2[j].atk);
                for (int h=0; h<15-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(15-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%d", tablist2[j].def);
                i = strlen(temp);
                printf("│ │ Defense : %d", tablist2[j].def);
                for (int h=0; h<15-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(15-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%d", tablist2[j].tc);
                i = strlen(temp);
                printf("│ │ Taux critique : %d", tablist2[j].tc);
                for (int h=0; h<9-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(9-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            for (int j=f;j<5+f;j++){
                sprintf(temp, "%d", tablist2[j].dc);
                i = strlen(temp);
                printf("│ │ Degats critique : %d", tablist2[j].dc);
                for (int h=0; h<7-i;h++){
                    printf(" ");
                    if (j == 4+f && h==(7-i)-1){
                        printf("│ │");
                    }
                }
            }
            printf("\n");
            printf("│ └──────────────────────────┘ └──────────────────────────┘ └──────────────────────────┘ └──────────────────────────┘ └──────────────────────────┘ │\n");
            f+=5;
            z++;;
            fgets(ligne1, sizeof(ligne1),perso);
        } else if (z == 14){
            printf("  │\n│                                                    "BLEU"Choissiez le personnage qui attaquera en %d"RESET
                "                                                    │\n",num);
            z++;

        } else if (strstr(ligne1, "Composition")){
            printf("%s  │\n",ligne1);
            for (int k=0; k<SQUADASSEMBLEUR;k++){
                if (a->tab[k].name[0] == '\0') {
                    printf("│       - : "BLEUC"Pas encore selectionne"RESET"                                                                                                                 │\n");
                } else {                          
                    sprintf(temp, "%s", a->tab[k].name);
                    i = strlen(temp);
                    printf("│       - : "VERT"%s"RESET, a->tab[k].name);
                    for (int h=0; h<135-i;h++){
                        printf(" ");
                        if (h==(135-i)-1){
                            printf("│\n");
                        }
                    }
                
                }
            }
            fgets(ligne1, sizeof(ligne1),perso);
            
        }
        else {
            z++;
            printf("%s"RESET, ligne1);
        }

    }
    printf("\n"); 
    fclose(perso);
}

void secondscreen(){
    FILE *menu = fopen("asset/menu.txt", "r");
    if (menu == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne), menu) != NULL) {
        printf("%s", ligne); 
    }
    printf("\n");
    fclose(menu);
}

void printequipe(Equipe_quatre *a){
    char temp[20];
    int i=0;
    for (int j=0;j<4;j++){
        sprintf(temp, "%s", a->tab[j].name);
        i = strlen(temp);
        printf("│ │ Nom : %s", a->tab[j].name);
        for (int h=0; h<19-i;h++){
            printf(" ");
            if (j == 3 && h==(19-i)-1){
                printf("│ │");
            }
        }
    }
    printf("\n");
    for (int j=0;j<4;j++){
        sprintf(temp, "%d", a->tab[j].pv);
        i = strlen(temp);
        printf("│ │ PV : %d", a->tab[j].pv);
        for (int h=0; h<20-i;h++){
            printf(" ");
            if (j == 3 && h==(20-i)-1){
                printf("│ │");
            }
        }
    }
    printf("\n");
}


//La procédure ci-dessous a seulement pour but de gérer la partie haute de l'affichage

void fight_affichage_informations_fixe(int tour,Personnage * attaquant, Equipe_quatre *a, Equipe_quatre *b){ 
    int equipe = 0;
    FILE * fixedscreen = fopen("asset/combat/fixedscreen.txt", "r");
    if (fixedscreen == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    Equipe_quatre * main;
    if (tour % 2 == 0){  //Equipe A qui attaque
        main = a;
    } else {  //Equibe B qui attaque
        main = b;
    } 
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne),fixedscreen) != NULL){
        if (strstr(ligne, "Informations")){
            printf("│   "BLEU"Informations générales : "VERT"Tour numéro %d"BLEU". "ORANGE"L'équipe "ROUGE"%s"ORANGE" a la main. C'est au tour de "ROUGE"%s"ORANGE" d'attaquer."RESET
            ,tour+1, main->name,attaquant->name);
            for (int i=0; i<51-strlen(main->name)-strlen(attaquant->name); i++){
                printf(" ");
            }
        } else if (strstr(ligne, "1:")){
            printf("│   Equipe 1: "BLEUC"%s"RESET,a->name); 
            for (int i=0; i<129-strlen(a->name); i++){
                printf(" ");
            }   
        } else if (strstr(ligne, "2:")){
            printf("│   Equipe 2: "VIOLET"%s"RESET,b->name); 
            for (int i=0; i<129-strlen(b->name); i++){
                printf(" ");
            }   
        } else if(strstr(ligne, "┌──────────────────────────┐")){
            printf("│ ┌──────────────────────────┐ ┌──────────────────────────┐ ┌──────────────────────────┐ ┌──────────────────────────┐ ┌──────────────────────────┐ │\n", ligne);
            if (equipe == 0){
                printequipe(a);
                equipe++;    
            } else {
                printequipe(b);
            }
            printf("│ └──────────────────────────┘ └──────────────────────────┘ └──────────────────────────┘ └──────────────────────────┘ └──────────────────────────┘ │\n");
            fgets(ligne, sizeof(ligne), fixedscreen);   
        } else {
            printf("%s",ligne);            
        }
    }
    fclose(fixedscreen);

}

//Fonction qui affiche la liste des attaques disponibles (les cd sont pas encore disponible)

void fight_affichage_attaque (Personnage * attaquant){
    FILE * attaqueselect = fopen("asset/combat/attaqueselect.txt", "r");
    if (attaqueselect == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne),attaqueselect) != NULL){
        if (strstr(ligne, "Attaque")){
            printf("│   "VERT"Liste des compétences de : "ROUGE"%s"RESET, attaquant->name);
            for (int i=0; i<116-strlen(attaquant->name);i++){
                printf(" ");
            }
            printf("│\n");
            for (int i=0;i<4;i++){
                printf("│       "JAUNE"Attaque numéro %d : "VIOLET"%s"RESET,i+1,attaquant->listedescapacites[i].nom);
                for (int k=0;k<120-strlen(attaquant->listedescapacites[i].nom);k++){
                    printf(" ");                      
                } 
                printf(ROSE"│\n"RESET);
            }
            fgets(ligne, sizeof(ligne), attaqueselect);
        }
        else {
            printf("%s", ligne);            
        }

    }
    printf("\n");
    fclose(attaqueselect);
}

void fight_affichage_cible(Equipe_quatre *a, Equipe_quatre *b, Personnage *attaquant,int tour, int atk){
    Equipe_quatre * defenseur;
    FILE * atkselect = fopen("asset/combat/attaqueselect.txt", "r");
    if (atkselect == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    if (tour % 2 == 0){  //Equipe A qui attaque donc equipe B qui défend.
        defenseur = b;
    } else {  //Equibe B qui attaque donc equipe B qui défend.
        defenseur = a;
    } 
    char ligne[SIZELINE];
    while (fgets(ligne, sizeof(ligne), atkselect) != NULL) {

        if (strstr(ligne, "Attaque")){
            printf("│    "VERT"Competence sélectionné : "ROUGE"%s"RESET, attaquant->listedescapacites[atk-1].nom);
            for (int i=0; i<117-strlen(attaquant->listedescapacites[atk-1].nom);i++){
                printf(" ");
            }
            printf("│\n");
            printf("│"JAUNE"    Sur quel adversaire attaquer?"RESET);
            for (int i=0; i<113;i++){
                printf(" ");
            }       
            printf("│\n");
            for (int i=0;i<4;i++){
                printf("│"JAUNE"        Defenseur numéro %d : %s"RESET,i+1, defenseur->tab[i].name);
                for (int k=0;k<117-strlen(defenseur->tab[i].name);k++){
                    printf(" ");                      
                } 
            printf("│\n");
            }
            fgets(ligne, sizeof(ligne), atkselect);
        } else {
            printf("%s", ligne);            
        }
    }
    printf("\n");
    fclose(atkselect);
}


const char *get_element_name(int elmt) {
        switch (elmt) {
            case 1:    
                return "Hydro";
            case 10:   
                return "Pyro";
            case 100:  
                return "Electro";
            case 1000: 
                return "Cryo";
            default:   
                return "neutre";
        }
}

void reaction_affichage(int react){
    switch (react){
        case 11: // Hydro + Pyro
            printf("│      "
                   BLEU       "E"
                   BLEU_CLAIR  "V"
                   BLEU_CLAIR2 "A"
                   ORANGE_TRES_CLAIR"P"
                   ORANGE_CLAIR"O"
                   ORANGE     "R"
                   ORANGE_CLAIR"A"
                   ORANGE_TRES_CLAIR"T"
                   ORANGE_CLAIR"I"
                   ORANGE     "O"
                   ORANGE_CLAIR"N"RESET
                   "                                                                                                                                 │\n");
            break;
        case 110:
        printf("│      "
            ORANGE      "S"
            ORANGE_CLAIR"U"
            ORANGE_CLAIR"R"
            ORANGE_TRES_CLAIR"C"
            VIOLET_CLAIR "H"
            VIOLET      "A"
            VIOLET_CLAIR "R"
            VIOLET_CLAIR "G"
            VIOLET      "E"RESET
            "                                                                                                                                   │\n");
     break;
        case 101:
        printf("│      "
            VIOLET       "E"
            VIOLET_CLAIR  "L"
            VIOLET_CLAIR  "E"
            VIOLET_TRES_CLAIR"C"
            BLEU_CLAIR    "T"
            BLEU          "R"
            BLEU_CLAIR2   "O"
            BLEU          "C"
            BLEU_CLAIR    "T"
            BLEU          "I"
            BLEU_CLAIR2   "O"
            BLEU          "N"RESET
            "                                                                                                                                │\n");
     break;
        case 1010:
        printf("│      "
            ORANGE      "F"
            ORANGE_CLAIR"O"
            ORANGE_TRES_CLAIR"N"
            BLEUC       "T"
            BLEU_CLAIR2 "E"RESET
            "                                                                                                                                       │\n");
     break;
        case 1001:
        printf("│      "
            BLEUC       "G"
            BLEU_CLAIR   "E"
            BLEU         "L"RESET
            "                                                                                                                                         │\n");
     break;
        case 1100:
        printf("│      "
            VIOLET       "S"
            VIOLET_CLAIR "U"
            VIOLET_CLAIR "P"
            VIOLET_TRES_CLAIR"R"
            BLEUC        "A"
            BLEU_CLAIR2  "C"
            BLEU         "O"
            BLEUC        "N"
            BLEU_CLAIR2  "D"
            BLEU         "U"
            BLEUC        "C"
            BLEU_CLAIR2  "T"
            "I"
            "O"
            "N"RESET
            "                                                                                                                             │\n");
     break;
        default:
            printf(ROUGE"Erreur.\n"RESET);
    }
}

void fight_affichage_result(Personnage *defenseur,int crit,int degat, int elmt,int react){
    int taille = 0;
    int n = degat;
    FILE * result = fopen("asset/combat/resultfight.txt", "r");
    if (result == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    const char *element = get_element_name(elmt);
    char ligne[SIZELINE];
    while (fgets(ligne ,sizeof(ligne),result)){
        if (strstr(ligne, "Resultat")){
            if (crit == 1){
                printf("│      "ROSE"COUP CRITIQUE!"RESET"                                                                                                                              │\n");
                if (react != 0){
                    reaction_affichage(react);
                    fgets(ligne,sizeof(ligne),result);
                }
                affichage_element(defenseur,degat,elmt);
                while (n > 0) {
                    n /= 10;
                    ++taille;
                }
                for (int i=0;i<84-taille-strlen(element)-strlen(defenseur->name);i++){
                    printf(" ");
                }
                printf("│\n");
                fgets(ligne,sizeof(ligne),result);
            } else if (crit == 0){
                if (react != 0){
                    reaction_affichage(react);
                    fgets(ligne,sizeof(ligne),result);
                }
                affichage_element(defenseur,degat,elmt);
                while (n > 0) {
                    n /= 10;
                    ++taille;
                }
                for (int i=0;i<84-taille-strlen(element)-strlen(defenseur->name);i++){
                        rintf(" ");
                }
                printf("│\n");
                fgets(ligne ,sizeof(ligne),result);    
            }  
        } else {
            printf("%s",ligne);
        }
    } 
    printf("\n");
    fclose(result);   
}

//Je m'en occuperais plus tard!
void procedure_mere_affichage_fight(Equipe_quatre *a, Equipe_quatre *b, int tour, Personnage *attaquant, Personnage *defenseur, int atk, int crit, int degat, int cle, int elmt,int react){
    switch (cle){
        case 1: //Affichage du premier écran (celui ou le joueur choisi ses attaques parmis la liste disponible)
            fight_affichage_informations_fixe(tour,attaquant,a,b);
            fight_affichage_attaque(attaquant);
            break;

        case 2: //Comfirmation de l'attaque séléectionné, l'attaquant choisi sa cible.
            fight_affichage_informations_fixe(tour,attaquant,a,b);
            fight_affichage_cible(a,b,attaquant,tour,atk);
            break;

        case 3: //Resultat des degats + information en cas de coup critique + réaction élémentaire 
            fight_affichage_informations_fixe(tour,attaquant,a,b);
            fight_affichage_result(defenseur,crit,degat,elmt,react);
            sleep(2);
            break;
    }

}



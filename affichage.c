#include "affichage.h"
#include "head.h"
#include "personnages.h"
#include "artefact.h"

void replace(){

}

void mainscreen(){
    FILE *menu = fopen("mainmenu.txt", "r");
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
    fclose(perso);    
}


void selectplayerv2(Personnage *tablist2){
    int i=0;
    FILE *perso = fopen("asset/select.txt", "r");
    if (perso == NULL) {
        printf(ROUGE"Impossible d'ouvrir le menu principal.\n"RESET);
        return;
    }
    char ligne1[SIZELINE];
    while (fgets(ligne1, sizeof(ligne1),perso) != NULL) {
        if (strstr(ligne1, "┌──────────────────────────┐")){
            printf("%s", ligne1);
            printf("\n");
            for (int j=0;j<5;j++){
                i = strlen(tablist2[j].name);
                printf("│ │ Nom : %s", tablist2[j].name);
                for (int h=0; h<19-i;h++){
                    printf(" ");
                    if (h==19-i){
                        printf("│ │");
                    }
                }
            }
        } else {
            printf("%s", ligne1);
        }

    } 
    fclose(perso);
}


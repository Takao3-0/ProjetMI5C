#include "personnages.h"
#include "createursquad.h"
#include "affichage.h"
#include "key.h"
#include "head.h"



Equipe_deux * assembleur_squad_deux(Personnage *tablist, int num){
    int count = 0;
    Equipe_deux * a = malloc(sizeof(Equipe_deux));
    if(a == NULL) {
        printf(ROUGE "Erreur d'allocation mémoire\n" RESET);
        exit(1);
    }
    int perso;
    selectname(num);
    //printf(BLEU"Avant de commencer veuillez choisir un nom de l'equipe numero %d\n"RESET, num);
    scanf("%s", a->name);
    *a->tab[0].name = '\0';
    *a->tab[1].name = '\0';
    selectplayerv2(tablist,1,a);
    /*printf(BLEU"Avant de commencer un combat, vous devez egalement composer votre équipe.\n"RESET
    "    La liste des personnages disponibles est la suivante.\n");
    for (int i=0; i<PERSONNAGEQ; i++){
        printf("Personnage numero %d : %s\n",i+1,tablist[i].name);
    }*/
    for (int j=0; j<SQUADASSEMBLEUR; j++){
        //printf("Qui attaquera en position numero %d?\n",j+1);
        do {
            perso = better_scan_int(1,PERSONNAGEQ);
        } while (perso == 0);
        a->tab[j]=tablist[perso-1];
        count++;
        selectplayerv2(tablist,count,a);
        sleep(1);  //Temps laissé à l'utilisateur avant de changer d'écran
    }
    /*printf(BLEUC"L'equipe est donc compose de :\n"RESET);
    for (int h=0; h<SQUADASSEMBLEUR; h++){
        printf("    %s\n",a->tab[h].name);
    }*/
    return a;
}
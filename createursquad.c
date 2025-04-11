#include "personnages.h"
#include "createursquad.h"
#include "affichage.h"
#define SQUADASSEMBLEUR 2 //Constante pour le nombre de personnage dans l'équipe


Equipe_deux * assembleur_squad_deux(Personnage *tablist, int num){
    Equipe_deux * a = malloc(sizeof(Equipe_deux));
    if(a == NULL) {
        printf(ROUGE "Erreur d'allocation mémoire\n" RESET);
        exit(1);
    }
    int perso;
    selectname(num);
    //printf(BLEU"Avant de commencer veuillez choisir un nom de l'equipe numero %d\n"RESET, num);
    scanf("%s", a->name);
    selectplayerv2(tablist);
    printf(BLEU"Avant de commencer un combat, vous devez egalement composer votre équipe.\n"RESET
    "    La liste des personnages disponibles est la suivante.\n");
    for (int i=0; i<PERSONNAGEQ; i++){
        printf("Personnage numero %d : %s\n",i+1,tablist[i].name);
    }
    for (int j=0; j<SQUADASSEMBLEUR; j++){
        printf("Qui attaquera en position numero %d?\n",j+1);
        scanf("%d",&perso);
        a->tab[j]=tablist[perso-1];
    }
    printf(BLEUC"L'equipe est donc compose de :\n"RESET);
    for (int h=0; h<SQUADASSEMBLEUR; h++){
        printf("    %s\n",a->tab[h].name);
    }
    return a;
}
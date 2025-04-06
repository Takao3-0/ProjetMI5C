#include "head.h"
#include "personnages.h"
#define SIZE 2 //nombre de personnage dans le jeu

int main(){
    FILE * fic=NULL;
    fic=fopen("personnages.txt", "r");
    Personnage * listeperso = malloc(SIZE * sizeof(Personnage));
    if (fic!=NULL){
        Personnage perso;
        char chaine[60];
        for (int i=0; i<SIZE; i++){
            if(fgets(chaine,50,fic)!= NULL){
                printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d;%d;%d;%d;%d", 
                perso.name,
                &perso.pv,
                &perso.pvmax,
                &perso.atk,
                &perso.def,
                &perso.tc,
                &perso.dc);
            printf("Nom recupere : %s\n", perso.name);
            printf("PV Actuels : %d\n", perso.pv); 
            printf("Pv maximum : %d\n", perso.pvmax); 
            printf("Attaque de base : %d\n", perso.atk); 
            printf("Defence : %d\n", perso.def); 
            printf("Taux critique : %d\n", perso.tc); 
            printf("Degats critique : %d\n", perso.dc);
            for (int j=0;j<4;j++){
                fgets(chaine,60,fic);
                printf(VIOLET"%s\n"RESET,chaine);
                sscanf(chaine, "%[^;];%[^;];%d;%d;%d",
                    perso.listedescapacites->nom,
                    &perso.listedescapacites->description,
                    &perso.listedescapacites->damage,
                    &perso.listedescapacites->type,
                    &perso.listedescapacites->cd);
                    printf(ROUGE"Capacite numero %d :\n"RESET
                        "Nom : %s\n"
                        "Description %s\n"
                        "Damage : %d\n"
                        "Type : %d\n"
                        "CD : %d\n",
                        j+1,
                        perso.listedescapacites->nom,
                        perso.listedescapacites->description,
                        perso.listedescapacites->damage,
                        perso.listedescapacites->type,
                        perso.listedescapacites->cd);
            }    
            fgets(chaine,50,fic);
            listeperso[i] = perso;
        }
        fclose(fic);
    } else {
        printf("echec d'ouverture\n");
    }

}
#include "head.h"
#include "personnages.h"

Personnage * extract(void){
    FILE * fic=NULL;
    fic=fopen("personnages.txt", "r");
    Personnage * listeperso = malloc(PERSONNAGEQ * sizeof(Personnage));
    if (fic!=NULL){
        Personnage perso;
        char chaine[60];
        for (int i=0; i<PERSONNAGEQ; i++){
            if(fgets(chaine,50,fic)!= NULL){
                //printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d;%d;%d;%d;%d", 
                perso.name,
                &perso.pv,
                &perso.pvmax,
                &perso.atk,
                &perso.def,
                &perso.tc,
                &perso.dc);
            /*printf("Nom recupere : %s\n", perso.name);  //à terme ces printfs disparaiterons.
            printf("PV Actuels : %d\n", perso.pv); 
            printf("Pv maximum : %d\n", perso.pvmax); 
            printf("Attaque de base : %d\n", perso.atk); 
            printf("Defence : %d\n", perso.def); 
            printf("Taux critique : %d\n", perso.tc); 
            printf("Degats critique : %d\n", perso.dc);*/
            for (int j=0;j<4;j++){
                fgets(chaine,60,fic);
                //printf(VIOLET"%s\n"RESET,chaine);
                sscanf(chaine, "%[^;];%[^;];%d;%d;%d",
                    perso.listedescapacites[j].nom,
                    perso.listedescapacites[j].description,
                    &perso.listedescapacites[j].damage,
                    &perso.listedescapacites[j].type,
                    &perso.listedescapacites[j].cd);
                /*printf(ROUGE"Capacite numero %d :\n"RESET  //à terme ce printf disparaitera.
                    "Nom : %s\n"
                    "Description : %s\n"
                    "Damage : %d\n"
                    "Type : %d\n"
                    "CD : %d\n",
                    j+1,
                    perso.listedescapacites[j].nom,
                    perso.listedescapacites[j].description,
                    perso.listedescapacites[j].damage,
                    perso.listedescapacites[j].type,
                    perso.listedescapacites[j].cd);*/ 
            }    
            fgets(chaine,50,fic);
            listeperso[i] = perso;
        }
        fclose(fic);
        return listeperso;
    } else {
        printf("echec d'ouverture\n");
    }
    return 0;
}

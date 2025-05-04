#include "head.h"
#include "personnages.h"
#include "textures.h"

Perso_select attribution_id(Personnage perso){
    if (strcmp(perso.name, "Criona")    == 0) {
        return CRIONA;
    } else if (strcmp(perso.name, "Glacius")   == 0) {
        return GLACIUS;
    } else if (strcmp(perso.name, "Terrorex")  == 0) {
        return TERROREX;
    }else if (strcmp(perso.name, "Vulcain")    == 0) {
        return VULCAIN;
    } else if (strcmp(perso.name, "Calyra")    == 0) {
        return CALYRA;
    } else if (strcmp(perso.name, "Aqualis")   == 0) {
        return AQUALIS;
    } else if(strcmp(perso.name, "Nova")       == 0) {
        return NOVA;
    }else if (strcmp(perso.name, "Arcaniste")  == 0) {
        return ARCANISTE;
    }else if (strcmp(perso.name, "Voltix")     == 0) {
        return VOLTIX;
    }
}

Personnage * extract(){
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
            sscanf(chaine, "%[^;];%d;%d;%d;%d;%d;%d;%d", 
                perso.name,
                &perso.pv,
                &perso.pvmax,
                &perso.atk,
                &perso.def,
                &perso.tc,
                &perso.dc,
                &perso.rarete);
            printf(ROUGE"Nom recupere : %s\n"RESET, perso.name);  //à terme ces printfs disparaiterons.
            /*printf("PV Actuels : %d\n", perso.pv); 
            printf("Pv maximum : %d\n", perso.pvmax); 
            printf("Attaque de base : %d\n", perso.atk); 
            printf("Defence : %d\n", perso.def); 
            printf("Taux critique : %d\n", perso.tc); 
            printf("Degats critique : %d\n", perso.dc);
            printf("Rarete du personnage %d etoiles\n", perso.rarete);*/
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
            perso.NOM = attribution_id(perso);    
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

void attribution_texture(Personnage *tablist){
    tablist[13].texture = Criona;
    tablist[3].texture = Voltix;
    tablist[7].texture = Terrorex;
    tablist[8].texture = Nova;
    tablist[14].texture = Arcaniste;
    tablist[9].texture = Calyra;
    tablist[6].texture = Aqualis;
    tablist[5].texture = Vulcain;
    tablist[4].texture = Glacius;
}

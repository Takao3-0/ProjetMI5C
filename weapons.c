#include "weapons.h"

Weapons * extract_weapons(void){
    FILE * fic=NULL;
    fic=fopen("weapons.txt", "r");
    Weapons * listearme = malloc(ARMEQ * sizeof(Weapons));
    if (fic!=NULL){
        Weapons arme;
        char chaine[60];
        for (int i=0; i<ARMEQ; i++){
            if(fgets(chaine,50,fic)!= NULL){
                //printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d", 
                arme.name,
                &arme.attaque,
                &arme.type);
            printf("Nom recupere : %s\n", arme.name);  //à terme ces printfs disparaiterons.
            printf("Attaque de base de l'arme : %d\n", arme.attaque); 
            printf("Type d'arme : %d\n", arme.type); 
            for (int j=0;j<1;j++){
                fgets(chaine,60,fic);
                //printf(VIOLET"%s\n"RESET,chaine);
                sscanf(chaine, "%d;%d;%d;%d;%d",
                    &arme.substat_w.pv,
                    &arme.substat_w.atk,
                    &arme.substat_w.def,
                    &arme.substat_w.tc,
                    &arme.substat_w.dc);
                printf(ROUGE"Substat arme:\n"RESET  //à terme ce printf disparaitera.
                    "PV : %d\n"
                    "ATK : %d\n"
                    "DEF : %d\n"
                    "TC : %d\n"
                    "DC : %d\n",
                    arme.substat_w.pv,
                    arme.substat_w.atk,
                    arme.substat_w.def,
                    arme.substat_w.tc,
                    arme.substat_w.dc);
            }    
            fgets(chaine,50,fic);
            listearme[i] = arme;
        }
        fclose(fic);
        return listearme;
    } else {
        printf("Echec d'ouverture\n");
    }
    return 0;
}

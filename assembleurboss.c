#include "assembleurboss.h"
#include "personnages.h"
#include "createursquad.h"
#include "key.h"
#define LVLQ 2

int selectlvl(){
    int lvl;
    do {
        lvl = better_scan_int(1,9);    
    } while (lvl == 0);
    return lvl;
}

Boss_config * extract_lvl(void){
    FILE * fic=NULL;
    fic=fopen("lvlboss.txt", "r");
    Boss_config * configlvl = malloc(LVLQ * sizeof(Boss_config));
    if (fic!=NULL){
        Boss_config lvl;
        char chaine[60];
        for (int i=0; i<LVLQ; i++){
            if(fgets(chaine,50,fic)!= NULL){
                //printf(VERT"%s"RESET,chaine);
            }
            sscanf(chaine, "%[^;];%d;%d;%d", 
                lvl.name,
                &lvl.id_adversaire,
                &lvl.r1,
                &lvl.r2);
            fgets(chaine,50,fic);
            configlvl[i] = lvl;
        }
        fclose(fic);
        return configlvl;
    } else {
        printf("Echec d'ouverture\n");
    }
    return 0;
}

Assemblage * assembleur_boss(Equipe_quatre * a, Boss *tabboss, Boss_config tabbossc){
    int lvl = selectlvl(); //lvl correspond à l'identifiant du niveau
    Assemblage * structure;
    structure->equipe = *a;
    

}
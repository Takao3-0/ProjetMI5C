#include "personnages.h"
#include "createursquad.h"
#include "head.h"
#include "btn.h"


//Ici on return 1 si le personnage p passé en paramètre est dans l'équipe e.
//Si le personnage p n'apparait pas dans l'équipe alors on return 0.

int verif(Equipe_quatre e, Perso_select p){
    for (int i=0; i<4; i++){
        if (e.tab[i].NOM == p){
            printf(ROUGE"On return 1 car le perso selectionne est deja dans l'equipe\n"RESET);
            return 1;
        } 
    }
    printf(VERT"On return 0 car le personnage n'est pas present dans l'equipe\n"RESET);
    return 0;
}

int id(Perso_select selection, Equipe_quatre * equipea, int pos, Personnage *tablist){
    int v = verif(*equipea,selection);
    if (v == 0){
        switch (selection){
            case CRIONA:
                equipea->tab[pos] = tablist[13];
                break;
            case GLACIUS:
                equipea->tab[pos] = tablist[4];
                break;
            case TERROREX:
                equipea->tab[pos] = tablist[7];
                break;
            case VULCAIN:
                equipea->tab[pos] = tablist[5];
                break;
            case CALYRA:
                equipea->tab[pos] = tablist[9];
                break;
            case AQUALIS:
                equipea->tab[pos] = tablist[6];
                break;
            case ARCANISTE:
                equipea->tab[pos] = tablist[14];
                break;
            case VOLTIX:
                equipea->tab[pos] = tablist[3];
                break;  
            case NOVA:
                equipea->tab[pos] = tablist[8];
                break; 
            case AQUANOVA:
                equipea->tab[pos] = tablist[11];
                break;
            case HYDRAGON:
                equipea->tab[pos] = tablist[1];
                break;
            case VOLTAZOR:
                equipea->tab[pos] = tablist[12];
                break;
            case EMBERA:
                equipea->tab[pos] = tablist[0];
                break;
            case PYROBANE:
                equipea->tab[pos] = tablist[10];
                break;
            case KAELEN:
                equipea->tab[pos] = tablist[2];
                break;
            default:
                printf("Erreur\n");
        }
        return 1; //On a ajouté dans l'équipe avec succès le personnage!
    } else {
        return 0; //On n'ajoute pas le personnage dans l'équipe puisqu'il y est déjà!
    }
}

void affichage_e(Perso_select select){
    switch (select){
        case CRIONA:
        printf("CRIONA\n");
        break;
    case GLACIUS:
        printf("GLACIUS\n");
        break;
    case TERROREX:
        printf("TERROREX\n");
        break;
    case VULCAIN:
        printf("VULCAIN\n");
        break;
    case CALYRA:
        printf("CALYRA\n");
        break;
    case AQUALIS:
        printf("AQUALIS\n");
        break;
    case NOVA:
        printf("NOVA\n");
        break;
    case ARCANISTE:
        printf("ARCANISTE\n");
        break;
    case VOLTIX:
        printf("VOLTIX\n");
        break;
    case AQUANOVA:
        printf("AQUANOVA\n");
        break;
    }
}

void Assembleur_equipe(Equipe_quatre *equipea,Personnage *tablist, Game_state *etat, Perso_select *archive_etat, Position pos, SDL_Event e, Game_state *equipe){
    int mx = e.button.x;
    int my = e.button.y;
    Perso_select selection = VIDE;
    if (mx >= btnCROIXarchive.x && mx < btnCROIXarchive.x + btnCROIXarchive.w && my >= btnCROIXarchive.y && my < btnCROIXarchive.y + btnCROIXarchive.h){
        *etat = EQUIPE;
    } else if (mx >= btnArchiveCriona.x && mx < btnArchiveCriona.x + btnArchiveCriona.w && my >= btnArchiveCriona.y && my < btnArchiveCriona.y + btnArchiveCriona.h){
        *archive_etat = CRIONA;    
    }  else if (mx >= btnArchiveGlacius.x && mx < btnArchiveGlacius.x + btnArchiveGlacius.w && my >= btnArchiveGlacius.y && my < btnArchiveGlacius.y + btnArchiveGlacius.h){
        *archive_etat = GLACIUS; 
    } else if (mx >= btnArchiveTerrorex.x && mx < btnArchiveTerrorex.x + btnArchiveTerrorex.w && my >= btnArchiveTerrorex.y && my < btnArchiveTerrorex.y + btnArchiveTerrorex.h){
        *archive_etat = TERROREX;    
    } else if (mx >= btnArchiveVulcain.x && mx < btnArchiveVulcain.x + btnArchiveVulcain.w && my >= btnArchiveVulcain.y && my < btnArchiveVulcain.y + btnArchiveVulcain.h){
        *archive_etat = VULCAIN;    
    } else if (mx >= btnArchiveCalyra.x && mx < btnArchiveCalyra.x + btnArchiveCalyra.w && my >= btnArchiveCalyra.y && my < btnArchiveCalyra.y + btnArchiveCalyra.h){
        *archive_etat = CALYRA;    
    } else if (mx >= btnArchiveAqualis.x && mx < btnArchiveAqualis.x + btnArchiveAqualis.w && my >= btnArchiveAqualis.y && my < btnArchiveAqualis.y + btnArchiveAqualis.h){
        *archive_etat = AQUALIS;    
    } else if (mx >= btnArchiveArcaniste.x && mx < btnArchiveArcaniste.x + btnArchiveArcaniste.w && my >= btnArchiveArcaniste.y && my < btnArchiveArcaniste.y + btnArchiveArcaniste.h){
        *archive_etat = ARCANISTE;    
    } else if (mx >= btnArchiveVoltix.x && mx < btnArchiveVoltix.x + btnArchiveVoltix.w && my >= btnArchiveVoltix.y && my < btnArchiveVoltix.y + btnArchiveVoltix.h){
        *archive_etat = VOLTIX;    
    } else if (mx >= btnArchiveNova.x && mx < btnArchiveNova.x + btnArchiveNova.w && my >= btnArchiveNova.y && my < btnArchiveNova.y + btnArchiveNova.h){
        *archive_etat = NOVA;    
    } else if (mx >= btnSelectionEmbera.x && mx < btnSelectionEmbera.x + btnSelectionEmbera.w && my >= btnSelectionEmbera.y && my < btnSelectionEmbera.y + btnSelectionEmbera.h){
        *archive_etat = EMBERA;    
    } else if (mx >= btnSelectionAquanova.x && mx < btnSelectionAquanova.x + btnSelectionAquanova.w && my >= btnSelectionAquanova.y && my < btnSelectionAquanova.y + btnSelectionAquanova.h){
        *archive_etat = AQUANOVA;    
    } else if (mx >= btnSelectionKaelen.x && mx < btnSelectionKaelen.x + btnSelectionKaelen.w && my >= btnSelectionKaelen.y && my < btnSelectionKaelen.y + btnSelectionKaelen.h){
        *archive_etat = KAELEN;    
    } else if (mx >= btnSelectionPyrobane.x && mx < btnSelectionPyrobane.x + btnSelectionPyrobane.w && my >= btnSelectionPyrobane.y && my < btnSelectionPyrobane.y + btnSelectionPyrobane.h){
        *archive_etat = PYROBANE;    
    } else if (mx >= btnSelectionHydragon.x && mx < btnSelectionHydragon.x + btnSelectionHydragon.w && my >= btnSelectionHydragon.y && my < btnSelectionHydragon.y + btnSelectionHydragon.h){
        *archive_etat = HYDRAGON;    
    } else if (mx >= btnSelectionVoltazor.x && mx < btnSelectionVoltazor.x + btnSelectionVoltazor.w && my >= btnSelectionVoltazor.y && my < btnSelectionVoltazor.y + btnSelectionVoltazor.h){
        *archive_etat = VOLTAZOR;    
    }else if (mx >= btnAdd.x && mx < btnAdd.x + btnAdd.w && my >= btnAdd.y && my < btnAdd.y + btnAdd.h){
        selection = *archive_etat;
        affichage_e(selection);
        switch (pos){
            case P1:
                if (id(selection, equipea, pos, tablist) == 1){
                    printf("Ajoute avec succes\n");
                } else {
                    printf("Refus\n");
                }
                printf("Personnage en P1 : %s\n", equipea->tab[0].name);
                equipea->tab[3].pos = 0;
                break;
            case P2:
                if (id(selection, equipea, pos, tablist) == 1){
                    printf("Ajoute avec succes\n");
                } else {
                    printf("Refus\n");
                }
                printf("Personnage en P2 : %s\n", equipea->tab[1].name);
                equipea->tab[3].pos = 1;
                break;         
            case P3:
                if (id(selection, equipea, pos, tablist) == 1){
                    printf("Ajoute avec succes\n");
                } else {
                    printf("Refus\n");
                }
                printf("Personnage en P3 : %s\n", equipea->tab[2].name);
                equipea->tab[3].pos = 2;
                break;
            case P4:
                if (id(selection, equipea, pos, tablist) == 1){
                    printf("Ajoute avec succes\n");
                } else {
                    printf("Refus\n");
                }
                printf("Personnage en P4 : %s\n", equipea->tab[3].name);
                equipea->tab[3].pos = 3;
                break;
        }
        *etat = EQUIPE;
    }
}









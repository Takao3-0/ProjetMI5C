#include "personnages.h"
#include "createursquad.h"
#include "head.h"
#include "btn.h"

void id(Perso_select selection, Equipe_quatre * equipea, int pos, Personnage *tablist){
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
        default :
            printf("Erreur\n");
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
    }
}

void Assembleur_equipe(Equipe_quatre *equipea,Personnage *tablist, Game_state *etat, Perso_select *archive_etat, Position pos, SDL_Event e){
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
    } else if (mx >= btnAdd.x && mx < btnAdd.x + btnAdd.w && my >= btnAdd.y && my < btnAdd.y + btnAdd.h){
        selection = *archive_etat;
        affichage_e(selection);
        switch (pos){
            case P1:
                id(selection, equipea, pos, tablist);
                printf("Personnage en P1 : %s\n", equipea->tab[0].name);
                equipea->tab[3].pos = 0;
                break;
            case P2:
                id(selection, equipea, pos, tablist);
                printf("Personnage en P2 : %s\n", equipea->tab[1].name);
                equipea->tab[3].pos = 1;
                break;         
            case P3:
                id(selection, equipea, pos, tablist);
                printf("Personnage en P3 : %s\n", equipea->tab[2].name);
                equipea->tab[3].pos = 2;
                break;
            case P4:
                id(selection, equipea, pos, tablist);
                printf("Personnage en P4 : %s\n", equipea->tab[3].name);
                equipea->tab[3].pos = 3;
                break;
        }
        *etat = EQUIPE;
    }
}









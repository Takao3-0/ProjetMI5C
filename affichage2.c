#include "affichage.h"

void affichage_element(Personnage* defenseur,int degat, int elmt){
    switch (elmt) {
        case 1:    
            printf("│      %s se voit infligé %d dégâts. Il est affecté par l'element "BLEUF"Hydro."RESET,defenseur->name,degat);
            break;
        case 10:   
            printf("│      %s se voit infligé %d dégâts. Il est affecté par l'element "ORANGE"Pyro."RESET,defenseur->name,degat);
            break;
        case 100:  
            printf("│      %s se voit infligé %d dégâts. Il est affecté par l'element "VIOLET"Electro."RESET,defenseur->name,degat);
            break;
        case 1000: 
            printf("│      %s se voit infligé %d dégâts. Il est affecté par l'element "BLEUC"Cryo."RESET,defenseur->name,degat);
            break;
        default:   
            printf("│      %s se voit infligé %d dégâts. Il est affecté par l'element neutre.",defenseur->name,degat);
            break;
    }
}
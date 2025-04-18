#include "head.h"
#include "personnages.h"
#include "fight.h"
#include "createursquad.h"
#include "affichage.h"
#include "key.h"

int main() {
    system("chcp 65001");
    int z = 0;
    int zz = 0;
    mainscreen();
    // Extraction du tableau de personnages depuis le fichier "personnages.txt"
    Personnage *tabPerso = extract();
    if (tabPerso == NULL) {
        printf("Erreur lors de l'extraction des personnages.\n");
        return 1;
    }
    Equipe_deux * a;
    Equipe_deux * b;
    do {
        if (z =! -19){
            mainscreen();
            z = 0;
        }
        z = better_scan_int(1,4);  //1,4 correspond au bouton disponible (1 à 4)
        if (z == 1){
            secondscreen();
            do {
                if (zz != -19){
                    secondscreen();
                    zz = 0;    
                }
                zz = better_scan_int(1,6);
                switch(zz) {
                    case 1:
                        if (a == NULL || b == NULL){ //le fight ne peut pas s'éxecuter
                            screenerror();
                            zz = -19;
                        } else {
                            fight(a,b);
                        }
                        break;
                    case 4:  //on crée notre équipe  (et l'équipe adverse temporairement);
                        a = assembleur_squad_deux(tabPerso,1);
                        b = assembleur_squad_deux(tabPerso,2);
                        zz = 0;
                        break;
                    case 5: // boutique 
                        break;
                    case 6:
                        zz = 6;
                        break;
                    default :
                        screenerror();
                        zz = -19;
                        break;
                }

            } while (zz < 1 || zz > 6);
            z = 0;
        } else if (z == 4){
            return 0; //fin du jeu
        }
        if (z != 1 || z!= 2 || z!= 3 || z != 4){
            mainscreenerror();
            z = -19;
        }
    }while (z != 1 || z!= 2 || z!= 3 || z != 4);
    // Envoi du tableau à la fonction de combat

    /*Equipe_deux a,b;
    a.tab[0] = tabPerso[0];
    a.tab[1] = tabPerso[1];
    b.tab[0] = tabPerso[2];
    b.tab[1] = tabPerso[3];
    printf(BLEU"Avant de commencer veuillez choisir un nom d' equipe\n"RESET);
    scanf("%s", a.name);
    printf(BLEU"Entrez egalement le nom de la seconde equipe\n"RESET);  //A terme on aura un fichier texte avec plusieurs noms d'équipe et un sera pris au hasard pour jouer l'équipe du bot.
    scanf("%s", b.name);*/
    // Libération de la mémoire allouée
    free(tabPerso);
    return 0;
}

#include "head.h"
#include "personnages.h"
#include "fight.h"
#include "createursquad.h"

int main() {
    // Extraction du tableau de personnages depuis un fichier ou autre
    Personnage *tabPerso = extract();
    if (tabPerso == NULL) {
        printf("Erreur lors de l'extraction des personnages.\n");
        return 1;
    }
    
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

    Equipe_deux * a;
    Equipe_deux * b;
    a = assembleur_squad_deux(tabPerso,1);
    b = assembleur_squad_deux(tabPerso,2);
    fight(a,b);

    // Libération de la mémoire allouée
    free(tabPerso);
    return 0;
}

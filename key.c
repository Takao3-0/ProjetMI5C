#include "head.h"
#include "personnages.h"

int better_scan_int(int a, int b) {
    int c;
    // Si scanf ne lit pas un entier, retourne 0
    if (scanf("%d", &c) != 1) {
        // On vide le tampon d'entrée pour éviter que les caractères invalides ne restent
        while(getchar() != '\n');
        return 0;
    }
    if (a <= c && c <= b) {
        return c;
    } else {
        return 0;
    }
}
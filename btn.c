#include "head.h"

    //Premier menu
    SDL_Rect btnJOUER = { .x = 515, .y = 409, .w = 325, .h = 134 };
    SDL_Rect btnQUITTER = { .x = 515, .y = 572, .w = 325, .h = 134 };

    //Menu jeux principal

    SDL_Rect btnArchive = { .x = 138, .y = 257, .w = 108, .h = 98 };
    SDL_Rect btnBACK1 = { .x = 1259, .y = 662, .w = 73, .h = 70 };
    SDL_Rect btnEQUIPE = { .x = 254, .y = 257, .w = 108, .h = 95 };
    SDL_Rect btn4VS4 = { .x = 371, .y = 257, .w = 108, .h = 95 };

    //Menu jeux archive :

    SDL_Rect btnCROIXarchive = { .x = 1302, .y = 9, .w = 37, .h = 37 };
    SDL_Rect btnArchiveCriona = { .x = 14, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchiveGlacius = { .x = 126, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchiveTerrorex = { .x = 237, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchiveVulcain = { .x = 14, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnArchiveCalyra = { .x = 126, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnArchiveAqualis = { .x = 14, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnArchiveArcaniste = { .x = 14, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnArchiveVoltix = { .x = 126, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnArchiveNova = { .x = 237, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnArchiveAquanova = { .x = 126, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnArchiveKaelen = { .x = 350, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchivePyrobane = { .x = 239, .y = 265, .w = 95, .h = 121 };
    SDL_Rect btnArchiveEmbera = { .x = 351, .y = 265, .w = 95, .h = 121 };
    SDL_Rect btnArchiveHydragon = { .x = 239, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnArchiveVoltazor = { .x = 350, .y = 526, .w = 95, .h = 121 };

    //Menu jeux equipe : 

    
    SDL_Rect btnCROIXjeux = { .x = 1302, .y = 15, .w = 37, .h = 37 };
    SDL_Rect btnJeuxP1 = { .x = 88, .y = 657, .w = 227, .h = 48 };
    SDL_Rect btnJeuxP2 = { .x = 400, .y = 591, .w = 227, .h = 48 };
    SDL_Rect btnJeuxP3 = { .x = 790, .y = 591, .w = 227, .h = 48 };
    SDL_Rect btnJeuxP4 = { .x = 1091, .y = 657, .w = 227, .h = 48 };

    //Menu selection personnage

    SDL_Rect btnAdd = { .x = 51, .y = 693, .w = 198, .h = 54 };
    SDL_Rect btnEquipechangement = { .x = 1160, .y = 16, .w = 125, .h = 38 };
    SDL_Rect btnCROIXselection = { .x = 1302, .y = 15, .w = 37, .h = 37 };
    SDL_Rect btnSelectionCriona = { .x = 14, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionGlacius = { .x = 126, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionTerrorex = { .x = 237, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionVulcain = { .x = 14, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnSelectionCalyra = { .x = 126, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnSelectionAqualis = { .x = 14, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnSelectionArcaniste = { .x = 14, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnSelectionVoltix = { .x = 126, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnSelectionNova = { .x = 237, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnSelectionAquanova = { .x = 126, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnSelectionKaelen = { .x = 350, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionPyrobane = { .x = 239, .y = 265, .w = 95, .h = 121 };
    SDL_Rect btnSelectionEmbera = { .x = 351, .y = 265, .w = 95, .h = 121 };
    SDL_Rect btnSelectionHydragon = { .x = 239, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnSelectionVoltazor = { .x = 350, .y = 526, .w = 95, .h = 121 };


    //Menu 4v4

    SDL_Rect btnA1  = { .x = 107, .y = 552, .w = 240, .h = 107 };
    SDL_Rect btnA2  = { .x = 378, .y = 552, .w = 240, .h = 107 };
    SDL_Rect btnA3  = { .x = 107, .y = 662, .w = 240, .h = 107 };
    SDL_Rect btnA4  = { .x = 378, .y = 662, .w = 240, .h = 107 };
    SDL_Rect Cible1 = { .x = 284, .y = 369, .w = 205, .h = 30 };
    SDL_Rect Cible2 = { .x = 533, .y = 339, .w = 205, .h = 30 };
    SDL_Rect Cible3 = { .x = 771, .y = 338, .w = 205, .h = 30 };
    SDL_Rect Cible4 = { .x = 1015, .y = 370, .w = 205, .h = 30 };
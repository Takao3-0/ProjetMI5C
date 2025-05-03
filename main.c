#include "head.h"
#include "personnages.h"
#include "fight.h"
#include "createursquad.h"
#include "affichage.h"
#include "key.h"
#include "weapons.h"
#include "fightboss.h"

#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>

SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char *filePath) {
    SDL_Texture *tex = IMG_LoadTexture(renderer, filePath);
    if (!tex) {
        fprintf(stderr, "IMG_LoadTexture failed for \"%s\": %s\n",
                filePath, IMG_GetError());
    }
    return tex;
}

//Etat de jeux
typedef enum {
    MENU,   // écran de base
    MENUP,  // écran principal du jeux (l'image sera à modifier (ajouter des elmts))
    FIN,
    ARCHIVE,
    EQUIPE,
    SELECTION,
} Game_state;

typedef enum {
    VIDE,
    CRIONA,
    GLACIUS,
    TERROREX,
    VULCAIN,
    CALYRA,
    AQUALIS,
    NOVA,
    ARCANISTE,
    VOLTIX,
    IRONAPSOL,
} Archive_state;

typedef enum {
    P1,
    P2,
    P3,
    P4
} Position;

typedef struct {
    const char  *name;      // par exemple "Criona"
    SDL_Texture *tex;       // la texture chargée
} Perso;

// une « slot » à l’écran
typedef struct {
    int           x, y;     // position du coin supérieur gauche
    int           w, h;     // optionnel : taille du rendu (ou prendre tex->w/tex->h)
    int           idxChar;  // index dans le tableau characters[], ou -1 si vide
} Slot;




int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        fprintf(stderr, "IMG_Init failed: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // 1) Création de la fenêtre et du renderer
    SDL_Window   *win = SDL_CreateWindow("CY-FIGHTERS",
                         SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED,
                         1366, 768, 0);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!win || !ren) {
        fprintf(stderr, "Window/Renderer creation failed: %s\n", SDL_GetError());
        IMG_Quit(); SDL_Quit();
        return 1;
    }

    //Chargement des textures des menu

    SDL_Texture *screenMenu  = LoadTexture(ren, "assets/Fondfinal.png");
    SDL_Texture *screenPlay  = LoadTexture(ren, "assets/fondmenuv2.png");
    SDL_Texture *screenEquipe = LoadTexture(ren, "assets/Equipe.png");

    //Chargement personnages en png

    SDL_Texture *Criona = LoadTexture(ren, "assets/CrionaPNG.png");
    SDL_Texture *Arcaniste = LoadTexture(ren, "assets/ArcanistePNG.png");
    SDL_Texture *Voltix = LoadTexture(ren, "assets/VoltixPNG.png" );
    SDL_Texture *Aqualis = LoadTexture(ren, "assets/AqualisPNG.png");
    SDL_Texture *Calyra = LoadTexture(ren, "assets/CalyraPNG.png");
    SDL_Texture *Terrorex = LoadTexture(ren, "assets/TerrorexPNG.png");
    SDL_Texture *Glacius = LoadTexture(ren, "assets/GlaciusPNG.png");
    SDL_Texture *Nova = LoadTexture(ren, "assets/NovaPNG.png");
    SDL_Texture *Vulcain = LoadTexture(ren, "assets/VulcainPNG.png");

    //Chargement textures menu Archives

    SDL_Texture *archiveCriona  = LoadTexture(ren, "assets/EquipeCriona.png");
    SDL_Texture *archiveVoltix  = LoadTexture(ren, "assets/EquipeVoltix.png");
    SDL_Texture *archiveGlacius  = LoadTexture(ren, "assets/EquipeGlacius.png");
    SDL_Texture *archiveArcaniste  = LoadTexture(ren, "assets/EquipeArcaniste.png");
    SDL_Texture *archiveVulcain  = LoadTexture(ren, "assets/EquipeVulcain.png");
    SDL_Texture *archiveCalyra  = LoadTexture(ren, "assets/EquipeCalyra.png");
    SDL_Texture *archiveNova  = LoadTexture(ren, "assets/EquipeNova.png");
    SDL_Texture *archiveTerrorex  = LoadTexture(ren, "assets/EquipeTerrorex.png");
    SDL_Texture *archiveAqualis  = LoadTexture(ren, "assets/EquipeAqualis.png");

    //Chargement des textures de chargement

    SDL_Texture *AddCriona  = LoadTexture(ren, "assets/AddCriona.png");
    SDL_Texture *AddVoltix  = LoadTexture(ren, "assets/AddVoltix.png");
    SDL_Texture *AddGlacius  = LoadTexture(ren, "assets/AddGlacius.png");
    SDL_Texture *AddArcaniste  = LoadTexture(ren, "assets/AddArcaniste.png");
    SDL_Texture *AddVulcain  = LoadTexture(ren, "assets/AddVulcain.png");
    SDL_Texture *AddCalyra  = LoadTexture(ren, "assets/AddCalyra.png");
    SDL_Texture *AddNova  = LoadTexture(ren, "assets/AddNova.png");
    SDL_Texture *AddTerrorex  = LoadTexture(ren, "assets/AddTerrorex.png");
    SDL_Texture *AddAqualis  = LoadTexture(ren, "assets/AddAqualis.png");

    if (!screenMenu || !screenPlay) {
        SDL_DestroyTexture(screenMenu);
        SDL_DestroyTexture(screenPlay);
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        IMG_Quit(); SDL_Quit();
        return 1;
    }

    //Premier menu
    SDL_Rect btnJOUER = { .x = 515, .y = 409, .w = 325, .h = 134 };
    SDL_Rect btnQUITTER = { .x = 515, .y = 572, .w = 325, .h = 134 };

    //Menu jeux principal

    SDL_Rect btnArchive = { .x = 138, .y = 257, .w = 108, .h = 98 };
    SDL_Rect btnBACK1 = { .x = 1259, .y = 662, .w = 73, .h = 70 };
    SDL_Rect btnEQUIPE = { .x = 254, .y = 257, .w = 108, .h = 95 };

    //Menu jeux archive :

    SDL_Rect btnCROIXarchive = { .x = 1302, .y = 9, .w = 37, .h = 37 };
    SDL_Rect btnArchiveCriona = { .x = 14, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchiveGlacius = { .x = 126, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchiveTerrorex = { .x = 237, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnArchiveKaelen = { .x = 300, .y = 128, .w = 95, .h = 121 }; //Pas encore d'asset pour Kaelen 
    SDL_Rect btnArchiveVulcain = { .x = 14, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnArchiveCalyra = { .x = 126, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnArchiveAqualis = { .x = 14, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnArchiveArcaniste = { .x = 14, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnArchiveVoltix = { .x = 126, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnArchiveNova = { .x = 237, .y = 522, .w = 95, .h = 121 };

    //Menu jeux equipe : 

    
    SDL_Rect btnCROIXjeux = { .x = 1302, .y = 15, .w = 37, .h = 37 };
    SDL_Rect btnJeuxP1 = { .x = 88, .y = 657, .w = 227, .h = 48 };
    SDL_Rect btnJeuxP2 = { .x = 400, .y = 591, .w = 227, .h = 48 };
    SDL_Rect btnJeuxP3 = { .x = 790, .y = 591, .w = 227, .h = 48 };
    SDL_Rect btnJeuxP4 = { .x = 1091, .y = 657, .w = 227, .h = 48 };

    //Menu selection personnage

    SDL_Rect btnAdd = { .x = 51, .y = 693, .w = 198, .h = 54 };
    SDL_Rect btnCROIXselection = { .x = 1302, .y = 15, .w = 37, .h = 37 };
    SDL_Rect btnSelectionCriona = { .x = 14, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionGlacius = { .x = 126, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionTerrorex = { .x = 237, .y = 128, .w = 95, .h = 121 };
    SDL_Rect btnSelectionKaelen = { .x = 300, .y = 128, .w = 95, .h = 121 }; //Pas encore d'asset pour Kaelen 
    SDL_Rect btnSelectionVulcain = { .x = 14, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnSelectionCalyra = { .x = 126, .y = 264, .w = 95, .h = 121 };
    SDL_Rect btnSelectionAqualis = { .x = 14, .y = 391, .w = 95, .h = 121 };
    SDL_Rect btnSelectionArcaniste = { .x = 14, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnSelectionVoltix = { .x = 126, .y = 522, .w = 95, .h = 121 };
    SDL_Rect btnSelectionNova = { .x = 237, .y = 522, .w = 95, .h = 121 };



    // état courant
    Game_state etat = MENU;
    Archive_state archive_etat = CRIONA;
    Archive_state selection = VIDE;
    Position pos = P1;

    Slot slots[4] = {
        { .x =  50, .y = 90, .w = 0, .h = 0, .idxChar = -1 },
        { .x = 400, .y = 30, .w = 0, .h = 0, .idxChar = -1 },
        { .x =  750, .y = 30, .w = 0, .h = 0, .idxChar = -1 },
        { .x = 1100, .y = 90, .w = 0, .h = 0, .idxChar = -1 },
    };

    // 4) Boucle principale
    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            int mx = e.button.x;
            int my = e.button.y;
            if (e.type == SDL_QUIT || etat == FIN) {
                running = false;
            }
            // clic gauche en MENU dans btnJouer → passage en MENUP
            else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == MENU){
                if (mx >= btnJOUER.x && mx < btnJOUER.x + btnJOUER.w && my >= btnJOUER.y && my < btnJOUER.y + btnJOUER.h){//Btn joueur menu base
                    etat = MENUP;
                    printf("Passage sur le menu principal de jeu\n");
                } else if (mx >= btnQUITTER.x && mx < btnQUITTER.x + btnQUITTER.w && my >= btnQUITTER.y && my < btnQUITTER.y + btnQUITTER.h){//Btn quitter menu base
                    printf("Fin du jeu\n");
                    etat = FIN;
                }
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == MENUP){
                if (mx >= btnBACK1.x && mx < btnBACK1.x + btnBACK1.w && my >= btnBACK1.y && my < btnBACK1.y + btnBACK1.h){
                    etat = MENU;
                } else if (mx >= btnArchive.x && mx < btnArchive.x + btnArchive.w && my >= btnArchive.y && my < btnArchive.y + btnArchive.h){
                    etat = ARCHIVE;
                } else if (mx >= btnEQUIPE.x && mx < btnEQUIPE.x + btnEQUIPE.w && my >= btnEQUIPE.y && my < btnEQUIPE.y + btnEQUIPE.h){
                    etat = EQUIPE;
                }
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == ARCHIVE){
                if (mx >= btnCROIXarchive.x && mx < btnCROIXarchive.x + btnCROIXarchive.w && my >= btnCROIXarchive.y && my < btnCROIXarchive.y + btnCROIXarchive.h){
                    etat = MENUP;
                } else if (mx >= btnArchiveCriona.x && mx < btnArchiveCriona.x + btnArchiveCriona.w && my >= btnArchiveCriona.y && my < btnArchiveCriona.y + btnArchiveCriona.h){
                    archive_etat = CRIONA;    
                }  else if (mx >= btnArchiveGlacius.x && mx < btnArchiveGlacius.x + btnArchiveGlacius.w && my >= btnArchiveGlacius.y && my < btnArchiveGlacius.y + btnArchiveGlacius.h){
                    archive_etat = GLACIUS;    
                } else if (mx >= btnArchiveTerrorex.x && mx < btnArchiveTerrorex.x + btnArchiveTerrorex.w && my >= btnArchiveTerrorex.y && my < btnArchiveTerrorex.y + btnArchiveTerrorex.h){
                    archive_etat = TERROREX;    
                } else if (mx >= btnArchiveVulcain.x && mx < btnArchiveVulcain.x + btnArchiveVulcain.w && my >= btnArchiveVulcain.y && my < btnArchiveVulcain.y + btnArchiveVulcain.h){
                    archive_etat = VULCAIN;    
                } else if (mx >= btnArchiveCalyra.x && mx < btnArchiveCalyra.x + btnArchiveCalyra.w && my >= btnArchiveCalyra.y && my < btnArchiveCalyra.y + btnArchiveCalyra.h){
                    archive_etat = CALYRA;    
                } else if (mx >= btnArchiveAqualis.x && mx < btnArchiveAqualis.x + btnArchiveAqualis.w && my >= btnArchiveAqualis.y && my < btnArchiveAqualis.y + btnArchiveAqualis.h){
                    archive_etat = AQUALIS;    
                } else if (mx >= btnArchiveArcaniste.x && mx < btnArchiveArcaniste.x + btnArchiveArcaniste.w && my >= btnArchiveArcaniste.y && my < btnArchiveArcaniste.y + btnArchiveArcaniste.h){
                    archive_etat = ARCANISTE;    
                } else if (mx >= btnArchiveVoltix.x && mx < btnArchiveVoltix.x + btnArchiveVoltix.w && my >= btnArchiveVoltix.y && my < btnArchiveVoltix.y + btnArchiveVoltix.h){
                    archive_etat = VOLTIX;    
                } else if (mx >= btnArchiveNova.x && mx < btnArchiveNova.x + btnArchiveNova.w && my >= btnArchiveNova.y && my < btnArchiveNova.y + btnArchiveNova.h){
                    archive_etat = NOVA;    
                }
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == EQUIPE){ //Quand on est dans le menu Equipe
                if(mx >= btnCROIXjeux.x && mx < btnCROIXjeux.x + btnCROIXjeux.w && my >= btnCROIXjeux.y && my < btnCROIXjeux.y + btnCROIXjeux.h){
                    etat = MENUP;
                } else if (mx >= btnJeuxP1.x && mx < btnJeuxP1.x + btnJeuxP1.w && my >= btnJeuxP1.y && my < btnJeuxP1.y + btnJeuxP1.h){
                    etat = SELECTION; 
                    pos = P1; 
                } else if (mx >= btnJeuxP2.x && mx < btnJeuxP2.x + btnJeuxP2.w && my >= btnJeuxP2.y && my < btnJeuxP2.y + btnJeuxP2.h){
                    etat = SELECTION; 
                    pos = P2;
                } else if (mx >= btnJeuxP3.x && mx < btnJeuxP3.x + btnJeuxP3.w && my >= btnJeuxP3.y && my < btnJeuxP3.y + btnJeuxP3.h){
                    etat = SELECTION; 
                    pos = P3;
                } else if (mx >= btnJeuxP4.x && mx < btnJeuxP4.x + btnJeuxP4.w && my >= btnJeuxP4.y && my < btnJeuxP4.y + btnJeuxP4.h){
                    etat = SELECTION; 
                    pos = P4;
                } 
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == SELECTION){
                if (mx >= btnCROIXarchive.x && mx < btnCROIXarchive.x + btnCROIXarchive.w && my >= btnCROIXarchive.y && my < btnCROIXarchive.y + btnCROIXarchive.h){
                    etat = EQUIPE;
                } else if (mx >= btnArchiveCriona.x && mx < btnArchiveCriona.x + btnArchiveCriona.w && my >= btnArchiveCriona.y && my < btnArchiveCriona.y + btnArchiveCriona.h){
                    archive_etat = CRIONA;    
                }  else if (mx >= btnArchiveGlacius.x && mx < btnArchiveGlacius.x + btnArchiveGlacius.w && my >= btnArchiveGlacius.y && my < btnArchiveGlacius.y + btnArchiveGlacius.h){
                    archive_etat = GLACIUS;    
                } else if (mx >= btnArchiveTerrorex.x && mx < btnArchiveTerrorex.x + btnArchiveTerrorex.w && my >= btnArchiveTerrorex.y && my < btnArchiveTerrorex.y + btnArchiveTerrorex.h){
                    archive_etat = TERROREX;    
                } else if (mx >= btnArchiveVulcain.x && mx < btnArchiveVulcain.x + btnArchiveVulcain.w && my >= btnArchiveVulcain.y && my < btnArchiveVulcain.y + btnArchiveVulcain.h){
                    archive_etat = VULCAIN;    
                } else if (mx >= btnArchiveCalyra.x && mx < btnArchiveCalyra.x + btnArchiveCalyra.w && my >= btnArchiveCalyra.y && my < btnArchiveCalyra.y + btnArchiveCalyra.h){
                    archive_etat = CALYRA;    
                } else if (mx >= btnArchiveAqualis.x && mx < btnArchiveAqualis.x + btnArchiveAqualis.w && my >= btnArchiveAqualis.y && my < btnArchiveAqualis.y + btnArchiveAqualis.h){
                    archive_etat = AQUALIS;    
                } else if (mx >= btnArchiveArcaniste.x && mx < btnArchiveArcaniste.x + btnArchiveArcaniste.w && my >= btnArchiveArcaniste.y && my < btnArchiveArcaniste.y + btnArchiveArcaniste.h){
                    archive_etat = ARCANISTE;    
                } else if (mx >= btnArchiveVoltix.x && mx < btnArchiveVoltix.x + btnArchiveVoltix.w && my >= btnArchiveVoltix.y && my < btnArchiveVoltix.y + btnArchiveVoltix.h){
                    archive_etat = VOLTIX;    
                } else if (mx >= btnArchiveNova.x && mx < btnArchiveNova.x + btnArchiveNova.w && my >= btnArchiveNova.y && my < btnArchiveNova.y + btnArchiveNova.h){
                    archive_etat = NOVA;    
                } else if (mx >= btnAdd.x && mx < btnAdd.x + btnAdd.w && my >= btnAdd.y && my < btnAdd.y + btnAdd.h){
                    selection = archive_etat;
                    etat = EQUIPE;
                }
            }

        }

        // 5) Rendu selon l'état
        SDL_RenderClear(ren); //On efface tout

        switch (etat) {
            case MENU:
                SDL_RenderCopy(ren, screenMenu, NULL, NULL);
                break;
            case MENUP:
                SDL_RenderCopy(ren, screenPlay, NULL, NULL);
                break;
            case EQUIPE:
                SDL_RenderCopy(ren, screenEquipe, NULL, NULL);
                switch (selection){
                    case CRIONA:
                    int texW, texH;
                    SDL_QueryTexture(Criona, NULL, NULL, &texW, &texH);
            
                    // tu peux positionner ton sprite où tu veux :
                    SDL_Rect dst = {
                        .x = 50,      // exemple : aux mêmes coords que ton btnJOUER
                        .y = 190,      // ou ailleurs, selon ton design
                        .w = texW,
                        .h = texH
                    };
                    SDL_RenderCopy(ren, Criona, NULL, &dst);

                }
                break;
            case ARCHIVE:
                switch (archive_etat){
                    case CRIONA:
                        SDL_RenderCopy(ren, archiveCriona, NULL, NULL);  
                        break; 
                    case GLACIUS:
                        SDL_RenderCopy(ren, archiveGlacius, NULL, NULL);  
                        break; 
                    case TERROREX:
                        SDL_RenderCopy(ren, archiveTerrorex, NULL, NULL);  
                        break;
                    case VULCAIN:
                        SDL_RenderCopy(ren, archiveVulcain, NULL, NULL);  
                        break;
                    case CALYRA:
                        SDL_RenderCopy(ren, archiveCalyra, NULL, NULL);  
                        break; 
                    case AQUALIS:
                        SDL_RenderCopy(ren, archiveAqualis, NULL, NULL);  
                        break;       
                    case ARCANISTE:
                        SDL_RenderCopy(ren, archiveArcaniste, NULL, NULL);  
                        break;    
                    case VOLTIX:
                        SDL_RenderCopy(ren, archiveVoltix, NULL, NULL);  
                        break;  
                    case NOVA:
                        SDL_RenderCopy(ren, archiveNova, NULL, NULL);  
                        break;                                
                }
                break;
            case SELECTION:
                switch (archive_etat){
                    case CRIONA:
                        SDL_RenderCopy(ren, AddCriona, NULL, NULL);  
                        break; 
                    case GLACIUS:
                        SDL_RenderCopy(ren, AddGlacius, NULL, NULL);  
                        break; 
                    case TERROREX:
                        SDL_RenderCopy(ren, AddTerrorex, NULL, NULL);  
                        break;
                    case VULCAIN:
                        SDL_RenderCopy(ren, AddVulcain, NULL, NULL);  
                        break;
                    case CALYRA:
                        SDL_RenderCopy(ren, AddCalyra, NULL, NULL);  
                        break; 
                    case AQUALIS:
                        SDL_RenderCopy(ren, AddAqualis, NULL, NULL);  
                        break;       
                    case ARCANISTE:
                        SDL_RenderCopy(ren, AddArcaniste, NULL, NULL);  
                        break;    
                    case VOLTIX:
                        SDL_RenderCopy(ren, AddVoltix, NULL, NULL);  
                        break;  
                    case NOVA:
                        SDL_RenderCopy(ren, AddNova, NULL, NULL);  
                        break;                                
                }                
                break;
            default:
                break;
        }
        
        SDL_RenderPresent(ren);

        SDL_Delay(16);  // ~60 FPS
    }
}

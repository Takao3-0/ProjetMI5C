#include "textures.h"
#include "head.h"

SDL_Texture *screenMenu   = NULL;
SDL_Texture *screenPlay   = NULL;
SDL_Texture *screenEquipe = NULL;
SDL_Texture *vide         = NULL;

// personnages
SDL_Texture *Criona    = NULL;
SDL_Texture *Arcaniste = NULL;
SDL_Texture *Voltix    = NULL;
SDL_Texture *Aqualis   = NULL;
SDL_Texture *Calyra    = NULL;
SDL_Texture *Terrorex  = NULL;
SDL_Texture *Glacius   = NULL;
SDL_Texture *Nova      = NULL;
SDL_Texture *Vulcain   = NULL;

// archives
SDL_Texture *archiveCriona    = NULL;
SDL_Texture *archiveVoltix    = NULL;
SDL_Texture *archiveGlacius   = NULL;
SDL_Texture *archiveArcaniste = NULL;
SDL_Texture *archiveVulcain   = NULL;
SDL_Texture *archiveCalyra    = NULL;
SDL_Texture *archiveNova      = NULL;
SDL_Texture *archiveTerrorex  = NULL;
SDL_Texture *archiveAqualis   = NULL;

// “Add” textures
SDL_Texture *AddCriona    = NULL;
SDL_Texture *AddVoltix    = NULL;
SDL_Texture *AddGlacius   = NULL;
SDL_Texture *AddArcaniste = NULL;
SDL_Texture *AddVulcain   = NULL;
SDL_Texture *AddCalyra    = NULL;
SDL_Texture *AddNova      = NULL;
SDL_Texture *AddTerrorex  = NULL;
SDL_Texture *AddAqualis   = NULL;

// — implémentation du loader — 
SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char *filePath) {
    SDL_Texture *tex = IMG_LoadTexture(renderer, filePath);
    if (!tex) {
        fprintf(stderr, "IMG_LoadTexture failed for \"%s\": %s\n",
                filePath, IMG_GetError());
    }
    return tex;
}

// (optionnel) fonction qui charge TOUTE tes textures en une seule fois
void Import_tex(SDL_Renderer *ren){
    screenMenu   = LoadTexture(ren, "assets/Fondfinal.png");
    screenPlay   = LoadTexture(ren, "assets/fondmenuv2.png");
    screenEquipe = LoadTexture(ren, "assets/Equipe.png");

    Criona    = LoadTexture(ren, "assets/CrionaPNG.png");
    Arcaniste = LoadTexture(ren, "assets/ArcanistePNG.png");
    Voltix    = LoadTexture(ren, "assets/VoltixPNG.png");
    Aqualis   = LoadTexture(ren, "assets/AqualisPNG.png");
    Calyra    = LoadTexture(ren, "assets/CalyraPNG.png");
    Terrorex  = LoadTexture(ren, "assets/TerrorexPNG.png");
    Glacius   = LoadTexture(ren, "assets/GlaciusPNG.png");
    Nova      = LoadTexture(ren, "assets/NovaPNG.png");
    Vulcain   = LoadTexture(ren, "assets/VulcainPNG.png");

    archiveCriona    = LoadTexture(ren, "assets/EquipeCriona.png");
    archiveVoltix    = LoadTexture(ren, "assets/EquipeVoltix.png");
    archiveGlacius   = LoadTexture(ren, "assets/EquipeGlacius.png");
    archiveArcaniste = LoadTexture(ren, "assets/EquipeArcaniste.png");
    archiveVulcain   = LoadTexture(ren, "assets/EquipeVulcain.png");
    archiveCalyra    = LoadTexture(ren, "assets/EquipeCalyra.png");
    archiveNova      = LoadTexture(ren, "assets/EquipeNova.png");
    archiveTerrorex  = LoadTexture(ren, "assets/EquipeTerrorex.png");
    archiveAqualis   = LoadTexture(ren, "assets/EquipeAqualis.png");

    AddCriona    = LoadTexture(ren, "assets/AddCriona.png");
    AddVoltix    = LoadTexture(ren, "assets/AddVoltix.png");
    AddGlacius   = LoadTexture(ren, "assets/AddGlacius.png");
    AddArcaniste = LoadTexture(ren, "assets/AddArcaniste.png");
    AddVulcain   = LoadTexture(ren, "assets/AddVulcain.png");
    AddCalyra    = LoadTexture(ren, "assets/AddCalyra.png");
    AddNova      = LoadTexture(ren, "assets/AddNova.png");
    AddTerrorex  = LoadTexture(ren, "assets/AddTerrorex.png");
    AddAqualis   = LoadTexture(ren, "assets/AddAqualis.png");
}
#include "textures.h"
#include "head.h"

SDL_Texture *screenMenu   = NULL;
SDL_Texture *screenPlay   = NULL;
SDL_Texture *screenEquipe = NULL;
SDL_Texture *vide         = NULL;
SDL_Texture *screenEquipe1 = NULL;
SDL_Texture *screenEquipe2 = NULL;

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
SDL_Texture *Aquanova  = NULL;
SDL_Texture *Embera    = NULL;
SDL_Texture *Kaelen    = NULL;
SDL_Texture *Voltazor  = NULL;
SDL_Texture *Pyrobane  = NULL;
SDL_Texture *Hydragon  = NULL;

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

// Add textures
SDL_Texture *AddCriona    = NULL;
SDL_Texture *AddVoltix    = NULL;
SDL_Texture *AddGlacius   = NULL;
SDL_Texture *AddArcaniste = NULL;
SDL_Texture *AddVulcain   = NULL;
SDL_Texture *AddCalyra    = NULL;
SDL_Texture *AddNova      = NULL;
SDL_Texture *AddTerrorex  = NULL;
SDL_Texture *AddAqualis   = NULL;
SDL_Texture *AddAquanova  = NULL;
SDL_Texture *AddKaelen    = NULL;
SDL_Texture *AddEmbera    = NULL;
SDL_Texture *AddVoltazor  = NULL;
SDL_Texture *AddHydragon  = NULL;
SDL_Texture *AddPyrobane  = NULL;

// Fight

SDL_Texture *Fight        = NULL;
SDL_Texture *HP           = NULL;
SDL_Texture *CrionaF      = NULL;
SDL_Texture *VoltixF      = NULL;
SDL_Texture *GlaciusF     = NULL;
SDL_Texture *TerrorexF    = NULL;
SDL_Texture *AqualisF     = NULL;
SDL_Texture *NovaF        = NULL;
SDL_Texture *CalyraF      = NULL;
SDL_Texture *VulcainF     = NULL;
SDL_Texture *ArcanisteF   = NULL;
SDL_Texture *AquanovaF    = NULL;
SDL_Texture *PyrobaneF    = NULL;
SDL_Texture *EmberaF      = NULL;
SDL_Texture *HydragonF    = NULL;
SDL_Texture *KaelenF      = NULL;
SDL_Texture *VoltazorF    = NULL;

//

// implémentation du chargeur d'img
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
    screenEquipe1 = LoadTexture(ren, "assets/Equipe1.png");
    screenEquipe2 = LoadTexture(ren, "assets/Equipe2.png");


    Criona    = LoadTexture(ren, "assets/CrionaPNG.png");
    Arcaniste = LoadTexture(ren, "assets/ArcanistePNG.png");
    Voltix    = LoadTexture(ren, "assets/VoltixPNG.png");
    Aqualis   = LoadTexture(ren, "assets/AqualisPNG.png");
    Calyra    = LoadTexture(ren, "assets/CalyraPNG.png");
    Terrorex  = LoadTexture(ren, "assets/TerrorexPNG.png");
    Glacius   = LoadTexture(ren, "assets/GlaciusPNG.png");
    Nova      = LoadTexture(ren, "assets/NovaPNG.png");
    Vulcain   = LoadTexture(ren, "assets/VulcainPNG.png");
    Aquanova  = LoadTexture(ren, "assets/AquanovaPNG.png");
    Embera    = LoadTexture(ren, "assets/EmberaPNG.png");
    Kaelen    = LoadTexture(ren, "assets/KaelenPNG.png");
    Voltazor  = LoadTexture(ren, "assets/VoltazorPNG.png");
    Pyrobane  = LoadTexture(ren, "assets/PyrobanePNG.png");
    Hydragon  = LoadTexture(ren, "assets/HydragonPNG.png");

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
    AddAquanova   = LoadTexture(ren, "assets/AddAquanova.png");
    AddKaelen   = LoadTexture(ren, "assets/AddKaelen.png");
    AddEmbera   = LoadTexture(ren, "assets/AddEmbera.png");
    AddVoltazor   = LoadTexture(ren, "assets/AddVoltazor.png");
    AddHydragon   = LoadTexture(ren, "assets/AddHydragon.png");
    AddPyrobane   = LoadTexture(ren, "assets/AddPyrobane.png");

    //Pour le fight

    Fight        = LoadTexture(ren, "assets/Fight.png");
    HP           = LoadTexture(ren, "assets/Barrehp.png");
    CrionaF      = LoadTexture(ren, "assets/CrionaF.png");
    VoltixF      = LoadTexture(ren, "assets/VoltixF.png");
    GlaciusF     = LoadTexture(ren, "assets/GlaciusF.png");
    TerrorexF    = LoadTexture(ren, "assets/TerrorexF.png");
    AqualisF     = LoadTexture(ren, "assets/AqualisF.png");
    NovaF        = LoadTexture(ren, "assets/NovaF.png");
    CalyraF      = LoadTexture(ren, "assets/CalyraF.png");
    VulcainF     = LoadTexture(ren, "assets/VulcainF.png");
    ArcanisteF   = LoadTexture(ren, "assets/ArcanisteF.png");
    AquanovaF    = LoadTexture(ren, "assets/AquanovaF.png");
    PyrobaneF    = LoadTexture(ren, "assets/PyrobaneF.png");
    EmberaF      = LoadTexture(ren, "assets/EmberaF.png");
    HydragonF    = LoadTexture(ren, "assets/HydragonF.png");
    KaelenF      = LoadTexture(ren, "assets/KaelenF.png");
    VoltazorF    = LoadTexture(ren, "assets/VoltazorF.png");


}
#ifndef _TEXTURES
#define _TEXTURES

#include "head.h"

//Chargement des textures des menu
extern SDL_Texture *screenMenu;
extern SDL_Texture *screenPlay;
extern SDL_Texture *screenEquipe;
extern SDL_Texture *vide;
extern SDL_Texture *screenEquipe1;
extern SDL_Texture *screenEquipe2;

//Chargement personnages en png
extern SDL_Texture *Criona;
extern SDL_Texture *Arcaniste;
extern SDL_Texture *Voltix;
extern SDL_Texture *Aqualis;
extern SDL_Texture *Calyra;
extern SDL_Texture *Terrorex;
extern SDL_Texture *Glacius;
extern SDL_Texture *Nova;
extern SDL_Texture *Vulcain;
extern SDL_Texture *Aquanova;
extern SDL_Texture *Embera;
extern SDL_Texture *Kaelen;
extern SDL_Texture *Voltazor;
extern SDL_Texture *Pyrobane;
extern SDL_Texture *Hydragon;

//Chargement textures menu Archives
extern SDL_Texture *archiveCriona;
extern SDL_Texture *archiveVoltix;
extern SDL_Texture *archiveGlacius;
extern SDL_Texture *archiveArcaniste;
extern SDL_Texture *archiveVulcain;
extern SDL_Texture *archiveCalyra;
extern SDL_Texture *archiveNova;
extern SDL_Texture *archiveTerrorex;
extern SDL_Texture *archiveAqualis;

//Chargement des textures de chargement
extern SDL_Texture *AddCriona;
extern SDL_Texture *AddVoltix;
extern SDL_Texture *AddGlacius;
extern SDL_Texture *AddArcaniste;
extern SDL_Texture *AddVulcain;
extern SDL_Texture *AddCalyra;
extern SDL_Texture *AddNova;
extern SDL_Texture *AddTerrorex;
extern SDL_Texture *AddAqualis;
extern SDL_Texture *AddAquanova;
extern SDL_Texture *AddKaelen;
extern SDL_Texture *AddEmbera;
extern SDL_Texture *AddVoltazor;
extern SDL_Texture *AddHydragon;
extern SDL_Texture *AddPyrobane;


extern SDL_Texture *Fight;
extern SDL_Texture *HP;
extern SDL_Texture *CrionaF;  
extern SDL_Texture *VoltixF;  
extern SDL_Texture *GlaciusF;   
extern SDL_Texture *TerrorexF; 
extern SDL_Texture *AqualisF;
extern SDL_Texture *NovaF;
extern SDL_Texture *CalyraF;
extern SDL_Texture *VulcainF;
extern SDL_Texture *ArcanisteF;
extern SDL_Texture *AquanovaF;
extern SDL_Texture *PyrobaneF;
extern SDL_Texture *EmberaF;
extern SDL_Texture *HydragonF;
extern SDL_Texture *KaelenF;
extern SDL_Texture *VoltazorF;

SDL_Texture* LoadTexture(SDL_Renderer *renderer, const char *filePath);
void Import_tex(SDL_Renderer *ren);

#endif

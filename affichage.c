#include "affichage.h"
#include "textures.h"
#include "head.h"
#include "createursquad.h"

void squad_affichage(SDL_Renderer *ren, Equipe_quatre equipe){
    Slot slots[4] = {
        { .x =  30, .y = 110, .w = 0, .h = 0},
        { .x = 320, .y = 50, .w = 0, .h = 0},
        { .x =  680, .y = 50, .w = 0, .h = 0},
        { .x = 1000, .y = 110, .w = 0, .h = 0},
    };
    for (int i=0; i<4; i++){
        switch (equipe.tab[i].NOM){
            int w, h;
            case CRIONA:
                SDL_QueryTexture(Criona, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst0 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Criona, NULL, &dst0);  
                break;
            case GLACIUS:
                SDL_QueryTexture(Glacius, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst1 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Glacius, NULL, &dst1); 
                break; 
            case ARCANISTE:
                SDL_QueryTexture(Arcaniste, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst2 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Arcaniste, NULL, &dst2); 
                break;
            case CALYRA:
                SDL_QueryTexture(Calyra, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst3 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Calyra, NULL, &dst3); 
                break;  
            case VULCAIN:
                SDL_QueryTexture(Vulcain, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst4 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Vulcain, NULL, &dst4); 
                break;
            case AQUALIS:
                SDL_QueryTexture(Calyra, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst5 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Aqualis, NULL, &dst5); 
                break;
            case NOVA:
                SDL_QueryTexture(Nova, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst6 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Nova, NULL, &dst6); 
                break;
            case TERROREX:
                SDL_QueryTexture(Terrorex, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst7 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Terrorex, NULL, &dst7); 
                break;
            case VOLTIX:
                SDL_QueryTexture(Voltix, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst8 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Voltix, NULL, &dst8); 
                break;
            case VIDE:
                SDL_QueryTexture(vide, NULL, NULL, &w, &h);
        
                // 4) Créer un dstRect plus petit : par ex. 100×100 pixels à (50,50)
                SDL_Rect dst9 = { .x = slots[i].x, .y = slots[i].y, .w = 400, .h = 590 };
                SDL_RenderCopy(ren, vide, NULL, &dst9); 

        }        
    }

}



void affichage(SDL_Renderer *ren, Perso_select archive_etat, Game_state etat, Perso_select selection, Equipe_quatre equipea){
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
            squad_affichage(ren,equipea);
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
    SDL_Delay(16);
}
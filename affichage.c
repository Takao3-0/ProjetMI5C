#include "affichage.h"
#include "textures.h"
#include "head.h"
#include "createursquad.h"

void squad_affichage(SDL_Renderer *ren, Equipe_quatre equipe, Slot *slots){
    for (int i=0; i<4; i++){
        switch (equipe.tab[i].NOM){
            int w, h;
            case CRIONA:
                SDL_QueryTexture(Criona, NULL, NULL, &w, &h);
        

                SDL_Rect dst0 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Criona, NULL, &dst0);  
                break;
            case GLACIUS:
                SDL_QueryTexture(Glacius, NULL, NULL, &w, &h);
        

                SDL_Rect dst1 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Glacius, NULL, &dst1); 
                break; 
            case ARCANISTE:
                SDL_QueryTexture(Arcaniste, NULL, NULL, &w, &h);
        

                SDL_Rect dst2 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Arcaniste, NULL, &dst2); 
                break;
            case CALYRA:
                SDL_QueryTexture(Calyra, NULL, NULL, &w, &h);
        

                SDL_Rect dst3 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Calyra, NULL, &dst3); 
                break;  
            case VULCAIN:
                SDL_QueryTexture(Vulcain, NULL, NULL, &w, &h);
        

                SDL_Rect dst4 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Vulcain, NULL, &dst4); 
                break;
            case AQUALIS:
                SDL_QueryTexture(Calyra, NULL, NULL, &w, &h);
        

                SDL_Rect dst5 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Aqualis, NULL, &dst5); 
                break;
            case NOVA:
                SDL_QueryTexture(Nova, NULL, NULL, &w, &h);
        

                SDL_Rect dst6 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Nova, NULL, &dst6); 
                break;
            case TERROREX:
                SDL_QueryTexture(Terrorex, NULL, NULL, &w, &h);
        

                SDL_Rect dst7 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Terrorex, NULL, &dst7); 
                break;
            case VOLTIX:
                SDL_QueryTexture(Voltix, NULL, NULL, &w, &h);
        

                SDL_Rect dst8 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, Voltix, NULL, &dst8); 
                break;
            case VIDE:
                SDL_QueryTexture(vide, NULL, NULL, &w, &h);
        

                SDL_Rect dst9 = { .x = slots[i].x, .y = slots[i].y, .w = 400, .h = 590 };
                SDL_RenderCopy(ren, vide, NULL, &dst9); 

        }        
    }

}

void barrehp(SDL_Renderer *ren, Equipe_quatre equipe){
    Slot slotbarrehp[4] = {
        { .x =  308, .y = 58, .w = 160, .h = 30},
        { .x =  556, .y = 29, .w = 160, .h = 30},
        { .x =  795, .y = 44, .w = 160, .h = 30},
        { .x =  1040, .y = 59, .w = 160, .h = 30},
    };
    for (int i=0; i<4; i++){
        int w;
        SDL_Rect pos = { .x = slotbarrehp[i].x, .y = slotbarrehp[i].y, .w = 150*(equipe.tab[i].pv/equipe.tab[i].pvmax), .h = 30 };
        SDL_RenderCopy(ren, HP, NULL, &pos);
        
    }
}

void convert_texte(const char *texte, TTF_Font *font, SDL_Renderer *ren, int x, int y){
    SDL_Color BLANC = {255,255,255,255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, texte, BLANC);
    SDL_Texture *le_texte = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    SDL_Rect position;
    position.x = x;  // position a l’écran
    position.y = y;
    SDL_QueryTexture(le_texte, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(ren, le_texte, NULL, &position);
}

int verificationcomplete(Equipe_quatre equipe){
    for (int i=0;i<4;i++){
        if (equipe.tab[i].rarete != 4 && equipe.tab[i].rarete != 5){
            return 1;
        }
    }
    return 0;

}



void affichage(SDL_Renderer *ren, Perso_select archive_etat, Game_state etat, Perso_select selection, Equipe_quatre equipea, Game_state equipe, TTF_Font *font){
    Slot slotscreate[4] = {
        { .x =  30, .y = 110, .w = 0, .h = 0},
        { .x = 320, .y = 50, .w = 0, .h = 0},
        { .x =  680, .y = 50, .w = 0, .h = 0},
        { .x = 1000, .y = 110, .w = 0, .h = 0},
    };
    Slot slotsfight[4] = {
        { .x =  30, .y = 110, .w = 0, .h = 0},
        { .x = 320, .y = 50, .w = 0, .h = 0},
        { .x =  680, .y = 50, .w = 0, .h = 0},
        { .x = 1000, .y = 110, .w = 0, .h = 0},
    };
    
    SDL_RenderClear(ren); //On efface tout
    SDL_Color BLANC = {255,255,255,255};
    int a = 0;
    switch (etat) {
        case MENU:
            SDL_RenderCopy(ren, screenMenu, NULL, NULL);
            break;
        case MENUP:
            SDL_RenderCopy(ren, screenPlay, NULL, NULL);
            convert_texte("Bite",font,ren,100,100);
            break;
        case EQUIPE:
            if (equipe == E1){
                SDL_RenderCopy(ren, screenEquipe2, NULL, NULL);   
                convert_texte("1",font,ren,173,22); 
            } else if (equipe == E2){
                SDL_RenderCopy(ren, screenEquipe1, NULL, NULL);
                convert_texte("2",font,ren,173,22);     
            }
            squad_affichage(ren,equipea,slotscreate);
            break;
        case VERSUS4:
        a = verificationcomplete(equipea);
            if (a == 1 ){
                SDL_RenderCopy(ren, screenPlay, NULL, NULL);  
                convert_texte("Impossible de lancer le combat en raison d'equipe manquante.",font,ren,350,100);
                break;       
            } else {
                SDL_RenderCopy(ren, Fight, NULL, NULL);
                squad_affichage(ren,equipea,slotsfight);
                barrehp(ren,equipea);
                break;
            }
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
    /*if (a==1){
        a=0;
        affichage(ren, archive_etat, MENUP, selection, equipea, equipe,font);
    }*/
}
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
                SDL_QueryTexture(Aqualis, NULL, NULL, &w, &h);
        

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
        float pvm = equipe.tab[i].pvmax;
        float pv = equipe.tab[i].pv;
        float coef = 150*(pv/pvm);
        int ww = coef; 
        SDL_Rect pos = { .x = slotbarrehp[i].x, .y = slotbarrehp[i].y, .w = ww, .h = 30 };
        SDL_RenderCopy(ren, HP, NULL, &pos);
        
    }
}

void convert_texte(const char *texte, TTF_Font *font, SDL_Renderer *ren, int x, int y){
    SDL_Color BLANC = {0,0,0,255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, texte, BLANC);
    SDL_Texture *le_texte = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    SDL_Rect position;
    position.x = x;
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

void affichage_attaque(Personnage attaquant, SDL_Renderer *ren, TTF_Font *font){
    Slot attaques[4] = {
        { .x = 104, .y = 529, .w = 240, .h = 107 },
        { .x = 372, .y = 529, .w = 240, .h = 107 },
        { .x = 104, .y = 640, .w = 240, .h = 107 },
        { .x = 372, .y = 640, .w = 240, .h = 107 },
    }; 
    for (int i=0; i<4; i++){ //4 attaques c'est pour ça
        convert_texte(attaquant.listedescapacites[i].nom, font, ren, attaques[i].x, attaques[i].y );
    }
    SDL_RenderPresent(ren);
}



void affichage(SDL_Renderer *ren, Perso_select archive_etat, Game_state * etat, Perso_select selection, Equipe_quatre equipea, Game_state equipe, TTF_Font *font){
    Slot slotscreate[4] = {
        { .x =  30, .y = 110, .w = 0, .h = 0},
        { .x = 320, .y = 50, .w = 0, .h = 0},
        { .x =  680, .y = 50, .w = 0, .h = 0},
        { .x = 1000, .y = 110, .w = 0, .h = 0},
    };
    SDL_RenderClear(ren); //On efface tout
    SDL_Color BLANC = {255,255,255,255};
    int a = 0;
    switch (*etat) {
        case MENU:
            SDL_RenderCopy(ren, screenMenu, NULL, NULL);
            break;
        case MENUP:
            SDL_RenderCopy(ren, screenPlay, NULL, NULL);
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
    SDL_Delay(20);
    if (a==1){
        SDL_Delay(1000);
    }

}

void squad_affichage_fight(SDL_Renderer *ren, Equipe_quatre equipe, Slot *slots){
    for (int i=0; i<4; i++){
        switch (equipe.tab[i].NOM){
            int w, h;
            case CRIONA:
                SDL_QueryTexture(CrionaF, NULL, NULL, &w, &h);
        

                SDL_Rect dst0 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, CrionaF, NULL, &dst0);  
                break;
            case GLACIUS:
                SDL_QueryTexture(GlaciusF, NULL, NULL, &w, &h);
        

                SDL_Rect dst1 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, GlaciusF, NULL, &dst1); 
                break; 
            case ARCANISTE:
                SDL_QueryTexture(ArcanisteF, NULL, NULL, &w, &h);
        

                SDL_Rect dst2 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, ArcanisteF, NULL, &dst2); 
                break;
            case CALYRA:
                SDL_QueryTexture(CalyraF, NULL, NULL, &w, &h);
        

                SDL_Rect dst3 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, CalyraF, NULL, &dst3); 
                break;  
            case VULCAIN:
                SDL_QueryTexture(VulcainF, NULL, NULL, &w, &h);
        

                SDL_Rect dst4 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, VulcainF, NULL, &dst4); 
                break;
            case AQUALIS:
                SDL_QueryTexture(AqualisF, NULL, NULL, &w, &h);
        

                SDL_Rect dst5 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, AqualisF, NULL, &dst5); 
                break;
            case NOVA:
                SDL_QueryTexture(NovaF, NULL, NULL, &w, &h);
        

                SDL_Rect dst6 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, NovaF, NULL, &dst6); 
                break;
            case TERROREX:
                SDL_QueryTexture(TerrorexF, NULL, NULL, &w, &h);
        

                SDL_Rect dst7 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, TerrorexF, NULL, &dst7); 
                break;
            case VOLTIX:
                SDL_QueryTexture(VoltixF, NULL, NULL, &w, &h);
        

                SDL_Rect dst8 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
                SDL_RenderCopy(ren, VoltixF, NULL, &dst8); 
                break;
            case VIDE:
                SDL_QueryTexture(vide, NULL, NULL, &w, &h);
        

                SDL_Rect dst9 = { .x = slots[i].x, .y = slots[i].y, .w = 400, .h = 590 };
                SDL_RenderCopy(ren, vide, NULL, &dst9); 

        }        
    }

}

void affichage_fight(SDL_Renderer *ren, Game_state * etat, Equipe_quatre atk, Equipe_quatre def, Game_state equipe, TTF_Font *font, Personnage attaquant, int tour){
    SDL_RenderClear(ren); //On efface tout 
    Slot slotsfight[4] = {
        { .x =  260, .y = 50, .w = 0, .h = 0},
        { .x = 500, .y = 20, .w = 0, .h = 0},
        { .x =  750, .y = 20, .w = 0, .h = 0},
        { .x = 1000, .y = 50, .w = 0, .h = 0},
    };
    int a = verificationcomplete(atk);
    if (a == 1 ){
        SDL_RenderCopy(ren, screenPlay, NULL, NULL);  
        convert_texte("Impossible de lancer le combat en raison d'equipe manquante.",font,ren,350,100);
        printf("Erreur\n");
        *etat = MENUP;    
    } else {
        SDL_RenderCopy(ren, Fight, NULL, NULL);
        squad_affichage_fight(ren,def,slotsfight);
        barrehp(ren,def);
        char msg[64];
        snprintf(msg, sizeof(msg), "Tour numero %d", tour+1);
        convert_texte(msg,font,ren,1000,700);
        affichage_attaque(attaquant,ren,font);
        SDL_RenderPresent(ren);
    }   
}
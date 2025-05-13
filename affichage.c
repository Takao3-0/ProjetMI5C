#include "affichage.h"
#include "textures.h"
#include "head.h"
#include "createursquad.h"
#include "fight.h"

void render_squad(SDL_Renderer *ren, SDL_Texture *tex, Slot slot) {
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    SDL_Rect dst = { .x = slot.x, .y = slot.y, .w = w, .h = h };
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

void squad_affichage(SDL_Renderer *ren, Equipe_quatre equipe, Slot *slots){
    for (int i=0; i<4; i++){
        switch (equipe.tab[i].NOM){
            int w, h;
            case CRIONA:
                render_squad(ren, Criona, slots[i]);
                break;
            case GLACIUS:
                render_squad(ren, Glacius, slots[i]);
                break; 
            case ARCANISTE:
                render_squad(ren, Arcaniste, slots[i]);
                break;
            case CALYRA:
                render_squad(ren, Calyra, slots[i]);
                break;  
            case VULCAIN:
                render_squad(ren, Vulcain, slots[i]);
                break;
            case AQUALIS:
                render_squad(ren, Aqualis, slots[i]);
                break;
            case NOVA:
                render_squad(ren, Nova, slots[i]);
                break;
            case TERROREX:
                render_squad(ren,Terrorex, slots[i]);
                break;
            case VOLTIX:
                render_squad(ren, Voltix, slots[i]);
                break;
            case AQUANOVA:
                render_squad(ren, Aquanova, slots[i]);
                break;
            case KAELEN:
                render_squad(ren, Kaelen, slots[i]);
                break;
            case EMBERA:
                render_squad(ren, Embera, slots[i]);
                break;
            case VOLTAZOR:
                render_squad(ren, Voltazor, slots[i]);
                break;
            case HYDRAGON:
                render_squad(ren, Hydragon, slots[i]);
                break;
            case PYROBANE:
                render_squad(ren, Pyrobane, slots[i]);
                break;
            case VIDE:
                render_squad(ren, vide, slots[i]);

        }        
    }

}

void barrehp(SDL_Renderer *ren, Equipe_quatre equipe){
    Slot slotbarrehp[4] = {
        { .x =  309, .y = 58, .w = 160, .h = 30},
        { .x =  557, .y = 29, .w = 160, .h = 30},
        { .x =  795, .y = 44, .w = 160, .h = 30},
        { .x =  1041, .y = 59, .w = 160, .h = 30},
    };
    for (int i=0; i<4; i++){
        float pvm = equipe.tab[i].pvmax;
        float pv = equipe.tab[i].pv;
        float coef = 159*(pv/pvm);
        int ww = coef; 
        SDL_Rect pos = { .x = slotbarrehp[i].x, .y = slotbarrehp[i].y, .w = ww, .h = 30 };
        SDL_RenderCopy(ren, HP, NULL, &pos);
        
    }
}

void convert_texte(const char *texte, TTF_Font *font, SDL_Renderer *ren, int x, int y, int couleur){
    SDL_Color NOIR = {0,0,0,255};
    SDL_Color ROJO = {255,0,0,255};
    SDL_Color BLANC = {255,255,255,255};

    //Couleur réaction

    SDL_Color SURCHARGE = {255,165,0,255 };
    SDL_Color ELECTROCUTION  = {128,0,255,255 };
    SDL_Color FONTE = {255,69,0,255 };
    SDL_Color FREEZE = {135,206,250,255 };
    SDL_Color SUPRACONDUCTION = {192,192,192,255};
    SDL_Color EVAPORATION = {200,200,200,255};

    SDL_Surface *surface;
    switch (couleur){
        case 1: 
            surface = TTF_RenderText_Solid(font, texte, NOIR);
            break;
        case 2:
            surface = TTF_RenderText_Solid(font, texte, ROJO);
            break;
        case 3:
            surface = TTF_RenderText_Solid(font, texte, SURCHARGE);
            break;
        case 4:
            surface = TTF_RenderText_Solid(font, texte, ELECTROCUTION);
            break;
        case 5:
            surface = TTF_RenderText_Solid(font, texte, FONTE);
            break; 
        case 6:
            surface = TTF_RenderText_Solid(font, texte, FREEZE);
            break;
        case 7:
            surface = TTF_RenderText_Solid(font, texte, SUPRACONDUCTION);
            break; 
        case 8:
            surface = TTF_RenderText_Solid(font, texte, EVAPORATION);
            break;          
        default:
            surface = TTF_RenderText_Solid(font, texte, BLANC);
            break;
    }
    SDL_Texture *le_texte = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    SDL_Rect position;
    position.x = x;
    position.y = y;
    SDL_QueryTexture(le_texte, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(ren, le_texte, NULL, &position);
    SDL_DestroyTexture(le_texte);
}

int verificationcomplete(Equipe_quatre equipe){
    for (int i=0;i<4;i++){
        if (equipe.tab[i].rarete != 4 && equipe.tab[i].rarete != 5){
            return 1;
        }
    }
    return 0;

}

//Procédure pour afficher les attaques des personnages 

void affichage_attaque(Personnage attaquant, SDL_Renderer *ren, TTF_Font *font){
    Slot attaques[4] = {
        { .x = 130, .y = 560, .w = 240, .h = 107 },
        { .x = 400, .y = 560, .w = 240, .h = 107 },
        { .x = 130, .y = 670, .w = 240, .h = 107 },
        { .x = 400, .y = 670, .w = 240, .h = 107 },
    }; 
    char msg[64];
    for (int i=0; i<4; i++){ //4 attaques c'est pour ça
        convert_texte(attaquant.listedescapacites[i].nom, font, ren, attaques[i].x, attaques[i].y,1);
        snprintf(msg, sizeof(msg), "Damage : %d%", attaquant.listedescapacites[i].damage);
        convert_texte(msg, font, ren, attaques[i].x, attaques[i].y+50,1);
        snprintf(msg, sizeof (msg), "CD actuel : %d tour", attaquant.listedescapacites[i].cd);
        convert_texte(msg, font, ren, attaques[i].x, attaques[i].y+25,1);
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
                convert_texte("1",font,ren,173,22,1); 
            } else if (equipe == E2){
                SDL_RenderCopy(ren, screenEquipe1, NULL, NULL);
                convert_texte("2",font,ren,173,22,1);     
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
                case AQUANOVA:
                    SDL_RenderCopy(ren, archiveAquanova, NULL, NULL);
                    break;
                case VOLTAZOR:
                    SDL_RenderCopy(ren, archiveVoltazor, NULL, NULL);
                    break;
                case EMBERA:
                    SDL_RenderCopy(ren, archiveEmbera, NULL, NULL);
                    break;
                case KAELEN:
                    SDL_RenderCopy(ren, archiveKaelen, NULL, NULL);
                    break;
                case PYROBANE:
                    SDL_RenderCopy(ren, archivePyrobane, NULL, NULL);
                    break;
                case HYDRAGON:
                    SDL_RenderCopy(ren, archiveHydragon, NULL, NULL);
                    break;
                default:
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
                case AQUANOVA:
                    SDL_RenderCopy(ren, AddAquanova, NULL, NULL);  
                    break;
                case PYROBANE:
                    SDL_RenderCopy(ren, AddPyrobane, NULL, NULL);  
                    break;
                case KAELEN:
                    SDL_RenderCopy(ren, AddKaelen, NULL, NULL);  
                    break;
                case VOLTAZOR:
                    SDL_RenderCopy(ren, AddVoltazor, NULL, NULL);  
                    break;
                case HYDRAGON:
                    SDL_RenderCopy(ren, AddHydragon, NULL, NULL);  
                    break;
                case EMBERA:
                    SDL_RenderCopy(ren, AddEmbera, NULL, NULL);  
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

/*
SDL_QueryTexture(CrionaF, NULL, NULL, &w, &h);
        
SDL_Rect dst0 = { .x = slots[i].x, .y = slots[i].y, .w = w, .h = h };
SDL_RenderCopy(ren, CrionaF, NULL, &dst0);  */

//On avait ça pour chaque case des 2 fonction affichage avant la fonction render squad!!!

void squad_affichage_fight(SDL_Renderer *ren, Equipe_quatre equipe, Slot *slots){
    for (int i=0; i<4; i++){
        if (equipe.tab[i].pv >0){
            switch (equipe.tab[i].NOM){
                int w, h;
                case CRIONA:
                    render_squad(ren, CrionaF, slots[i]);
                    break;
                case GLACIUS:
                    render_squad(ren, GlaciusF, slots[i]);
                    break; 
                case ARCANISTE:
                    render_squad(ren, ArcanisteF, slots[i]);
                    break;
                case CALYRA:
                    render_squad(ren, CalyraF, slots[i]);
                    break;  
                case VULCAIN:
                    render_squad(ren, VulcainF, slots[i]);
                    break;
                case AQUALIS:
                    render_squad(ren, AqualisF, slots[i]);
                    break;
                case NOVA:
                    render_squad(ren, NovaF, slots[i]);
                    break;
                case TERROREX:
                    render_squad(ren, TerrorexF, slots[i]);
                    break;
                case VOLTIX:
                    render_squad(ren, VoltixF, slots[i]);
                    break;
                case AQUANOVA:
                    render_squad(ren, AquanovaF, slots[i]);
                    break;
                case KAELEN:
                    render_squad(ren, KaelenF, slots[i]);
                    break;
                case EMBERA:
                    render_squad(ren, EmberaF, slots[i]);
                    break;
                case VOLTAZOR:
                    render_squad(ren, VoltazorF, slots[i]);
                    break;
                case HYDRAGON:
                    render_squad(ren, HydragonF, slots[i]);
                    break;
                case PYROBANE:
                    render_squad(ren, PyrobaneF, slots[i]);
                    break;
                case VIDE:
                    render_squad(ren, vide, slots[i]);

            } 
        }          
    }
}

void cadre_affichage_fight(SDL_Renderer *ren, Equipe_quatre equipe, Slot *slots){
    for (int i=0; i<4; i++){
        if (equipe.tab[i].pv >0){
            switch (equipe.tab[i].NOM){
                int w, h;
                case CRIONA:
                    render_squad(ren, CrionaCadre, slots[i]);
                    break;
                case GLACIUS:
                    render_squad(ren, GlaciusCadre, slots[i]);
                    break; 
                case ARCANISTE:
                    render_squad(ren, ArcanisteCadre, slots[i]);
                    break;
                case CALYRA:
                    render_squad(ren, CalyraCadre, slots[i]);
                    break;  
                case VULCAIN:
                    render_squad(ren, VulcainCadre, slots[i]);
                    break;
                case AQUALIS:
                    render_squad(ren, AqualisCadre, slots[i]);
                    break;
                case NOVA:
                    render_squad(ren, NovaCadre, slots[i]);
                    break;
                case TERROREX:
                    render_squad(ren, TerrorexCadre, slots[i]);
                    break;
                case VOLTIX:
                    render_squad(ren, VoltixCadre, slots[i]);
                    break;
                case AQUANOVA:
                    render_squad(ren, AquanovaCadre, slots[i]);
                    break;
                case KAELEN:
                    render_squad(ren, KaelenCadre, slots[i]);
                    break;
                case EMBERA:
                    render_squad(ren, EmberaCadre, slots[i]);
                    break;
                case VOLTAZOR:
                    render_squad(ren, VoltazorCadre, slots[i]);
                    break;
                case HYDRAGON:
                    render_squad(ren, HydragonCadre, slots[i]);
                    break;
                case PYROBANE:
                    render_squad(ren, PyrobaneCadre, slots[i]);
                    break;
                default :
                    printf(ROUGE"Erreur\n"RESET);

            } 
        } else {
            render_squad(ren, Dead, slots[i]);    
        }          
    }
}

void delay_safe(Uint32 ms, SDL_Renderer *ren) {
    Uint32 start = SDL_GetTicks();
    SDL_Event event;
    while (SDL_GetTicks() - start < ms) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_Quit();
                exit(0);
            }
        }

        // Exemple d'affichage pendant le délai
        // tes fonctions de dessin ici

        SDL_Delay(1);
    }
}

void affichage_reaction(int react, int x, int y, SDL_Renderer *ren, TTF_Font *font){
    switch (react){
        case 11:
            convert_texte("EVAPORATION",font,ren,x,y,8);
            break; 
        case 110:
            convert_texte("SURCHARGE",font,ren,x,y,3);
            break; 
        case 101:
            convert_texte("ELECTROCUTION",font,ren,x,y,4);
            break; 
        case 1010:
            convert_texte("FONTE",font,ren,x,y,5);
            break; 
        case 1001:
            convert_texte("GEL",font,ren,x,y,6);
            break; 
        case 1100:
            convert_texte("SUPRACONDUCTION",font,ren,x,y,7);
            break; 
        default:
            break;
    }
}


void affichage_fight(SDL_Renderer *ren, Game_state * etat, Equipe_quatre atk, Equipe_quatre def, Game_state equipe, TTF_Font *font, Personnage attaquant, Personnage defenseur, int tour, int select, int iddef,  EventType * event, int dmg, int crit, int react){
    SDL_RenderClear(ren); //On efface tout 
    Slot slotsfight[4] = {
        { .x =  270, .y = 65, .w = 0, .h = 0},
        { .x = 510, .y = 35, .w = 0, .h = 0},
        { .x =  750, .y = 35, .w = 0, .h = 0},
        { .x = 1000, .y = 65, .w = 0, .h = 0},
    };
        Slot slotshistorique[5] = {
        { .x = 870, .y = 600, .w = 0, .h = 0},
        { .x = 870, .y = 620, .w = 0, .h = 0},
        { .x = 870, .y = 640, .w = 0, .h = 0},
        { .x = 870, .y = 660, .w = 0, .h = 0},
        { .x = 870, .y = 680, .w = 0, .h = 0},
    };
    Slot cadre[4] = {
        { .x =  107, .y = 444, .w = 0, .h = 0},
        { .x = 207, .y = 444, .w = 0, .h = 0},
        { .x =  307, .y = 444, .w = 0, .h = 0},
        { .x = 407, .y = 444, .w = 0, .h = 0},
    };
    Slot cadre2[4] = {
        { .x =  859, .y = 444, .w = 0, .h = 0},
        { .x = 959, .y = 444, .w = 0, .h = 0},
        { .x =  1059, .y = 444, .w = 0, .h = 0},
        { .x = 1159, .y = 444, .w = 0, .h = 0},
    };
    int a = verificationcomplete(atk);
    if (a == 1 ){
        SDL_RenderCopy(ren, screenPlay, NULL, NULL);  
        convert_texte("Impossible de lancer le combat en raison d'equipe manquante.",font,ren,350,100,1);
        printf("Erreur\n");
        SDL_RenderPresent(ren); 
        delay_safe(1000,ren); //idem, 1'' d'affichage de message d'erreur
        *etat = MENUP;
    } else {
        SDL_RenderCopy(ren, Fight, NULL, NULL);
        squad_affichage_fight(ren,def,slotsfight);
        barrehp(ren,def);
        char msg[64];

        //Affichage du tour;
        snprintf(msg, sizeof(msg), "Tour numero %d, %s attaque", tour+1, attaquant.name);
        convert_texte(msg,font,ren,870,580,1);
        cadre_affichage_fight(ren,atk,cadre);
        cadre_affichage_fight(ren,def,cadre2);
        convert_texte("EQUIPE ATTAQUANTE",font ,ren, 187, 410,1);
        convert_texte("EQUIPE DEFENSEUSE",font ,ren, 939, 410,1);
        if (*event == EVT_Atk){
            snprintf(msg, sizeof(msg), "%s attaque %s",attaquant.name, attaquant.listedescapacites[select].nom);
            convert_texte(msg,font,ren,slotshistorique[0].x,slotshistorique[0].y,1);    
        } else if (*event == EVT_InvalideATK){
            convert_texte("Attaque invalide -> CD",font,ren,slotshistorique[1].x,slotshistorique[1].y,2);   
        } else if (*event == EVT_Invalide){
            snprintf(msg, sizeof(msg), "%s attaque %s",attaquant.name, attaquant.listedescapacites[select].nom);
            convert_texte(msg,font,ren,slotshistorique[0].x,slotshistorique[0].y,1);
            convert_texte("Adversaire invalide car deja mort",font ,ren, slotshistorique[1].x,slotshistorique[1].y,2);                
        } else if (*event == EVT_Adv){
            snprintf(msg, sizeof(msg), "%s attaque %s",attaquant.name, attaquant.listedescapacites[select].nom);
            convert_texte(msg,font,ren,slotshistorique[0].x,slotshistorique[0].y,1); 
            snprintf(msg, sizeof(msg), "%s attaque %s",attaquant.name, defenseur.name);
            convert_texte(msg,font,ren,slotshistorique[1].x,slotshistorique[1].y,1);
        } else if (*event == EVT_Recap){
            //Affichage de qui attaque qui
            snprintf(msg, sizeof(msg), "%s attaque %s", attaquant.name, attaquant.listedescapacites[select].nom);
            convert_texte(msg, font, ren, slotshistorique[0].x, slotshistorique[0].y,1); 

            //Affichage de l'attaque choisi
            snprintf(msg, sizeof(msg), "%s attaque %s", attaquant.name, defenseur.name);
            convert_texte(msg, font, ren, slotshistorique[1].x, slotshistorique[1].y,1);

            //Affichage des dégâts sur l'interface "historique"
            snprintf(msg, sizeof(msg), "%s subit %d degats", defenseur.name, dmg); // <-- attention ici, bug probable !
            convert_texte(msg, font, ren, slotshistorique[2].x, slotshistorique[2].y,1);


            //Affichage des dégâts sur l'écran de façon temp.
            snprintf(msg, sizeof(msg), "%d", dmg);
            convert_texte(msg,font,ren, slotsfight[iddef].x+85, slotsfight[iddef].y+50,2);

            //AFFICHAGE DE COUP CRITIQUE
            if (crit == 1){ //agit comme un bool
                convert_texte("COUP CRITIQUE!",font,ren,slotsfight[iddef].x+35, slotsfight[iddef].y+75,2);
            }

            //Affichage de la réaction 

            affichage_reaction(react,slotsfight[iddef].x+35,slotsfight[iddef].y+100,ren,font);

            affichage_attaque(attaquant,ren,font);
            SDL_RenderPresent(ren);
            delay_safe(1500, ren); //2'' d'affichage 
            *event = EVT_Vide;

        }
        if (*event != EVT_Recap){
            affichage_attaque(attaquant,ren,font);
            SDL_RenderPresent(ren);
        }
        SDL_Delay(20);
    }   
}
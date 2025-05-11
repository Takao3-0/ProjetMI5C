#include "head.h"
#include "personnages.h"
#include "fight.h"
#include "createursquad.h"
#include "weapons.h"
#include "btn.h"
#include "textures.h"
#include "affichage.h"


int main(int argc, char* argv[]) {

    //Init normale du programme
    Personnage *tabPerso = extract();
    if (tabPerso == NULL) {
        printf("Erreur lors de l'extraction des personnages.\n");
        return 1;
    }
    srand(time(NULL));
    Equipe_quatre squad1;
    Equipe_quatre squad2;
    /*squad1.tab[0]= tabPerso[13];
    squad1.tab[1]= tabPerso[14];
    squad1.tab[2]= tabPerso[9];
    squad1.tab[3]= tabPerso[4];
    squad2.tab[0]= tabPerso[13];
    squad2.tab[1]= tabPerso[8];
    squad2.tab[2]= tabPerso[3];
    squad2.tab[3]= tabPerso[5];*/
    /*printf(VERT"L'equipe est composé de : %s %s %s %s\n"RESET,
        squad1.tab[0].name,
        squad1.tab[1].name, 
        squad1.tab[2].name,
        squad1.tab[3].name);*/
    //Init de SDL + SDL IMG + SDL TTF
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { //Depuis la documentation de SLD
        printf("SDL_Init raté: %s\n", SDL_GetError());
        return 1;
    }
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("IMG_Init raté: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }
    if (TTF_Init() != 0) { //Depuis la documentation de SDL
        printf("TTF_Init raté: %s\n", TTF_GetError());
        return 1;
    }

    //On crée la fenetre
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

    TTF_Font *font = TTF_OpenFont("assets/FUTURA.ttf", 24);

    Import_tex(ren);

    // état courant
    Game_state etat = MENU;
    Game_state equipe = E1;
    Perso_select archive_etat = CRIONA;
    Perso_select selection = VIDE;
    Position pos = P1;


    //Boucle principale
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
                } else if (mx >= btn4VS4.x && mx < btn4VS4.x + btn4VS4.w && my >= btn4VS4.y && my < btn4VS4.y + btn4VS4.h){
                    etat = VERSUS4;
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
                } else if(mx >= btnEquipechangement.x && mx < btnEquipechangement.x + btnEquipechangement.w && my >= btnEquipechangement.y && my < btnEquipechangement.y + btnEquipechangement.h){
                    printf("Clic\n");
                    if (equipe == E1){
                        equipe = E2;
                    } else if (equipe == E2){
                        equipe = E1;
                    }
                }
            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == SELECTION){
                printf("Passage dans le menu de création d'équipe\n");
                if (equipe == E1){
                    Assembleur_equipe(&squad1,tabPerso,&etat,&archive_etat,pos,e,&equipe);                    
                } else if (equipe == E2){
                    Assembleur_equipe(&squad2,tabPerso,&etat,&archive_etat,pos,e,&equipe);  
                }
                selection = archive_etat;

            } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && etat == VERSUS4 ){
                equipe = E1;
                printf("Passage en fight\n");
                //fight(&squad1,&squad2, ren, archive_etat, &etat, selection, equipe, font);

            }
        }

        //Affichage via la fonction dans le fichier affichage.c
        if (equipe == E1){
            affichage(ren, archive_etat, &etat, selection, squad1, equipe,font);                    
        } else if (equipe == E2){
            affichage(ren, archive_etat, &etat, selection, squad2, equipe,font); 
        }
        if (etat == VERSUS4){ //On appel la fonction fight ici parce qu'elle gère elle même son affichage. Dans le cas ou on l'appel plus haut on a un écran noir le temps d'un clic.
           fight(&squad1,&squad2, ren, archive_etat, &etat, selection, equipe, font); 
        }

    }
}
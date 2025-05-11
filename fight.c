#include "head.h"
#include "fight.h"
#include "personnages.h"
#include "affichage.h"
#include "btn.h"

//Ce porgramme porte sur les fight entre vrai utilisateur, pas d'IA disponible

int randtc(){
    int crit = 0;
    return crit = rand() % 100 + 1;
}

int verification_type(Personnage *attaquant, Personnage *defenseur, int capa, int * degat);

int damage(Personnage attaquant, Personnage * defenseur,int capa, int *crit, int *elmt){ 
    printf("Avant tt calcul %d est le type de %s\n", defenseur->type, defenseur->name);
    int critique = randtc(); 
    int degats = 0;  //Dégats réelement infligés.
    if (critique <= attaquant.tc){ //Cas ou l'attaquant effectue un coup critique.
        printf(ROSE"COUP CRITIQUE!\n"RESET);
        degats = (((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->def))*(attaquant.dc/100.0);
        *elmt = verification_type(&attaquant, defenseur, capa,&degats);
        if (*elmt == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
            printf(ORANGE"Le type de %s est alors %d\n"RESET,defenseur->name, defenseur->type);
        }
        *crit = 1;
        printf(ROUGE"Les degats recu sont de %d\n"RESET,degats);
    } else {
        degats = ((attaquant.atk*(attaquant.listedescapacites[capa].damage/100.0))*attaquant.atk)/(attaquant.atk+defenseur->def);
        *elmt = verification_type(&attaquant, defenseur, capa, &degats);
        if (*elmt == 0){
            defenseur->type = attaquant.listedescapacites[capa].type;
            printf(ORANGE"Le type de %s, est alors %d\n"RESET,defenseur->name, defenseur->type);
        }
        *crit = 0;
        printf(ROUGE"Les degats recu sont de %d\n"RESET,degats);
    }
    return degats; //On return de force un entier, plus simple de travailler avec des entier dans le contexte du jeu.
}

int equipe_morte(Equipe_quatre equipe){  //on utilisera cette fonction des lors qu'on aura des equipe a plusieurs 4 perso
    if (equipe.tab[0].pv <=0 && equipe.tab[1].pv <=0){
        return 1;
    } else {
        return 0;
    }
}


int verification_type(Personnage * attaquant, Personnage *defenseur, int capa, int * degat){ //on supprime la partie décimale de façon a avoir une meilleur expérience de jeu
    int somme = attaquant->listedescapacites[capa].type + defenseur->type;
    switch (somme){
        case 11:
            printf(ORANGE"EVAPORATION\n"RESET); //Hydro + Pyro
            defenseur->type = 0;
            * degat *= 1.5;
            return 11;
        case 110:
            printf(ORANGE"SURGARGE\n"RESET); //Pyro + Electro
            defenseur->type = 0;
            * degat *= 1.3;
            return 110;
        case 101:
            printf(VIOLET"ELECTROCUTION\n"RESET); //Electro + Hydro
            defenseur->type = 0;
            * degat *= 1.5;
            return 101;
        case 1010:
            printf(BLEUC"FONTE\n"RESET); //Pyro + Cryo
            defenseur->type = 0;
            * degat *= 2;
            return 1010;
        case 1001:
            printf(BLEUF"GEL\n"RESET); //Cryo + Hydro
            defenseur->type = 0;
            return 1001;
        case 1100:
            printf(VIOLET"SUPRACONDUCTION\n"RESET); //Electro + Cryo
            defenseur->type = 0;
            * degat *= 1.3;
            return 1100;
        default:
            printf(BLEU"Pas de reaction elementaire qu'un seul élément est actif.\n"RESET);
            return 0;
    }
}

int verification(Equipe_quatre a){
    int rturn = 0;
    for (int i=0; i<4; i++){
        if (a.tab[i].pv >= 0){
            rturn++; 
        }
    }
    return rturn;
}

void resetpv(Equipe_quatre *equipe){
    for (int i=0; i<4; i++){
        equipe->tab[i].pv = equipe->tab[i].pvmax;
    }
}



// Boucle principale de combat entre deux équipes de deux personnages
void fight(Equipe_quatre *equipea, Equipe_quatre *equipeb,SDL_Renderer *ren, Perso_select archive_etat, Game_state * etat, Perso_select selection, Game_state equipe, TTF_Font *font){ //Fonction mère de la gestion du combat
    int compteur_de_tour = 0;
    int degat = 0;
    int atk = 0;
    int adversaire = 0;
    int crit = 0;
    int elmt = 0;              // type élémentaire final
    int i = 0;
    bool fightrunning = true;
    Fight_state fight_etat = Slt_atk;
    SDL_Event e;
    EventType event = EVT_Vide;
    while (fightrunning){
        while(SDL_PollEvent(&e)){
            int mx = e.button.x;
            int my = e.button.y;
            if (e.type == SDL_QUIT || *etat == MENUP) {
                fightrunning = false;
                *etat = MENUP;
                break;
            }
            if (compteur_de_tour % 2 == 0) { // Equipe A qui attaque
                equipe = E1;
                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && fight_etat == Slt_atk ){ //Séléction de l'atk;
                    if (mx >= btnA1.x && mx < btnA1.x + btnA1.w && my >= btnA1.y && my < btnA1.y + btnA1.h){
                        atk = 0; 
                        printf(VERT"Attaque choisi : %s\n"RESET, equipea->tab[i].listedescapacites[0].nom); 
                        fight_etat = Slt_Adversaire;
                        event = EVT_Atk;
                    } else if (mx >= btnA2.x && mx < btnA2.x + btnA2.w && my >= btnA2.y && my < btnA2.y + btnA2.h){
                        atk = 1;
                        printf(VERT"Attaque choisi : %s\n"RESET, equipea->tab[i].listedescapacites[1].nom);
                        fight_etat = Slt_Adversaire; 
                        event = EVT_Atk;
                    } else if (mx >= btnA3.x && mx < btnA3.x + btnA3.w && my >= btnA3.y && my < btnA3.y + btnA3.h){
                        atk = 2;
                        printf(VERT"Attaque choisi : %s\n"RESET, equipea->tab[i].listedescapacites[2].nom);
                        fight_etat = Slt_Adversaire; 
                        event = EVT_Atk;
                    } else if (mx >= btnA4.x && mx < btnA4.x + btnA4.w && my >= btnA4.y && my < btnA4.y + btnA4.h){
                        atk = 3;
                        printf(VERT"Attaque choisi : %s\n"RESET, equipea->tab[i].listedescapacites[3].nom);
                        fight_etat = Slt_Adversaire;
                        event = EVT_Atk;
                    }
                } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && fight_etat == Slt_Adversaire){
                    if (mx >= Cible1.x && mx < Cible1.x + Cible1.w && my >= Cible1.y && my < Cible1.y + Cible1.h){
                        adversaire = 0;
                        printf(ROUGE"Adversaire choisi : %s\n"RESET,equipeb->tab[0].name);
                        fight_etat = Slt_Fight;
                        event = EVT_Recap;
                    } else if (mx >= Cible2.x && mx < Cible2.x + Cible2.w && my >= Cible2.y && my < Cible2.y + Cible2.h){
                        adversaire = 1;
                        printf(ROUGE"Adversaire choisi : %s\n"RESET,equipeb->tab[1].name);
                        fight_etat = Slt_Fight;
                        event = EVT_Recap;
                    } else if (mx >= Cible3.x && mx < Cible3.x + Cible3.w && my >= Cible3.y && my < Cible3.y + Cible3.h){
                        adversaire = 2;
                        printf(ROUGE"Adversaire choisi : %s\n"RESET,equipeb->tab[2].name);
                        fight_etat = Slt_Fight;
                        event = EVT_Recap;
                    } else if (mx >= Cible4.x && mx < Cible4.x + Cible4.w && my >= Cible4.y && my < Cible4.y + Cible4.h){
                        adversaire = 3;
                        printf(ROUGE"Adversaire choisi : %s\n"RESET,equipeb->tab[3].name);
                        fight_etat = Slt_Fight;
                        event = EVT_Recap;
                    }               
                }            
            } else { // Equipe B qui attaque
                    equipe = E2;
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && fight_etat == Slt_atk ){ //Séléction de l'atk;
                        if (mx >= btnA1.x && mx < btnA1.x + btnA1.w && my >= btnA1.y && my < btnA1.y + btnA1.h){
                            atk = 0; 
                            printf(VERT"Attaque choisi : %s\n"RESET, equipeb->tab[i].listedescapacites[0].nom); 
                            fight_etat = Slt_Adversaire;
                            event = EVT_Atk;  
                        } else if (mx >= btnA2.x && mx < btnA2.x + btnA2.w && my >= btnA2.y && my < btnA2.y + btnA2.h){
                            atk = 1;
                            printf(VERT"Attaque choisi : %s\n"RESET, equipeb->tab[i].listedescapacites[1].nom);
                            fight_etat = Slt_Adversaire;
                            event = EVT_Atk;  
                        } else if (mx >= btnA3.x && mx < btnA3.x + btnA3.w && my >= btnA3.y && my < btnA3.y + btnA3.h){
                            atk = 2;
                            printf(VERT"Attaque choisi : %s\n"RESET, equipeb->tab[i].listedescapacites[2].nom);
                            fight_etat = Slt_Adversaire;
                            event = EVT_Atk;  
                        } else if (mx >= btnA4.x && mx < btnA4.x + btnA4.w && my >= btnA4.y && my < btnA4.y + btnA4.h){
                            atk = 3;
                            printf(VERT"Attaque choisi : %s\n"RESET, equipeb->tab[i].listedescapacites[3].nom);
                            fight_etat = Slt_Adversaire;
                            event = EVT_Atk; 
                        }
                    } else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && fight_etat == Slt_Adversaire){
                        if (mx >= Cible1.x && mx < Cible1.x + Cible1.w && my >= Cible1.y && my < Cible1.y + Cible1.h){
                            adversaire = 0;
                            printf(ROUGE"Adversaire choisi : %s\n"RESET,equipea->tab[0].name);
                            fight_etat = Slt_Fight;
                            event = EVT_Recap;
                        } else if (mx >= Cible2.x && mx < Cible2.x + Cible2.w && my >= Cible2.y && my < Cible2.y + Cible2.h){
                            adversaire = 1;
                            printf(ROUGE"Adversaire choisi : %s\n"RESET,equipea->tab[1].name);
                            fight_etat = Slt_Fight;
                            event = EVT_Recap;
                        } else if (mx >= Cible3.x && mx < Cible3.x + Cible3.w && my >= Cible3.y && my < Cible3.y + Cible3.h){
                            adversaire = 2;
                            printf(ROUGE"Adversaire choisi : %s\n"RESET,equipea->tab[2].name);
                            fight_etat = Slt_Fight;
                            event = EVT_Recap;
                        } else if (mx >= Cible4.x && mx < Cible4.x + Cible4.w && my >= Cible4.y && my < Cible4.y + Cible4.h){
                            adversaire = 3;
                            printf(ROUGE"Adversaire choisi : %s\n"RESET,equipea->tab[3].name);
                            fight_etat = Slt_Fight;
                            event = EVT_Recap;
                        }                  
                    } 
            }

        switch (fight_etat){
            case Slt_atk:
                if (equipe == E1){
                    event = EVT_Vide;
                    affichage_fight(ren,etat,*equipea,*equipeb,equipe,font,equipea->tab[i],equipeb->tab[0],compteur_de_tour,atk,adversaire,&event,0);    
                } else {
                    event = EVT_Vide;
                    affichage_fight(ren,etat,*equipeb,*equipea,equipe,font,equipeb->tab[i],equipea->tab[0],compteur_de_tour,atk,adversaire,&event,0);                    
                }
                break;
            case Slt_Adversaire:
                if (equipe == E1){
                    affichage_fight(ren,etat,*equipea,*equipeb,equipe,font,equipea->tab[i],equipeb->tab[atk],compteur_de_tour,atk,adversaire,&event,0);                    
                } else {
                    affichage_fight(ren,etat,*equipeb,*equipea,equipe,font,equipeb->tab[i],equipea->tab[atk],compteur_de_tour,atk,adversaire,&event,0);                    
                }
                break;
            case Slt_Fight:
                crit = 0, elmt  = 0;
                switch (equipe){
                    case E1: //E1 attaque E2 reçoit les dmgs
                        degat = damage(equipea->tab[i],&equipeb->tab[adversaire],atk,&crit, &elmt);
                        equipeb->tab[adversaire].pv -= degat;
                        printf(ROUGE"Les pv de %s sont alors de %d\n"RESET,equipeb->tab[adversaire].name, equipeb->tab[adversaire].pv);
                        break;
                    case E2: //E2 attaque E1 reçoit les dmgs
                        degat = damage(equipeb->tab[i],&equipea->tab[adversaire],atk,&crit, &elmt);
                        equipea->tab[adversaire].pv -= degat;
                        printf(ROUGE"Les pv de %s sont alors de %d\n"RESET,equipea->tab[adversaire].name, equipea->tab[adversaire].pv);
                        break;
                }
                if (equipe == E1){
                    event = EVT_Recap;
                    affichage_fight(ren,etat,*equipea,*equipeb,equipe,font,equipea->tab[i],equipeb->tab[adversaire],compteur_de_tour,atk,adversaire,&event,degat);                    
                } else {
                    event = EVT_Recap;
                    affichage_fight(ren,etat,*equipeb,*equipea,equipe,font,equipeb->tab[i],equipea->tab[adversaire],compteur_de_tour,atk,adversaire,&event,degat);                    
                }
                if (i==3){
                    i=0;
                    compteur_de_tour ++;
                }else { 
                    i++;
                };    
                fight_etat = Slt_atk;
                break; 
        } 
        if (verification(*equipea) <= 0 || verification(*equipeb) <= 0 ){
            fightrunning = false;
            resetpv(equipea);
            resetpv(equipeb);

        }
        SDL_Delay(20);
    }
    } 
}


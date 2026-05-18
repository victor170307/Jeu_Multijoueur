#ifndef MON_TENNIS_H
#define MON_TENNIS_H

#include <windows.h> // IMPORTANT : Ne pas inclure mon_tennis.h ici !

// Structure pour représenter une raquette
typedef struct {
    int x, y;       
    int largeur;
    int hauteur;
    int vitesse;
} Raquette;

// Structure pour représenter la balle
typedef struct {
    int x, y;       
    int taille;
    int vitesseX;   
    int vitesseY;   
} Balle;

// Déclaration des fonctions
void initialiser_jeu(Raquette* r1, Balle* b);
void dessiner_jeu(HDC hdc, Raquette* r1, Balle* b);

void deplacer_raquette(Raquette* r, int direction);

#endif
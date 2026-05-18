#include "mon_tennis.h"

// Met en place les positions de départ
void initialiser_jeu(Raquette* r1, Balle* b) {
    r1->x = 30;
    r1->y = 250;
    r1->largeur = 15;
    r1->hauteur = 80;
    r1->vitesse = 10;

    b->x = 400;
    b->y = 300;
    b->taille = 12;
    b->vitesseX = 4;
    b->vitesseY = 4;
}

// Dessine les éléments sur l'écran
void dessiner_jeu(HDC hdc, Raquette* r1, Balle* b) {
    // Pinceau blanc pour les objets
    HBRUSH pinceauBlanc = CreateSolidBrush(RGB(255, 255, 255));
    
    // Dessin raquette
    RECT rectRaquette = { r1->x, r1->y, r1->x + r1->largeur, r1->y + r1->hauteur };
    FillRect(hdc, &rectRaquette, pinceauBlanc);
    
    // Dessin balle
    RECT rectBalle = { b->x, b->y, b->x + b->taille, b->y + b->taille };
    FillRect(hdc, &rectBalle, pinceauBlanc);
    
    // Nettoyage
    DeleteObject(pinceauBlanc);
}

void deplacer_raquette(Raquette* r, int direction) {
    // direction : -1 pour monter, 1 pour descendre
    r->y += direction * r->vitesse;

    // Limite supérieure (ne pas dépasser le haut de la fenêtre)
    if (r->y < 0) {
        r->y = 0;
    }
    // Limite inférieure (hauteur écran 600 - hauteur raquette 80)
    if (r->y > 520) {
        r->y = 520;
    }
}
/*
Fichier : "grille.h"
Groupe : Thibaut Fontaine, Bixente Hiriart--Dicharry, Cédric Rouillé
Création : 10/12/2025
*/

#ifndef GRILLE_H
#define GRILLE_H

struct Case {
        char symbole;   // Symbole stocké dans la case
        bool estCache;  // Vrai si la case est cachée, faux sinon
};

const unsigned short int TAILLE_TAB = 200;  // Taille pysique du tableau

struct Grille {
        Case matrice[TAILLE_TAB][TAILLE_TAB];
        // Matrice contenant les cases de la grille
        unsigned short int taille;  // taille logique du tableau
        char symboleCaseVide;  // Symbole dans la cazse est vide quand elle est
                               // vide
        char symbooleCaseCachee;  // Symbole affiché quand la case est cachée
};

#endif

// Définition des types abstrait

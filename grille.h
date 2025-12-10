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

const short int TAILLE_TAB = 200;  // Taille pysique du tableau

struct Grille {
        Case matrice[TAILLE_TAB][TAILLE_TAB];
        // Matrice contenant les cases de la grille
        short int taille;        // taille logique du tableau
        char symboleCaseVide;    // Symbole dans la case est vide quand elle est
                                 // vide
        char symboleCaseCachee;  // Symbole affiché quand la case est cachée
};

// Getters
char getSymboleCase(const Grille &grille, short int ligne, short int colonne);
// Renvoie le symbole dans la case(ligne, colonne) donnée en paramètres

short int getTailleGrille(const Grille &grille);
// Renvoie la taille logique de la grille

char getSymboleCaseVide(const Grille &grille;
// Revoie le symbole mis dans une case quand elle est vide

char getSymboleCaseCachee(const Grille &grille);
// Renvoie le symbole affiché quand une case est cachée

// Setters
void setCaseSymbole(Grille &grille, char symbole, short int ligne, short int colonne);
// Remplit la case(ligne, colonne) avec sybole

void setCaseCachee(Grille &grille, short int ligne, short int colonne);
// Cache la case(ligne, colonne)

void setTailleGrille(Grille &grille, short int taille);
// Change la taille logique de la grille pour qu'elle soit taille

void setSymboleCaseVide(Grille &grille, char symbole);
// Change le symbole mis dans une case pour qu'elle soit vide pour qu'il soit symbole

void setSymboleCaseCachee(Grille &grille, char symbole);
// Change le symbole affiché quand une case est cachée pour qu'il soit symbole
#endif  // GRILLE_H_

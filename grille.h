/*
Fichier : "grille.h"
Groupe : Thibaut Fontaine, Bixente Hiriart--Dicharry, Cédric Rouillé
Création : 10/12/2025
*/

#ifndef GRILLE_H
#define GRILLE_H

struct Case
{
    char symbole;  // Symbole stocké dans la case
    bool estCache; // Vrai si la case est cachée, faux sinon
};

const unsigned short int TAILLE_TAB = 200; // Taille pysique du tableau

struct Grille
{
    Case matrice[TAILLE_TAB][TAILLE_TAB];
    // Matrice contenant les cases de la grille
    unsigned short int taille; // taille logique du tableau
    char symboleCaseVide;      // Symbole dans la case est vide quand elle est vide
    char symbooleCaseCachee;   // Symbole affiché quand la case est cachée
};

bool isGrillePleine(Grille &grille);
// But : indique si aucune case de la grille "grille" est vide

bool isAlignementHoriz(Grille &grille, const unsigned short int ligne, const unsigned short int nbSymbole);
// But : indique s'il y a un certain nombre d’un symbole passé en paramètre en continu sur une ligne

bool isAlignementVerti(Grille &grille, const unsigned short int colonne, const unsigned short int nbSymbole);
// But : indique s'il y a un certain nombre d’un symbole passé en paramètre en continu sur une colonne

bool isAlignementDiago(Grille &grille, const unsigned short int nbSymbole);
// But : vérifie s'il y a un nombre de symbole en continue sur une diagonale

/*******************************
        Modificateurs
*******************************/

void initGrille();
// But :

/*******************************
        Entrées / Sorties
*******************************/

#endif

/*
Procedure ou fonction
Nommage du sous programme
Typage de la valeur de retour
Passage de parametres
Nommage des parametres
Le But decrit le sous programme (comprehensible)
Le But explique le role de chacun des parametres
Typage coordonnees
*/

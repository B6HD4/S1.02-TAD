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
        short int taille;        // taille logique du tableau
        char symboleCaseVide;    // Symbole dans la case est vide quand elle est
                                 // vide
        char symboleCaseCachee;  // Symbole affiché quand la case est cachée
};

/*******************************
             Getters
*******************************/
char getSymboleCase(const Grille &grille, short int ligne, short int colonne);
// Renvoie le symbole dans la case(ligne, colonne) donnée en paramètres

short int getTailleGrille(const Grille &grille);
// Renvoie la taille logique de la grille

char getSymboleCaseVide(const Grille &grille;
// Revoie le symbole mis dans une case quand elle est vide

char getSymboleCaseCachee(const Grille &grille);
// Renvoie le symbole affiché quand une case est cachée

/*******************************
             Setters
*******************************/
void setCaseSymbole(Grille &grille, char symbole, short int ligne,
                    short int colonne);
// Remplit la case(ligne, colonne) avec sybole

void setCaseCachee(Grille &grille, short int ligne, short int colonne);
// Cache la case(ligne, colonne)

void setTailleGrille(Grille &grille, short int taille);
// Change la taille logique de la grille pour qu'elle soit taille

void setSymboleCaseVide(Grille &grille, char symbole);
// Change le symbole mis dans une case pour qu'elle soit
// vide pour qu'il soit symbole

void setSymboleCaseCachee(Grille &grille, char symbole);
// Change le symbole affiché quand une case est cachée pour qu'il soit symbole

/*******************************
          Observateurs
*******************************/

bool isCoordoneesValide(const Grille &grille, unsigned short int ligne,
                        unsigned short int colonne);
// Indique si le couple (ligne, colonne) désigne (ou pas)
// une case appartenant à la grille

bool isCaseVide(const Grille &grille, unsigned short int ligne,
                unsigned short int colonne);
// Indique si la case est vide

bool isCaseCachee(const Grille &grille, unsigned short int ligne,
                  unsigned short int colonne);
// Idnique si la case est cachée

bool isGrilleVide(const Grille &grille);
// Inidique si la grille est vide

bool isGrilleVisible(const Grille &grille);
// Indique si toute les cases de la grille sont visible

bool isGrillePleine(Grille &grille);
// But : indique si aucune case de la grille "grille" est vide

bool isAlignementHoriz(Grille &grille, const unsigned short int ligne,
                       const unsigned short int nbSymbole);
// But : indique s'il y a un certain nombre d’un symbole passé
// en paramètre en continu sur une ligne

bool isAlignementVerti(Grille &grille, const unsigned short int colonne,
                       const unsigned short int nbSymbole);
// But : indique s'il y a un certain nombre d’un symbole passé
// en paramètre en continu sur une colonne

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

void printGrille(const Grille &grille);
// Afficher la grille

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

#endif  // GRILLE_H

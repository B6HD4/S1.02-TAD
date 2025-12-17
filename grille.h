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
// But : Renvoie le symbole dans la case(ligne, colonne) donnée en paramètres
// Préconditions : la case existe dans la grille
// Post conditions : aucunes

short int getTailleGrille(const Grille &grille);
// But : Renvoie la taille logique de la grille
// Préconditions : aucune
// Post conditions : aucune

char getSymboleCaseVide(const Grille &grille);
// But : Revoie le symbole mis dans une case quand elle est vide
// Préconditions : Aucune
// Post condition : aucune

char getSymboleCaseCachee(const Grille &grille);
// But : Renvoie le symbole affiché quand une case est cachée
// Préconditions : Aucune
// Post condition : aucune

/*******************************
             Setters
*******************************/
void setCaseSymbole(Grille &grille, char symbole, short int ligne,
                    short int colonne);
// But : Remplit la case(ligne, colonne) avec sybole
// Préconditions : La case existe
// Post condition : La case remplie avec symbole

void setCaseCachee(Grille &grille, short int ligne, short int colonne);
// But : Cache la case(ligne, colonne)
// Préconditions : La case existe
// Post condition : La case est cachée

void setCaseVisible(Grille &grille, short int ligne, short int colonne);
// But : Rend visible la case(ligne, colonne)
// Préconditions : La case existe
// Post condition : La case est visible

void setTailleGrille(Grille &grille, short int taille);
// But : Change la taille logique de la grille pour qu'elle soit taille
// Préconditions : Aucune
// Post condition : La grille a une taille

void setSymboleCaseVide(Grille &grille, char symbole);
// But : Change le symbole mis dans une case pour qu'elle soit
// vide pour qu'il soit symbole
// Préconditions : Aucune
// Post condition : Le symbole qui représente un case vide est symbole

void setSymboleCaseCachee(Grille &grille, char symbole);
// But : Change le symbole affiché quand une case est cachée pour qu'il soit
// symbole
// vide pour qu'il soit symbole
// Préconditions : Aucune
// Post condition : Le symbole qui représente un case cachée est symbole

/*******************************
          Observateurs
*******************************/

bool isCoordoneesValide(const Grille &grille, unsigned short int ligne,
                        unsigned short int colonne);
/* BUT : Indique si le couple (ligne, colonne) désigne (ou pas)
une case appartenant à la grille
Précondition : -Grille : la grille de référence (aucune préconditions)
-Ligne : numéro de ligne, peut être quelconque, même négatifs
-Colonne : numéro de colonne, peut être quelconque, même négatifs
Postcondition : True si less coordonnées désignent une case valide de la grille
False sinon
*/

bool isCaseVide(const Grille &grille, unsigned short int ligne,
                unsigned short int colonne);
/*But : Indique si la case est vide
Précondition : -Grille : la grille de référence (aucune préconditions)
-Ligne : numéro de ligne de la case désignée
Préconditions : La ligne est est valide ( 1 <= ligne <= taille de la grille)
-Colonne : numéro de colonne de la case désignée
Préconditions : La colonne est valide ( 1 <= colonne <= taille de la grille)
Postcondition : True si la case est vide
False sinon
*/

bool isCaseCachee(const Grille &grille, unsigned short int ligne,
                  unsigned short int colonne);
/*But : Indique si la case est cachée
Précondition : -Grille : la grille de référence (aucune préconditions)
-Ligne : numéro de ligne de la case désignée
Préconditions : La ligne est est valide ( 1 <= ligne <= taille de la grille)
-Colonne : numéro de colonne de la case désignée
Préconditions : La colonne est valide ( 1 <= colonne <= taille de la grille)
Postcondition : True si la case est cachée
False sinon
*/

bool isGrilleVide(const Grille &grille);
/*But : Inidique si la grille est vide
Préconditions : Grille : la grille de références (aucune préconditions)
Postcondition : True si la grille est vide
False sinon
*/
bool isGrilleVisible(const Grille &grille);
/*But : Indique si toute les cases de la grille sont visible
Préconditions : Grille : la grille de références (aucune préconditions)
Postcondition : True si toutes les cases de la grille sont visibles
False sinon
*/

bool isGrillePleine(Grille &grille);
/*But : Indique si aucune case de la grille "grille" est vide
Préconditions : Grille : la grille de références (aucune préconditions)
Postcondition : True si la grille est pleine
False sinon
*/

bool isAlignementHoriz(Grille &grille, const unsigned short int ligne,
                       const unsigned short int nbSymbole);
/*But : Indique s'il y a un certain nombre d’un symbole passé en
paramètre en continu sur une ligne
Préconditions : Grille : la grille de références (aucune préconditions)
-Ligne : numéro de ligne vérifier
Préconditions : ne dépasse pas la taille de la grille
-Nombre de symbole d'affilée attendus
Préconditions : 0 < nombre <= taille
Postcondition : True si un alignement est trouvé
False sinon
*/

bool isAlignementVerti(Grille &grille, const unsigned short int colonne,
                       const unsigned short int nbSymbole);
/*But : Indique s'il y a un certain nombre d’un symbole passé
en paramètre en continu sur une colonne
Préconditions : Grille : la grille de références (aucune préconditions)
-Colonne : numéro de colonne vérifier
Préconditions : ne dépasse pas la taille de la grille
-Nombre de symbole d'affilée attendus
Préconditions : 0 < nombre <= taille
Postcondition : True si un alignement est trouvé
False sinon
*/

bool isAlignementDiago(Grille &grille, const unsigned short int nbSymbole);
/*But : Vérifie s'il y a un nombre de symbole en continue sur une diagonale
Préconditions : Grille : la grille de références (aucune préconditions)
-Nombre de symbole d'affilée attendus
Préconditions : 0 < nombre <= taille
Postcondition : True si un alignement est trouvé
False sinon
*/

/*******************************
        Modificateurs
*******************************/

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                char symboleCaseVide, bool estCache, char symboleCaseCachee);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                char symboleCaseVide, bool estCache);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                bool estCache, char symboleCaseCachee);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

void initGrille(Grille &grille, short int taille, bool estVide,
                char symboleCaseVide, bool estCache, char symboleCaseCachee);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                bool estCache);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

void initGrille(Grille &grille, short int taille, bool estVide, bool estCache,
                char symboleCaseCachee);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

void initGrille(Grille &grille, short int taille, bool estVide, bool estCache);
// But : Remplit les champs de grille
// Préconditions : Aucune
// Post condition : Tout les paramètre de la grille ont une valeur valide

/*******************************
        Entrées / Sorties
*******************************/

void printGrille(const Grille &grille);
// But : Afficher la grille
// Préconditions : Aucune
// Post condition : aucune

/*******************************
             Utils
*******************************/

short int ValUtoR(short int val);
// But : retourne les coordonnées réelles à partir des coordonnées de
// l'utilisateur

short int ValRtoU(short int val);
// But : retourne les coordonnées de l'utilisateur à partir des coordonnées
// réelles

#endif  // GRILLE_H

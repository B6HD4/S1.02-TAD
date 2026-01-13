/*
 * Nom du Fichier : "grille.h"
 * Contenu : Corps du TAD Grille2D permettant la gestion de grilles de jeux de
 * plateau à 2 dimensions.
 * Auteurs : Équipe 15, TP 4
 * Membres : Thibaut Fontaine, Bixente Hiriart--Dicharry, Cédric Rouillé
 * Déclaration :
 *       Je soussigné, HIRIART--DICHARRY Bixente, certifie que je suis co-auteur
 * du code ci-dessous.
 *       Je soussigné, ROUILLÉ Cedric, certifie que je suis co-auteur du code
 * ci-dessous.
 *       Je soussigné, FONTAINE Thibaut, certifie que je suis co-auteur du code
 * ci-dessous.
 * Création : 10/12/2025
 */

#ifndef GRILLE_H
#define GRILLE_H
#include <string>

struct Case {
        char symbole;   // Symbole stocké dans la case
        bool estCache;  // Vrai si la case est cachée, faux sinon
};

const unsigned short int TAILLE_TAB = 200;  // Taille physique du tableau

struct Grille {
        Case matrice[TAILLE_TAB][TAILLE_TAB];
        // Matrice contenant les cases de la grille
        unsigned short int taille;  // taille logique du tableau
        char symboleCaseVide;    // Symbole dans la case est vide quand elle est
                                 // vide
        char symboleCaseCachee;  // Symbole affiché quand la case est cachée
};

/*******************************
             Getters
*******************************/
char getSymboleCase(const Grille &grille, short int ligne, short int colonne);
// But : Renvoie le symbole dans la case(ligne, colonne) donnée en paramètres
// Préconditions : la case existe dans la grille et la grille est initialisée
// Post conditions : aucunes

short int getTailleGrille(const Grille &grille);
// But : Renvoie la taille logique de la grille
// Préconditions : aucune
// Post conditions : aucune

char getSymboleCaseVide(const Grille &grille);
// But : Renvoie le symbole mis dans une case quand elle est vide
// Préconditions : Aucune
// Post conditions : aucune

char getSymboleCaseCachee(const Grille &grille);
// But : Renvoie le symbole affiché quand une case est cachée
// Préconditions : Aucune
// Post condition : aucune

/*******************************
             Setters
*******************************/
void setCaseSymbole(Grille &grille, char symbole, short int numLigne,
                    short int numColonne);
// But : Remplit la case(ligne, colonne) avec symbole
// Préconditions : La ligne et la colonne sont compris entre 1 et taille
// Post condition : La case remplie avec symbole

void setCaseCachee(Grille &grille, short int numLigne, short int numColonne);
// But : Cache la case(ligne, colonne)
// Préconditions : La ligne et la colonne sont compris entre 1 et taille
// Post condition : La case est cachée

void setCaseVisible(Grille &grille, short int numLigne, short int numColonne);
// But : Rend visible la case(ligne, colonne)
// Préconditions : La ligne et la colonne sont compris entre 1 et taille
// Post condition : La case est visible

void setTailleGrille(Grille &grille, short int taille);
// But : Change la taille logique de la grille pour qu'elle soit taille
// Préconditions : 1 <= taille <= TAILLE_TAB
// Post condition : La grille a une taille

void setSymboleCaseVide(Grille &grille, char pSymbole);
// But : Remplace le symbole mis dans une case pour qu'elle soit
// vide pour qu'il soit pSymbole et change le symbole dans les anciennes cases
// vides pour qu'il soit le nouveau
// Préconditions : Aucune
// Post conditions : Le symbole qui représente un case vide est pSymbole

void setSymboleCaseCachee(Grille &grille, char pSymbole);
// But : Remplace le symbole affiché quand une case est cachée pour qu'il soit
// pSymbole
// Préconditions : Aucune
// Post conditions : Le symbole qui représente un case cachée est pSymbole

/*******************************
          Observateurs
*******************************/

bool isCoordoneesValide(const Grille &grille, short int numLigne,
                        short int numColonne);
/* BUT : Indique si le couple (ligne, colonne) désigne (ou pas)
une case appartenant à la grille
Préconditions : -Grille : la grille de référence initialisée
-Ligne : numéro de ligne de la case désignée
        La ligne est valide ( 1 <= ligne <= taille de la grille) sinon
        une exception est générée
-Colonne : numéro de colonne de la case désignée
        La colonne est valide ( 1 <= colonne <= taille de la grille)
        sinon une exception est générée
Postcondition : aucune
*/

bool isCaseVide(const Grille &grille, short int numLigne, short int numColonne);
/*But : Indique si la case est vide
Préconditions : -Grille : la grille de référence initialisée
-Ligne : numéro de ligne de la case désignée
        La ligne est valide ( 1 <= ligne <= taille de la grille) sinon
        une exception est générée
-Colonne : numéro de colonne de la case désignée
        La colonne est valide ( 1 <= colonne <= taille de la grille)
        sinon une exception est générée
Postcondition : aucune
*/

bool isCaseCachee(const Grille &grille, short int numLigne,
                  short int numColonne);
/*But : Indique si la case est cachée
Préconditions : -Grille : la grille de référence initialisée
-Ligne : numéro de ligne de la case désignée
        La ligne est valide ( 1 <= ligne <= taille de la grille) sinon
        une exception est générée
-Colonne : numéro de colonne de la case désignée
        La colonne est valide ( 1 <= colonne <= taille de la grille)
        sinon une exception est générée
Postcondition : aucune
*/

bool isGrilleVide(const Grille &grille);
/*But : Indique si la grille est vide
Préconditions : -Grille : la grille de référence initialisée
Postcondition : aucune
*/
bool isGrilleVisible(const Grille &grille);
/*But : Indique si toute les cases de la grille sont visible
Préconditions : -Grille : la grille de référence initialisée
Postcondition : True si la grille est vide
Postcondition : aucune
*/

bool isGrillePleine(const Grille &grille);
/*But : Indique si aucune case de la grille "grille" est vide
Préconditions : -Grille : la grille de référence initialisée
Postcondition : aucune
*/

bool isAlignementHoriz(const Grille &grille, short int numLigne,
                       unsigned short int nbSymbole, char symbole);
/*But : Indique s'il y a un certain nombre d’un symbole passé en
paramètre en continu sur une ligne
Préconditions : -Grille : la grille de référence initialisée
-numLigne : numéro de ligne vérifier
        0 < numLigne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool detecterAlignementHorizontale(const Grille &grille,
                                   unsigned short int nbSymbole, char symbole);
/*But : Indique s'il y a un certain nombre d’un symbole passé en
paramètre en continu sur toute les lignes de la grille
Préconditions : -Grille : la grille de référence initialisée
-numLigne : numéro de ligne vérifier
        0 < numLigne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool isAlignementVerti(const Grille &grille, short int numColonne,
                       unsigned short int nbSymbole, char symbole);
/*But : Indique s'il y a un certain nombre d’un symbole passé
en paramètre en continu sur une colonne
Préconditions : -Grille : la grille de référence initialisée
-numColonne : numéro de colonne vérifier
        0 < numColonne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool detecterAlignementVerticale(const Grille &grille,
                                 unsigned short int nbSymbole, char symbole);
/*But : Indique s'il y a un certain nombre d’un symbole passé
en paramètre en continu sur toute les colonnes de la grille
Préconditions : -Grille : la grille de référence initialisée
-numColonne : numéro de colonne vérifier
        0 < numColonne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool isAlignementDiagoPrincipale(const Grille &grille, short int numLigne,
                                 unsigned short int nbSymbole, char symbole);
/*But : Vérifie s'il y a un nombre de symbole en continu en diagonale sur une
ligne
Diagonale principale : diagonale allant d'en haut a gauche jusqu'à en bas à
droite
Préconditions : -Grille : la grille de référence initialisée
-numLigne : numéro de ligne vérifier
        0 < numLigne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool detecterAlignementDiagoPrinc(const Grille &grille,
                                  unsigned short int nbSymbole, char symbole);
/*But : Vérifie s'il y a un nombre de symbole en continu en diagonale sur toute
les lignes de la grille Diagonale principale : diagonale allant d'en haut a
gauche jusqu'à en bas à droite Préconditions : -Grille : la grille de référence
initialisée -numLigne : numéro de ligne vérifier 0 < numLigne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool isAlignementDiagoSecondaire(const Grille &grille, short int numLigne,
                                 unsigned short int nbSymbole, char symbole);
/*But : Vérifie s'il y a un nombre de symbole en continu en diagonale sur une
ligne
Diagonale secondaire : diagonale allant d'en haut a droite jusqu'à en bas à
gauche
Préconditions : -Grille : la grille de référence initialisée
-numLigne : numéro de ligne vérifier
        0 < numLigne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

bool detecterAlignementDiagoSec(const Grille &grille,
                                unsigned short int nbSymbole,
                                const char symbole);
/*But : Vérifie s'il y a un nombre de symbole en continu en diagonale sur toute
ligness de la grille
Diagonale secondaire : diagonale allant d'en haut a droite jusqu'à en bas à
gauche
Préconditions : -Grille : la grille de référence initialisée
-numLigne : numéro de ligne vérifier
        0 < numLigne <= taille
-nbSymbole : nombre de symbole d'affilée attendus
        0 < nbSymbole <= taille
Postcondition : aucune
*/

/*******************************
        Modificateurs
*******************************/

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                char symboleCaseVide, bool estCache, char symboleCaseCachee);
// But : Remplit les champs de grille avec des valeurs valides
// Préconditions : Aucune
// Post condition : Tout les paramètres de la grille ont une valeur valide

/*******************************
        Entrées / Sorties
*******************************/

void afficherLigne(const Grille &grille, short int ligne);
// But : affiche la ligne passée en paramètre
// Préconditions : la grille de référence est initialisée
// ligne : la ligne est comprise entre 1 et taille
// Post condition : aucune

void afficherGrille(const Grille &grille);
// But : Affiche la grille
// Préconditions : la grille de référence initialisée
// Post condition : aucune

#endif  // GRILLE_H

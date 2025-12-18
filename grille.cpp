/*
 * @brief Corps des primitives de Grille
 * @name grille.cpp
 * @authors Bixente Hiriart--Dicharry <bhdicharry@iutbayonne.univ-pau.fr>
 *          Thibaut Fontaine <tfontaine006@iutbayonne.univ-pau.fr>
 *          Cédric Rouillé <crouille@iutbayonne.univ-pau.fr>
 * @date mar. 16 déc. 2025 16:42:40
 * @remarks
 */

#include "grille.h"
#include <iostream>
using namespace std;

/*******************************
             Getters
*******************************/

char getSymboleCase(const Grille &grille, short int ligne, short int colonne) {
        return grille.matrice[ValUtoR(ligne)][ValUtoR(colonne)].symbole;
}

short int getTailleGrille(const Grille &grille) { return grille.taille; }

char getSymboleCaseVide(const Grille &grille) { return grille.symboleCaseVide; }

char getSymboleCaseCachee(const Grille &grille) {
        return grille.symboleCaseCachee;
}

/*******************************
             Setters
*******************************/

void setCaseSymbole(Grille &grille, char symbole, short int numLigne,
                    short int numColonne) {
        grille.matrice[numLigne][numColonne].symbole = symbole;
}

void setCaseCachee(Grille &grille, short int numLigne, short int numColonne) {
        grille.matrice[numLigne][numColonne].estCache = true;
}

void setCaseVisible(Grille &grille, short int numLigne, short int numColonne) {
        grille.matrice[numLigne][numColonne].estCache = false;
}

void setCaseVide(Grille &grille, short int numLigne, short int numColonne) {
        grille.matrice[numLigne][numColonne].symbole =
            getSymboleCaseVide(grille);
}

void setTailleGrille(Grille &grille, short int taille) {
        grille.taille = taille;
}

void setSymboleCaseVide(Grille &grille, char symbole) {
        grille.symboleCaseVide = symbole;
}

void setSymboleCaseCachee(Grille &grille, char symbole) {
        grille.symboleCaseCachee = symbole;
}

/*******************************
        Modificateurs
*******************************/

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,char symboleCaseVide, bool estCache, char symboleCaseCachee)
{
    if (taille > TAILLE_TAB)
    {
        genererException("Taille supérieure à la taille maximum");
    }
    
    setTailleGrille(grille, taille);
    setSymboleCaseVide(grille, symboleCaseVide);
    setSymboleCaseCachee(grille, symboleCaseCachee);

    for (unsigned short int i = 0; i < taille-1; i++)
        {
            for (unsigned short int j = 0; j < taille-1; j++)
            {
                setCaseSymbole(grille, symbole, i, j);
            }
        }

    if (estVide)
    {
        for (unsigned short int i = 0; i < taille-1; i++)
        {
            for (unsigned short int j = 0; j < taille-1; j++)
            {
                setCaseVide(grille, i, j);
            }
        }
    }    
    if (estCache)
    {
        for (unsigned short int i = 0; i < taille-1; i++)
        {
            for (unsigned short int j = 0; j < taille-1; j++)
            {
                setCaseCachee(grille, i, j);
            }
        }
    }    
    else {
        for (unsigned short int i = 0; i < taille-1; i++)
        {
            for (unsigned short int j = 0; j < taille-1; j++)
            {
                setCaseVisible(grille, i, j);
            }
        }
    }
}

/*******************************
          Observateurs
*******************************/

bool isCoordoneesValide(const Grille &grille, unsigned short int ligne, unsigned short int colonne)
{
    if((getTailleGrille(grille) >= ligne && ligne > 0) && (getTailleGrille(grille) >= colonne && colonne > 0))
    {
        return true;
    }
    return false;
}

bool isCaseVide(const Grille &grille, unsigned short int ligne, unsigned short int colonne)
{
    if((getSymboleCase(grille, ligne, colonne) == getSymboleCaseVide(grille)) && isCoordoneesValide(grille, ligne, colonne))
    {
        return true;
    }
    return false;
}

bool isCaseCachee(const Grille &grille, unsigned short int ligne, unsigned short int colonne)
{
    if((getSymboleCase(grille, ligne, colonne) == getSymboleCaseCachee(grille)) && isCoordoneesValide(grille, ligne, colonne))
    {
        return true;
    }
    return false;
}

bool isGrilleVide(const Grille &grille)
{
    for (int i = 0; i > getTailleGrille(grille); i++)
    {
        for(int j = 0; j > getTailleGrille(grille); j++)
        {
            if(!(getSymboleCase(grille, ligne, colonne) == getSymboleCaseVide(grille)) && isCoordoneesValide(grille, ligne, colonne))
            {
                return false;
            }
        }
    }
    return true;
}

bool isGrilleVisible(const Grille &grille)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = true;
    }
    return 0;
}

bool isGrillePleine(Grille &grille)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = true;
    }
    return 0;
}

bool isAlignementHoriz(Grille &grille, const unsigned short int ligne, const unsigned short int nbSymbole)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = true;
    }
    return 0;
}

bool isAlignementVerti(Grille &grille, const unsigned short int colonne, const unsigned short int nbSymbole)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = true;
    }
    return 0;
}

bool isAlignementDiago(Grille &grille, const unsigned short int nbSymbole)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = true;
    }
    return 0;
}

/*******************************
        Entrées / Sorties
*******************************/

/* Exemple d'affichage vu en soutien 
*
* void afficherLigne(const Case& ligne[], unsigned short int nbColonne, char leSymboleCaseCachee)
* {
*     for (unsigned short int c = 0; c <= nbColonne; c++)
*     {
*         if (ligne[c].visibilite)
*         {
*             cout << ligne[c].symbole << endl;
*         }
*         else
*         {
*             cout << leSymboleCaseCachee << endl;
*         }
*     }
* }
* 
* // exemple d'appel : afficherLigne(grille.case[l], grille.taille, grille.symboleCaseVide);
*
*/

/*******************************
             Utils
*******************************/

void genererException(const string &detailException) {
        throw std::invalid_argument(detailException);
}

short int ValUtoR(short int val) { return val - 1; }

short int ValRtoU(short int val) { return val + 1; }

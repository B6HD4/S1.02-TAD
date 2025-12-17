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

void setCaseSymbole(Grille &grille, char symbole, short int ligne,
                    short int colonne) {
        grille.matrice[ligne][colonne].symbole = symbole;
}

void setCaseCachee(Grille &grille, short int ligne, short int colonne) {
        grille.matrice[ligne][colonne].estCache = true;
}

void setCaseVisible(Grille &grille, short int ligne, short int colonne) {
        grille.matrice[ligne][colonne].estCache = false;
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

void initGrille(Grille &grille, short int taille, bool estVide,char symboleCaseVide, bool estCache, char symboleCaseCachee){
    setTailleGrille(grille, taille);
    if (estVide)
    {
        for (int i = 0; i < taille-1; i++)
        {
            setSymboleCaseVide(grille, symboleCaseVide);
        }
    }    
    else if (estCache)
    {
        for (int i = 0; i < taille-1; i++)
        {
            setSymboleCaseCachee(grille, symboleCaseCachee);
        }
    }
    else if (symbole)
    {
        for (int i = 0; i < taille-1; i++)
        {
            setCaseSymbole(grille, symbole);
        }
    }
    else {
        genererException("Impossible de créer la grille");
    }
}

void initGrille(Grille &grille, short int taille, bool estVide, bool estCache,char symboleCaseCachee){}

void initGrille(Grille &grille, short int taille, bool estVide, bool estCache){}


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


/*******************************
             Utils
*******************************/

void genererException(const string &detailException) {
        throw std::invalid_argument(detailException);
}

short int ValUtoR(short int val) { return val - 1; }

short int ValRtoU(short int val) { return val + 1; }

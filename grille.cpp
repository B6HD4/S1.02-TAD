/*
 * @brief Corps des primitives de Grille
 * @name grille.cpp
 * @authors Bixente Hiriart--Dicharry <bhdicharry@iutbayonne.univ-pau.fr>
 *          Thibaut Fontaine <tfontaine006@iutbayonne.univ-pau.fr>
 *          Cédric Rouillé <crouille@iutbayonne.univ-pau.fr>
 * @date mar. 16 déc. 2025 16:42:40
 * @remarks
 */

#include"grille.h"

void initGrille(Grille &grille, short int taille, char symbole, bool estVide, char symboleCaseVide, bool estCache, char symboleCaseCachee){
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
    else
        genererException("Impossible de créer la grille");
}

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,char symboleCaseVide, bool estCache){
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
            setSymboleCaseCachee(grille, '.');
        }
    }
    else if (symbole)
    {
        for (int i = 0; i < taille-1; i++)
        {
            setCaseSymbole(grille, symbole);
        }
    }
    else
        genererException("Impossible de créer la grille");
}

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,bool estCache, char symboleCaseCachee){setTailleGrille(grille, taille);
    if (estVide)
    {
        for (int i = 0; i < taille-1; i++)
        {
            setSymboleCaseVide(grille, '_');
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
    else
        genererException("Impossible de créer la grille");}

void initGrille(Grille &grille, short int taille, bool estVide,char symboleCaseVide, bool estCache, char symboleCaseCachee){}

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,bool estCache){}

void initGrille(Grille &grille, short int taille, bool estVide, bool estCache,char symboleCaseCachee){}

void initGrille(Grille &grille, short int taille, bool estVide, bool estCache){}
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
             Utils
*******************************/

void genererException(const string &detailException)
{
    throw std::invalid_argument(detailException);
}

short int ValUtoR(short int val) { return val - 1; }

short int ValRtoU(short int val) { return val + 1; }

/*******************************
             Getters
*******************************/

char getSymboleCase(const Grille &grille, short int ligne, short int colonne)
{
    return grille.matrice[ValUtoR(ligne)][ValUtoR(colonne)].symbole;
}

short int getTailleGrille(const Grille &grille) { return grille.taille; }

char getSymboleCaseVide(const Grille &grille) { return grille.symboleCaseVide; }

char getSymboleCaseCachee(const Grille &grille)
{
    return grille.symboleCaseCachee;
}

/*******************************
             Setters
*******************************/

void setCaseSymbole(Grille &grille, char symbole, short int numLigne,
                    short int numColonne)
{
    grille.matrice[numLigne][numColonne].symbole = symbole;
}

void setCaseCachee(Grille &grille, short int numLigne, short int numColonne)
{
    grille.matrice[numLigne][numColonne].estCache = true;
}

void setCaseVisible(Grille &grille, short int numLigne, short int numColonne)
{
    grille.matrice[numLigne][numColonne].estCache = false;
}

void setCaseVide(Grille &grille, short int numLigne, short int numColonne)
{
    grille.matrice[numLigne][numColonne].symbole =
        getSymboleCaseVide(grille);
}

void setTailleGrille(Grille &grille, short int taille)
{
    grille.taille = taille;
}

void setSymboleCaseVide(Grille &grille, char pSymbole)
{
    char ancienSymbole = getSymboleCaseVide(grille);
    short int taille = getTailleGrille(grille);
    for (unsigned short int i = 0; i < taille; i++)
    {
        for (unsigned short int j = 0; j < taille; j++)
        {
            if (getSymboleCase(grille, i, j) == ancienSymbole)
            {
                setCaseSymbole(grille, pSymbole, i, j);
            }
        }
    }
    grille.symboleCaseVide = pSymbole;
}

void setSymboleCaseCachee(Grille &grille, char pSymbole)
{
    grille.symboleCaseCachee = pSymbole;
}

/*******************************
          Observateurs
*******************************/

bool isCoordoneesValide(const Grille &grille, short int numLigne,
                        short int numColonne)
{
    if ((getTailleGrille(grille) >= numLigne && numLigne > 0) &&
        (getTailleGrille(grille) >= numColonne && numColonne > 0))
    {
        return true;
    }
    return false;
}

bool isCaseVide(const Grille &grille, short int numLigne,
                short int numColonne)
{
    if ((getSymboleCase(grille, numLigne, numColonne) ==
         getSymboleCaseVide(grille)) &&
        isCoordoneesValide(grille, numLigne, numColonne))
    {
        return true;
    }
    return false;
}

bool isCaseCachee(const Grille &grille, short int numLigne,
                  short int numColonne)
{
    if ((getSymboleCase(grille, numLigne, numColonne) ==
         getSymboleCaseCachee(grille)) &&
        isCoordoneesValide(grille, numLigne, numColonne))
    {
        return true;
    }
    return false;
}

bool isGrilleVide(const Grille &grille)
{
    for (short int i = 0; i <= getTailleGrille(grille); i++)
    {
        for (short int j = 0; j <= getTailleGrille(grille); j++)
        {
            if (!((getSymboleCase(grille, i, j) ==
                   getSymboleCaseVide(grille)) &&
                  isCoordoneesValide(grille, i, j)))
            {
                return false;
            }
        }
    }
    return true;
}

bool isGrilleVisible(const Grille &grille)
{
    for (short int i = 0; i <= getTailleGrille(grille); i++)
    {
        for (short int j = 0; j <= getTailleGrille(grille); j++)
        {
            if (!((getSymboleCase(grille, i, j) ==
                   getSymboleCaseCachee(grille)) &&
                  isCoordoneesValide(grille, i, j)))
            {
                return false;
            }
        }
    }
    return true;
}

bool isGrillePleine(const Grille &grille)
{
    for (short int i = 0; i <= getTailleGrille(grille); i++)
    {
        for (short int j = 0; j <= getTailleGrille(grille); j++)
        {
            if ((getSymboleCase(grille, i, j) ==
                 getSymboleCaseVide(grille)) &&
                isCoordoneesValide(grille, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

bool isAlignementHoriz(const Grille &grille, short int numLigne, unsigned short int nbSymbole, char symbole)
{
    // Initialiser
    bool alignementHoriz = false; // Variable d'alignement
    short int compteur = 0;       // Compteur de symboles alignés
    int ligne = 0;                // Ligne de départ

    // Recherche alignement dans la grille
    while (true)
    {
        if (ligne > getTailleGrille(grille) - 1) // Fin de la grille
        {
            break;
        }

        // Evaluation de la condition d'alignement dans la ligne l
        // Initialiser
        int colonne = 0; // Colonne de départ

        // Recherche symbole dans la ligne
        while (true)
        {
            if (colonne > getTailleGrille(grille) - 1) // Fin de la ligne
            {
                break;
            }

            // Evaluer la condition dans la colonne c

            if (compteur == nbSymbole) // Condition d'alignement remplie
            {
                alignementHoriz = true; // Mettre à vrai la variable d'alignement
                break;                  // Sortir de la boucle de recherche
            }

            if (getSymboleCase(grille, numLigne, colonne) == symbole) // Symbole trouvé
            {
                compteur = compteur + 1; // Incrémenter le compteur
            }
            else // Symbole non trouvé
            {
                compteur = 0; // Réinitialiser le compteur
            }

            colonne = colonne + 1; // Colonne suivante
        }

        if (alignementHoriz == true) // Sortir de la boucle principale si alignement trouvé
        {
            break;
        }

        ligne = ligne + 1; // Ligne suivante
    }

    ligne = 0; // Réinitialiser la ligne

    return alignementHoriz; // Retourner le résultat
}

bool isAlignementVerti(Grille &grille, const short int numColonne, unsigned short int nbSymbole, char symbole)
{
    // Initialiser
    bool alignementVerti = false; // Variable d'alignement
    short int compteur = 0;       // Compteur de symboles alignés
    int colonne = 0;              // Colonne de départ

    // Recherche alignement dans la grille
    while (true)
    {
        if (colonne > getTailleGrille(grille) - 1) // Fin de la grille
        {
            break;
        }

        // Evaluation de la condition d'alignement dans la ligne l
        // Initialiser
        int ligne = 0; // Colonne de départ

        // Recherche symbole dans la ligne
        while (true)
        {
            if (ligne > getTailleGrille(grille) - 1) // Fin de la ligne
            {
                break;
            }

            // Evaluer la condition dans la ligne l

            if (compteur == nbSymbole) // Condition d'alignement remplie
            {
                alignementVerti = true; // Mettre à vrai la variable d'alignement
                break;                  // Sortir de la boucle de recherche
            }

            if (getSymboleCase(grille, numLigne, ligne) == symbole) // Symbole trouvé
            {
                compteur = compteur + 1; // Incrémenter le compteur
            }
            else // Symbole non trouvé
            {
                compteur = 0; // Réinitialiser le compteur
            }

            ligne = ligne + 1; // Ligne suivante
        }

        if (alignementVerti == true) // Sortir de la boucle principale si alignement trouvé
        {
            break;
        }

        colonne = colonne + 1; // Colonne suivante
    }

    colonne = 0; // Réinitialiser la colonne

    return alignementVerti; // Retourner le résultat
}

bool isAlignementDiagoPrincipale(Grille &grille, short int numLigne, unsigned short int nbSymbole,
                                 const char symbole)
{
    if ((ligne > 0) && (colonne > 0))
    {
        return true;
    }
    return false;
}

bool isAlignementDiagoSecondaire(Grille &grille, short int numLigne, unsigned short int nbSymbole,
                                 const char symbole)
{
    if ((ligne > 0) && (colonne > 0))
    {
        return true;
    }
    return false;
}

/*******************************
        Modificateurs
*******************************/

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                char symboleCaseVide, bool estCache, char symboleCaseCachee)
{
    if (taille > TAILLE_TAB)
    {
        genererException("Taille supérieure à la taille maximum");
    }

    setTailleGrille(grille, taille);
    setSymboleCaseVide(grille, symboleCaseVide);
    setSymboleCaseCachee(grille, symboleCaseCachee);

    for (unsigned short int i = 0; i < taille - 1; i++)
    {
        for (unsigned short int j = 0; j < taille - 1; j++)
        {
            setCaseSymbole(grille, symbole, i, j);
        }
    }

    if (estVide)
    {
        for (unsigned short int i = 0; i < taille - 1; i++)
        {
            for (unsigned short int j = 0; j < taille - 1; j++)
            {
                setCaseVide(grille, i, j);
            }
        }
    }
    if (estCache)
    {
        for (unsigned short int i = 0; i < taille - 1; i++)
        {
            for (unsigned short int j = 0; j < taille - 1; j++)
            {
                setCaseCachee(grille, i, j);
            }
        }
    }
    else
    {
        for (unsigned short int i = 0; i < taille - 1; i++)
        {
            for (unsigned short int j = 0; j < taille - 1; j++)
            {
                setCaseVisible(grille, i, j);
            }
        }
    }

    /*******************************
            Entrées / Sorties
    *******************************/

    /* Exemple d'affichage vu en soutien
     *
     * void afficherLigne(const Case& ligne[], unsigned short int nbColonne, char
     * leSymboleCaseCachee)
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
     * // exemple d'appel : afficherLigne(grille.case[l], grille.taille,
     * grille.symboleCaseVide);
     * // il faudrait creer un type pour afficher des cases donc on est obligé de
     * passer la grille car elle est dans un struct
     */

    void afficherLigne(const Grille &grille, unsigned int ligne)
    {
        for (unsigned short int colonne = 0; colonne <= grille.taille - 1; colonne++)
        {
            if (grille.matrice[ligne, colonne]->estCache == false)
            {
                cout << grille.matrice[ligne][colonne].symbole << endl;
            }
            else
            {
                cout << grille.symboleCaseCachee << endl;
            }
        }
    }

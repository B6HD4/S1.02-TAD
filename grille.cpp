/*
 * Nom du Fichier : "grille.h"
 * Contenu : Corps du TAD Grille2D contenant les déclarations des primitives
 * d'un TAD simple permettant la gestion de grilles de jeux de plateau à 2
 * dimensions.
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

#include "grille.h"
#include <iostream>
using namespace std;

/*******************************
             Utils
*******************************/

void genererException(const string &detailException) {
        throw std::invalid_argument(detailException);
}

short int valUtoR(short int val) { return val - 1; }

short int valRtoU(short int val) { return val + 1; }

/*******************************
             Getters
*******************************/

char getSymboleCase(const Grille &grille, short int ligne, short int colonne) {
        return grille.matrice[valUtoR(ligne)][valUtoR(colonne)].symbole;
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
        grille.matrice[valUtoR(numLigne)][valUtoR(numColonne)].symbole =
            symbole;
}

void setCaseCachee(Grille &grille, short int numLigne, short int numColonne) {
        grille.matrice[valUtoR(numLigne)][valUtoR(numColonne)].estCache = true;
}

void setCaseVisible(Grille &grille, short int numLigne, short int numColonne) {
        grille.matrice[valUtoR(numLigne)][valUtoR(numColonne)].estCache = false;
}

void setCaseVide(Grille &grille, short int numLigne, short int numColonne) {
        grille.matrice[valUtoR(numLigne)][valUtoR(numColonne)].symbole =
            getSymboleCaseVide(grille);
}

void setTailleGrille(Grille &grille, short int taille) {
        grille.taille = taille;
}

void setSymboleCaseVide(Grille &grille, char pSymbole) {
        char ancienSymbole = getSymboleCaseVide(grille);
        short int taille = getTailleGrille(grille);
        for (unsigned short int i = 1; i <= taille; i++) {
                for (unsigned short int j = 1; j <= taille; j++) {
                        if (getSymboleCase(grille, i, j) == ancienSymbole) {
                                setCaseSymbole(grille, pSymbole, i, j);
                        }
                }
        }
        grille.symboleCaseVide = pSymbole;
}

void setSymboleCaseCachee(Grille &grille, char pSymbole) {
        grille.symboleCaseCachee = pSymbole;
}

/*******************************
          Observateurs
*******************************/

bool isCoordoneesValide(const Grille &grille, short int numLigne,
                        short int numColonne) {
        if ((getTailleGrille(grille) >= numLigne && numLigne > 0) &&
            (getTailleGrille(grille) >= numColonne && numColonne > 0)) {
                return true;
        }
        return false;
}

bool isCaseVide(const Grille &grille, short int numLigne,
                short int numColonne) {
        if ((getSymboleCase(grille, numLigne, numColonne) ==
             getSymboleCaseVide(grille)) &&
            isCoordoneesValide(grille, numLigne, numColonne)) {
                return true;
        }
        return false;
}

bool isCaseCachee(const Grille &grille, short int numLigne,
                  short int numColonne) {
        if ((getSymboleCase(grille, numLigne, numColonne) ==
             getSymboleCaseCachee(grille)) &&
            isCoordoneesValide(grille, numLigne, numColonne)) {
                return true;
        }
        return false;
}

bool isGrilleVide(const Grille &grille) {
        for (short int i = 1; i <= getTailleGrille(grille); i++) {
                for (short int j = 1; j <= getTailleGrille(grille); j++) {
                        if (!((getSymboleCase(grille, i, j) ==
                               getSymboleCaseVide(grille)) &&
                              isCoordoneesValide(grille, i, j))) {
                                return false;
                        }
                }
        }
        return true;
}

bool isGrilleVisible(const Grille &grille) {
        for (short int i = 1; i <= getTailleGrille(grille); i++) {
                for (short int j = 1; j <= getTailleGrille(grille); j++) {
                        if (!((getSymboleCase(grille, i, j) ==
                               getSymboleCaseCachee(grille)) &&
                              isCoordoneesValide(grille, i, j))) {
                                return false;
                        }
                }
        }
        return true;
}

bool isGrillePleine(const Grille &grille) {
        for (short int i = 1; i <= getTailleGrille(grille); i++) {
                for (short int j = 1; j <= getTailleGrille(grille); j++) {
                        if ((getSymboleCase(grille, i, j) ==
                             getSymboleCaseVide(grille)) &&
                            isCoordoneesValide(grille, i, j)) {
                                return false;
                        }
                }
        }
        return true;
}

bool isAlignementHoriz(const Grille &grille, short int numLigne,
                       unsigned short int nbSymbole, char symbole) {
        // Initialiser
        bool alignementHoriz = false;  // Variable d'alignement
        short int compteur = 0;        // Compteur de symboles alignés
        short int colonne = 1;         // Colonne de départ

        // Recherche symbole dans la ligne
        while (true) {
                if (colonne > getTailleGrille(grille))  // Fin de la ligne
                {
                        break;
                }

                // Evaluer la condition dans la colonne c

                if (compteur == nbSymbole)  // Condition d'alignement remplie
                {
                        alignementHoriz = true;  // Mettre à vrai la variable
                                                 // d'alignement
                        break;  // Sortir de la boucle de recherche
                }

                if (getSymboleCase(grille, numLigne, colonne) ==
                    symbole)  // Symbole trouvé
                {
                        compteur = compteur + 1;  // Incrémenter le compteur
                } else                            // Symbole non trouvé
                {
                        compteur = 0;  // Réinitialiser le compteur
                }

                colonne = colonne + 1;  // Colonne suivante
        }
        return alignementHoriz;  // Retourner le résultat
}

bool detecterAlignementHorizontale(const Grille &grille,
                                   unsigned short int nbSymbole, char symbole) {
        bool detecterAlignementHoriz = false;
        short int ligne = 1;
        while (true) {
                if (ligne > getTailleGrille(grille)) {
                        break;
                }

                if (isAlignementHoriz(grille, ligne, nbSymbole, symbole)) {
                        detecterAlignementHoriz = true;
                        break;
                }

                ligne++;
        }
        return detecterAlignementHoriz;
}

bool isAlignementVerti(const Grille &grille, short int numColonne,
                       unsigned short int nbSymbole, char symbole) {
        // Initialiser
        bool alignementVerti = false;  // Variable d'alignement
        short int compteur = 0;        // Compteur de symboles alignés
        short int ligne =
            1;  // Ligne de départ*// Recherche symbole dans la ligne
        while (true) {
                if (ligne > getTailleGrille(grille))  // Fin de la ligne
                {
                        break;
                }

                // Evaluer la condition dans la ligne l

                if (compteur == nbSymbole)  // Condition d'alignement remplie
                {
                        alignementVerti =
                            true;  // Mettre à vrai la variable d'alignement
                        break;     // Sortir de la boucle de recherche
                }

                if (getSymboleCase(grille, ligne, numColonne) ==
                    symbole)  // Symbole trouvé
                {
                        compteur = compteur + 1;  // Incrémenter le compteur
                } else                            // Symbole non trouvé
                {
                        compteur = 0;  // Réinitialiser le compteur
                }

                ligne = ligne + 1;  // Ligne suivante
        }
        return alignementVerti;  // Retourner le résultat
}

bool detecterAlignementVerticale(const Grille &grille,
                                 unsigned short int nbSymbole, char symbole) {
        bool detecterAlignementVerti = false;
        short int colonne = 1;
        while (true) {
                if (colonne > getTailleGrille(grille)) {
                        break;
                }
                if (isAlignementVerti(grille, colonne, nbSymbole, symbole)) {
                        detecterAlignementVerti = true;
                        break;
                }

                colonne++;
        }
        return detecterAlignementVerti;
}

bool isAlignementDiagoPrincipale(const Grille &grille, short int numLigne,
                                 unsigned short int nbSymbole, char symbole) {
        // Initialiser
        bool alignementDiagoPrincipale = false;  // Variable d'alignement
        short int colonne = 1;                   // Colonne de départ
        short int colDansLigne;
        // Recherche symbole dans la ligne
        while (true) {
                short int compteur = 0;  // Compteur de symboles alignés
                if (numLigne > getTailleGrille(grille) - 1)  // Fin de la ligne
                {
                        break;
                }

                // Evaluer la condition dans la colonne c

                if (getSymboleCase(grille, numLigne, colonne) ==
                    symbole)  // Symbole trouvé
                {
                        colDansLigne = colonne;
                        compteur = compteur + 1;  // Incrémenter le compteur
                        while (true) {
                                colDansLigne++;
                                numLigne++;

                                if (numLigne > getTailleGrille(grille) - 1) {
                                        break;
                                }

                                if (getSymboleCase(grille, numLigne, colonne) !=
                                    symbole) {
                                        break;
                                }

                                if (compteur ==
                                    nbSymbole)  // Condition d'alignement
                                                // remplie
                                {
                                        alignementDiagoPrincipale =
                                            true;  // Mettre à vrai la variable
                                                   // d'alignement
                                        break;     // Sortir de la boucle de
                                                   // recherche
                                }
                                compteur =
                                    compteur + 1;  // Incrémenter le compteur
                        }

                        if (alignementDiagoPrincipale) {
                                break;
                        }
                        colonne = colonne + 1;  // Colonne suivante
                }
        }
        return alignementDiagoPrincipale;  // Retourner le résultat
}

bool detecterAlignementDiagoPrinc(const Grille &grille,
                                  unsigned short int nbSymbole, char symbole) {
        bool detecterAlignementDiagoPrinc = false;
        short int ligne = 1;
        while (true) {
                if (ligne > getTailleGrille(grille)) {
                        break;
                }
                if (isAlignementVerti(grille, ligne, nbSymbole, symbole)) {
                        detecterAlignementDiagoPrinc = true;
                        break;
                }

                ligne++;
        }
        return detecterAlignementDiagoPrinc;
}

bool isAlignementDiagoSecondaire(const Grille &grille, short int numLigne,
                                 unsigned short int nbSymbole, char symbole) {
        // Initialiser
        bool alignementDiagoSecondaire = false;       // Variable d'alignement
        short int colonne = getTailleGrille(grille);  // Colonne de départ
        short int colDansLigne;
        // Recherche symbole dans la ligne
        while (true) {
                short int compteur = 0;  // Compteur de symboles alignés
                if (numLigne > getTailleGrille(grille))  // Fin de la ligne
                {
                        break;
                }

                // Evaluer la condition dans la colonne c

                if (getSymboleCase(grille, numLigne, colonne) ==
                    symbole)  // Symbole trouvé
                {
                        colDansLigne = colonne;
                        compteur = compteur + 1;  // Incrémenter le compteur
                        while (true) {
                                colDansLigne--;
                                numLigne++;
                                if (numLigne > getTailleGrille(grille)) {
                                        break;
                                }

                                if (getSymboleCase(grille, numLigne,
                                                   colDansLigne) != symbole) {
                                        break;
                                }

                                if (compteur ==
                                    nbSymbole)  // Condition d'alignement
                                                // remplie
                                {
                                        alignementDiagoSecondaire =
                                            true;  // Mettre à vrai la variable
                                                   // d'alignement
                                        break;     // Sortir de la boucle de
                                                   // recherche
                                }
                                compteur =
                                    compteur + 1;  // Incrémenter le compteur
                        }

                        if (alignementDiagoSecondaire) {
                                break;
                        }
                        colonne = colonne - 1;  // Colonne suivante
                }
        }
        return alignementDiagoSecondaire;  // Retourner le résultat
}

bool detecterAlignementDiagoSec(const Grille &grille,
                                unsigned short int nbSymbole,
                                const char symbole) {
        bool detecterAlignementDiagoSec = false;
        short int ligne = 1;
        while (true) {
                if (ligne > getTailleGrille(grille)) {
                        break;
                }
                if (isAlignementVerti(grille, ligne, nbSymbole, symbole)) {
                        detecterAlignementDiagoSec = true;
                        break;
                }

                ligne++;
        }
        return detecterAlignementDiagoSec;
}

/*******************************
        Modificateurs
*******************************/

void initGrille(Grille &grille, short int taille, char symbole, bool estVide,
                char symboleCaseVide, bool estCache, char symboleCaseCachee) {
        if (taille > TAILLE_TAB) {
                genererException("Taille supérieure à la taille maximum");
        }
        setTailleGrille(grille, taille);
        setSymboleCaseVide(grille, symboleCaseVide);
        setSymboleCaseCachee(grille, symboleCaseCachee);

        for (unsigned short int i = 1; i <= taille; i++) {
                for (unsigned short int j = 1; j <= taille; j++) {
                        setCaseSymbole(grille, symbole, i, j);
                }
        }

        if (estVide) {
                for (unsigned short int i = 1; i <= taille; i++) {
                        for (unsigned short int j = 1; j <= taille; j++) {
                                setCaseVide(grille, i, j);
                        }
                }
        }
        if (estCache) {
                for (unsigned short int i = 1; i <= taille; i++) {
                        for (unsigned short int j = 1; j <= taille; j++) {
                                setCaseCachee(grille, i, j);
                        }
                }
        } else {
                for (unsigned short int i = 1; i <= taille; i++) {
                        for (unsigned short int j = 1; j <= taille; j++) {
                                setCaseVisible(grille, i, j);
                        }
                }
        }
}

/*******************************
        Entrées / Sorties
*******************************/

void afficherLigne(const Grille &grille, short int ligne) {
        for (unsigned short int colonne = 1; colonne <= getTailleGrille(grille);
             colonne++) {
                if (!isCaseCachee(grille, ligne, colonne)) {
                        cout << getSymboleCase(grille, ligne, colonne);
                } else {
                        cout << getSymboleCaseCachee(grille);
                }
        }
        cout << endl;
}

void afficherGrille(const Grille &grille) {
        for (short int i = 1; i <= getTailleGrille(grille); i++) {
                afficherLigne(grille, i);
        }
}

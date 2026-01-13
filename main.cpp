/*
 * Nom du Fichier : "grille.h"
 * Contenu : Programme du jeu du morpion, utilisant le TAD Grille2D pour gérer
 * la grille du jeu.
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

void jouerUnTour(Grille &morpion, char symboleJ1, char symboleJ2,
                 unsigned short int tour, int indicFinPartie);

void joueurJoue(Grille &morpion, char symboleJ, int indicFinPartie, unsigned short int tour);
/* BUT : */

void evaluerSiJoueurGagnant(Grille &morpion, char symboleJ,
                            int indicFinPartie);

void afficherResultatPartie(int indicFinPartie);

void initialiserLesElementsDuJeu(char symboleJ1, char symboleJ2,
                                 unsigned short int tour, int indicFinPartie);

int main(void)
{

    return 0;
}

void joueurJoue(Grille &morpion, char symboleJ, int indicFinPartie, unsigned short int tour)
{
    // déclaration
    short int ligneJ;
    short int colonneJ;
    bool valide;
    const int SEUIL_D_EVALUATION = 3;

    // saisie verif
    do
    {
        cout << "Saisir la ligne : ";
        cin >> ligneJ;
        cout << "Saisir la colonne : ";
        cin >> colonneJ;

        if (isCoordoneesValide(morpion, ligneJ, colonneJ) && isCaseVide(morpion, ligneJ, colonneJ))
        {
            valide = true;
        }
        else
        {
            valide = false;
        }
    } while (valide == false);

    // placer symbole du joueur sur la grille
    setCaseSymbole(morpion, symboleJ, ligneJ, colonneJ);

    // afficher grille
    afficherGrille(morpion);

    // finJeu
    if (tour >= SEUIL_D_EVALUATION)
    {
        evaluerSiJoueurGagnant(morpion, symboleJ, indicFinPartie);
    }
}
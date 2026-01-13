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

void jouerUnTour(Grille &morpion, char symboleJ1, char symboleJ2,
                 unsigned short int tour, int indicFinPartie);

void joueur1joue(Grille &morpion, char symboleJ1, int indicFinPartie);

void joueur2joue(Grille &morpion, char symboleJ2, int indicFinPartie);

void evaluerSiJoueurGagnant(Grille &morpion, char symboleJ,
                             int indicFinPartie);


void afficherResultatPartie(int indicFinPartie);

void initialiserLesElementsDuJeu(char symboleJ1, char symboleJ2,
                                 unsigned short int tour, int indicFinPartie);

int main(void) {
        afficherGrille(grilleTest);
        return 0;
}

void evaluerSiJoueurGagnant(Grille &morpion, char symboleJ, int indicFinPartie)
{
        // Initaliser
        short int ligne; // Variables pour parcourir les lignes
        unsigned short int nbSymbRequis = 3; // Variables pour connaître le nombre de symbole requis

        
        if(detecterAlignementHorizontale(morpion, nbSymbRequis, symboleJ)||
                        detecterAlignementVerticale(morpion, nbSymbRequis, symboleJ)
                        ||detecterAlignementDiogoPrinc(morpion, nbSymbRequis, symboleJ)||
                        detecterAlignementDiogoSec(morpion, nbSymbRequis, symboleJ)) // Vérifier alignement horizontal, vertical et diagonal
        {
                if(symboleJ == 'X') // Condition avec le symbole du joueur 1
                {        
                        indicFinPartie = 1;
                }

                if(symboleJ == 'O') // Condition avec le symbole du joueur 2
                {
                        indicFinPartie = 2;
                }       
        }
}

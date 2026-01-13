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

void joueur1joue(Grille &morpion, char symboleJ1, int indicFinPartie);

void joueur2joue(Grille &morpion, char symboleJ2, int indicFinPartie);

void evaluerSiJoueur1gagnant(Grille &morpion, char symboleJ1,
                             int indicFinPartie);

void evaluerSiJoueur2gagnant(Grille &morpion, char symboleJ2,
                             int indicFinPartie);

void afficherResultatPartie(int indicFinPartie);

int main(void) {
        // Variables
        Grille morpion;
        char symboleJ1;           // Caractère représentant le joueur 1
        char symboleJ2;           // Caractère représentant le joueur 2
        unsigned short int tour;  // Numéro du tour courant
        int indicFinPartie;  // Indice donnant l'identité du vainqueur de la
                             // partie

        // Création grille
        initGrille(morpion, 3, '-', true, '-', false, '?');

        // Initialiser éléments du jeu
        symboleJ1 = 'X';
        symboleJ2 = 'O';
        tour = 0;
        indicFinPartie = -1;

        // Afficher grille
        afficherGrille(morpion);

        // Jouer
        while (true) {
                // Gestion tours
                tour++;
                cout << "On est au tour : " << tour << endl;

                // Joueur 1 joue
                joueurJoue(morpion, symboleJ1, indicFinPartie, tour);

                // Verif fin de partie
                if (indicFinPartie == 1) {
                        break;
                }
                if (isGrillePleine(morpion)) {
                        indicFinPartie = 0;
                        break;
                }

                // Joueur 2 joue
                joueurJoue(morpion, symboleJ2, indicFinPartie, tour);

                // Verif fin de partie
                if (indicFinPartie == 2) {
                        break;
                }
        }

        // Afficher résultat partie
        switch (indicFinPartie) {
        case 0:
                cout << "Egaltite !" << endl;
                break;
        case 1:
                cout << "Bravo, " << symboleJ1 << "a gagne !" << endl;
                break;
        case 2:
                cout << "Bravo, " << symboleJ2 << "a gagne !" << endl;
                break;
        default:
                cout << "Erreur, fin de partie" << endl;
        }

        return 0;
}

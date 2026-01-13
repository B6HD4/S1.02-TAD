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

void joueurJoue(Grille &morpion, char symboleJ, int indicFinPartie, unsigned short int tour);
/* BUT : Demande au joueur courant les coordonnées souhaitées, vérifie l'éligibilité de ces coordonnées, et appelle evaluerSiJoueurGagnant*/

void evaluerSiJoueurGagnant(Grille &morpion, char symboleJ,
                            int indicFinPartie);
/* BUT : Retourne l'indice du joueur gagnant ou zéro si la grille est pleine sans gagnant*/

int main(void)
{
    // Variables
    Grille morpion;
    char symboleJ1;          // Caractère représentant le joueur 1
    char symboleJ2;          // Caractère représentant le joueur 2
    unsigned short int tour; // Numéro du tour courant
    int indicFinPartie;      // Indice donnant l'identité du vainqueur de la
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
    while (true)
    {
        // Gestion tours
        tour++;
        cout << "On est au tour : " << tour << endl;

        // Joueur 1 joue
        joueurJoue(morpion, symboleJ1, indicFinPartie, tour);

        // Verif fin de partie
        if (indicFinPartie == 1)
        {
            break;
        }
        if (isGrillePleine(morpion))
        {
            indicFinPartie = 0;
            break;
        }

        // Joueur 2 joue
        joueurJoue(morpion, symboleJ2, indicFinPartie, tour);

        // Afficher résultat partie
        cout << "------ FIN DE PARTIE ------" << endl;
        switch (indicFinPartie) {
        case 0:
                cout << "Egalite ! Grille pleine." << endl;
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
    }
}

void joueurJoue(Grille &morpion, char symboleJ, int indicFinPartie,
                unsigned short int tour) {
        // déclaration
        short int ligneJ;
        short int colonneJ;
        bool valide;
        const int SEUIL_D_EVALUATION = 3;

        // saisie verif
        do {
                cout << "Saisir la ligne : ";
                cin >> ligneJ;
                cout << "Saisir la colonne : ";
                cin >> colonneJ;

                if (isCoordoneesValide(morpion, ligneJ, colonneJ) &&
                    isCaseVide(morpion, ligneJ, colonneJ)) {
                        valide = true;
                } else {
                        valide = false;
                }
        } while (valide == false);

        // placer symbole du joueur sur la grille
        setCaseSymbole(morpion, symboleJ, ligneJ, colonneJ);

        // afficher grille
        afficherGrille(morpion);

        // finJeu
        if (tour >= SEUIL_D_EVALUATION) {
                evaluerSiJoueurGagnant(morpion, symboleJ, indicFinPartie);
        }
}

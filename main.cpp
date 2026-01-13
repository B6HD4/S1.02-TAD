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

void jouerUnTour(Grille &morpion, char symboleJ1, char symboleJ2,
                 unsigned short int tour, int indiceFinDePartie);

void joueur1joue(Grille &morpion, char symboleJ1, int indiceFinDePartie);

void joueur2joue(Grille &morpion, char symboleJ2, int indiceFinDePartie);

void evaluerSiJoueur1gagnant(Grille &morpion, char symboleJ1,
                             int indiceFinDePartie);

void evaluerSiJoueur2gagnant(Grille &morpion, char symboleJ2,
                             int indiceFinDePartie);

int main(void) {
        afficherGrille(grilleTest);
        return 0;
}

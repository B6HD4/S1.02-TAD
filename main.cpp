#include "grille.h"

int main(void) {
        Grille grilleTest = {
            {{{'1', true}, {'2', true}}, {{'3', true}, {'4', true}}},
            2,
            ' ',
            '?'};
        afficherGrille(grilleTest);
        return 0;
}

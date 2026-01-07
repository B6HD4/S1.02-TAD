#include"grille.h"

void afficherLigne(const Grille& grille, unsigned int ligne);


int main(void)
{
    Grille grilleTest = {2,
        {
            {{'1', true}, {'2', true}},
            {{'3', true}, {'4', true}}
        },
        ' ',
        '?'
    };
    return 0;
}

/*
 * @brief Corps des primitives de Grille
 * @name grille.cpp
 * @authors Bixente Hiriart--Dicharry <bhdicharry@iutbayonne.univ-pau.fr>
 *          Thibaut Fontaine <tfontaine006@iutbayonne.univ-pau.fr>
 *          Cédric Rouillé <crouille@iutbayonne.univ-pau.fr>
 * @date mar. 16 déc. 2025 16:42:40
 * @remarks
 */

int main(void)
{
    return 0;
}

 /********************************************************************
*************************OBSERVATEUR**********************************
 *********************************************************************/

bool isCoordoneesValide(const Grille &grille, unsigned short int ligne, unsigned short int colonne)
{
    if((getTailleGrille(grille) >= ligne && ligne > 0) && (getTailleGrille(grille) >= colonne && colonne > 0))
    {
        return True;
    }
    return False;
}
/* BUT : Indique si le couple (ligne, colonne) désigne (ou pas)
une case appartenant à la grille
Précondition : -Grille : la grille de référence (aucune préconditions)
-Ligne : numéro de ligne, peut être quelconque, même négatifs
-Colonne : numéro de colonne, peut être quelconque, même négatifs
Postcondition : True si les coordonnées désignent une case valide de la grille
False sinon
*/

bool isCaseVide(const Grille &grille, unsigned short int ligne, unsigned short int colonne)
{
    if((getSymboleCase(grille, ligne, colonne) == getSymboleCaseVide(grille)) && isCoordoneesValide(grille, ligne, colonne))
    {
        return True;
    }
    return False;
}
/*But : Indique si la case est vide
Précondition : -Grille : la grille de référence (aucune préconditions)
-Ligne : numéro de ligne de la case désignée
Préconditions : La ligne est est valide ( 1 <= ligne <= taille de la grille)
-Colonne : numéro de colonne de la case désignée
Préconditions : La colonne est valide ( 1 <= colonne <= taille de la grille)
Postcondition : True si la case est vide
False sinon
*/

bool isCaseCachee(const Grille &grille, unsigned short int ligne, unsigned short int colonne)
{
    if((getSymboleCase(grille, ligne, colonne) == getSymboleCaseCachee(grille)) && isCoordoneesValide(grille, ligne, colonne))
    {
        return True;
    }
    return False;
}
/*But : Indique si la case est cachée
Précondition : -Grille : la grille de référence (aucune préconditions)
-Ligne : numéro de ligne de la case désignée
Préconditions : La ligne est est valide ( 1 <= ligne <= taille de la grille)
-Colonne : numéro de colonne de la case désignée
Préconditions : La colonne est valide ( 1 <= colonne <= taille de la grille)
Postcondition : True si la case est cachée
False sinon
*/

bool isGrilleVide(const Grille &grille)
{
    for (int i = 0; i > getTailleGrille(grille); i++)
    {
        for(int j = 0; j > getTailleGrille(grille); j++)
        {
            if(!(getSymboleCase(grille, ligne, colonne) == getSymboleCaseVide(grille)) && isCoordoneesValide(grille, ligne, colonne))
            {
                return False;
            }
        }
    }
    return True;
}
/*But : Inidique si la grille est vide
Préconditions : Grille : la grille de références (aucune préconditions)
Postcondition : True si la grille est vide 
False sinon
*/
bool isGrilleVisible(const Grille &grille)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = True;
    }
    return 0;
}
/*But : Indique si toute les cases de la grille sont visible
Préconditions : Grille : la grille de références (aucune préconditions)
Postcondition : True si toutes les cases de la grille sont visibles
False sinon
*/

bool isGrillePleine(Grille &grille)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = True;
    }
    return 0;
}
/*But : Indique si aucune case de la grille "grille" est vide
Préconditions : Grille : la grille de références (aucune préconditions)
Postcondition : True si la grille est pleine
False sinon
*/

bool isAlignementHoriz(Grille &grille, const unsigned short int ligne, const unsigned short int nbSymbole)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = True;
    }
    return 0;
}
/*But : Indique s'il y a un certain nombre d’un symbole passé en 
paramètre en continu sur une ligne
Préconditions : Grille : la grille de références (aucune préconditions)
-Ligne : numéro de ligne vérifier
Préconditions : ne dépasse pas la taille de la grille
-Nombre de symbole d'affilée attendus
Préconditions : 0 < nombre <= taille
Postcondition : True si un alignement est trouvé
False sinon
*/

bool isAlignementVerti(Grille &grille, const unsigned short int colonne, const unsigned short int nbSymbole)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = True;
    }
    return 0;
}
/*But : Indique s'il y a un certain nombre d’un symbole passé
en paramètre en continu sur une colonne
Préconditions : Grille : la grille de références (aucune préconditions)
-Colonne : numéro de colonne vérifier
Préconditions : ne dépasse pas la taille de la grille
-Nombre de symbole d'affilée attendus
Préconditions : 0 < nombre <= taille
Postcondition : True si un alignement est trouvé
False sinon
*/

bool isAlignementDiago(Grille &grille, const unsigned short int nbSymbole)
{
    if((ligne > 0) && (colonne > 0))
    {
        grille = True;
    }
    return 0;
}
/*But : Vérifie s'il y a un nombre de symbole en continue sur une diagonale
Préconditions : Grille : la grille de références (aucune préconditions)
-Nombre de symbole d'affilée attendus
Préconditions : 0 < nombre <= taille
Postcondition : True si un alignement est trouvé
False sinon
*/
#include <iostream>
#include <array>
void modeDeuxJoueurs() {}
void modeIA() {}

void Initialisation(std::array<char , 9 > &grille )
{
    grille.fill(' ');
}
void AfficheGrille(const char std::array<char , 9 > &grille)
{
    for( int i = 0; i < 9; i++)
    {

    }
}
int main()
{
    int choix;
    do{
        std::cout << "=====================\n";
        std::cout << "   Jeu de Morpion    \n";
        std::cout << "=====================\n";
        std::cout << "1. Jouer a 2 joueurs\n";
        std::cout << "2. Jouer contre l'IA\n";
        std::cout << "3. Quitter\n";
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;
        switch (choix)
        {
        case 1:
        modeDeuxJoueurs();
        break;
        case 2:
        modeIA();
        break;
        case 3:
        std::cout <<"Au revoir !"<<std::endl;
        break;

        default:
        std::cout <<"Erreur ! Reessayer" <<std::endl;
        break;
        }
    }
    while(choix !=3);
    return 0;
}
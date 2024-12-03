#include <iostream>
#include <array>

void Initialisation(std::array<char , 9 > &grille )
{
    grille.fill(' ');
}
void AfficheGrille(const std::array<char , 9 > &grille)
{
    for( int i = 0; i < 9; i++)
    {
        std::cout << grille[i];
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
            if (i < 6) std::cout << "---------\n";
        } else {
            std::cout << " | ";
        }
    }
    std::cout << "\n";
}

void modeDeuxJoueurs() {
    std::array<char , 9 > grille;
    Initialisation(grille);
    std::cout << "Debut de la partie 2 joueurs !" << std::endl;
    AfficheGrille(grille);
}
void modeIA() {
    std::array<char , 9 > grille;
    Initialisation(grille);
    std::cout << "Debut de la partie contre l'IA !" << std::endl;
    AfficheGrille(grille);
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
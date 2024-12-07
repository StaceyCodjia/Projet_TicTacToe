#include <iostream>
#include <array>
#include "Player.hpp"

void Initialisation(std::array<char , 9 > &grille )
{
    for (size_t i = 0; i < grille.size(); ++i) {
        grille[i] = '1' + i;
    }
}
void AfficheGrille(const std::array<char , 9 > &grille)
{
    for (size_t i = 0; i < grille.size(); i++) {
        std::cout << "| " << grille[i] << " ";
        if ((i + 1) % 3 == 0) { 
            std::cout << "|\n";
            if (i < 6) std::cout << "-------------\n"; 
        }
    }
    std::cout << "\n";
}

void modeDeuxJoueurs() {

    std::array<char , 9 > grille;
    Initialisation(grille);
    std::cout << "Debut de la partie 2 joueurs !" << std::endl;
    Player J1 = creeJoueur();
    Player J2 = creeJoueur(J1.symbol);
    J1.afficheInfo();
    J2.afficheInfo();
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
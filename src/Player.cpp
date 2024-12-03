#include <iostream>
#include "Player.hpp"

void Player::afficheInfo()
{
    std::cout << "Joueur : " << nom << "avec le symbole " << symbol << std::endl;
}

Player creeJoueur()
{
    std::string nom;
    char symbol;

    std::cout << "Entrer le nom du joueur 1 : " << std::endl;
    std::cin >> nom;
}

do
{
   std::cout << "Entrez le symbole du joueur (X ou O) : ";
        std::cin >> symbole;
        if (symbole != 'X' && symbole != 'O') {
            std::cout << "Symbole invalide. Veuillez entrer X ou O.\n";
        }
} while (symbole != 'X' && symbole != 'O');

    // return Player(nom, symbole);
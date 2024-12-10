#include <iostream>
#include "Player.hpp"

void Player::afficheInfo()
{
    std::cout << "Joueur : " << nom << " avec le symbole " << symbol << std::endl;
}

Player creeJoueur(char memeSymbol)
{
    std::string nom;
    char symbol;

    std::cout << "Entrer le nom du joueur  : " << std::endl;
    std::cin >> nom;

    do {
   std::cout << "Entrez le symbole du joueur (X ou O) : ";
        std::cin >> symbol;
        if (symbol != 'X' && symbol != 'O') {
            std::cout << "Symbole invalide. Veuillez entrer X ou O.\n";
        }
        else if (symbol == memeSymbol)
        {
           std::cout << "Symbole deja pris ! Choisir un autre !" << std::endl;
        }
        
} while (symbol != 'X' && symbol != 'O' || symbol == memeSymbol);
 
 return Player(nom, symbol);
}


#include <string>
#include <iostream>

struct Player
{
    std::string nom;
    char symbol;

    Player (const std::string& n = "", char s = ' ') : nom(n), symbol(s){}

    void afficheInfo();
};
Player creeJoueur(char memeSymbol = '\n');

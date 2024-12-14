#include <iostream>
#include <array>
#include <vector>
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

char victoire(const std::array<char , 9 > &grille)
{
    const std::array<std::array<int, 3 > , 8 > combi ={
        {
            {{0,1,2}},
            {{3,4,5}},
            {{6,7,8}},
            {{0,3,6}},
            {{1,4,7}},
            {{2,5,8}},
            {{0,4,8}},
            {{2,4,6}},
        }
    };
    for(const auto& combi:combi){
        if(grille[combi[0]] == grille[combi[1]] && grille[combi[1]] == grille[combi[2]] && (grille[combi[0]] == 'X' || grille[combi[0]] == 'O') )
        {
            return grille[combi[0]];
        }
    }
    return '\0';
}

void jouer(const Player& joueur, std::array<char, 9> &grille)
{
    int choix;
    bool coupValide = false;

    std::cout << joueur.nom << " c'est a vous de jouer" << std::endl;

    while(!coupValide)
    {
        std::cout << "Entrez le numero de votre case : ";
        std::cin >> choix;

        if(choix < 1 || choix > 9)
        {
        std::cout << "Numero de case invalide. Reessayer." << std::endl;
        }
        else if (grille[choix - 1] == 'X' || grille[choix - 1] == 'O')
        {
            std::cout << "Cette case est deja remplie. Reessayer" << std::endl;
        }
        else
        {
            grille[choix - 1] = joueur.symbol;
            coupValide = true;
        }
    }
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

    int tours = 0;
    while(tours < 9)
    {
        if(tours % 2 == 0)
        {
            jouer(J1,grille);
        }
        else
        {
            jouer(J2, grille);
        }
        AfficheGrille(grille);

        char gagnant = victoire(grille);
        if(gagnant != '\0')
        {
            std::cout << "Felicitations ! Le joueur " <<(gagnant == J1.symbol ? J1.nom : J2.nom)<< " a gagne !" << std::endl;
            return;
        }
        tours++;
    }
    std::cout << "Match nul ! Aucun gagnant"<<std::endl;
}

int jouerIA(const std::array<char, 9>& grille) {
    std::vector<int> casesLibres;

    for (int i = 0; i < 9; ++i) {
        if (grille[i] != 'X' && grille[i] != 'O') {
            casesLibres.push_back(i);
        }
    }

    if (!casesLibres.empty()) {
        int indexChoisi = rand() % casesLibres.size();
        return casesLibres[indexChoisi];
    }

    return -1; 
}

void modeIA() {
    std::array<char , 9 > grille;
    Initialisation(grille);
    std::cout << "Debut de la partie contre l'IA !" << std::endl;
    Player joueur1, ordinateur;

    joueur1.nom = "Joueur 1";
    joueur1.symbol = 'X';
    ordinateur.nom = "Ordinateur";
    ordinateur.symbol = 'O';

    AfficheGrille(grille);
   char resultat = '\0';
    int tour = 0;

    while (resultat == '\0') {
        Player& joueurActuel = (tour % 2 == 0) ? joueur1 : ordinateur;

        if (joueurActuel.nom == "Ordinateur") {
            
            int position = jouerIA(grille); 
            if (position != -1) {
                grille[position] = joueurActuel.symbol;
                std::cout << "L'ordinateur joue en position " << position + 1 << "\n";
            }
        } else 
        {
            jouer(joueurActuel, grille);
        }

        AfficheGrille(grille);
        resultat = victoire(grille);
        tour++;
    }
    if (resultat == 'X') {
        std::cout << "Felicitations, vous avez gagne !\n";
    } else if (resultat == 'O') {
        std::cout << "L'ordinateur a gagné !\n";
    } else if (resultat == 'D') {
        std::cout << "Match nul !\n";
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
        std::cout <<"Merci d'avoir jouer !"<<std::endl;
        break;

        default:
        std::cout <<"Erreur ! Reessayer" <<std::endl;
        break;
        }
    }
    while(choix !=3);
    return 0;
}
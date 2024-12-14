# Projet_TicTacToe
## Indications d'exécution
Le projet n'utilise pas de librairies particulières et a été testé sous Windows uniquement.
## Organisation du code
Le projet est structuré en un fichier main et des fichiers "Player.cpp" et "Player.hpp".
J'ai crée différentes fonctions pour le plateau, entrer les informations des joueurs, implémenter la logique du jeu et les différents modes. 
## Choix d'implémentations 
- Utilisation d'un tableau de caractères  <std::array> : Pour faciliter le parcours des boucles.
- Imposition des symboles des joueurs : C'était plus facile de gérer les cas de victoire et pour vérifier si les joueurs prenaient les même symboles.
- IA simple : N'étant pas forcément très douée en programmation, j'ai préféré partir sur la piste d'une IA qui choisi une case aléatoirement. C'était plus compréhensible pour moi. 
- Gestion des erreurs : J'ai fais en sorte de pouvoir vérifier que les joueurs n'utilisent pas les même symboles ou des symboles invalides. 
## Problèmes et Solutions 

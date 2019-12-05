/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>

// joueur.cpp
#ifndef JOUEUR
#define JOUEUR
#include "joueur.cpp"
#endif

// lots.cpp
#ifndef LOTS
#define LOTS
#include "lots.cpp"
#endif

// vitrail.cpp
#ifndef VITRAIL
#define VITRAIL
#include "vitrail.cpp"
#endif

int main()
{

    //get name for player 1
    std::string nom1;
    std::cout << "Entrer un nom pour joueur 1: ";
    std::cin >> nom1;

    //get name for player 2
    std::string nom2;
    std::cout << "Entrer un nom pour joueur 2: ";
    std::cin >> nom2;

    //board size
    int cols(7);
    int rows(5);

    //initialize player1
    Joueur joueur1(nom1, cols, rows);
    //initialize player2
    Joueur joueur2(nom2, cols, rows);

    //creer lots
    Lots lot = Lots();
    //initialiser lot
    lot.reset();

    //Processus princical du jeu
    int tour(0);                                //compte le nombre de tours
    Joueur joueurArray[2] = {joueur1, joueur2}; //array des deux joueurs
    Joueur *j;                                  //ptr de joueur
    j = &joueurArray[tour % 2];                 //ptr au joueur 1

    while (!(joueur1.getVitrail()->estCompleteFull() || joueur2.getVitrail()->estCompleteFull()))
    {

        while (!(lot.lotIsEmpty() && lot.surplusIsEmpty())) //Jusqu'a ce que les lots et le surplus soient vides
        {
            std::cout << "Le tour de " << j->getNom() << std::endl;
            std::cout << "Voici ton tableau " << std::endl;
            std::cout << *j << std::endl;

            //print lot
            std::cout << "Voici les lots" << std::endl;
            std::cout << lot;

            //choix au joueur
            int choixAction(0); //choisis quelle action que le joueur va prendre
            std::cout << "Quelle action voulez vous éffectuer?" << std::endl;
            std::cout << "1- Choisir un lot et placer \n2- Changer le vitrer de position\n>";
            std::cin >> choixAction;
            std::cout << '\n';
            while (!(choixAction == 1 || choixAction == 2)) //mauvaise selection
            {
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cout << "Un choix valide SVP" << std::endl;
                std::cout << "Quelle action voulez vous éffectuer?" << std::endl;
                std::cout << "1- Choisir un lot et placer \n2- Changer le vitrer de position\n>";
                std::cin >> choixAction;
                std::cout << '\n';
            }

            if (choixAction == 1) //choisit lot ou surplus
            {
                int choixColLot;
                //ask what col of lot or surplus user wants to take
                std::cout << "Quelle colonne du lot voulez vous choisir?" << std::endl;
                std::cout << "Choisissez une colone entre 0 et 4 ou entrez -1 pour choisir dans le surplus\n>";
                std::cin >> choixColLot;
                std::cout << '\n';

                //verify choice is good
                while ( !(choixColLot == -1 || choixColLot == 0 || choixColLot == 1 || choixColLot == 2 || choixColLot == 3 || choixColLot == 4) || (lot.colIsEmpty(choixColLot))) //mauvaise selection
                {
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Un choix valide SVP" << std::endl;
                    std::cout << "Quelle colonne du lot voulez vous choisir?" << std::endl;
                    std::cout << "Choisissez une colone entre 0 et 4 ou entrez -1 pour choisir dans le surplus\n>";
                    std::cin >> choixColLot;
                    std::cout << '\n';
                }
                //cant get it to work if use inputs a char so i gotta do this
                std::cin.clear();
                std::cin.ignore(100, '\n');

                char choixCouleur;
                //ask what col of lot or surplus user wants to take
                std::cout << "Quelle couleur voulez vous choisir?" << std::endl;
                std::cout << "'G', 'J', 'B', 'R', où 'O' \n>";
                std::cin >> choixCouleur;
                std::cout << '\n';

                //verify choice is good
                choixCouleur = toupper(choixCouleur);
                while (!(choixCouleur == 'G' || choixCouleur == 'J' || choixCouleur == 'B' || choixCouleur == 'R' || choixCouleur == 'O')) //mauvaise selection
                {
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Un choix valide SVP" << std::endl;
                    std::cout << "Quelle couleur voulez vous choisir?" << std::endl;
                    std::cout << "'G', 'J', 'B', 'R', où 'O' \n>";
                    std::cin >> choixCouleur;
                    std::cout << '\n';
                    choixCouleur = toupper(choixCouleur);
                }
                std::cin.clear();
                std::cin.ignore(100, '\n');

                //choix de col du vitrail
                int choixColVitrail;
                //ask what col of vitrail to put on
                std::cout << "Sur quelle colonne voulez vous placer les vitres?" << std::endl;
                std::cout << "Choisissez une colone entre 0 et " << j->getPosition() << "\n>";
                std::cin >> choixColVitrail;
                std::cout << '\n';

                //verify choice is good
                while (!(choixColVitrail >= 0 && choixColVitrail <= j->getPosition())) //mauvaise selection
                {
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Un choix valide SVP" << std::endl;
                    std::cout << "Quelle colonne du lot voulez vous choisir?" << std::endl;
                    std::cout << "Choisissez une colone entre 0 et " << j->getPosition() << "\n>";
                    std::cin >> choixColVitrail;
                    std::cout << '\n';
                }

                //creer le vecteur de vitres ramassees et construire vitrail
                std::vector<char> vitres = lot.ramasseVitre(choixCouleur, choixColLot);
                bool done(false);
                while (!done)
                {
                    try
                    {
                        int vitresNonInst = j->getVitrail()->construireVitrail(vitres, choixColVitrail); //get vitres non installées
                        j->setPosition(choixColVitrail);                                                 //met position au vitrail
                        j->updatePoints(-vitresNonInst);
                        done = true;
                    }
                    catch (const std::invalid_argument& e)
                    {
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                        std::cout << "Colonne remplie" << std::endl;
                        std::cout << "Quelle colonne du lot voulez vous choisir?" << std::endl;
                        std::cout << "Choisissez une colone entre 0 et " << j->getPosition() << "\n>";
                        std::cin >> choixColVitrail;
                        std::cout << '\n';
                    }
                }

                if (j->getVitrail()->estComplete(choixColVitrail)) // colonne est complette
                {
                    j->updatePoints(3);
                }

                tour++;
                j = &joueurArray[tour % 2];
            }
            else if (choixAction == 2) //reset position
            {
                //change spots
                if (j->getPosition() == j->getVitrail()->getCols() - 1) //if totally left
                {
                    std::cout << "Déja a gauche" << std::endl;
                }
                else //change spots
                {
                    ~(*j);
                    tour++;
                    j = &joueurArray[tour % 2];
                }
            }
            else //Should never be here bekyaa of check but ya never know
            {
                return -1;
            }
            std::cout << '\n'
                      << std::endl;
            std::cout << "-------------------------" << std::endl;
            std::cout << '\n'
                      << std::endl;
        }

        std::cout << '\n'
                  << std::endl;
        std::cout << "Nouveau lots" << std::endl;
        lot.reset();
    }
    std::cout << '\n'
              << std::endl;
    std::cout << "Partie terminée." << std::endl;
    std::cout << joueur1.getNom() << " a " << joueur1.getPoints() << " points." << std::endl;
    std::cout << joueur2.getNom() << " a " << joueur2.getPoints() << " points." << std::endl;

    return 0;
}

//Luc-Cyril Bonnet
//8234136
//CSI 2772 - Devoir 1

#include <iostream>
#include <fstream>
#include <vector>

int main(){

    //Int qui correspond aà la longueur des  noms
    int input(0);
    while (input <=0 || !std::cin)
    {
        std::cout << "Entrez un entier (non negatif) qui correspond à la longeure de lettre: ";
        std::cin >> input;

        if (!std::cin)
        {
            std::cout << "Un entier valide svp"<<std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        else if (input < 0)
        {
            std::cout << "Un nombre positif svp"<<std::endl;
        }
    }
    
    //ifstream qui permet de lire le fichier text
    std::ifstream inFile;
    inFile.open("prenoms.txt");
    if (!inFile){
        std::cerr << "Erreur de fichier";
        exit(1);
    }
        

    //code qui cherche les noms
    std::vector<std::string> lstPrenom;
    std::string prenom;
    while (inFile >> prenom)
    {
        if (prenom.length() == input)
        {
            lstPrenom.push_back(prenom);
        }
    }
    inFile.close();

    if (lstPrenom.size() == 0)
    {
        std::cout << "Il n'y aucun prénom(s) de taille " << input << std::endl;
    }
    else{
        std::cout<<"Il y a "<<lstPrenom.size()<<" prénom(s) de taille "<<input<<std::endl;
        std::cout<<"Ils sont dans le fichier 'output.txt'"<<std::endl;

        std::ofstream outfile ("output.txt");
        for (int i = 0; i < lstPrenom.size(); i++)
        {
            outfile << lstPrenom[i]<<std::endl;
        }
    outfile.close();


    }



    return 0;
}
#include <fstream>
#include "achat.h"

int PanierDAchat::getCapacity()
{
    return capacity;
}

bool PanierDAchat::ajouteItem(const Item &toAdd)
{
    if (capacity == items)
    {
        std::cout<<"Liste pleine"<<std::endl;
        return false;
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            if(liste[i].description == "") // ajoute a la premiere case vide
            {
                liste[i] = toAdd;
                items++;
                break;
            }
 
        }
        return true;
    }
}

bool PanierDAchat::enleverItem(std::string desc)
{
    if (items == 0)
    {
       std::cout<<"Il n'y a pas d'éléments"<<std::endl;
       return false;
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            if (liste[i].description == desc)
            {
                Item temp;
                liste[i] = temp;
                items--;
                return true;
            } 
        }

        std::cout<<"L'éleément n'a pas été trouvé"<<std::endl;
        return false;
    }
}


void PanierDAchat::afficherFacture()
{
    std::ofstream outfile("test.txt");

    outfile << "-----Facture-----" << std::endl;
    outfile << std::endl;
    for (int i = 0; i < capacity; i++)
    {
        if (liste[i].description != "")
        {
            outfile << liste[i].description << "--- " << liste[i].prix << "$" <<std::endl;
        }
    }
    outfile << std::endl;
    outfile << "TOTAL: " << calculateTotal() << "$" << std::endl;
}

float PanierDAchat::calculateTotal()
{
    float total = 0;

    for (int i = 0; i < capacity; i++)
    {
        total = total + liste[i].prix;
    }
    return total;
    
}

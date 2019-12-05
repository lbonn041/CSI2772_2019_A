#include <iostream>
#include <string>

class Item
{
public:
    std::string description;
    float prix;

    Item(std::string nom, float price){
        description = nom;
        prix = price;
    }

    Item(){
        description = "";
        prix = 0.0;
    }
};

class PanierDAchat
{
    private:
        int capacity;
        Item (*liste);
        int items;

    public:

        PanierDAchat(const PanierDAchat &obj)
        { //constructeur copieur
            std::cout << "Copy Constructor" << std::endl;
            capacity = obj.capacity;
            liste = obj.liste;
            items = obj.items;
        }


        PanierDAchat()
        { //constructeur par default
            std::cout << "Default constructor" << std::endl;
            capacity = 0;
            liste = new Item[capacity];
            items = 0;
        }


        PanierDAchat(int c)
        {//constructeur avec parametre
            std::cout << "Param constructor" << std::endl;
            capacity = c;
            liste = new Item[c];
            items = 0;
        }
        ~PanierDAchat()
        {//destructeur
            std::cout << "Destructeur" << std::endl;
            delete[] liste;
        }

        int getCapacity();
        bool ajouteItem(const Item &toAdd);
        bool enleverItem(std::string desc);
        void afficherFacture();
        float calculateTotal();
};

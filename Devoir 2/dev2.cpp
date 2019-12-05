#include <iostream>
#include <array>
#include "achat.cpp"


int main(){

    Item pomme("Pomme", 0.99);
    Item orange("Orange", 1.99);
    Item jus("Jus", 4.00);
    Item pain("pain", 2.49);

    PanierDAchat test(4);
    test.ajouteItem(pomme);
    test.ajouteItem(orange);
    test.ajouteItem(jus);
    test.enleverItem("Jus");
    test.ajouteItem(pain);
    test.afficherFacture();

    return 0;
}
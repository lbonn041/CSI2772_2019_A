/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>

//joueur.h
#ifndef VITRAIL
#define VITRAIL
#include "vitrail.cpp"
#endif

class Joueur
{
private:
    std::string nom;
    int points;
    int position;
    Vitrail *ptr_vitrail;

public:
    Joueur(std::string nom_j) : nom(nom_j), points(0), ptr_vitrail(new Vitrail())
    {
        this->position = ptr_vitrail->getCols() - 1;
    }

    Joueur(std::string nom_j, int n_cols, int n_vitres) : nom(nom_j), points(0), ptr_vitrail(new Vitrail(n_cols, n_vitres))
    {
        this->position = ptr_vitrail->getCols() - 1;
    }
    std::string getNom() { return nom; }
    int getPosition() { return position; }
    void setPosition(int x) { position = x; }
    Vitrail *getVitrail() { return ptr_vitrail; }
    int getPoints() { return points; }
    void updatePoints(int x){ points += x;}
};
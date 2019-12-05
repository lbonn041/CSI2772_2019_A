/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>
#include "joueur.h"

Joueur &operator--(Joueur &j)
{
    if (j.getPosition() == 0)
    {
        throw std::out_of_range("Déplacement invalide");
    }
    else
    {
        j.setPosition(j.getPosition() - 1);
        return j;
    }
}

Joueur &operator-=(int x, Joueur &j)
{
    if ((j.getVitrail()->getCols() - x) < 0)
    {
        throw std::out_of_range("Déplacement invalide");
    }
    else
    {
        j.setPosition(j.getVitrail()->getCols() - x);
        return j;
    }
} 
Joueur &operator~(Joueur &j)
{
    j.setPosition(j.getVitrail()->getCols() - 1);
    return j;
}
        
inline std::ostream &operator<<(std::ostream &os, Joueur &j)
{
    os << "Joueur " << j.getNom() << " : " << j.getPoints() << " points" << '\n'
       << '\n'
       << "Vitrer à la position " << j.getPosition() << '.' << '\n'
       << '\n'
       << *j.getVitrail()
       << std::endl;
    return os;
}

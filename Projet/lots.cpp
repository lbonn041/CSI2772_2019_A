/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>
#include <cstdlib>
#include "lots.h"

std::vector<char> Lots::ramasseVitre(char couleur, int numeroLot)
{
    std::vector<char> vitres;

    if (numeroLot < 0)
    {
        std::vector<char>::iterator it = surplus.begin();
        while (it != surplus.end())
        {
            if (*it == couleur)
            {
                vitres.push_back(*it);
                it = surplus.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    else
    {
        for (int i = 0; i < n_rows; i++)
        {
            if (lots_vitres[numeroLot][i] == couleur) //4-(numeroLot*2) gives the backwards row
            {
                //Mettre dans vitres a retourner et marquer .
                vitres.push_back(lots_vitres[numeroLot][i]);
                lots_vitres[numeroLot][i] = '.';
            }
            else
            {
                //Mettre dans le surplus et marquer .
                surplus.push_back(lots_vitres[numeroLot][i]);
                lots_vitres[numeroLot][i] = '.';
            }
        }
    }
    return vitres;
}

void Lots::reset()
{
    srand(time(NULL));
    for (int i = 0; i < this->n_cols; i++)
    {
        for (int j = 0; j < this->n_rows; j++)
        {
            int color = rand() % 5;
            this->lots_vitres[i][j] = intToChar(color);
        }
    }
}

inline std::ostream &operator<<(std::ostream &os, Lots &l)
{
    std::string result = l.toStringTableau();
    std::string surplus = l.toStringSurplus();

    os << "Lots : \n"
       << result
       << '\n'
       << "Surplus: "
       << surplus
       << '\n'
       << std::endl;
    return os;
}

std::string Lots::toStringTableau()
{
    std::string result;
    for (int i = 0; i < this->getRows(); i++)
    {
        for (int j = this->getCols() - 1; j >= 0; --j)
        {
            result += this->getLots()[j][i];
            result += ' ';
        }
        result += '\n';
    }
    //numeros sous tableau
    for (int i = this->getCols() - 1; i >= 0; --i)
    {
        result += std::to_string(i);
        result += ' ';
    }
    return result;
}

std::string Lots::toStringSurplus()
{
    std::string result;
    result += '[';
    for (std::vector<char>::iterator it = surplus.begin(); it != surplus.end(); ++it)
    {
        result += *it;
    }
    result += ']';
    return result;
    
}

bool Lots::colIsEmpty(int col)
{
    if (col == -1)
    {
        return false;
    }
    
    else if (lots_vitres[col][0] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Lots::lotIsEmpty(){
    bool empty(true);
    for (int i = 0; i < n_cols; i++)
    {
        if ( !(this->colIsEmpty(i)) )
        {

            return false;
        } 
    }
    return true;
}

bool Lots::surplusIsEmpty()
{
    if (surplus.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
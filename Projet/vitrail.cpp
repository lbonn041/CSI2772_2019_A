/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>
#include <vector>
// vitrail.h
#include "vitrail.h"



//TODO - construireVitrail non complet
int Vitrail::construireVitrail(std::vector<char> vitres, int colonne)
{
    if (this->estComplete(colonne))
    {
        throw std::invalid_argument("Colonne remplie.");
    }
    else
    {
        
        int installed(0);
        for (int i = 0; i < vitresParColone; i++)
        {
            std::vector<char>::iterator it = vitres.begin();
            while (it != vitres.end()) //go through vector while its not empty
            {
                if (*it == desc[colonne][i])
                {
                    desc[colonne][i] = 'x'; //change to x
                    vitres.erase(it);       // remove vitre added
                    installed++;
                }
                else
                {
                    it++;
                }
            }
        }
        


        return vitres.size() - installed;
    }
}

bool Vitrail::estComplete(int colonne)
{
    for (int i = 0; i < this->vitresParColone; i++) //loop through rows
    {
        if (this->desc[colonne][i] != 'x')//part of column that isn't complete
        {
            return false;
        }
    }
    return true;
}

bool Vitrail::estEnConstruction(int colonne)
{
    for (int i = 0; i < this->vitresParColone -1; i++)//loop through rows
    {
        if (this->desc[colonne][i] == 'x')
        {
            return true;
        }
    }
    return false;
}

bool Vitrail::estCompleteFull(){
    for (int i = 0; i < cols; i++)//loop trough cols
    {
        if (estComplete(i) == false)
        {
            return false;
        }
        
    }
    return true;
    
}

inline std::ostream &operator<<(std::ostream &os, Vitrail &v)
{
    std::string result;
    for (int h = 0; h < v.getRows(); h++) // show in reverse order
    {
        for (int i = v.getCols() - 1; i >= 0; --i)
        {
            result += (v.getDesc())[i][h];
            result += ' ';
        }
        result += '\n';
    }

    for (int i = v.getCols() - 1; i >= 0; --i) //print numbers at bottom
    {
        result += std::to_string(i);
        result += ' ';
    }
    os << result
       << std::endl;
    return os;
}

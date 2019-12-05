/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>
#include <vector>

class Lots
{
private:
    char** lots_vitres;
    int n_cols;
    int n_rows;
    std::vector<char> surplus;

public:
    Lots();
    ~Lots();
    std::vector<char> ramasseVitre(char couleur, int numeroLot);
    void reset();
    std::string toStringTableau();
    std::string toStringSurplus();
    bool lotIsEmpty();
    bool surplusIsEmpty();
    bool colIsEmpty(int col);
    char **getLots() { return lots_vitres; }
    int getRows(){return n_rows;}
    int getCols() {return n_cols;}
    int getSizeCol(int x){if (x < 0){return surplus.size();}return n_rows;}
};

Lots::Lots()
{
    //initialize cols and rows
    n_cols = 5;
    n_rows = 4;

    //dynamic allocation
    lots_vitres = (char **)calloc(n_cols, sizeof(char *));
    for (int i = 0; i < n_cols; i++)
    {
        lots_vitres[i] = (char *)calloc(n_rows, sizeof(char));
    }
}

Lots::~Lots()
{
    for (int i = 0; i < 4; i++)
    {
        delete[] lots_vitres[i];
    }
    delete[] lots_vitres;
}

//redefinied, didnt want to call Vitrail::intToChar(color) cuz its ugly
char intToChar(int color)
{

    switch (color)
    {
    case 0:
        return 'G';
        break;
    case 1:
        return 'J';
        break;
    case 2:
        return 'B';
        break;
    case 3:
        return 'R';
        break;
    case 4:
        return 'O';
        break;
    }
    return 'x';
}
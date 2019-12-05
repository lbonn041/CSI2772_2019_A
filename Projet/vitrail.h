/*
Luc-Cyril Bonnet - 8234136
*/
#include <iostream>
#include <vector>
#include <cstdlib>

class Vitrail
{
private:
    int cols;
    int vitresParColone;
    char **desc;

public:
    Vitrail()
    {
        cols = 0;
        vitresParColone = 0;
    }
    Vitrail(int n_cols, int n_vitres)
    { //fingers crossed it works
        cols = n_cols;
        vitresParColone = n_vitres;

        //dynamic allocation
        srand(time(NULL));
        desc = (char **)calloc(cols, sizeof(char *));
        for (int i = 0; i < cols; i++)
        {
            int color1 = rand() % 5;
            int color2 = rand() % 5;
            int h = rand() % vitresParColone;
            desc[i] = (char *)calloc(vitresParColone, sizeof(char));

            for (int j = 0; j < h; j++)
            {
                desc[i][j] = intToChar(color1);
            }

            for (int k = h; k < vitresParColone; k++)
            {
                desc[i][k] = intToChar(color2);
            }
        }
    }

    int construireVitrail(std::vector<char> vitres, int colonne);
    bool estComplete(int colonne);
    bool estEnConstruction(int colonne);
    bool estCompleteFull();
    int getCols() { return cols; }
    int getRows() { return vitresParColone; }
    char **getDesc() { return desc; }
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
};

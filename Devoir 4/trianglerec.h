#include "triangle.h"

class TriangleRectangle : public Triangle 
{
    public:
        TriangleRectangle(double base, double cote) : Triangle(base, cote, sqrt((base * base) + (cote * cote)))
        {}

        double getAire() const
        {
            double area = (this->getBase() * this->getCote1())/2;
            return area;
        }

        double getHyp()
        {
            return this->getCote2();
        }
};
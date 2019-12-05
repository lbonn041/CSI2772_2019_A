#include <iostream>
#include "forme.h"
#include "triangle.h"
#include "trianglerec.h"

int main()
{
    TriangleRectangle *t = new TriangleRectangle(3.0, 5.0);
    std::cout<< t->getAire() <<std::endl;
    std::cout << t->getHyp() << std::endl;
    return 0;
}
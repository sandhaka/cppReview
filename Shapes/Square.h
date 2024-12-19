#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

namespace Shapes {
    class Square : Shape {
    public:
        Square(double side);
        double Area() override;
        double Perimeter() override;
    private:
        double side;
    };
}


#endif //SQUARE_H

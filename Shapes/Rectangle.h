#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

namespace Shapes {

    class Rectangle : public Shape {
    public:
        Rectangle(double width, double height);
        double Area() override;
        double Perimeter() override;
    private:
        double width;
        double height;
    };

}


#endif //RECTANGLE_H

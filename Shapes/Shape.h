#ifndef SHAPE_H
#define SHAPE_H

namespace Shapes {

class Shape {
    public:
    virtual ~Shape() = default;

    virtual double Area() = 0;
    virtual double Perimeter() = 0;
};

} // Shapes

#endif //SHAPE_H

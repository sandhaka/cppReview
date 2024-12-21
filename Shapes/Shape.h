#ifndef SHAPE_H
#define SHAPE_H

namespace Shapes {

    class Shape {
        public:
        virtual ~Shape() { }

        virtual double Area() { return 0; }
        virtual double Perimeter() { return 0; }
    };

} // Shapes

#endif //SHAPE_H

#include "Square.h"

Shapes::Square::Square(const double side) {
    this->side = side;
}

double Shapes::Square::Area() {
    return this->side * this->side;
}

double Shapes::Square::Perimeter() {
    return 4 * this->side;
}

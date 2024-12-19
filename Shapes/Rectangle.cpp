#include "Rectangle.h"

Shapes::Rectangle::Rectangle(const double width, const double height) {
    this->width = width;
    this->height = height;
}

double Shapes::Rectangle::Area() {
    return this->width * this->height;
}

double Shapes::Rectangle::Perimeter() {
    return 2 * (this->width + this->height);
}

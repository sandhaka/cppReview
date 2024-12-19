#include <iostream>

#include "Shapes/Rectangle.h"
#include "Shapes/Shape.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Square.h"

int main() {

    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "review !\n";

    /// Public inheritance:
    /// - Derived class is a type of base class (e.g., can use polymorphism).
    Shapes::Rectangle rectangle(10, 20);
    Shapes::Shape *shape = &rectangle; // OK

    /// Private inheritance:
    /// - Derived class is not a type of base class.
    Shapes::Square square(10);
    // Shapes::Shape *shape2 = &square; ERROR

    return 0;
}

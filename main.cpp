// ReSharper disable CppDFAUnusedValue
// ReSharper disable CppEntityAssignedButNoRead
// ReSharper disable CppDFAUnreadVariable
// ReSharper disable CppDeclaratorNeverUsed
#include <iostream>

#include "Birds/FlyingBird.h"
#include "Shapes/NotDerivedRectangle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Shape.h"
#include "Shapes/ShapesComposition.h"
#include "Shapes/Square.h"

int main() {

    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "review !\n";

    /// Public inheritance:
    /// - Derived class is a type of base class (e.g., can use polymorphism).
    Shapes::Rectangle rectangle(10, 20);
    Shapes::Shape *shape = &rectangle; // OK, more specialized to base type
    const Shapes::Rectangle* rectPtr = dynamic_cast<Shapes::Rectangle*>(shape); // Need cast to assign
    // N.B. dynamic_cast check if the shape is a rectangle instance type. static_cast doesn't.

    Shapes::NotDerivedRectangle notDerivedRectangle(10, 20);

    /// Private inheritance:
    /// - Derived class is not a type of base class.
    Shapes::Square square(10);
    // Shapes::Shape *shape2 = &square; ERROR

    // Sizes...
    std::cout << "double: " << sizeof(double) << "\n";
    std::cout << "Shape: " << sizeof(Shapes::Shape) << "\n";
    std::cout << "Rectangle: " << sizeof(Shapes::Rectangle) << "\n";
    std::cout << "Square: " << sizeof(Shapes::Square) << "\n"; // Shape hasn't data but must be non-zero object
    std::cout << "Composition: " << sizeof(Shapes::ShapesComposition) << "\n"; // Composition has data
    std::cout << "Not derived Rectangle: " << sizeof(Shapes::NotDerivedRectangle) << "\n"; // Not derived rectangle has data

    // N.B. Original type encoded in derived type need size!

    // Cannot instantiate an abstract class:
    // Birds::FlyingBird *bird = new Birds::FlyingBird(); // ERROR

    return 0;
}

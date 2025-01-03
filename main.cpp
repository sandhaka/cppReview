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
#include "Templates/ArrayOf2.h"
#include "Templates/Ratio.h"
#include "Templates/Swap12.h"

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

    /// Const expressions:
    /// - Are computed at compile-time
    constexpr int x = 5 * 2;
    int y = x; // y = 10

    // Cannot instantiate an abstract class:
    // Birds::FlyingBird *bird = new Birds::FlyingBird(); // ERROR

    /// Templates:
    Templates::ArrayOf2<int> array;
    array[0] = 1;
    array[1] = 2;
    std::cout << "Sum: " << array.sum() << "\n";

    // auto pair = Templates::swap12(9); // Run-time ERROR on time deduction
    auto successfulPair = Templates::swap12(std::make_pair(9, 10));

    auto ratio = Templates::Ratio(2.0, 2.0);
    const auto val = static_cast<double>(ratio);

    std::cout << "Value: " << val << "\n";

    return 0;
}

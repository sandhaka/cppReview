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
#include "Templates/Specialization/Ratio.h"
#include "Templates/Ratio.h"
#include "Templates/Swap12.h"

int main() {

    const auto lang = "C++";

    std::cout << "Hello and welcome to my personal notes of a " << lang << "review !\n";

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
    constexpr int x = 5 * 2; // It's never calculated again is a constant in the compiled code
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

    auto ratio = Templates::Ratio(5.0, 2.0); // <double> are deduced
    const auto val = static_cast<double>(ratio); // using the explicit operator

    std::cout << "Generic Value: " << val << "\n";

    // Templates specialization

    auto ratio_float = Templates_Specialization::Ratio(6.0f, 2.0f); // <float> are deduced (float is not a double
    const auto val_from_float = static_cast<double>(ratio_float); // using the explicit operator>

    std::cout << "Float Value: " << val_from_float << "\n";

    auto ratio_spec = Templates_Specialization::Ratio(2.0, 2.0);
    const auto val_spec = static_cast<double>(ratio_spec); // using the explicit operator

    std::cout << "Specialized Value: " << val_spec << "\n";

    constexpr int three = 3; // Just to be explicit
    auto partial_spec_ratio = Templates_Specialization::Ratio(2.0, three);
    const auto val_partial_spec = static_cast<double>(partial_spec_ratio); // using the explicit operator

    std::cout << "Partial Specialized Value: " << val_partial_spec << "\n";

    /*
     * NOTE: "Why not just create a separate class?"
     * Why specialization is useful if it's a complete new entity?
     * Can sound better just to have another class or template class? Why I should use specialization?
     *
     * Template specialization allows you to tie "special cases to general cases" in a way that makes sense semantically.
     * Even if a specialized class is treated as a "completely new entity," you’re still signaling,
     * "This is a variant of the same concept."
     *
     * It keeps everything logically grouped together, making the intent clear that "special cases are still part of the same broader idea."
     * If you create an entirely new class (not related by templates), you lose this organizational and conceptual link.
     * This can make the code harder to understand or maintain.
    */

    int five = 5;
    auto fiveVal = Templates_Specialization::Value<int*>(&five);

    return 0;
}

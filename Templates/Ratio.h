#ifndef RATIO_H
#define RATIO_H

namespace Templates {

    template<typename T>
    class Ratio {
    public:
        Ratio(const T &numerator, const T &denominator) : numerator(numerator), denominator(denominator) {}
        /*
        Use of dynamic_cast:
        `dynamic_cast` is only valid with pointers or references to polymorphic types (i.e., classes with virtual methods).
        Since `T` could be a fundamental type (e.g., `int`, `double`), `dynamic_cast<double>(numerator)` will fail to compile.
        Instead, `static_cast` (or implicit casting when possible) should be used
         */
        explicit operator double() { return static_cast<double>(numerator) / denominator; }
    private:
        T numerator;
        T denominator;
    };

}

#endif //RATIO_H

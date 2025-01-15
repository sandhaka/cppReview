#ifndef RATIO_SPEC_H
#define RATIO_SPEC_H

namespace Templates_Specialization {

    // The class template
    template<typename N, typename D>
    class Ratio {
    public:
        Ratio() : value_() {}
        Ratio(const N &numerator, const D &denominator) : value_(static_cast<double>(numerator) / denominator) {}
        explicit operator double() const { return value_; } // Explicit conversion to double
    private:
        double value_;
    };

    // The template specialization
    template<>
    class Ratio<double, double> {
    public:
        Ratio() : value_() {}
        template<typename N, typename D>
        Ratio(const N &numerator, const D &denominator) : value_(static_cast<double>(numerator) / denominator) {} // Instantiate value_ to the ratio
        explicit operator double() const { return value_; } // Explicit conversion to double
    private:
        double value_;
    };

}

#endif

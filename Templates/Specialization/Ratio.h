#ifndef RATIO_SPEC_H
#define RATIO_SPEC_H

namespace Templates_Specialization {

    // The class template
    template<typename N, typename D>
    class Ratio {
    public:
        Ratio() : value_() {}
        Ratio(const N &numerator, const D &denominator) : value_(static_cast<double>(numerator) / denominator) {}
        explicit operator double() const { return value_; }
    private:
        double value_;
    };

    // The template specialization full
    template<>
    class Ratio<double, double> {
    public:
        Ratio() : value_() {}
        template<typename N, typename D>
        Ratio(const N &numerator, const D &denominator) : value_(static_cast<double>(numerator) / denominator) {}
        explicit operator double() const { return value_; }
    private:
        double value_;
    };

    // A partial specialization
    template<typename D>
    class Ratio<double, D> {
    public:
        Ratio() : value_() {}
        Ratio(const double &numerator, const D &denominator) : value_(numerator / static_cast<double>(denominator)) {}
        explicit operator double() const { return value_; }
    private:
        double value_;
    };

    // To define a specialization, generic template can be also just forward declared:
    template<typename T> class Value; // Declaration
    template<> class Value<int*> { // int pointer specialization
    public:
        explicit Value(int* int_pointer) : int_pointer_(int_pointer) {}
        int Get() const { return *int_pointer_; }
    private: int* int_pointer_;
    };

}

#endif

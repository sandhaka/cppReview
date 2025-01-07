#ifndef RATIO_H
#define RATIO_H

namespace Templates_Specialization {

    class Ratio<double, double> {
    public:
        Ratio() : value_() {} // Instantiate value_ at a default value
        // Specialization:
        template<typename N, typename D>
        Ratio(const N &numerator, const D &denominator) : value_(static_cast<double>(numerator) / denominator) {} // Instantiate value_ to the ratio
        explicit operator double() const { return value_; } // Explicit conversion to double
    private:
        double value_;
    };

}

#endif //RATIO_H

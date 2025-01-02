#ifndef ARRAYOF2_H
#define ARRAYOF2_H

namespace Templates {

    template<typename T>
    class ArrayOf2 {
    public:
        /// The `&` in the method `T &operator[](size_t i)` indicates that the
        /// method returns a **reference** to an object of type `T`.
        T &operator[](size_t i) { return data[i]; }
        T sum() { return data[0] + data[1]; }

    private:
        T data[2];
    };

}

#endif //ARRAYOF2_H

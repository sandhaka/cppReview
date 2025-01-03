#ifndef SWAP12_H
#define SWAP12_H
#include <utility>

namespace Templates {

    template<typename T>
    auto swap12(const T& x) {
        return std::make_pair(x.second, x.first); // deduction of pair argument
    }
}

#endif //SWAP12_H

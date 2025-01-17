#ifndef GROUP_H
#define GROUP_H
#include <algorithm>

template<typename T1>
class Group {
    public:
    Group() = default;
    explicit Group(T1&& t) { t1_(std::move(t)); }
private:
    T1 t1_;

};

#endif //GROUP_H

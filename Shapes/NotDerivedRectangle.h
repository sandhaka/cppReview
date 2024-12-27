#ifndef NOTDERIVEDRECTANGLE_H
#define NOTDERIVEDRECTANGLE_H

namespace Shapes {
    class NotDerivedRectangle {
    public:
        NotDerivedRectangle(double width, double height) {
            this->width = width;
            this->height = height;
        }
    private:
        double width;
        double height;
    };
}

#endif //NOTDERIVEDRECTANGLE_H

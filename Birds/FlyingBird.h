#ifndef FLYINGBIRD_H
#define FLYINGBIRD_H
#include "Bird.h"

namespace Birds {

    class FlyingBird : public Birds::Bird {
    public:
        virtual void Fly() = 0; // A pure virtual function
    };

}



#endif //FLYINGBIRD_H

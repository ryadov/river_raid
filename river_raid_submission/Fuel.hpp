#ifndef TEST2_FUEL_H
#define TEST2_FUEL_H
#include "Character.hpp"

class Fuel : public Character  {
protected:

public:
    Fuel();  // to  spawn empty object  ,used for killing
    Fuel(int): Character(pick_shape(fuel)) {
        m_score = setScore(fuel);
    }


};

#endif //TEST2_FUEL_H

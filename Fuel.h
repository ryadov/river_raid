//
// Created by REM005 on 5/2/2023.
//

#ifndef TEST2_FUEL_H
#define TEST2_FUEL_H
#include "Character.hpp"

class Fuel : public Character  {
protected:

public:
    Fuel(): Character(pick_shape(fuel)) {
        m_score = setScore(fuel);
    }
};


#endif //TEST2_FUEL_H

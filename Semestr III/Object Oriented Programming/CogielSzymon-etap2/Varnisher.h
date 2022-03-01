//
// Created by szymon on 15.12.2021.
//

#ifndef COGIELSZYMON_ETAP1_VARNISHER_H
#define COGIELSZYMON_ETAP1_VARNISHER_H
#include <vector>
#include "Car.h"
#include "Motor.h"
class Varnisher {
public:

    void changeColor_of_car(Car *x);
    void changeColor_of_motor(Motor *x);

    friend class Car;
    friend class Motor;

};


#endif //COGIELSZYMON_ETAP1_VARNISHER_H

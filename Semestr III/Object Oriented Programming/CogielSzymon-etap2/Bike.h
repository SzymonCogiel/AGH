//
// Created by szymon on 19.12.2021.
//

#ifndef COGIELSZYMON_ETAP1_BIKE_H
#define COGIELSZYMON_ETAP1_BIKE_H
#include "Vehicle.h"
#include <string>
#include "Cin_exception.h"
class Bike : public Vehicle {
public:
    Bike(std::string _color="Black", float _speedmeter=0, float _capacity=200);
    void drive();
    void add_basket(float &x);
    Cin_exception<double> cinException_double;
    Cin_exception<int> cinException_int;

    friend class Factory;
};


#endif //COGIELSZYMON_ETAP1_BIKE_H

//
// Created by szymon on 19.12.2021.
//

#ifndef COGIELSZYMON_ETAP1_VEHICLE_H
#define COGIELSZYMON_ETAP1_VEHICLE_H
#include <string>

class Vehicle {
public:
    void drive();
    Vehicle(const std::string &color="Czarny", float speedMeter=0, float capacity=200);
protected:
    std::string color;
    float speed_meter;
    float capacity;
};


#endif //COGIELSZYMON_ETAP1_VEHICLE_H

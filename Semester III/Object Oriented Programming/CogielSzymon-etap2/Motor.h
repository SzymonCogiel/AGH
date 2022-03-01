//
// Created by szymon on 15.12.2021.
//

#ifndef COGIELSZYMON_ETAP1_MOTOR_H
#define COGIELSZYMON_ETAP1_MOTOR_H
#include <iostream>
#include <string>
#include "Motor_vehicle.h"
using namespace std;
enum class gears;

class Motor : Motor_vehicle{

public:
    Motor(int year=2021, float mileage=0, float fuelUsage=5.5, float maxFuelLevel=20.0,
        const string &brand="None", const string &name="None", double price=0, string color="Czarny", float capacity=300, float fuelLevel=0, float speedMeter=0);
    Motor(const Motor &motor);
    void setPrice(double price);
    void setColor();
    int getYear() const;
    int getID() const;
    float getMileage() const;
    float getFuelUsage() const;
    float getMaxFuelLevel() const;
    float getCapacity() const;
    double getPrice() const;
    const string &getBrand() const;
    const string &getColor() const;
    const string &getName() const;


    friend class Factory;

};


#endif //COGIELSZYMON_ETAP1_MOTOR_H

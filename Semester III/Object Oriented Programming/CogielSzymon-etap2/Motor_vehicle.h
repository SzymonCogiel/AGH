//
// Created by szymon on 15.12.2021.
//

#ifndef COGIELSZYMON_ETAP1_MOTOR_VEHICLE_H
#define COGIELSZYMON_ETAP1_MOTOR_VEHICLE_H

#include <iostream>
#include <string>
#include "Cin_exception.h"
using namespace std;
enum class gears;

class Motor_vehicle {

public:
    int ID;
    gears change_gear();
    void acceleration_max();
    void refueling();
    void full_refueling();
    void do_acce(float min_pr, float max_pr,int step, float &speed);
    void containment();
    void drive();
    float dzielenie(float &licz, float &mian);

    virtual void setColor()=0;
    virtual void setPrice(double price)=0;



    Motor_vehicle(int year=2021, float mileage=0, float fuelUsage=5.5, float maxFuelLevel=20.0,
        const string &brand="None", const string &name="None", double price=0, float fuelLevel=0, float speedMeter=0, string color = "Czarny", float capacity = 800);
    Motor_vehicle(const Motor_vehicle &car);

protected:
    int year;
    float mileage;
    float fuel_usage;
    float fuel_level;
    float max_fuel_level;
    float speed_meter;
    float capacity;
    double price;
    string brand;
    string name;
    string color;
    Cin_exception<int> cinException_int;
    Cin_exception<float> cinException_float;
};

enum class gears{
    luz=0,
    jendynka,
    i_cyk_dwojeczka,
    trojka,
    czworka,
    piatka,
    szostka,
    atuomat,
    wsteczny
};


#endif //COGIELSZYMON_ETAP1_MOTOR_VEHICLE_H

//
// Created by szymon on 15.12.2021.
//

#include "Motor.h"

Motor::Motor(int year, float mileage, float fuelUsage, float maxFuelLevel,
         const string &brand, const string &name, double price, string color, float capacity, float fuelLevel, float speedMeter) : Motor_vehicle(year,
                                                                                                                                 mileage,
                                                                                                                                 fuelUsage,
                                                                                                                                 maxFuelLevel,
                                                                                                                                 brand, name,
                                                                                                                                 price, fuelLevel,
                                                                                                                                 speedMeter, color, capacity){

}

Motor::Motor(const Motor &motor) : Motor_vehicle(motor){

}

void Motor::setPrice(double price) {
    Motor::price = price;
}

void Motor::setColor(){
    string _color;
    std::cout<<"Podaj nowy kolor motoru: ";
    std::cin>>_color;
    color = _color;
}

int Motor::getYear() const {
    return year;
}

float Motor::getMileage() const {
    return mileage;
}

float Motor::getFuelUsage() const {
    return fuel_usage;
}

float Motor::getMaxFuelLevel() const {
    return max_fuel_level;
}
double Motor::getPrice() const{
    return price;
}
const string &Motor::getBrand() const {
    return brand;
}
float Motor::getCapacity() const {
    return capacity;
}
int Motor::getID() const{
    return ID;
}
const string &Motor::getColor() const {
return color;
}
const string &Motor::getName() const {
    return name;
}
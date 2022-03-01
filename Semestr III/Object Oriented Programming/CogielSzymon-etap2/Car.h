//
// Created by szymon on 01.12.2021.
//

#ifndef TESTOWANIE_CPP_CAR_H
#define TESTOWANIE_CPP_CAR_H
#include <iostream>
#include <string>
#include "Motor_vehicle.h"
using namespace std;
enum class gears;


class Car : public  Motor_vehicle{
public:
    int radio();

    // KONSTRUKTORY
    Car(int year=2021, float mileage=0, float fuelUsage=5.5, float maxFuelLevel=20.0,
                  const string &brand="None", const string &name="None", double price=0,string color="Czarny", float capacity=800, float fuelLevel=0, float speedMeter=0);
    Car(const Car &car);


    const string &getBrand() const;
    const string &getName() const;
    const string &getColor() const;
    int getYear() const;
    int getID() const;
    float getMileage() const;
    float getFuelUsage() const;
    float getMaxFuelLevel() const;
    float getCapacity() const;
    double getPrice() const;




    void setColor();
    void setPrice(double price);

    friend std::ostream& operator<<(std::ostream& stream,const Car& car);
    friend class Factory;

};
inline std::ostream& operator<<(std::ostream& stream,const Car& car){
    stream <<"Marka: "<<car.brand <<std::endl<<"Nazwa: "<< car.name<<std::endl<<"Przebieg: "<<car.mileage<<std::endl<<"Rocznik: "<< car.year<<std::endl<<"Pojemnosc baku: "<<car.max_fuel_level;
    return stream;
}


#endif //TESTOWANIE_CPP_CAR_H

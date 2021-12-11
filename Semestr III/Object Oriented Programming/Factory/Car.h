//
// Created by szymon on 01.12.2021.
//

#ifndef TESTOWANIE_CPP_CAR_H
#define TESTOWANIE_CPP_CAR_H
#include <iostream>
#include <string>
using namespace std;
enum class gears;


class Car {
public:
    int ID;

    int radio();
    gears change_gear();
    void acceleration_max();
    void refueling();
    void full_refueling();
    void do_acce(float min_pr, float max_pr,int step, float &speed);
    void containment();
    void drive();


    Car(int year=2021, float mileage=0, float fuelUsage=5.5, float maxFuelLevel=20.0,
        const string &brand="None", const string &name="None", double price=0, float fuelLevel=0, float speedMeter=0);

    Car(const Car &car);


    const string &getBrand() const;
    const string &getName() const;
    int getYear() const;
    float getMileage() const;
    float getFuelUsage() const;
    float getMaxFuelLevel() const;
    float getSpeedMeter() const;
    float getFuelLevel() const;

    void setPrice(double price);

    friend std::ostream& operator<<(std::ostream& stream,const Car& car);
    friend class Factory;
protected:
    int year;
    float mileage;
    float fuel_usage;
    float fuel_level;
    float max_fuel_level;
    float speed_meter;
    double price;
    string brand;
    string name;

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

inline std::ostream& operator<<(std::ostream& stream,const Car& car){
    stream <<"Marka: "<<car.brand <<std::endl<<"Nazwa: "<< car.name<<std::endl<<"Przebieg: "<<car.mileage<<std::endl<<"Rocznik: "<< car.year<<std::endl<<"Pojemnosc baku: "<<car.max_fuel_level;
    return stream;
}


#endif //TESTOWANIE_CPP_CAR_H

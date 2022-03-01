//
// Created by szymon on 02.12.2021.
//

#ifndef CAR_H_FACTORY_H
#define CAR_H_FACTORY_H
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <sstream>
#include <algorithm>
#include "Car.h"
#include "Motor.h"
#include "Varnisher.h"
#include "Komis.h"
#include "Bike.h"
#include "Cin_exception.h"
#include "utils.h"
using std::vector;


class Factory {

public:
    static int carID;
    void produce();

    void produce_bike();
    void printListOfBike();
    void ride_bike();
    void addBasket();

    void printListOfMotor();
    void save_to_csv_motor();
    void download_cars_from_csv_motor(const char* pliko="0");
    void copy_motor();
    void predict_price_motor();
    void motor_exploration();

    void remove_car();
    void sent_to_sell();
    void printListOfCar();
    void printListOfCarForSell();
    void save_to_csv();
    void save_to_csv_sell();
    void car_exploration();
    void read_record_from_csv();
    void download_cars_from_csv(const char* pliko= nullptr);
    void copy_car();
    void predict_price_car();

    void vehicle_color_change();
    void print_komis_list();
    void sprzedaj_poj_kom();


    friend std::ostream& operator<<(std::ostream& stream,const Factory& factory);
    friend std::ofstream & operator<<(std::ofstream & disp, Factory& factory);
    friend std::ifstream & operator>>(std::ifstream & disp, Factory& factory);
    Factory(const std::string &city, const std::string &name);


protected:
    template <typename T>
    T createCar();
    template <typename T>
    T createCar1(int id, int year, float mileage, float fuelUsage, float maxFuelLevel, double price, string brand, string name, string color, float capacity);
    std::string _city;
    std::string _name;
    vector<Car> car_list;
    vector<Car> car_for_sell_list;
    vector<Motor> motor_list;
    vector<Bike> bike_list;

    Varnisher varnisher;
    Komis komis{car_list,motor_list};
    Cin_exception<int> cinException_int;
    Cin_exception<double> cinException_double;
    Cin_exception<float> cinException_float;


};


inline std::ostream& operator<<(std::ostream& stream,const Factory& factory){
    stream<<"Name: "<<factory._name<< std::endl<<"Miasto: "<<factory._city<<std::endl;
    return stream;
}


// PRZELADOWANIE OPERATOROW WPROGRAMIE NIE SA UZYWANE!!! UZYWAM DO TEGO INNYCH FUNKCJI MIALEM INNA KONCEPCJE ALE DOCZYTALEM ZE POWNNY BYC W PROJEKCIE
inline std::ofstream & operator<<(std::ofstream & disp, Factory& factory){
    disp<<"Nazwa, Lokalizacja\n";
    disp<<factory._name<<", "<<factory._city<<std::endl;
    disp<<"===========Samochody w magazynie================\n";
    disp<<"ID, Marka, Nazwa, Rocznik, Spalanie, Licznik, Bak";
    for(int i = 0; i<factory.car_list.size(); i++)
    {
        disp<<factory.car_list.at(i).ID<<", "<<factory.car_list.at(i).getBrand()<<", "<<factory.car_list.at(i).getName()<<", "<<factory.car_list.at(i).getYear()
        <<", "<<factory.car_list.at(i).getFuelUsage()<<", "<<factory.car_list.at(i).getMileage()<<", "<<factory.car_list.at(i).getMaxFuelLevel();
    }
    return disp;
}

inline std::ifstream & operator>>(std::ifstream & disp, Factory& factory)
{
    std::string row, ID, Brand, Name, Rocznik, Spalanie, Licznik, Bak;
    std::getline(disp,row); // wyrzucenie naglowkow
    std::getline(disp,row); // wyrzucenie danych firmy
    std::getline(disp,row); // wyrzucenie naglowkow samochodow
    while(disp.peek() != EOF)  //dopoki ne nojdzeny do EOF
    {
        std::getline(disp,row); // wczytanie lini z danymi
        std::replace( row.begin(), row.end(), ',', ' ');
        std::istringstream iss(row);
        iss>>ID>>Brand>>Name>>Rocznik>>Spalanie>>Licznik>>Bak; // zapisywanie zmiennych
        Car x(stoi(Rocznik), stof(Licznik), stof(Spalanie), stof(Bak), Brand, Name);
        x.ID = stoi(ID);
        factory.car_list.push_back(x);
    }
    return disp;
}


#endif //CAR_H_FACTORY_H

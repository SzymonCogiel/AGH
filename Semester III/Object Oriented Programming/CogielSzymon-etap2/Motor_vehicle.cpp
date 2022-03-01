//
// Created by szymon on 15.12.2021.
//

#include "Motor_vehicle.h"
#include <iostream>
#include <math.h>
#include "Div_zero_exc.h"
#define CENAPALIWA 6.2

// konstruktor
Motor_vehicle::Motor_vehicle(int year, float mileage, float fuelUsage, float maxFuelLevel,
         const string &brand, const string &name, double price, float fuelLevel, float speedMeter, string color, float capacity) : year(year), mileage(mileage), fuel_usage(fuelUsage),
                                                                                                     fuel_level(fuelLevel), max_fuel_level(maxFuelLevel),
                                                                                                     speed_meter(speedMeter), brand(brand), name(name), price(price), color(color), capacity(capacity){

}


Motor_vehicle::Motor_vehicle(const Motor_vehicle &car) : year(car.year), mileage(car.mileage), fuel_usage(car.fuel_usage),
                           fuel_level(car.fuel_level), max_fuel_level(car.max_fuel_level),
                           speed_meter(car.speed_meter), brand(car.brand), name(car.name), price(car.price), ID(car.ID), color(car.color), capacity(car.capacity){

}

// metoda do zmiany biegow
gears Motor_vehicle::change_gear()
{
    using namespace std;
    gears biegi;
    int wybor;
    std::cout<<"Jaki bieg (0-7)?"<<endl;
    cinException_int.wpisz(wybor);
    switch (wybor) {
        case 0:
            biegi = gears::luz;
            cout<<"LUZ"<<endl;
            break;
        case 1:
            biegi = gears::jendynka;
            cout<<"I cyk jedyneczka"<<endl;
            break;
        case 2:
            biegi = gears::i_cyk_dwojeczka;
            cout<<"I cyk dwojeczka"<<endl;
            break;
        case 3:
            biegi = gears::trojka;
            cout<<"I pyk trojeczka"<<endl;
            break;
        case 4:
            biegi = gears::czworka;
            cout<<"I pyk 4"<<endl;
            break;
        case 5:
            biegi = gears::piatka;
            cout<<"Łohoho piateczka"<<endl;
            break;
        case 6:
            biegi = gears::szostka;
            cout<<"O cie..."<<endl;
            break;
        case 7:
            biegi = gears::atuomat;
            cout<<"Automacik"<<endl;
            break;
        case 8:
            biegi = gears::wsteczny;
            cout<<"Rakieta"<<endl;
            break;
        default:
            biegi = gears::luz;
            cout<<"LUZ"<<endl;
            break;
    }
    return biegi;
}

// metoda do przyspieszenia
void Motor_vehicle::do_acce(float min_pr, float max_pr,int step, float &speed){
    if(min_pr <= speed && speed <= max_pr){
        for (int i = (int) speed; i < max_pr; )
        {
            i += step;
            std::cout << i << "km/h" << endl;
            speed = (float) i;
        }
    }else{
        std::cout<<"Toja predkosc "<<speed<<"km/h"<<endl;
        std::cout<<"wwrrrrrrrrrr"<<endl;
    }
}

// metoda do przyspieszenia na maxa przy danym biegu
void Motor_vehicle::acceleration_max()
{
    using namespace std;

    float speed = speed_meter;
    gears bieg = change_gear();
    if(bieg == gears::jendynka)
    {
        do_acce(0,20,1,speed);
    }
    if(bieg == gears::i_cyk_dwojeczka)
    {
        do_acce(0,40,1,speed);

    }
    if(bieg == gears::trojka)
    {
        do_acce(40,75,2,speed);
    }
    if(bieg == gears::czworka)
    {
        do_acce(50,110,3,speed);
    }
    if(bieg == gears::piatka)
    {
        do_acce(80,160,4,speed);
    }
    if(bieg == gears::szostka)
    {

        do_acce(100,300,10,speed);
    }
    if(bieg == gears::atuomat)
    {
        do_acce(0,300,10,speed);
    }
    if(bieg == gears::wsteczny)
    {
        if(speed == 0){
            cout<<"Cofam"<<endl;
        }else{
            cout<<"wwrrrrrrrrrr"<<endl;
        }
    }
    this->speed_meter = speed;
}

// tankowanie do pelnego balu
void Motor_vehicle::full_refueling(){
    using namespace std;
    int poczatkowy = (int)fuel_level;
    if(poczatkowy < max_fuel_level) {
        for (int i = poczatkowy; i <= (int) max_fuel_level; i++) {
            cout << "Poziom baku: " << i << " l" << endl;
        }
        cout << "Do zaplaty " << CENAPALIWA * (max_fuel_level - poczatkowy) << "zl" << endl;
        cout << "OPCJA DO PELNA"<<endl;
        this->fuel_level = max_fuel_level;
    }else{
        cout<<"Masz juz pelny bak"<<endl;
    }
}

// tankowanie x litrow
void Motor_vehicle::refueling() {
    using namespace std;

    int poczatkowy = (int)fuel_level;
    int ilosc;
    cout<<"Ile litrow chcesz zatankowac lub jak do pelna to wybierz 0"<<endl;
    cinException_int.wpisz(ilosc);
    if(poczatkowy < this->max_fuel_level) {
        if (ilosc == 0) {
            full_refueling();
        } else {
            if((poczatkowy+ilosc)< this->max_fuel_level) {
                for (int i = 0; i < ilosc; i++) {
                    poczatkowy++;
                    cout << "Poziom baku: " << poczatkowy << "l" << endl;
                }
                cout << "Do zaplaty " << CENAPALIWA * ilosc << "zl" << endl;
                this->fuel_level += (float)ilosc;
            } else{
                cout<<"Masz za mala pojemnosc nalejemy do pelna"<<endl;
                full_refueling();
            }
        }
    } else{
        cout<<"Masz juz pelny bak"<<endl;
    }
}

// jazda (zwieksza wartosc licznik i zmnijsza wartosc paliwa)
void Motor_vehicle::drive(){
    float km;
    if(speed_meter != 0) {
        std::cout << "Ile km chcesz przejechac?" << std::endl;
        cinException_float.wpisz(km);
        float spalone = km * (fuel_usage / 100);
        if (spalone >= this->fuel_level) {
            std::cout << "Masz za malo paliwa" << endl;
        } else {
            this->fuel_level -= spalone;
            this->mileage += km;
            std::cout << "Przejechales " << km << " km w " << round(dzielenie(km, speed_meter) * 60)
                      << " min ze srednia predkoscia " << speed_meter << "km/h, stan twojego baku wynosi: "
                      << fuel_level << endl;
        }
    } else{
        std::cout<<"Musisz przyspieszyc zeby ruszyc w droge"<<endl;
    }
}
float Motor_vehicle::dzielenie(float &licz, float &mian){
    if (mian == 0)
        throw Exception();
    return (licz / mian);
}
// hamowanie
void Motor_vehicle::containment()
{
    std::cout<<"Hamujemy"<<endl;
    this->speed_meter=0;
}
//
// Created by szymon on 19.12.2021.
//

#include "Bike.h"
#include <iostream>

Bike::Bike(std::string _color, float _speedmeter, float _capacity): Vehicle(_color, _speedmeter,_capacity) {}

void Bike::add_basket(float &x){
    this->capacity +=x;
}

void Bike::drive() {
    int  sex;
    double time, spalone, tentno, waga, age, predkosc;
    std::cout<<"Ile minut chcesz jechac: "<<std::endl;
    cinException_double.wpisz(time);
    std::cout<<"Podaj swoj wiek: "<<std::endl;
    cinException_double.wpisz(age);
    std::cout<<"Podaj swoja wage: "<<std::endl;
    cinException_double.wpisz(waga);
    std::cout<<"Podaj swoj plec(1=mezczyzna/2=kobieta): "<<std::endl;
    cinException_int.wpisz(sex);
    std::cout<<"Podaj swoj swoje tentno: "<<std::endl;
    cinException_double.wpisz(tentno);
    std::cout<<"Podaj predkosc z jaka bedziesz jechac: "<<std::endl;
    cinException_double.wpisz(predkosc);

    double scaled_predkosc = (predkosc - 0)/40 + 3.5;

    if(sex==1){
        spalone =((age*0.2017-waga*0.09036+tentno*0.6309-55.0969)*time*scaled_predkosc)/4.184;
    } else{
        spalone =((age*0.0074-waga*0.05741+tentno*0.4472-20.4022)*time*scaled_predkosc)/4.184;
    }
    std::cout<<"Przez "<<time<<" min jazdy rowerem spaliles "<<spalone * (-1)<<" kalorii"<<std::endl;
}

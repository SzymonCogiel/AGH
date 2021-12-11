//
// Created by szymon on 02.12.2021.
//

#include "Factory.h"
#include "Car.h"
#include <iostream>
#include <string>
#include<algorithm>
#include <fstream>

// zmienna statyczna
int Factory::carID = 0;

// konstruktor
Factory::Factory(const std::string &city, const std::string &name) : _city(city), _name(name) {}


// metoda do wykonywania metod instancji Car w wektorze car_list
void Factory::car_exploration(){
    using namespace std;

    if(car_list.size() != 0) {
        int nr_ID;
        int choice_car;
        do {
            cout << "Podaj ID samochodu ktory chcesz eksplorowac: " << endl;
            cin >> nr_ID;
            if(nr_ID < 0 || nr_ID >= (car_list.size())) {
                cout << "Nie ma samochodu o ID: " << nr_ID <<"\nDOSTEPNE SAMOCHODY"<<endl;
                printListOfCar();
            }
        } while (nr_ID < 0 ||  nr_ID >= (car_list.size()));
        Car exploited_car;
        exploited_car = car_list.at(nr_ID);
        do {
            cout << "=============Opcje samochodu===============" << endl;
            cout << "(1)Jedz\n" << "(2)Napelnij bak\n" << "(3)Napelnij bak do pelna\n" << "(4)Przyspiesz\n"
                 << "(5)Hamuj\n" <<"(6)Wyswietl informacje na temat samochodu\n"<<"(7)RADIOOOOOO!!!!!!!!!!!!!\n" <<"(8)Wroc do menu\n";
            cin>>choice_car;
            switch (choice_car) {
                case 1:
                    exploited_car.drive();
                    break;
                case 2:
                    exploited_car.refueling();
                    break;
                case 3:
                    exploited_car.full_refueling();
                    break;
                case 4:
                    exploited_car.acceleration_max();
                    break;
                case 5:
                    exploited_car.containment();
                    break;
                case 6:
                    cout<<exploited_car<<endl;
                    break;
                case 7:
                    exploited_car.radio();
                    break;
                default:
                    cout << "Nie nie ma operazji o numerze: " << choice_car << endl<<endl;
                    break;

            }
        } while (choice_car != 8);
    }else{
        cout<<"Brak samochodow do testowania dodaj samochod"<<endl;
    }
}



// metoda produce() oraganizuje ui(w postaci konsoli) oraz używa metody createCar() do dodania do vektora samochodu
void Factory::produce(){
    int choice=0;
    std::cout<<"Jaki samochod chcesz wyprodukowac: "<<std::endl;
    std::cout<<"===============LISTA==============="<<std::endl;
    std::cout<<"(1) Samochod"<<std::endl;
    std::cin>>choice;
    switch(choice)
    {
        case 0:
            std::cout<<"Pomijamy";
            break;
        case 1:
            car_list.push_back(createCar());
            break;
        default:
            std::cout<<"Pomijamy"<<std::endl;
            break;
    }
}

// metoda createCar() prosi o wpisanie danych samochodu i zwraca instancjie klasy Car o podanych parametrach
Car Factory::createCar() {
    string D_name, D_brand;
    int D_year;
    float D_mileage, D_fuelUsage, D_maxFuelLevel;
    double D_price;
    cout<<"Podaj nazwe: "<<endl;
    cin>>D_name;
    cout<<"Podaj marke: "<<endl;
    cin>>D_brand;
    cout<<"Podaj rocznik: "<<endl;
    cin>> D_year;
    cout<<"Podaj przebieg: "<<endl;
    cin>>D_mileage;
    cout<<"Podaj spalanie(l/100km): "<<endl;
    cin>>D_fuelUsage;
    cout<<"Podaj pojemnosc baku: "<<endl;
    cin>>D_maxFuelLevel;
    cout<<"Podaj cene: "<<endl;
    cin>>D_price;

    Car x(D_year, D_mileage,D_fuelUsage, D_maxFuelLevel, D_brand, D_name, D_price);
    x.ID = carID++;
    return x;
}

// moteoda zwracajaca nowa instancje klasy Car (metoda ta jest po to zeby dzialalo przeladaowanie operatorow ktore nie sa uzywane w programie ale zostaly napisane)
Car Factory::createCar(int id, int year, float mileage, float fuelUsage, float maxFuelLevel, double price, string brand, string name){
    Car x(year,mileage,fuelUsage, maxFuelLevel, brand, name, price);
    x.ID = id + car_list.size() + 1;
    return x;
}


// metoda wyswietlajaca samochody w magazynie
void Factory::printListOfCar(){
    std::cout<<"LISTA SAMOCHODZIKOW"<<std::endl;
    std::cout<<"Ilosc samochodzikow: "<<car_list.size()<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"ID"<<"\t\t"<<"MARKA\t"<<"NAZWA\t"<<"ROCZNIK\t"<<"PRZEBIEG\t"<<"CENA\t"<<std::endl;
    for(Car car:car_list)
    {
        std::cout<<car.ID<<"\t\t"<<car.brand<<"\t\t"<<car.name<<"\t\t"<<car.year<<"\t\t"<<car.mileage<<"\t\t"<<car.price<<std::endl;
    }

}

//usowanie samochodu z vektora car_list
void Factory::remove_car(){
    int index;
    std::cout<<"Ktory samochod chcesz usunac(Podaj ID):"<<std::endl;
    std::cin>>index;
    if(index!=0) {
        car_list.erase(car_list.begin() + index - 1);
    } else{
        car_list.erase(car_list.begin() + index);
    }
}

// przesylanie somochodw z vektora car_list do car_for_sell_list
void Factory::sent_to_sell(){
    int index;
    bool is_for_sell;
    float new_price;
    std::cout<<"Podaj samochod na sprzedarz: "<<std::endl;
    std::cin>>index;
    std::cout<<"Chcesz ustawic nowa cene?(1-tak / 0-nie) "<<std::endl;
    std::cin>>is_for_sell;
    if(is_for_sell){
        std::cout<<"Podaj nowa cene: "<<std::endl;
        std::cin>>new_price;
        car_list[index].setPrice(new_price);
    }
    car_for_sell_list.insert(car_for_sell_list.end(), std::make_move_iterator(car_list.begin() + index),
              std::make_move_iterator(car_list.end()));
    car_list.erase(car_list.begin() + index, car_list.end());
}


// wyswietlanie listy samochodow
void Factory::printListOfCarForSell(){
    std::cout<<"LISTA SAMOCHODZIKOW WYSTAWIONYCH NA SPRZEDARZ"<<std::endl;
    std::cout<<"Ilosc samochodzikow: "<<car_list.size()<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"MARKA\t"<<"NAZWA\t"<<"ROCZNIK\t"<<"PRZEBIEG\t"<<"CENA\t"<<std::endl;
    for(Car car:car_for_sell_list)
    {
        std::cout<<car.brand<<"\t\t"<<car.name<<"\t\t"<<car.year<<"\t\t"<<car.mileage<<"\t\t"<<car.price<<std::endl;
    }
}

// metoda do zapisu vektora samochodow z magazynu do pliku csv
void Factory::save_to_csv(){
    fstream csvka;
    csvka.open("cars_in_stock.csv", ios::out | ios::app);
    for(Car car : car_list)
    {
        csvka <<car.ID  << ", "
             << car.brand << ", "
             << car.name << ", "
             << car.year << ", "
             << car.mileage << ", "
             << car.fuel_usage << ", "
             << car.max_fuel_level <<", "
             << car.price
             << "\n";
    }
    csvka.close();
}

// metoda do zapisu vektora samochodow na sprzedarz do pliku csv
void Factory::save_to_csv_sell(){
    fstream csvka;
    csvka.open("cars_for_sell.csv", ios::out | ios::app);
    for(Car car : car_for_sell_list)
    {
        csvka << car.brand << ","
              << car.name << ","
              << car.year << ","
              << car.mileage << ","
              << car.fuel_usage << ","
              << car.max_fuel_level <<","
              << car.price
              << "\n";
    }
    csvka.close();
}


// motoda do czytania danych z pliku csv
void Factory::read_record_from_csv(){
    using namespace std;
    string file_name;
    cout<<"Wproadz nazwe pliku csv wraz z rozszerzeniem: ";
    cin>>file_name;

    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    fstream file (file_name, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Nie ma takiego pliku\n";

    for(int i=0;i<content.size();i++) //z naglowkiem
    {
        for(int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// motoda do pobierania danych z pliku csv i uzywania ich w programie
void Factory::download_cars_from_csv(){
    using namespace std;
    string file_name;
    string D_name, D_brand, D_ID, D_year, D_mileage, D_fuelUsage, D_maxFuelLevel, D_price;
    cout<<"Wproadz nazwe pliku csv wraz z rozszerzeniem: ";
    cin>>file_name;

    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    fstream file (file_name, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Nie ma takiego pliku\n";


    for(int i=1;i<content.size();i++) // bez naglowka
    {
        for(int j=0;j<content[i].size();j++)
        {
            D_ID = content[i].at(0);
            D_ID.erase(remove(D_ID.begin(), D_ID.end(), ' '), D_ID.end());
            D_name = content[i].at(1);
            D_name.erase(remove(D_name.begin(), D_name.end(), ' '), D_name.end());
            D_brand = content[i].at(2);
            D_brand.erase(remove(D_brand.begin(), D_brand.end(), ' '), D_brand.end());
            D_year = content[i].at(3);
            D_year.erase(remove(D_year.begin(), D_year.end(), ' '), D_year.end());
            D_mileage = content[i].at(4);
            D_mileage.erase(remove(D_mileage.begin(), D_mileage.end(), ' '), D_mileage.end());
            D_fuelUsage = content[i].at(5);
            D_fuelUsage.erase(remove(D_fuelUsage.begin(), D_fuelUsage.end(), ' '), D_fuelUsage.end());
            D_maxFuelLevel = content[i].at(6);
            D_maxFuelLevel.erase(remove(D_maxFuelLevel.begin(), D_maxFuelLevel.end(), ' '), D_maxFuelLevel.end());
            D_price = content[i].at(7);
            D_price.erase(remove(D_price.begin(), D_price.end(), ' '), D_price.end());
        }
        int i_id, i_year;
        float f_milage, f_fuelUsage, f_maxFuelLevel;
        double d_price;
        i_id = atoi(D_ID.c_str());
        i_year = atoi(D_year.c_str());
        f_milage = stof(D_mileage);
        f_fuelUsage = stof(D_fuelUsage) ;
        f_maxFuelLevel = stof(D_maxFuelLevel) ;
        d_price = stod(D_price);
        car_list.push_back(createCar(i_id, i_year, f_milage, f_fuelUsage, f_maxFuelLevel, d_price, D_brand, D_name));

    }
    cout<<"Wczytane!!!\n";
}

// metoda kopiujaca samochod
void Factory::copy_car(){
    Car x;
    int index;
    std::cout<<"Podaj index samochodu ktory chcesz skopiowac\n";
    cin>>index;
    x = car_list.at(index);
    Car y(x);
    y.ID = car_list.size() + 1;
    car_list.push_back(y);
    std::cout<<"Skopiowany\n";
}
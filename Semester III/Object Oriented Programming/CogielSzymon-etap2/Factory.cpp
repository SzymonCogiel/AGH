//
// Created by szymon on 02.12.2021.
//

#include "Factory.h"
#include "Car.h"
#include <iostream>
#include <string>
#include<algorithm>

extern vector<string> *v;


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
            cout << "Podaj Index samochodu ktory chcesz eksplorowac: " << endl;
            cinException_int.wpisz(nr_ID);
            if(nr_ID < 0 || nr_ID >= (car_list.size())) {
                cout << "Nie ma samochodu o Index: " << nr_ID <<"\nDOSTEPNE SAMOCHODY"<<endl;
                printListOfCar();
                break;
            }
        } while (nr_ID < 0 ||  nr_ID >= (car_list.size()));
        Car exploited_car;
        exploited_car = car_list.at(nr_ID);
        do {
            cout << "=============Opcje samochodu===============" << endl;
            cout << "(1) Jedz\n" << "(2) Napelnij bak\n" << "(3) Napelnij bak do pelna\n" << "(4) Przyspiesz\n"
                 << "(5) Hamuj\n" <<"(6) Wyswietl informacje na temat samochodu\n"<<"(7) RADIOOOOOO!!!!!!!!!!!!!\n" <<"(8) Wroc do menu\n";
            cinException_int.wpisz(choice_car);
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


void Factory::motor_exploration(){
    using namespace std;

    if(car_list.size() != 0) {
        int nr_ID;
        int choice_car;
        do {
            cout << "Podaj Index motoru ktory chcesz eksplorowac: " << endl;
            cinException_int.wpisz(nr_ID);
            if(nr_ID < 0 || nr_ID >= (motor_list.size())) {
                cout << "Nie ma motoru o Index: " << nr_ID <<"\nDOSTEPNE MOTORY"<<endl;
                printListOfCar();
                break;
            }
        } while (nr_ID < 0 ||  nr_ID >= (motor_list.size()));
        Motor exploited_car;
        exploited_car = motor_list.at(nr_ID);
        do {
            cout << "=============Opcje motoru===============" << endl;
            cout << "(1) Jedz\n" << "(2) Napelnij bak\n" << "(3) Napelnij bak do pelna\n" << "(4) Przyspiesz\n"
                 << "(5) Hamuj\n"<<"(6) Wroc do menu\n";
            cinException_int.wpisz(choice_car);
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
    std::cout<<"Jaki pojazd chcesz wyprodukowac: "<<std::endl;
    std::cout<<"===============LISTA==============="<<std::endl;
    std::cout<<"(1) Samochod"<<std::endl;
    std::cout<<"(2) Motor"<<std::endl;
    if(counter < v->size()){
        choice = dane_z_pliku_int(*v, choice);
    } else {
        cinException_int.wpisz(choice);
    }
    switch(choice)
    {
        case 0:
            std::cout<<"Pomijamy";
            break;
        case 1:
            car_list.push_back(createCar<Car>());
            break;
        case 2:
            motor_list.push_back(createCar<Motor>());
            break;
        default:
            std::cout<<"Pomijamy"<<std::endl;
            break;
    }
}

void Factory::produce_bike() {
    string _color;
    std::cout<<"Podaj kolor: "<<std::endl;

    if(counter < v->size()){
        _color = dane_z_pliku(*v, _color);
    } else {
        std::cin>>_color;
    }

    Bike x(_color);
    bike_list.push_back(x);
}

void Factory::printListOfBike() {
    std::cout << "=========LISTA_ROWEROW============" << endl;
    std::cout << "Ilosc rowerow: " << bike_list.size() << endl;
    std::cout << "INDEX\t\t" << "KOLOR" << endl;
    for (int i=0; i < bike_list.size(); i++)
        std::cout << i << "\t\t\t" << bike_list.at(i).color << endl;
}
void Factory::ride_bike(){
    int ind;
    std::cout<<"Podaj index rowera ktorym chcesz jezdzic: "<<std::endl;
    cinException_int.wpisz(ind);
    bike_list.at(ind).drive();
}
void Factory::addBasket(){
    int ind;
    float size;
    std::cout<<"Podaj ladownosc koszyka: "<<std::endl;
    cinException_float.wpisz(size);
    std::cout<<"Podaj index rowera do ktorego chcesz doddac koszyk: "<<std::endl;
    cinException_int.wpisz(ind);
    bike_list.at(ind).add_basket(size);
}

template <typename T>
T Factory::createCar() {
    string D_name, D_brand, D_color;
    int D_year;
    float D_mileage, D_fuelUsage, D_maxFuelLevel, D_capacity;
    double D_price;
    cout<<"Podaj nazwe: "<<endl;
    if(counter < v->size()){
        D_name = dane_z_pliku(*v, D_name);
    } else {
        cin>>D_name;
    }
    cout<<"Podaj marke: "<<endl;
    if(counter < v->size()){
        D_brand = dane_z_pliku(*v, D_brand);
    } else {
        cin>>D_brand;
    }
    cout<<"Podaj rocznik: "<<endl;
    if(counter < v->size()){
        D_year = dane_z_pliku_int(*v, D_year);
    } else {
        cinException_int.wpisz(D_year);
    }
    cout<<"Podaj przebieg: "<<endl;
    if(counter < v->size()){
        D_mileage = dane_z_pliku_float(*v, D_mileage);
    } else {
        cinException_float.wpisz(D_mileage);
    }
    cout<<"Podaj spalanie(l/100km): "<<endl;
    if(counter < v->size()){
        D_fuelUsage = dane_z_pliku_float(*v, D_fuelUsage);
    } else {
        cinException_float.wpisz(D_fuelUsage);
    }
    cout<<"Podaj pojemnosc baku: "<<endl;
    if(counter < v->size()){
        D_maxFuelLevel = dane_z_pliku_float(*v, D_maxFuelLevel);
    } else {
        cinException_float.wpisz(D_maxFuelLevel);
    }
    cout<<"Podaj cene: "<<endl;
    if(counter < v->size()){
        D_price = dane_z_pliku_double(*v, D_price);
    } else {
        cinException_double.wpisz(D_price);
    }

    cout<<"Podaj kolor: "<<endl;
    if(counter < v->size()){
        D_color = dane_z_pliku(*v, D_color);
    } else {
        cin>>D_color;
    }
    cout<<"Podaj capacity: "<<endl;
    if(counter < v->size()){
        D_capacity = dane_z_pliku_float(*v, D_capacity);
    } else {
        cinException_float.wpisz(D_capacity);
    }

    T x(D_year, D_mileage,D_fuelUsage, D_maxFuelLevel, D_brand, D_name, D_price, D_color, D_capacity);
    x.ID = carID++;
    return x;
}



template <typename T>
T Factory::createCar1(int id, int year, float mileage, float fuelUsage, float maxFuelLevel, double price, string brand, string name, string color, float capacity){
    T x(year,mileage,fuelUsage, maxFuelLevel, brand, name, price, color, capacity);
    x.ID = id + car_list.size() + 1;
    return x;
}




// metoda wyswietlajaca samochody w magazynie
void Factory::printListOfCar(){
    std::cout<<"LISTA SAMOCHODZIKOW"<<std::endl;
    std::cout<<"Ilosc samochodzikow: "<<car_list.size()<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"ID"<<"\t\t"<<"MARKA\t"<<"NAZWA\t"<<"ROCZNIK\t"<<"PRZEBIEG\t"<<"CENA\t"<<"COLOR\t"<<"CAPACITY\t"<<std::endl;
    for(Car car:car_list)
    {
        std::cout<<car.ID<<"\t\t"<<car.brand<<"\t\t"<<car.name<<"\t\t"<<car.year<<"\t\t"<<car.mileage<<"\t\t"
        <<car.price<<"\t\t"<<car.color<<"\t\t"<<car.capacity<<std::endl;
    }
}


void Factory::printListOfMotor(){
    std::cout<<"LISTA MOTOROW"<<std::endl;
    std::cout<<"Ilosc motorow: "<<motor_list.size()<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"ID"<<"\t\t"<<"MARKA\t"<<"NAZWA\t"<<"ROCZNIK\t"<<"PRZEBIEG\t"<<"CENA\t"<<"COLOR\t"<<"CAPACITY\t"
    <<std::endl;
    for(Motor car:motor_list)
    {
        std::cout<<car.ID<<"\t\t"<<car.brand<<"\t\t"<<car.name<<"\t\t"<<car.year<<"\t\t"<<car.mileage<<"\t\t"
        <<car.price<<"\t\t"<<car.color<<"\t\t"<<car.capacity<<std::endl;
    }
}



//usowanie samochodu z vektora car_list
void Factory::remove_car(){
    int index;
    std::cout<<"Ktory samochod chcesz usunac(Podaj ID):"<<std::endl;
    cinException_int.wpisz(index);
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
    double new_price;
    std::cout<<"Podaj samochod na sprzedarz: "<<std::endl;
    cinException_int.wpisz(index);
    std::cout<<"Chcesz ustawic nowa cene?(1-tak / 0-nie) "<<std::endl;
    std::cin>>is_for_sell;
    if(is_for_sell){
        std::cout<<"Podaj nowa cene: "<<std::endl;
        cinException_double.wpisz(new_price);
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
        std::cout<<car.brand<<"\t\t"<<car.name<<"\t\t"<<car.year<<"\t\t"<<car.mileage<<"\t\t"
        <<car.price<<std::endl;
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
             << car.price<<","
             << car.color<<","
             << car.capacity
             << "\n";
    }
    csvka.close();
}
void Factory::save_to_csv_motor(){
    fstream csvka;
    csvka.open("motor_in_stock.csv", ios::out | ios::app);
    for(Motor car : motor_list)
    {
        csvka <<car.ID  << ", "
              << car.brand << ", "
              << car.name << ", "
              << car.year << ", "
              << car.mileage << ", "
              << car.fuel_usage << ", "
              << car.max_fuel_level <<", "
              << car.price<<","
              << car.color<<","
              << car.capacity
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
              << car.price <<","
              << car.color<<","
              << car.capacity
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
void Factory::download_cars_from_csv(const char* pliko){
    using namespace std;
    string file_name;
    string D_name, D_brand, D_ID, D_year, D_mileage, D_fuelUsage, D_maxFuelLevel, D_price, D_color, D_capacity;
    if(pliko == nullptr) {
        cout << "Wproadz nazwe pliku csv wraz z rozszerzeniem: ";
        cin >> file_name;
    }else{
        file_name=pliko;
    }
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
            content[i][0] = D_ID;
            D_name = content[i].at(1);
            D_name.erase(remove(D_name.begin(), D_name.end(), ' '), D_name.end());
            content[i][1] = D_name;
            D_brand = content[i].at(2);
            D_brand.erase(remove(D_brand.begin(), D_brand.end(), ' '), D_brand.end());
            content[i][2] = D_brand;
            D_year = content[i].at(3);
            D_year.erase(remove(D_year.begin(), D_year.end(), ' '), D_year.end());
            content[i][3] = D_year;
            D_mileage = content[i].at(4);
            D_mileage.erase(remove(D_mileage.begin(), D_mileage.end(), ' '), D_mileage.end());
            content[i][4] = D_mileage;
            D_fuelUsage = content[i].at(5);
            D_fuelUsage.erase(remove(D_fuelUsage.begin(), D_fuelUsage.end(), ' '), D_fuelUsage.end());
            content[i][5] = D_fuelUsage;
            D_maxFuelLevel = content[i].at(6);
            D_maxFuelLevel.erase(remove(D_maxFuelLevel.begin(), D_maxFuelLevel.end(), ' '),D_maxFuelLevel.end());
            content[i][6] = D_maxFuelLevel;
            D_price = content[i].at(7);
            D_price.erase(remove(D_price.begin(), D_price.end(), ' '), D_price.end());
            content[i][7] = D_price;
            D_color = content[i].at(8);
            D_color.erase(remove(D_color.begin(), D_color.end(), ' '), D_color.end());
            content[i][8] = D_color;
            D_capacity = content[i].at(9);
            D_capacity.erase(remove(D_capacity.begin(), D_capacity.end(), ' '), D_capacity.end());
            content[i][9] = D_capacity;
        }
        int i_id, i_year;
        float f_milage, f_fuelUsage, f_maxFuelLevel, f_capacity;
        double d_price;
        i_id = atoi(D_ID.c_str());
        i_year = atoi(D_year.c_str());
        f_milage = stof(D_mileage);
        f_fuelUsage = stof(D_fuelUsage) ;
        f_maxFuelLevel = stof(D_maxFuelLevel) ;
        f_capacity = stof(D_capacity);
        d_price = stod(D_price);
        car_list.push_back(createCar1<Car>(i_id, i_year, f_milage, f_fuelUsage, f_maxFuelLevel, d_price,
                                           D_brand, D_name, D_color, f_capacity));

    }
    cout<<"Samochody zostaly wczytane!!!\n";
}

void Factory::download_cars_from_csv_motor(const char* pliko){
    using namespace std;
    string file_name;
    string D_name, D_brand, D_ID, D_year, D_mileage, D_fuelUsage, D_maxFuelLevel, D_price, D_color, D_capacity;
    if(pliko=="0") {
        cout << "Wproadz nazwe pliku csv wraz z rozszerzeniem: ";
        cin >> file_name;
    }else{
     file_name=pliko;
    }

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
            D_color = content[i].at(8);
            D_color.erase(remove(D_color.begin(), D_color.end(), ' '), D_color.end());
            D_capacity = content[i].at(9);
            D_capacity.erase(remove(D_capacity.begin(), D_capacity.end(), ' '), D_capacity.end());

        }
        int i_id, i_year;
        float f_milage, f_fuelUsage, f_maxFuelLevel, f_capacity;
        double d_price;
        i_id = atoi(D_ID.c_str());
        i_year = atoi(D_year.c_str());
        f_milage = stof(D_mileage);
        f_fuelUsage = stof(D_fuelUsage) ;
        f_maxFuelLevel = stof(D_maxFuelLevel) ;
        f_capacity = stof(D_capacity);
        d_price = stod(D_price);
        motor_list.push_back(createCar1<Motor>(i_id, i_year, f_milage, f_fuelUsage, f_maxFuelLevel, d_price,
                                               D_brand, D_name, D_color, f_capacity));

    }
    cout<<"Motory zostaly wczytane!!!\n";
}

// metoda kopiujaca samochod
void Factory::copy_car(){
    Car x;
    int index;
    std::cout<<"Podaj index samochodu ktory chcesz skopiowac\n";
    cinException_int.wpisz(index);
    x = car_list.at(index);
    Car y(x);
    y.ID = car_list.size() + 1;
    car_list.push_back(y);
    std::cout<<"Skopiowany\n";
}
void Factory::copy_motor(){
    Motor x;
    int index;
    std::cout<<"Podaj index motoru ktory chcesz skopiowac\n";
    cinException_int.wpisz(index);
    x = motor_list.at(index);
    Motor y(x);
    y.ID = motor_list.size() + 1;
    motor_list.push_back(y);
    std::cout<<"Skopiowany\n";
}

void Factory::vehicle_color_change(){
    using namespace std;
    int choice, index;
    cout<<"Podaj rodzaj pojazdu którego chcesz zmienic kolor:\n(1) Samochod \n(2) Motor "<<endl;
    cinException_int.wpisz(choice);
    std::cout<<"Podaj index pojazdu ktorego chcesz zminic kolor\n";
    cinException_int.wpisz(index);
    Car *car = &car_list[index];
    Motor *motor = &motor_list[index];
    cout<<car<<endl;
    switch (choice) {
        case 1:
            varnisher.changeColor_of_car(car);
            break;
        case 2:
            varnisher.changeColor_of_motor(motor);
            break;
        default:
            cout<<"Nie ma takiego typu pojazdow"<<endl;
            break;
    }
}

void Factory::predict_price_car(){
    int index;
    komis.extract_car(car_list);
    index = komis.predict1(car_list);
    if(index!=0) {
        car_list.erase(car_list.begin() + index - 1);
    } else{
        car_list.erase(car_list.begin() + index);
    }

}
void Factory::predict_price_motor(){
    int index;
    komis.extract_motor(motor_list);
    index = komis.predict2(motor_list);
    if(index!=0) {
        motor_list.erase(motor_list.begin() + index - 1);
    } else{
        motor_list.erase(motor_list.begin() + index);
    }
}
void Factory::print_komis_list(){
    komis.print_list_vehicle();
}

void Factory::sprzedaj_poj_kom(){
    komis.sprzedaj();
}

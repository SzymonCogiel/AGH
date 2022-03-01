//
// Created by szymon on 19.12.2021.
//

#ifndef COGIELSZYMON_ETAP1_KOMIS_H
#define COGIELSZYMON_ETAP1_KOMIS_H
#include <vector>
#include "Car.h"
#include "Motor.h"
#include <numeric>
#include <math.h>
//#include "Regressor.h"
#include "Cin_exception.h"

using namespace std;
class Komis {
public:
   Komis(const vector<Car> &listaSamochodowKomis, const vector<Motor> &listaMotorowKomis);

    vector<Car>lista_samochodow_komis;
    vector<Motor> lista_motorow_komis;
    vector<Car> kupione_samochody;
    vector<Motor> kupione_motory;

    Cin_exception<int> wczyt;

    std::vector<string>v_nazw;
    std::vector<double>error;
    std::vector<double>x0;
    std::vector<double>x1;
    std::vector<double>x2;
    std::vector<double>x3;
    std::vector<double>y;


    int _size;
    double err;
    double b0 = 0;
    double b1 = 0;
    double b2 = 0;
    double b3 = 0;
    double b4 = 0;
    double alpha = 0.01;


    int predict1(const vector<Car> &list_veh);
    int predict2(const vector<Motor> &list_veh);
    static bool sortowanko(double a, double b);
    void extract_car(std::vector<Car> vect);
    void extract_motor(std::vector<Motor> vect);
    void print_list_vehicle();
    void sprzedaj();
    void predict();

};


#endif //COGIELSZYMON_ETAP1_KOMIS_H

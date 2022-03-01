//
// Created by szymon on 03.01.2022.
//

#ifndef COGIELSZYMON_ETAP2_UTILS_H
#define COGIELSZYMON_ETAP2_UTILS_H

#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>


static int counter = 0; /* global static variable not visible outside this file.*/

std::string dane_z_pliku(std::vector<std::string> &vec, std::string &result);
int dane_z_pliku_int(std::vector<std::string> &vec, int &result);
double dane_z_pliku_double(std::vector<std::string> &vec, double &result);
float dane_z_pliku_float(std::vector<std::string> &vec, float &result);


#endif //COGIELSZYMON_ETAP2_UTILS_H

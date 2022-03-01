
//
// Created by szymon on 03.01.2022.
//

#include "utils.h"

std::string dane_z_pliku(std::vector<std::string> &vec, std::string &result) {
    result = vec.at(counter);
    std::cout<<vec.at(counter)<<std::endl;
    counter++;
    return result;
}

int dane_z_pliku_int(std::vector<std::string> &vec, int &result) {
    result = std::stoi(vec.at(counter));
    std::cout<<vec.at(counter)<<std::endl;
    counter++;
    return result;
}

double dane_z_pliku_double(std::vector<std::string> &vec, double &result) {
    result = std::stod(vec.at(counter));
    std::cout<<vec.at(counter)<<std::endl;
    counter++;
    return result;
}

float dane_z_pliku_float(std::vector<std::string> &vec, float &result) {
    result = std::stof(vec.at(counter));
    std::cout<<vec.at(counter)<<std::endl;
    counter++;
    return result;
}

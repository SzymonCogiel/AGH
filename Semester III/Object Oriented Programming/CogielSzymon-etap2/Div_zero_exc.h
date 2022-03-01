//
// Created by szymon on 29.12.2021.
//

#ifndef COGIELSZYMON_ETAP2_DIV_ZERO_EXC_H
#define COGIELSZYMON_ETAP2_DIV_ZERO_EXC_H


#include <iostream>
#include <stdexcept>
using namespace std;

class Exception : public runtime_error {
public:
    Exception()
            : runtime_error("Math error: Attempted to divide by Zero\n") {
    }
};


#endif //COGIELSZYMON_ETAP2_DIV_ZERO_EXC_H

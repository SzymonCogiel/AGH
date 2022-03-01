//
// Created by szymon on 29.12.2021.
//

#ifndef COGIELSZYMON_ETAP2_CIN_EXCEPTION_H
#define COGIELSZYMON_ETAP2_CIN_EXCEPTION_H

#include <iostream>
using namespace std;

template<typename T>
struct Cin_exception {
    void wpisz(T &x);
};
template<typename T>
void Cin_exception<T>::wpisz(T &x) {
    bool sedz = true;
    while (sedz) {
        cin >> x;
        sedz = false;
        try {
            if (cin.fail()) {
                throw "error wipisz dane numeryczne";
            }
            if (x < 0) {
                cout << "wpisz numer wiekszy lub rowny 0" << endl;
                sedz = true;
            }
        }
        catch (const char *error) {
            cout << error << endl;
            // std::cin.clear() czysci flage bledu
            std::cin.clear();
            //std::cin.ignore() ignoruje znaki w strumieniu wejsciowym
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //'\n'ustawia ogranicznik, czyli znak, po którym cin przestaje ignorować
            //numeric_limits<streamsize>::max()ustawia maksymalną liczbę znaków do zignorowania.
            // Ponieważ jest to górny limit rozmiaru strumienia, w praktyce oznacza to, że cin nie ma limitu liczby znaków do zignorowania.
            break;
        }
    }
}

#endif //COGIELSZYMON_ETAP2_CIN_EXCEPTION_H

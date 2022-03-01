#include <iostream>
#include "Factory.h"
#include "utils.h"
#include "Cin_exception.h"

std::vector<string> vec_wsa;
std::vector<string>* v = &vec_wsa;


void wczytanie(std::string &pliczek, std::string &name, std::string &city){
    std::string x;
    std::vector<string> vec;
    ifstream inFile;
    inFile.open(pliczek);
    if (!inFile) {
        cerr << "Nie da sie otworzyc datafactory.txt";
        exit(1);
    }
    while (inFile >> x) {
        vec.push_back(x);
    }
    name = vec.at(0);
    city = vec.at(1);
    inFile.close();
}



struct Dane_Fabryki{
  string _name;
  string _city;
};

void set_factory(Dane_Fabryki &x) {
    cout << "Stworz fabryke samochodow" << endl;
    cout << "Podaj nazwe fabryki: " << endl;
    cin >> x._name;
    cout << "Podaj lokalizacjie fabryki (miasto): " << endl;
    cin >> x._city;
}

Factory create_factory(){
    Dane_Fabryki x;
    set_factory(x);
    Factory new_fac(x._city, x._name);
    return new_fac;
}
void wczytanie_pliku_wsadowego(const char* pliczek, std::vector<std::string> &vec){
    std::string x;
    ifstream inFile;
    inFile.open(pliczek);
    if (!inFile) {
        cerr << "Nie da sie otworzyc datafactory.txt";
        exit(1);
    }
    while (inFile >> x) {
        vec.push_back(x);
    }
    inFile.close();
}



int main(int argc, char* argv[]) {
    using namespace std;
    int choice, choice2;
    int index_fab=0;
    string name, city, plik_fabtyka;
    std::vector<Factory> lista_fabryk;
    Cin_exception<int> cinException_int;


    if(argc==2) {

        wczytanie_pliku_wsadowego(argv[1], vec_wsa);
        cout<<"Wczytano plik wsadowy!!!"<<endl;
    }else{
        cout<<"nie podano pliku wsadowego stwórz sam fabryke"<<endl;
    }
    if(argc==2) {
        plik_fabtyka = dane_z_pliku(vec_wsa,plik_fabtyka);
        wczytanie(plik_fabtyka, name, city);
    }else{
        cout << "Stworz fabryke samochodow" << endl;
        cout << "Podaj nazwe fabryki: " << endl;
        cin >> name;
        cout << "Podaj lokalizacjie fabryki (miasto): " << endl;
        cin >> city;
    }
    Factory f(city, name);
    lista_fabryk.push_back(f);

    do {
        cout << "======================MENU=========================" << endl;
        cout<<"(1) Produkcja i spis pojazdow\n"<<"(2) Operacje na plikach\n"<<"(3) Eksploracja samochodu\n"
        <<"(4) Eksploracja motoru\n"<<"(5) Komis\n"<<"(6) Lakiernik\n"<<"(7) Jazda na rowerze\n"<<"(8) Zmien uzywana fabryke\n"<<"(9) Stworz nowa fabryke\n"<<"(0) Zakoncz prace"<<endl;
        if(counter<vec_wsa.size()){
          choice = dane_z_pliku_int(vec_wsa, choice);
        } else{
            cinException_int.wpisz(choice);
        }
        switch (choice) {
            case 1:
                cout<<"\n\n\n\n"<<"=================PRODUKCJA_I_SPIS_POJAZDOW====================="<<endl;
                cout<<"(1) Wyprodukuj samochod lub motor\n"<<"(2) Wyświetl liste wyprodukowanych samochodow\n"<<"(3) Wyświetl liste wyprodukowanych motorow\n"
                <<"(4) Wyswietl liste wyprodukowanych rowerow\n"<<"(5) Wyswietl liste samochodow na sprzedaz\n"<<"(6) Wyswietl informacje na temat fabryki\n"
                <<"(7) Wyprodukuj rower\n"<<"(8) Wroć do menu"<<endl;
                if(counter<vec_wsa.size()){
                    choice2 = dane_z_pliku_int(vec_wsa, choice);
                } else {
                    cinException_int.wpisz(choice2);
                }
                switch (choice2) {
                    case 1:
                        try {
                            lista_fabryk.at(index_fab).produce();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 2:
                        try{
                            lista_fabryk.at(index_fab).printListOfCar();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 3:
                        try{
                            lista_fabryk.at(index_fab).printListOfMotor();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 4:
                        try{
                            lista_fabryk.at(index_fab).printListOfBike();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 5:
                        try{
                        lista_fabryk.at(index_fab).printListOfCarForSell();
                        }
                            catch (const std::out_of_range& oor) {
                        std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 6:
                        cout<<lista_fabryk.at(index_fab)<<endl;
                        break;
                    case 7:
                        try{
                        lista_fabryk.at(index_fab).produce_bike();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                counter=90;
                cout<<"\n\n\n\n"<<"=================OPERACJE_NA_PLIKACH====================="<<endl;
                cout<<"(1) Wyswietl pozazdy z plikow\n"<<"(2) Pobierz liste samochodow z pliku\n"
                <<"(3) Pobierz liste motorow z pliku\n"<<"(4) Zapisz samochody do plku\n"<<"(5) Zapisz motory do pliku\n"
                <<"(6) Zapisz sprzedane samochody do pliku\n"<<"(8) Wroć do menu"<<endl;
                cinException_int.wpisz(choice2);
                switch (choice2) {
                    case 1:
                        try{
                            lista_fabryk.at(index_fab).read_record_from_csv();
                            }
                            catch (const std::out_of_range& oor) {
                                std::cerr << "Out of Range error: " << oor.what() << '\n';
                            }
                        break;
                    case 2:
                        try{
                        lista_fabryk.at(index_fab).download_cars_from_csv();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 3:
                        try{
                        lista_fabryk.at(index_fab).download_cars_from_csv_motor();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 4:
                        try{
                        lista_fabryk.at(index_fab).save_to_csv();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 5:
                        try{
                        lista_fabryk.at(index_fab).save_to_csv_motor();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 6:
                        try{
                        lista_fabryk.at(index_fab).save_to_csv_sell();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                    default:
                        break;
                }
                break;
            case 3:
                cout<<"\n\n\n\n"<<"=================EKSPLORACJA_SAMOCHODOW====================="<<endl;
                cout<<"(1) Uzyj samochodu \n"<<"(2) Wyprodukuj samochod na wzor innego istniejacego samochodu\n"
                    <<"(3) Usun samochod\n"<<"(4) Wyslij samochod na sprzedaz\n"<<"(5) Wroć do menu"<<endl;
                counter=90;
                cinException_int.wpisz(choice2);
                switch (choice2) {
                    case 1:
                        try{
                        lista_fabryk.at(index_fab).car_exploration();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 2:
                        try{
                        lista_fabryk.at(index_fab).copy_car();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 3:
                        try{
                        lista_fabryk.at(index_fab).remove_car();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 4:
                        try{
                        lista_fabryk.at(index_fab).sent_to_sell();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                cout<<"\n\n\n\n"<<"=================EKSPLORACJA_MOTOROW====================="<<endl;
                cout<<"(1) Uzyj motoruu \n"<<"(2) Wyprodukuj motor na wzor innego istniejacego motoru\n"
                    <<"(3) Powrot do menu"<<endl;
                cinException_int.wpisz(choice2);
                switch (choice2) {
                    case 1:
                        try{
                        lista_fabryk.at(index_fab).motor_exploration();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 2:
                        try{
                        lista_fabryk.at(index_fab).copy_motor();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                cout<<"\n\n\n\n"<<"=================KOMIS====================="<<endl;
                cout<<"(1) Wyswietl pojazdy w komisie \n"<<"(2) Przewidz cene i potencjalnie kup samochod\n"
                    <<"(3) Przewidz cene i potencjalnie kup motoru\n"<<"(4) Sprzedaj pojazd\n"<<"(5) Powrot do menu"<<endl;
                cinException_int.wpisz(choice2);
                switch (choice2) {
                    case 1:
                        try{
                        lista_fabryk.at(index_fab).print_komis_list();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 2:
                        try{
                        lista_fabryk.at(index_fab).predict_price_car();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 3:
                        try{
                        lista_fabryk.at(index_fab).predict_price_motor();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 4:
                        try{
                        lista_fabryk.at(index_fab).sprzedaj_poj_kom();
                        }
                        catch (const std::out_of_range& oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 6:
                try{
                lista_fabryk.at(index_fab).vehicle_color_change();
                }
                catch (const std::out_of_range& oor) {
                    std::cerr << "Out of Range error: " << oor.what() << '\n';
                }
                break;
            case 7:
                cout<<"\n\n\n\n"<<"=================ROWER====================="<<endl;
                cout<<"(1) Jedz \n"<<"(2) Dodaj koszyk\n"
                    <<"(3) Powrot do menu"<<endl;
                cinException_int.wpisz(choice2);
                switch (choice2) {
                    case 1:
                    try {
                        lista_fabryk.at(index_fab).ride_bike();
                    }
                    catch (const std::out_of_range &oor) {
                        std::cerr << "Out of Range error: " << oor.what() << '\n';
                    }
                        break;
                    case 2:
                        try {
                        lista_fabryk.at(index_fab).addBasket();
                        }
                        catch (const std::out_of_range &oor) {
                            std::cerr << "Out of Range error: " << oor.what() << '\n';
                        }
                        break;
                    case 3:
                        break;
                }
            case 8:
                cout<<"Podaj index fabryki ktorej bedziesz uzywac\n";
                if(counter<vec_wsa.size()){
                    index_fab = dane_z_pliku_int(vec_wsa, index_fab);
                } else {
                    cinException_int.wpisz(index_fab);
                }
                break;
            case 9:
                try{
                lista_fabryk.push_back(create_factory());
                }
                catch (const std::out_of_range& oor) {
                    std::cerr << "Out of Range error: " << oor.what() << '\n';
                }
                break;
            default:
                cout << "Nie nie ma takiej operacji \n" << choice << endl;
                break;
        }
    } while (choice != 0);

    cout<<"Dziekujemy za uzytkowanie programu :)"<<endl;
    return 0;
}
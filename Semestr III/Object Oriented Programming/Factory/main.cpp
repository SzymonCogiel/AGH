#include <iostream>
#include <tuple>
#include "Factory.h"

tuple<string, string> plik_wsadowy_dla_factory();
int main() {
    using namespace std;

    int choice;
    //string name, city;

    auto [city, name] = plik_wsadowy_dla_factory(); // aby automatyzowac prace programu i pominac zbedne wpisywanie cin
//    cout<<"Stworz fabryke samochodow"<<endl;
//    cout<<"Podaj nazwe fabryki: "<<endl;
//    cin>>name;
//    cout<<"Podaj lokalizacjie fabryki (miasto): "<<endl;
//    cin>>city;
    Factory f(city, name);
    do {
        cout << "======================MENU=========================" << endl;
        cout << "(1) Wyprodukuj samochod\n" << "(2) Pokaz liste wyprodukowanych samochodow\n"
             << "(3) Wyslij samochod na liste samochodow do sprzedazy\n"
             << "(4) Wyswietl liste samochodow na sprzedaz\n" << "(5) Usun samochod z listy wyprodukowanych samochodow\n"
             << "(6) Zapisz liste wyprodukowanych samochodow do pliku csv\n"
             << "(7) Zapisz liste samochodow na sprzedaz do pliku csv\n"
             << "(8) Eksploruj/Testuj samochod(z listy wprodukowanych samochodow)\n" << "(9) Wyswietl samochody z pliku\n"
             <<"(10) Wczytaj samochody z pliku do programu\n"<<"(11) Wyswietl informacje na temat fabryki\n"<<"(12) Wyprodukuj samochod na wzor innego istniejacego samochodu\n"<< "(0) Zakoncz program\n";
        cin >> choice;
        switch (choice) {
            case 1:
                f.produce();
                break;
            case 2:
                f.printListOfCar();
                break;
            case 3:
                f.sent_to_sell();
                break;
            case 4:
                f.printListOfCarForSell();
                break;
            case 5:
                f.remove_car();
                break;
            case 6:
                f.save_to_csv();
                break;
            case 7:
                f.save_to_csv_sell();
                break;
            case 8:
                f.car_exploration();
                break;
            case 9:
                f.read_record_from_csv();
                break;
            case 10:
                f.download_cars_from_csv();
                break;
            case 11:
                cout<<f<<endl;
                break;
            case 12:
                f.copy_car();
                break;
            default:
                cout << "Nie nie ma operazji o numerze: " << choice << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

tuple<string, string> plik_wsadowy_dla_factory(){

    std::string x, name, city;
    std::vector<string> vec;
    ifstream inFile;
    inFile.open("datafactory.txt");
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
    return make_tuple(city, name);// w nowym standarfzie nie trzeba make tuple wystarczy {}
}

//
// Created by szymon on 19.12.2021.
//

#include "Komis.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>


Komis::Komis(const vector<Car> &listaSamochodowKomis, const vector<Motor> &listaMotorowKomis) : lista_samochodow_komis(
        listaSamochodowKomis), lista_motorow_komis(listaMotorowKomis) {}


bool Komis::sortowanko(double a, double b){
    double  a1=abs(a-0);
    double  b1=abs(b-0);
    return a1<b1;
}
int Komis::predict1(const vector<Car> &list_veh) {
    using namespace std;
    int index;
    double Xmean,Ymean, m, b, predict, test, sum_var, stdiv, tolerancja_zakupu;
    double sumXmean=0;
    double sumYmean=0;
    double sumaa=0;
    double sum_qua=0;
    if(x1.empty()){
        Xmean=0;
        Ymean=0;
    }else {
        double const count = static_cast<double>(x1.size());
        Xmean = std::reduce(x1.begin(), x1.end()) / count;
        Ymean = std::reduce(y.begin(), y.end()) / count;
    }
    for(int i=0; i<x1.size();i++){
        sumXmean = x1.at(i)- Xmean;
        sumYmean = y.at(i) - Ymean;
        sumaa += sumXmean * sumYmean;
        sum_qua += pow(sumXmean, 2);
    }
    m = sumaa/sum_qua;
    b = Ymean - m*Xmean;
    cout<<"Podaj index samochodu/motoru który chcesz sprzedac: "<<endl;
    wczyt.wpisz(index);
    if(v_nazw.at(index) == "Porche") {
        test = x1.at(index) / 2;
    }else{
        test = x1.at(index);
    }
    predict = m * test + b;

    cout<<"predykcja: "<<predict<<endl;

    for(int i=0; i <y.size();i++){
        sum_var += pow(y.at(i)-Ymean, 2);
    }

    stdiv = sqrt((sum_var/(x1.size()-1)));
    tolerancja_zakupu = stdiv / 4;
    cout<<"tolerancja: "<<tolerancja_zakupu<<endl;

    if(y.at(index) < predict + tolerancja_zakupu)
    {
        cout<<"Kupiony za "<< y.at(index) <<endl;
        kupione_samochody.push_back(list_veh[index]);
        double cena = y.at(index) + y.at(index) * 0.1;
        kupione_samochody.at(kupione_samochody.size() - 1).setPrice(cena);
        return index;
    } else{
        cout<<"ZA DROGI"<<endl;
        return -1;
    }

}

int Komis::predict2(const vector<Motor> &list_veh) {
    using namespace std;
    int index;
    double Xmean,Ymean, m, b, predict, test, sum_var, stdiv, tolerancja_zakupu;
    double sumXmean=0;
    double sumYmean=0;
    double sumaa=0;
    double sum_qua=0;
    if(x1.empty()){
        Xmean=0;
        Ymean=0;
    }else {
        double const count = static_cast<double>(x1.size());
        Xmean = std::reduce(x1.begin(), x1.end()) / count;
        Ymean = std::reduce(y.begin(), y.end()) / count;
    }
    for(int i=0; i<x1.size();i++){
        sumXmean = x1.at(i)- Xmean;
        sumYmean = y.at(i) - Ymean;
        sumaa += sumXmean * sumYmean;
        sum_qua += pow(sumXmean, 2);
    }
    m = sumaa/sum_qua;
    b = Ymean - m*Xmean;
    cout<<"Podaj index samochodu/motoru który chcesz sprzedac: "<<endl;
    wczyt.wpisz(index);
    if(v_nazw.at(index) == "Porche") {
        test = x1.at(index) / 2;
    }else{
        test = x1.at(index);
    }
    predict = m * test + b;
    cout<<"predykcja: "<<predict<<endl;
    for(int i=0; i <y.size();i++){
        sum_var += pow(y.at(i)-Ymean, 2);
    }
    stdiv = sqrt((sum_var/(x1.size()-1)));
    tolerancja_zakupu = stdiv / 4;
    cout<<"tolerancja: "<<tolerancja_zakupu<<endl;
    if(y.at(index) < predict + tolerancja_zakupu)
    {
        cout<<"Kupiony za "<< y.at(index) <<endl;
            kupione_motory.push_back(list_veh[index]);
        double cena = y.at(index) + y.at(index) * 0.2;
        kupione_motory.at(kupione_motory.size() - 1).setPrice(cena);
        return index;
    } else{
        cout<<"ZA DROGI"<<endl;
        return -1;
    }
}

void Komis::predict() {
    using namespace std;

    cout<<_size<<" casd"<<endl;
    for(int i=0; i < _size * 8; i++) // 8 epok uczenia
    {
        int idx = i % _size;
        double p = b0 + b1 * x0.at(idx) + b2 * x1.at(idx) + b3 * x2.at(idx) + b4 * x3.at(idx);
        cout<<"\n"<<p<<" cadsofa"<<endl;
        err = p - y[idx];
        b0 = b0 - alpha * err;
        b1 = b1 - alpha * err * x0.at(idx);
        b2 = b2 - alpha * err * x1.at(idx);
        b3 = b3 - alpha * err * x2.at(idx);
        b4 = b4 - alpha * err * x3.at(idx);
        cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" "<<"B3="<<b3<<" "<<"B4="<<b4<<" "<<"error="<<err<<std::endl;// printing values after every updation
        error.push_back(err);

    }


    sort(error.begin(),error.end(), sortowanko);

    cout<<"Ostateczne współczynniki: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" "<<"B3="<<b3<<" "<<"B4="<<b4<<" "<<"error="<<err<<std::endl;

    cout<<"Wprowadz parametry samochodu ktorego chcesz przewidziec cene: ";
    double test1, test2, test3, test4;
    cin>>test1;
    cin>>test2;
    cin>>test3;
    cin>>test4;
    double pred=b0+b1*test1+b2*test2+b3 * test3 + b4*test4;
    cout<<endl;
    cout<<"The value predicted by the model= "<<pred;
}

void Komis::extract_car(std::vector<Car> vect){
    _size = vect.size();
    for(int i=0; i < _size; i++) {
        v_nazw.push_back(vect.at(i).getBrand());
        x0.push_back((double)(vect.at(i).getYear()));
        x1.push_back(vect.at(i).getMileage());
        x2.push_back(vect.at(i).getFuelUsage());
        x3.push_back(vect.at(i).getMaxFuelLevel());
        y.push_back(vect.at(i).getPrice());
    }
}
void Komis::extract_motor(std::vector<Motor> vect) {
    _size = vect.size();
    for(int i=0; i < _size; i++) {
        v_nazw.push_back(vect.at(i).getBrand());
        x0.push_back(static_cast<double>(vect.at(i).getYear()));
        x1.push_back(vect.at(i).getMileage());
        x2.push_back(vect.at(i).getFuelUsage());
        x3.push_back(vect.at(i).getMaxFuelLevel());
        y.push_back(vect.at(i).getPrice());
    }
}

void Komis::print_list_vehicle(){

    std::cout<<"LISTA MOTOROW"<<std::endl;
    std::cout<<"Ilosc motorow: "<<kupione_motory.size()<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"ID"<<"\t\t"<<"MARKA\t"<<"NAZWA\t"<<"ROCZNIK\t"<<"PRZEBIEG\t"<<"CENA\t"<<"COLOR\t"<<"CAPACITY\t"<<std::endl;
    for(Motor car:kupione_motory)
    {
        std::cout<<car.getID()<<"\t\t"<<car.getBrand()<<"\t\t"<<car.getName()<<"\t\t"<<car.getYear()<<"\t\t"<<car.getMileage()<<"\t\t"<<car.getPrice()<<"\t\t"<<car.getColor()<<"\t\t"<<car.getCapacity()<<std::endl;
    }
    std::cout<<"LISTA SAMOCHODOW"<<std::endl;
    std::cout<<"Ilosc samochodow: "<<kupione_samochody.size()<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"ID"<<"\t\t"<<"MARKA\t"<<"NAZWA\t"<<"ROCZNIK\t"<<"PRZEBIEG\t"<<"CENA\t"<<"COLOR\t"<<"CAPACITY\t"<<std::endl;
    for(Car car:kupione_samochody)
    {
        std::cout<<car.ID<<"\t\t"<<car.getBrand()<<"\t\t"<<car.getName()<<"\t\t"<<car.getYear()<<"\t\t"<<car.getMileage()<<"\t\t"<<car.getPrice()<<"\t\t"<<car.getColor()<<"\t\t"<<car.getCapacity()<<std::endl;
    }
}

void Komis::sprzedaj() {
    int index, choice;
    double price;
    std::cout<<"Chcesz sprzedac samochod czy motor?"<<endl;
    std::cout<<"Samochod wpisz \"1\"\n"<<"Motor wpisz \"0\"\n"<<endl;
    wczyt.wpisz(choice);
    std::cout<<"Podaj index: "<<endl;
    wczyt.wpisz(index);
    if(choice==0){
        price = kupione_motory.at(index).getPrice();
        kupione_motory.erase(kupione_motory.begin() + index);
    }else{
        price = kupione_samochody.at(index).getPrice();
        kupione_samochody.erase(kupione_samochody.begin() + index);
    }
    std::cout<<"SPRZEDANY ZA "<<price<<" zl"<<endl;
}


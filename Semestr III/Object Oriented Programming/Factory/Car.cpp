//
// Created by szymon on 01.12.2021.
//

#include "Car.h"
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#define CENAPALIWA 6.2

//====================================================================================METODY_CAR=================================================================================================



// metoda do zmiany biegow
gears Car::change_gear()
{
    using namespace std;
    gears biegi;
    int wybor;
    std::cout<<"Jaki bieg (0-7)?"<<endl;
    std::cin>>wybor;
    switch (wybor) {
        case 0:
            biegi = gears::luz;
            cout<<"LUZ"<<endl;
            break;
        case 1:
            biegi = gears::jendynka;
            cout<<"I cyk jedyneczka"<<endl;
            break;
        case 2:
            biegi = gears::i_cyk_dwojeczka;
            cout<<"I cyk dwojeczka"<<endl;
            break;
        case 3:
            biegi = gears::trojka;
            cout<<"I pyk trojeczka"<<endl;
            break;
        case 4:
            biegi = gears::czworka;
            cout<<"I pyk 4"<<endl;
            break;
        case 5:
            biegi = gears::piatka;
            cout<<"Łohoho piateczka"<<endl;
            break;
        case 6:
            biegi = gears::szostka;
            cout<<"O cie..."<<endl;
            break;
        case 7:
            biegi = gears::atuomat;
            cout<<"Automacik"<<endl;
            break;
        case 8:
            biegi = gears::wsteczny;
            cout<<"Rakieta"<<endl;
            break;
        default:
            biegi = gears::luz;
            cout<<"LUZ"<<endl;
            break;
    }
    return biegi;
}

// metoda do przyspieszenia
void Car::do_acce(float min_pr, float max_pr,int step, float &speed){
    if(min_pr <= speed && speed <= max_pr){
        for (int i = (int) speed; i < max_pr; )
        {
            i += step;
            std::cout << i << "km/h" << endl;
            speed = (float) i;
        }
    }else{
        std::cout<<"Toja predkosc "<<speed<<"km/h"<<endl;
        std::cout<<"wwrrrrrrrrrr"<<endl;
    }
}

// metoda do przyspieszenia na maxa przy danym biegu
void Car::acceleration_max()
{
    using namespace std;

    float speed = speed_meter;
    gears bieg = change_gear();
    if(bieg == gears::jendynka)
    {
        do_acce(0,20,1,speed);
    }
    if(bieg == gears::i_cyk_dwojeczka)
    {
        do_acce(0,40,1,speed);

    }
    if(bieg == gears::trojka)
    {
        do_acce(40,75,2,speed);
    }
    if(bieg == gears::czworka)
    {
        do_acce(50,110,3,speed);
    }
    if(bieg == gears::piatka)
    {
        do_acce(80,160,4,speed);
    }
    if(bieg == gears::szostka)
    {

        do_acce(100,300,10,speed);
    }
    if(bieg == gears::atuomat)
    {
        do_acce(0,300,10,speed);
    }
    if(bieg == gears::wsteczny)
    {
        if(speed == 0){
            cout<<"Cofam"<<endl;
        }else{
            cout<<"wwrrrrrrrrrr"<<endl;
        }
    }
    speed_meter = speed;
}

// tankowanie do pelnego balu
void Car::full_refueling(){
    using namespace std;
    int poczatkowy = (int)fuel_level;
    if(poczatkowy < max_fuel_level) {
        for (int i = poczatkowy; i <= (int) max_fuel_level; i++) {
                cout << "Poziom baku: " << i << " l" << endl;
            }
        cout << "Do zaplaty " << CENAPALIWA * (max_fuel_level - poczatkowy) << "zl" << endl;
        cout << "OPCJA DO PELNA"<<endl;
        fuel_level = max_fuel_level;
    }else{
        cout<<"Masz juz pelny bak"<<endl;
    }
}

// tankowanie x litrow
void Car::refueling() {
    using namespace std;

    int poczatkowy = (int)fuel_level;
    int ilosc;
    cout<<"Ile litrow chcesz zatankowac lub jak do pelna to wybierz 0"<<endl;
    cin>>ilosc;
    if(poczatkowy < max_fuel_level) {
        if (ilosc == 0) {
            full_refueling();
        } else {
            if((poczatkowy+ilosc)<max_fuel_level) {
                for (int i = 0; i < ilosc; i++) {
                    poczatkowy++;
                    cout << "Poziom baku: " << poczatkowy << "l" << endl;
                }
                cout << "Do zaplaty " << CENAPALIWA * ilosc << "zl" << endl;
                fuel_level += ilosc;
            } else{
                cout<<"Masz za mala pojemnosc nalejemy do pelna"<<endl;
                full_refueling();
            }
        }
    } else{
        cout<<"Masz juz pelny bak"<<endl;
    }
}

// jazda (zwieksza wartosc licznik i zmnijsza wartosc paliwa)
void Car::drive(){
    float km;
    if(speed_meter != 0) {
        std::cout << "Ile km chcesz przejechac?" << std::endl;
        std::cin >> km;
        float spalone = km * (fuel_usage / 100);
        if (spalone >= fuel_level) {
            std::cout << "Masz za malo paliwa" << endl;
        } else {
            fuel_level -= spalone;
            mileage += km;
            std::cout << "Przejechales " << km << " km w " << round(km / speed_meter * 60)
                      << " min ze srednia predkoscia " << speed_meter << "km/h, stan twojego baku wynosi: "
                      << fuel_level << endl;
        }
    } else{
        std::cout<<"Musisz przyspieszyc zeby ruszyc w droge"<<endl;
    }
}

// hamowanie
void Car::containment()
{
    std::cout<<"Hamujemy"<<endl;
    speed_meter=0;
}

//=================================================================================KONSTRUKTORY===========================================================================================================


Car::Car(int year, float mileage, float fuelUsage, float maxFuelLevel,
         const string &brand, const string &name, double price, float fuelLevel, float speedMeter) : year(year), mileage(mileage), fuel_usage(fuelUsage),
                                                                                                     fuel_level(fuelLevel), max_fuel_level(maxFuelLevel),
                                                                                                     speed_meter(speedMeter), brand(brand), name(name), price(price){

}

Car::Car(const Car &car) : year(car.year), mileage(car.mileage), fuel_usage(car.fuel_usage),
                           fuel_level(car.fuel_level), max_fuel_level(car.max_fuel_level),
                           speed_meter(car.speed_meter), brand(car.brand), name(car.name), price(car.price), ID(car.ID){

}


//============================================================================GETTERY======================================================================================================
float Car::getFuelLevel() const {
    return fuel_level;
}

const string &Car::getBrand() const {
    return brand;
}

const string &Car::getName() const {
    return name;
}

int Car::getYear() const {
    return year;
}

float Car::getMileage() const {
    return mileage;
}

float Car::getFuelUsage() const {
    return fuel_usage;
}

float Car::getMaxFuelLevel() const {
    return max_fuel_level;
}

float Car::getSpeedMeter() const {
    return speed_meter;
}

//==================================================================================SETERRY===============================================================================================
void Car::setPrice(double price) {
    Car::price = price;
}



//===============================================BIBLIOTEKA SDL JAKBY NIE DZIALALO NA INNYCH KOMPACH USUNAC====================================================================
struct AudioData
{
    Uint8* position; // length of our sample
    Uint32 length;
};

//userdata	parametr specyficzny dla aplikacji przechowywany w polu userdata struktury SDL_AudioSpec.
//stream	wskaźnik bufora danych audio wypełnianego przez SDL_AudioCallback().
//len	długość tego bufora w bajtach.
//Gdy nastąpi powrót z funkcji wywoływanej zwrotnie zawartość bufora nie będzie już ważna. Sample stereo są przechowywane w kolejności LPLPLP...
//Funkcja wywoływana zwrotnie musi całkowicie zainicjować ten bufor, w SDL 2.0 nie jest on inicjowany przed skorzystaniem z funkcji wywoływanej zwrotnie. Jeśli nie ma nic do zagrania, funkcja wywoływana zwrotnie powinna wypełnić bufor ciszą (z pola silence struktury).
void audioCallback(void* userData, Uint8* stream, int streamLength)
{
    AudioData* audio = (AudioData*)userData;

    if (audio->length == 0)
    {
        return;
    }

    Uint32 length = (Uint32)streamLength;

    length = (length > audio->length ? audio->length : length);

    SDL_memcpy(stream, audio->position, length); // to samo co memcpy Kopiuje num bajtów z miejsca wskazywanego przez source do pamięci wskazywanej przez destination. arg 1 Wskaźnik na pamięć, do której nastąpi kopiowanie., arg 2 Wskaźnik na pamięć, z której nastąpi kopiowanie., arg 3 Liczba bajtów do skopiowania.

    audio->position += length;
    audio->length -= length;
}


int Car::radio() {
    SDL_InitSubSystem(SDL_INIT_AUDIO);

    SDL_AudioSpec wavSpec; //format danych dwiekowych
    Uint8* wavStart; //8 bitowa liczba bez znaku 	0...255
    Uint32 wavLength; //32 bitowa liczba bez znaku  0...4294967295
    const char* filePath = "KK_CHCIALBYM.wav"; // W_PORCIE.wav  // wskaznik do pliku

    if(SDL_LoadWAV(filePath, &wavSpec, &wavStart, &wavLength) == nullptr) // SDL_LoadWAV(const char * file, SDL_AudioSpec* spec, Uint8** audio_buf, Uint32* audio_len) 1 nazwa pliku, 2 format audio, bufor audio, dlugosc bufora audio w bajtach
    {
        std::cout<< "plik nie mógł zostać załadowany jako plik audio." << std::endl;
    }
    //filePath sciezka do pliku, &wavSpec to struktura SDL_AudioSpec reprezentujaca pożądany format wyjsciowy, &wavStart po funkcji SDL_LoadWAV jest wypelnona wskaznikiem do przydzielonego bufora zawierajjacego dane dzwiekowe, audio len jest wypelnane dlugoscia tego bufora


    AudioData audio; //nowa istancja struktury Audio data
    audio.position = wavStart; //ustawiamy paramatry posion jako wavStart  wavStart zostalo zapelnone wartoscia poprzez SDL_LoadWAV
    audio.length = wavLength;  //ustawiamy paramatry length jako wavLength  wavLength zostalo zapelnone wartoscia poprzez SDL_LoadWAV


    wavSpec.callback = audioCallback; //SDL_AudioCallback	callback	funkcja wywoływana zwrotnie do wywołania, gdy urządzenie audio potrzebuje więcej danych;
    wavSpec.userdata = &audio; //struktura

    SDL_AudioDeviceID audioDevice;
    audioDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
    //Zwraca ważny identyfikator ID urządzenia, który przy sukcesie jest większy od 0, a równy 0 przy niepowodzeniu; wywołaj funkcję SDL_GetError(), aby otrzymać więcej informacji na temat błędu.
    //Użyj tej funkcji, aby otworzyć określone urządzenie dźwiękowe.
    //Jeśli twoja aplikacja może obsługiwać tylko jeden określony format danych, prześlij zero w parametrze allowed_changes i pozwól SDL przezroczyście zająć się obsługą różnic.
    // SDL_OpenAudioDevice funkcja zwaracajaca zmienna typu SDL_AudioDeviceID, iscapture	wartość niezerowa określa, że urządzenie powinno zostać otwarte do nagrywania, nie do odtwarzania dźwięku
    // desired struktura SDL_AudioSpec reprezentująca pożądany format wyjściowy; więcej szczegółów w opisie SDL_OpenAudio()

    SDL_PauseAudioDevice(audioDevice, 0);//wlącza glosniki jak jest 0

    // poczekaj, aż przestaniemy grać
    while (audio.length > 0)  //odtwarzaj dopuki dlugosc pioseki nie osignie 0, 30000000
    {
        SDL_Delay(100);
    }



    SDL_CloseAudioDevice(audioDevice); // wylacz urzadzenia
    SDL_FreeWAV(wavStart); // zwolnij pamiec od wavStart
    SDL_Quit();//Wyczyść wszystkie zainicjowane podsystemy.

    return 0;
}



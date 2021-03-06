//
// Created by szymon on 01.12.2021.
//

#include "Car.h"
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>


//====================================================================================METODY_CAR=================================================================================================


//=================================================================================KONSTRUKTORY===========================================================================================================

Car::Car(int year, float mileage, float fuelUsage, float maxFuelLevel,
    const string &brand, const string &name, double price,  string color, float capacity, float fuelLevel, float speedMeter) : Motor_vehicle(year,
                                                                                                              mileage,
                                                                                                              fuelUsage,
                                                                                                              maxFuelLevel,
                                                                                                              brand, name,
                                                                                                              price, fuelLevel,
                                                                                                              speedMeter, color, capacity){

}
Car::Car(const Car &car) : Motor_vehicle(car){

}





//============================================================================GETTERY======================================================================================================
const string &Car::getBrand() const {
    return brand;
}

const string &Car::getName() const {
    return name;
}
const string &Car::getColor() const {
    return color;
}

int Car::getYear() const {
    return year;
}
int Car::getID() const{
    return ID;
}

float Car::getMileage() const {
    return mileage;
}
float Car::getCapacity() const {
    return capacity;
}


float Car::getFuelUsage() const {
    return fuel_usage;
}

float Car::getMaxFuelLevel() const {
    return max_fuel_level;
}
double Car::getPrice() const{
    return price;
}

//==================================================================================SETERRY===============================================================================================
void Car::setPrice(double price) {
    Car::price = price;
}

void Car::setColor(){
    string _color;
    std::cout<<"Podaj nowy kolor samochodu: ";
    std::cin>>_color;
    color = _color;
}




//===============================================BIBLIOTEKA SDL JAKBY NIE DZIALALO NA INNYCH KOMPACH USUNAC====================================================================
struct AudioData
{
    Uint8* position; // length of our sample
    Uint32 length;
};

//userdata	parametr specyficzny dla aplikacji przechowywany w polu userdata struktury SDL_AudioSpec.
//stream	wska??nik bufora danych audio wype??nianego przez SDL_AudioCallback().
//len	d??ugo???? tego bufora w bajtach.
//Gdy nast??pi powr??t z funkcji wywo??ywanej zwrotnie zawarto???? bufora nie b??dzie ju?? wa??na. Sample stereo s?? przechowywane w kolejno??ci LPLPLP...
//Funkcja wywo??ywana zwrotnie musi ca??kowicie zainicjowa?? ten bufor, w SDL 2.0 nie jest on inicjowany przed skorzystaniem z funkcji wywo??ywanej zwrotnie. Je??li nie ma nic do zagrania, funkcja wywo??ywana zwrotnie powinna wype??ni?? bufor cisz?? (z pola silence struktury).
void audioCallback(void* userData, Uint8* stream, int streamLength)
{
    AudioData* audio = (AudioData*)userData;

    if (audio->length == 0)
    {
        return;
    }

    Uint32 length = (Uint32)streamLength;

    length = (length > audio->length ? audio->length : length);

    SDL_memcpy(stream, audio->position, length); // to samo co memcpy Kopiuje num bajt??w z miejsca wskazywanego przez source do pami??ci wskazywanej przez destination. arg 1 Wska??nik na pami????, do kt??rej nast??pi kopiowanie., arg 2 Wska??nik na pami????, z kt??rej nast??pi kopiowanie., arg 3 Liczba bajt??w do skopiowania.

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
        std::cout<< "plik nie m??g?? zosta?? za??adowany jako plik audio." << std::endl;
    }
    //filePath sciezka do pliku, &wavSpec to struktura SDL_AudioSpec reprezentujaca po????dany format wyjsciowy, &wavStart po funkcji SDL_LoadWAV jest wypelnona wskaznikiem do przydzielonego bufora zawierajjacego dane dzwiekowe, audio len jest wypelnane dlugoscia tego bufora


    AudioData audio; //nowa istancja struktury Audio data
    audio.position = wavStart; //ustawiamy paramatry posion jako wavStart  wavStart zostalo zapelnone wartoscia poprzez SDL_LoadWAV
    audio.length = wavLength;  //ustawiamy paramatry length jako wavLength  wavLength zostalo zapelnone wartoscia poprzez SDL_LoadWAV


    wavSpec.callback = audioCallback; //SDL_AudioCallback	callback	funkcja wywo??ywana zwrotnie do wywo??ania, gdy urz??dzenie audio potrzebuje wi??cej danych;
    wavSpec.userdata = &audio; //struktura

    SDL_AudioDeviceID audioDevice;
    audioDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
    //Zwraca wa??ny identyfikator ID urz??dzenia, kt??ry przy sukcesie jest wi??kszy od 0, a r??wny 0 przy niepowodzeniu; wywo??aj funkcj?? SDL_GetError(), aby otrzyma?? wi??cej informacji na temat b????du.
    //U??yj tej funkcji, aby otworzy?? okre??lone urz??dzenie d??wi??kowe.
    //Je??li twoja aplikacja mo??e obs??ugiwa?? tylko jeden okre??lony format danych, prze??lij zero w parametrze allowed_changes i pozw??l SDL przezroczy??cie zaj???? si?? obs??ug?? r????nic.
    // SDL_OpenAudioDevice funkcja zwaracajaca zmienna typu SDL_AudioDeviceID, iscapture	warto???? niezerowa okre??la, ??e urz??dzenie powinno zosta?? otwarte do nagrywania, nie do odtwarzania d??wi??ku
    // desired struktura SDL_AudioSpec reprezentuj??ca po????dany format wyj??ciowy; wi??cej szczeg??????w w opisie SDL_OpenAudio()

    SDL_PauseAudioDevice(audioDevice, 0);//wl??cza glosniki jak jest 0

    // poczekaj, a?? przestaniemy gra??
    while (audio.length > 0)  //odtwarzaj dopuki dlugosc pioseki nie osignie 0, 30000000
    {
        SDL_Delay(100);
    }



    SDL_CloseAudioDevice(audioDevice); // wylacz urzadzenia
    SDL_FreeWAV(wavStart); // zwolnij pamiec od wavStart
    SDL_Quit();//Wyczy???? wszystkie zainicjowane podsystemy.

    return 0;
}




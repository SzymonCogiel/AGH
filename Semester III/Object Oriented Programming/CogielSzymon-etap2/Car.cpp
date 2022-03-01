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




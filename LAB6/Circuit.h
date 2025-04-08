#pragma once
#include "Car.h"

class Circuit {
    Car* cars[10];
    float length;
    int weather;
    int carCount;

public:
    Circuit();
    void SetLength(float len);
    void SetWeather(int w); // 0 = sunny, 1 = rain, 2 = snow
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

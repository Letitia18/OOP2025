#pragma once
#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    void SetFuel(float cap, float cons);
    void SetSpeed(float sun, float rain, float snow);
    float Race(float length, int weather);
    const char* GetName();
};

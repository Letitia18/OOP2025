#pragma once
#include "Car.h"

class RangeRover : public Car {
public:
    RangeRover();
    void SetFuel(float cap, float cons);
    void SetSpeed(float sun, float rain, float snow);
    float Race(float length, int weather);
    const char* GetName();
};

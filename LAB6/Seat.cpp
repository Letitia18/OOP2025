#include "Seat.h"
#include "Fiat.h"

Seat::Seat() {
    SetFuel(60, 6);
    SetSpeed(120, 90, 70); // sunny, rain, snow
}

void Seat::SetFuel(float cap, float cons) {
    fuelCapacity = cap;
    fuelConsumption = cons;
}

void Seat::SetSpeed(float sun, float rain, float snow) {
    speedSunny = sun;
    speedRain = rain;
    speedSnow = snow;
}

float Seat::Race(float length, int weather) {
    float fuelNeeded = length * fuelConsumption / 100.0f;
    if (fuelNeeded > fuelCapacity) {
        finished = false;
        time = -1;
        return -1;
    }
    finished = true;
    float speed = (weather == 0 ? speedSunny : (weather == 1 ? speedRain : speedSnow));
    time = length / speed;
    return time;
}

const char* Fiat::GetName() {
    return "Fiat";
}

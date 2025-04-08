#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
    carCount = 0;
}

void Circuit::SetLength(float len) {
    length = len;
}

void Circuit::SetWeather(int w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    if (carCount < 10) {
        cars[carCount++] = car;
    }
}

void Circuit::Race() {
    for (int i = 0; i < carCount; ++i) {
        cars[i]->Race(length, weather);
    }
}

void Circuit::ShowFinalRanks() {
    for (int i = 0; i < carCount - 1; ++i) {
        for (int j = i + 1; j < carCount; ++j) {
            if (cars[i]->HasFinished() && cars[j]->HasFinished() &&
                cars[i]->GetTime() > cars[j]->GetTime()) {
                Car* temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
            }
        }
    }
    for (int i = 0; i < carCount; ++i) {
        if (cars[i]->HasFinished()) {
            std::cout << cars[i]->GetName() << " finished in " << cars[i]->GetTime() << " hours\n";
        }
    }
}

void Circuit::ShowWhoDidNotFinish() {
    for (int i = 0; i < carCount; ++i) {
        if (!cars[i]->HasFinished()) {
            std::cout << cars[i]->GetName() << " did not finish the race.\n";
        }
    }
}

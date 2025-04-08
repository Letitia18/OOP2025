#pragma once

class Car {
protected:
    float fuelCapacity;
    float fuelConsumption;
    float speedSunny;
    float speedRain;
    float speedSnow;
    float time; 
    bool finished;

public:
    virtual void SetFuel(float cap, float cons) = 0;
    virtual void SetSpeed(float sun, float rain, float snow) = 0;
    virtual float Race(float length, int weather) = 0;
    virtual const char* GetName() = 0;
    float GetTime() { return time; }
    bool HasFinished() { return finished; }
};

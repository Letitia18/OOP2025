#include <iostream>
#include <cstring>
#include "Number.h"
using namespace std;

Number::Number(const char* value, int base)
{
    strcpy(numar, value);
    baza = base;
    lungime = strlen(value);
}

void Number::Print() {
    cout << "Scrierea in baza " << baza << " a numarului este " << numar << endl;
}

void Number::Print1() {
	cout << "Numarul este: " << numar << endl;
}

int Number::GetBase10Value() const 
{
    int rez = 0, putere = 1;
    int i;

    for (i = lungime - 1; i >= 0; i--)
    {
        if (numar[i] >= '0' && numar[i] <= '9') { 
            rez = rez + (numar[i] - '0') * putere; 

        }
        else 
        {
            rez = rez + (numar[i] - 'A' + 10) * putere;
        }
        putere = putere * baza;
    }
    return rez;
}

void Number::SwitchBase(int newBase) {

    int val = GetBase10Value();
    int rest = 0, contor = 0;
    char rez[100];

    while (val) {
        rest = val % newBase;
        val = val / newBase;  
        if (rest <= 9) rez[contor] = (char)rest + '0';
        else rez[contor] = (char)rest + 'A'; 
        contor++;
    }
    rez[contor] = '\0'; 
    _strrev(rez);
    strcpy(numar, rez);
    baza = newBase;
}

int Number::GetDigitsCount() const{
    return lungime;
}

int Number::GetBase() const{
    return baza;
}

bool Number::operator<(Number& num) {
    return GetBase10Value() < num.GetBase10Value();
}

bool Number::operator>(Number& num) {
    return GetBase10Value() > num.GetBase10Value();
}

bool Number::operator<=(Number& num) {
    return GetBase10Value() <= num.GetBase10Value();
}

bool Number::operator>=(Number& num) {
    return GetBase10Value() >= num.GetBase10Value();
}

bool Number::operator==(Number& num) {
    return GetBase10Value() == num.GetBase10Value();
}

Number operator+(const Number& num1, const Number& num2) {
    int suma = num1.GetBase10Value() + num2.GetBase10Value();
    char rezultat[100];
    int contor = 0, bazamaxima;

    if (num1.GetBase() > num2.GetBase()) bazamaxima = num1.GetBase();
    else bazamaxima = num2.GetBase();

    while (suma) {
        int rest = suma % bazamaxima;
        suma = suma / bazamaxima;
        if (rest < 9) rezultat[contor] = (char)rest + '0';
        else rezultat[contor] = (char)rest + 'A';
        contor++;
    }
    rezultat[contor] = '\0';
    _strrev(rezultat);
    return Number(rezultat, bazamaxima);
}

Number operator-(const Number& num1, const Number& num2){
    int dif = num1.GetBase10Value() - num2.GetBase10Value();
    char rezultat[100];
    int contor = 0, bazamaxima = 0;

    if (num1.GetBase() > num2.GetBase()) bazamaxima = num1.GetBase();
    else bazamaxima = num2.GetBase();

    while (dif) {
        int rest = dif % bazamaxima;
        dif = dif / bazamaxima;
        if (rest < 9) rezultat[contor] = (char)rest + '0';
        else rezultat[contor] = (char)rest + 'A';
        contor++;
    }
    rezultat[contor] = '\0';
    _strrev(rezultat);
    return Number(rezultat, bazamaxima);
}

Number& Number::operator--() 
{
    strcpy(numar, numar + 1);
    lungime = strlen(numar); 
    return *this; 
}
 
Number Number::operator--(int) 
{
    numar[strlen(numar) - 1] = '\0';
    lungime = strlen(numar); 
    return *this;
}


Number::~Number()
{
    numar[0] = NULL;
}

Number Number::operator--(int) {
    Number temp = *this;
    if (value.length() > 0)
        value.pop_back();
    return temp;
}

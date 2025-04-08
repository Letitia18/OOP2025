#pragma once
#include <iostream>
#include <string>

class Number {
private:
    std::string value;
    int base;

    int ToDecimal() const;
    void FromDecimal(int decimal, int newBase);

public:
    Number(const char* value, int base);
    Number(int decimal);
    Number(const Number& other);
    Number(Number&& other) noexcept;
    ~Number();

    Number& operator=(const Number& other);
    Number& operator=(Number&& other) noexcept;
    Number& operator=(int val);
    Number& operator=(const char* val);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

    char operator[](int index) const;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
    friend bool operator>(const Number& a, const Number& b);
    friend bool operator<(const Number& a, const Number& b);
    friend bool operator>=(const Number& a, const Number& b);
    friend bool operator<=(const Number& a, const Number& b);
    friend bool operator==(const Number& a, const Number& b);
    friend bool operator!=(const Number& a, const Number& b);

    Number& operator+=(const Number& other);

    Number& operator--();    // prefix
    Number operator--(int);  // postfix
};

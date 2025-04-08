#include "Number.h"
#include <cmath>
#include <algorithm>

static int charToInt(char c) {
    return (c >= '0' && c <= '9') ? c - '0' : toupper(c) - 'A' + 10;
}

static char intToChar(int x) {
    return (x < 10) ? x + '0' : x - 10 + 'A';
}

Number::Number(const char* val, int base) : value(val), base(base) {}
Number::Number(int decimal) : base(10) { FromDecimal(decimal, 10); }

Number::Number(const Number& other) : value(other.value), base(other.base) {}
Number::Number(Number&& other) noexcept : value(std::move(other.value)), base(other.base) {}

Number::~Number() {}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        value = other.value;
        base = other.base;
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        value = std::move(other.value);
        base = other.base;
    }
    return *this;
}

Number& Number::operator=(int val) {
    FromDecimal(val, base);
    return *this;
}

Number& Number::operator=(const char* val) {
    value = val;
    return *this;
}

int Number::ToDecimal() const {
    int result = 0;
    for (char c : value) {
        result = result * base + charToInt(c);
    }
    return result;
}

void Number::FromDecimal(int decimal, int newBase) {
    if (decimal == 0) {
        value = "0";
        base = newBase;
        return;
    }

    std::string result;
    while (decimal > 0) {
        result.push_back(intToChar(decimal % newBase));
        decimal /= newBase;
    }
    std::reverse(result.begin(), result.end());
    value = result;
    base = newBase;
}

void Number::SwitchBase(int newBase) {
    int decimal = ToDecimal();
    FromDecimal(decimal, newBase);
}

void Number::Print() const {
    std::cout << value << " (base " << base << ")\n";
}

int Number::GetDigitsCount() const {
    return value.length();
}

int Number::GetBase() const {
    return base;
}

char Number::operator[](int index) const {
    return (index >= 0 && index < value.size()) ? value[index] : '?';
}

Number operator+(const Number& a, const Number& b) {
    int val = a.ToDecimal() + b.ToDecimal();
    int newBase = std::max(a.base, b.base);
    Number result("0", newBase);
    result.FromDecimal(val, newBase);
    return result;
}

Number operator-(const Number& a, const Number& b) {
    int val = a.ToDecimal() - b.ToDecimal();
    int newBase = std::max(a.base, b.base);
    Number result("0", newBase);
    result.FromDecimal(val, newBase);
    return result;
}

bool operator>(const Number& a, const Number& b) {
    return a.ToDecimal() > b.ToDecimal();
}
bool operator<(const Number& a, const Number& b) {
    return a.ToDecimal() < b.ToDecimal();
}
bool operator>=(const Number& a, const Number& b) {
    return a.ToDecimal() >= b.ToDecimal();
}
bool operator<=(const Number& a, const Number& b) {
    return a.ToDecimal() <= b.ToDecimal();
}
bool operator==(const Number& a, const Number& b) {
    return a.ToDecimal() == b.ToDecimal();
}
bool operator!=(const Number& a, const Number& b) {
    return a.ToDecimal() != b.ToDecimal();
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator--() {
    if (value.length() > 0)
        value.erase(0, 1);
    return *this;
}

Number Number::operator--(int) {
    Number temp = *this;
    if (value.length() > 0)
        value.pop_back();
    return temp;
}

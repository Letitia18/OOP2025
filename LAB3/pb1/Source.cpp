#include <iostream>
#include "Math.h"
using namespace std;
int main() {
    cout << "Add(int, int): " << Math::Add(1, 2) << endl;
    cout << "Add(int, int, int): " << Math::Add(1, 2, 3) << endl;
    cout << "Add(double, double): " << Math::Add(1.1, 2.2) << endl;
    cout << "Add(double, double, double): " << Math::Add(1.1, 2.2, 3.3) << endl;
    cout << "Mul(int, int): " << Math::Mul(2, 3) << endl;
    cout << "Mul(int, int, int): " << Math::Mul(2, 3, 4) << endl;
    cout << "Mul(double, double): " << Math::Mul(2.2, 3.3) << endl;
    cout << "Mul(double, double, double): " << Math::Mul(2.2, 3.3, 4.4) << endl;
    cout << "Add(int count, ...): " << Math::Add(4, 1, 2, 3, 4) << endl;

    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    char* result = Math::Add(str1, str2);
    if (result) {
        cout << "Add(const char*, const char*): " << result << endl;
        free(result);
    }
    else {
        cout << "Add(const char*, const char*): nullptr" << endl;
    }
    return 0;
}

#include "Sort.h"
#include <iostream>

int main() {
    Sort sort1(10, 1, 100);
    std::cout << "Random values: ";
    sort1.Print();

    Sort sort2{ 10, 40, 100, 5, 70 };
    std::cout << "Initialization list: ";
    sort2.Print();

    std::vector<int> vec = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    Sort sort3(vec, 5);
    std::cout << "Existing vector: ";
    sort3.Print();

    Sort sort4("10,40,100,5,70");
    std::cout << "String: ";
    sort4.Print();

    Sort sort5(5, 10, 40, 100, 5, 70);
    std::cout << "Variadic parameters: ";
    sort5.Print();

    sort1.BubbleSort(true);
    std::cout << "BubbleSort ascending: ";
    sort1.Print();

    sort2.InsertSort(false);
    std::cout << "InsertSort descending: ";
    sort2.Print();

    sort3.QuickSort(true);
    std::cout << "QuickSort ascending: ";
    sort3.Print();

    std::cout << "Elements count: " << sort4.GetElementsCount() << std::endl;
    std::cout << "Element at index 2: " << sort4.GetElementFromIndex(2) << std::endl;

    return 0;
}

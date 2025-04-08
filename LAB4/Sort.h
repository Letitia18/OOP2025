#pragma once
#include <vector>
#include <string>

class Sort
{
private:
    std::vector<int> elements;

public:
    Sort(int numElements, int minValue, int maxValue);
    Sort(std::initializer_list<int> initList);
    Sort(const std::vector<int>& vec, int numElements);
    Sort(const char* str);
    Sort(int count, ...);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};

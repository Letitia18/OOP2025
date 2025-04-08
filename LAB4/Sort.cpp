#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <sstream>

Sort::Sort(int numElements, int minValue, int maxValue) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < numElements; ++i) {
        elements.push_back(minValue + std::rand() % (maxValue - minValue + 1));
    }
}

Sort::Sort(std::initializer_list<int> initList) : elements(initList) {}

Sort::Sort(const std::vector<int>& vec, int numElements) {
    elements.assign(vec.begin(), vec.begin() + numElements);
}

Sort::Sort(const char* str) {
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, ',')) {
        elements.push_back(std::stoi(item));
    }
}

Sort::Sort(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        elements.push_back(va_arg(args, int));
    }
    va_end(args);
}

void Sort::InsertSort(bool ascendent) {
    for (size_t i = 1; i < elements.size(); ++i) {
        int key = elements[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)) {
            elements[j + 1] = elements[j];
            --j;
        }
        elements[j + 1] = key;
    }
}

int partition(std::vector<int>& arr, int low, int high, bool ascendent) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (ascendent ? arr[j] < pivot : arr[j] > pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high, bool ascendent) {
    if (low < high) {
        int pi = partition(arr, low, high, ascendent);
        quickSort(arr, low, pi - 1, ascendent);
        quickSort(arr, pi + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    quickSort(elements, 0, elements.size() - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
    for (size_t i = 0; i < elements.size() - 1; ++i) {
        for (size_t j = 0; j < elements.size() - i - 1; ++j) {
            if (ascendent ? elements[j] > elements[j + 1] : elements[j] < elements[j + 1]) {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Sort::Print() {
    for (const int& el : elements) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return elements.size();
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < elements.size()) {
        return elements[index];
    }
    return -1; 
}

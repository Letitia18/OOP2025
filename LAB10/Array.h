#pragma once
#include <stdexcept>
#include <utility>
#include "Compare.h"
#include <iostream>

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

    void Resize(int newCapacity) {
        if (newCapacity <= Capacity) return;
        T** newList = new T * [newCapacity];
        for (int i = 0; i < Size; i++)
            newList[i] = List[i];
        for (int i = Size; i < newCapacity; i++)
            newList[i] = nullptr;
        delete[] List;
        List = newList;
        Capacity = newCapacity;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
        for (int i = 0; i < Capacity; i++)
            List[i] = nullptr;
    }

    ~Array() {
        for (int i = 0; i < Size; i++)
            delete List[i];
        delete[] List;
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size)
            throw std::out_of_range("Index out of range");
        return *List[index];
    }

    void Add(const T& elem) {
        if (Size == Capacity) {
            int newCap = (Capacity == 0) ? 2 : Capacity * 2;
            Resize(newCap);
        }
        List[Size++] = new T(elem);
    }

    void Insert(int index, const T& elem) {
        if (index < 0 || index > Size)
            throw std::out_of_range("Index out of range la inserare");
        if (Size == Capacity) {
            int newCap = (Capacity == 0) ? 2 : Capacity * 2;
            Resize(newCap);
        }
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(elem);
        Size++;
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    std::swap(List[i], List[j]);
            }
        }
    }

    int GetSize() const { return Size; }
};

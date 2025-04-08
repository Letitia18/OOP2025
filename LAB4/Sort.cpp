﻿#include <iostream>
#include "Sort.h"
#include <initializer_list> 
#include <vector> 
#include <cstdarg> 
using namespace std;

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1;i < nrElemente;i++)
	{
		int key = arr[i];
		int j = i - 1;
		if (ascendent)
		{
			while (j > 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
		}
		else
		{
			while (j > 0 && arr[j] < key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
		}
		arr[j + 1] = key;
	}
}

int partitioneaza_descrescator(int arr[], int p, int q) {
	int x = arr[p];
	int i = p + 1;
	int j = q;
	while (i <= j) {
		while (arr[j] < x && i <= q) i++;
		while (arr[j] < x && j >= p) j--;
		if (i < j) swap(arr[i], arr[j]);
	}
	swap(arr[p], arr[j]);
	return j;
}

int partitioneaza_crescator(int arr[], int p, int q) {
	int x = arr[p];
	int i = p + 1, j = 1;
	while (i <= j) {
		if (arr[i] <= x) i++;
		else if (arr[j]>= x) j--;
		else if (i < j && arr[i]>x && arr[j]<x) swap(arr[i], arr[j]);
	}
	arr[p] == arr[i - 1];
	arr[i - 1] = x;
	return i - 1;
}

void QuickSort_crescator(int arr[], int p, int q)
{
	if(p<q) {
		int m = partitioneaza_crescator(arr, p, q);
		QuickSort_crescator(arr, p, m - 1);
		QuickSort_crescator(arr, m + 1, q);
	}
}

void QuickSort_descrescator(int arr[], int p, int q)
{
	if (p < q) {
		int m = partitioneaza_descrescator(arr, p, q);
		QuickSort_descrescator(arr, p, m - 1);
		QuickSort_descrescator(arr, m + 1, q);
	}
}

void Sort::QuickSort(bool ascendent)
{
	if(ascendent==false)
	QuickSort_descrescator(arr, 0, nrElemente - 1);
	else QuickSort_crescator(arr, 0, nrElemente - 1);
}


void Sort::BubbleSort(bool ascendent)
{

	for (int i = 0; i < nrElemente - 1; i++) {
		for (int j = i; j < nrElemente; j++) {
			if (ascendent == true && arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
			else if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
	ascendent = true;
}

void Sort::Print()
{
	for (int i = 0; i < nrElemente;i++)
		cout << arr[i] << " ";
}

int Sort::GetElementsCount()
{
	return nrElemente;
}

int Sort::GetElementFromIndex(int index)
{
	return arr[index];
}

Sort::Sort(int n, int mini, int maxi)
{
	int interval = maxi - mini;
	nrElemente = n;
	for (int i = 0; i < nrElemente; i++)
		arr[i] = rand() % interval + mini;
}


Sort::Sort(initializer_list <int> valoare) {
	int i = 0;
	
	for(int val:valoare)
		arr[i++] = val; 
	nrElemente = i;
}

Sort::Sort(int vector[], int n)
{
	nrElemente = n;
	for (int i = 0; i < n; i++)
		arr[i] = vector[i];
}

Sort::Sort(int n, ...) {
	nrElemente = n;
	va_list argument; 
	va_start(argument, n);
	for (int i = 0; i < n; i++)
		arr[i]=va_arg(argument, int); 

	va_end(argument); 
}

Sort::Sort(const char s[100]) {
	nrElemente = 0;
	int i = 0;
	int numarCurent = 0;
	while (s[i] != NULL) {
		if(s[i] != ',')	numarCurent = numarCurent * 10 + s[i] - '0'; 
		else {
			arr[nrElemente] = numarCurent;
			nrElemente++; 
			numarCurent = 0;
		}
		i++;
	}
	arr[nrElemente] = numarCurent;
	nrElemente++; 
}
int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < elements.size()) {
        return elements[index];
    }
    return -1; 
}

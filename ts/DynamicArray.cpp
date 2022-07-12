//
// Created by user on 01.06.22.
//

#include "DynamicArray.h"
#include <vector>

DynamicArray::DynamicArray() {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }

}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::push_back(int value) {
    size += 1;
    int *new_array = new int[size];
    for (int i = 0; i < size; ++i) {
        new_array[i] = array[i];
    }
    delete[]array;
    new_array[size - 2] = value;
    array = new_array;
}

int &DynamicArray::operator[](const int index) {
    return array[index];
}
bool DynamicArray::operator==(const DynamicArray &ar2) {
    bool equal;
    for (int i = 0; i < size; ++i) {
        if (array[i] == ar2.array[i]) equal = true;
        else equal = false;
    }
    return equal;

}

DynamicArray &DynamicArray::operator=(const DynamicArray &arr) {
    if (*this==arr){return *this;}
    if (size < arr.size) {

        size = arr.size;
        int *new_array = new int[size];
        for (int i = 0; i < size; ++i) {
            new_array[i] = 0;
        }
        delete[]array;
        array = new_array;
    }
    for (int i = 0; i < size; ++i) {
        array[i] = arr.array[i];

    }

    return *this;
}

DynamicArray &DynamicArray::operator++() {//префикс
    for (int i = 0; i < size; ++i) {
        array[i] += 1;
    }
    return *this;
}

DynamicArray DynamicArray::operator++(int) {//постфикс
    DynamicArray currentArray;
    currentArray = *this;
    ++(*this);
    return currentArray;
}

bool DynamicArray::operator()(int value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}



//
// Created by user on 01.06.22.
//

#ifndef TS_DYNAMICARRAY_H
#define TS_DYNAMICARRAY_H

#include <iostream>
class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();
    void push_back(const int value);
    int& operator[] (const int index);
    bool operator== (const DynamicArray& ar2);
    DynamicArray& operator=(const DynamicArray& arr);
    DynamicArray& operator++();//префикс
    DynamicArray operator++(int);//постфикс
    bool operator()(int value);
    friend std::ostream& operator<< (std::ostream &out, const DynamicArray& arr){
        for (int i = 0; i < arr.size; ++i) {
            out<< arr.array[i]<< " ";
        }
        return out;
    }

private:
    int *array;
    int size=1;
};


#endif //TS_DYNAMICARRAY_H

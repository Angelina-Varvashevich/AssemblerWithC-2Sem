#include <iostream>
#include "DynamicArray.h"
#include "abstract.h"

int main() {
    int size = 4;
    DynamicArray array;
    array.push_back(10);
    array.push_back(12);
    array.push_back(13);
    array.push_back(14);
    DynamicArray array1;


    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }
    std::cout << std::endl;
    array1 = array;

    for (int i = 0; i < size; ++i) {
        std::cout << array1[i] << std::endl;
    }
    std::cout << std::endl;
    /* array1++;
     for(int i=0; i<size; ++i){
         std::cout<< array1[i]<< std::endl;
     }*/
    ++array1;
    ++array1;
    std::cout << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << array1[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << array1(12);

    std::cout<< array<< std::endl;

Doctor doc("Ivanov", 12);
doc.Occupation();

Worker w;
w.work(&doc);


    return 0;
}

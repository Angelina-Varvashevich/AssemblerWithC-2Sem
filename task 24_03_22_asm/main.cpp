#include <iostream>
#include <algorithm>
#include <windows.h>

#include "Tasks.h"


int main() {
    //Algorithm4();
    //Algorithm5();
    /*TCHAR _first_string[100] = TEXT("Harmony");
    TCHAR _second_string[100] = TEXT("Hollo");
    int result = 0;// 0-равны; 1- 1>2; 2- 1<2
    int i = 0;//first
    int j = 0;//second*/
    //char *_first_string = new char[]{"Harmony"};
    //char *_second_string = new char[]{"Hollo"};
    //int result = 0;// 0-равны; 1- 1>2; 2- 1<2
    /* int Func(int result) {
         char *first_string = new char[]{"Harmony"};
         char *second_string = new char[]{"Hollo"};
         int i = 0;//first
         int j = 0;//second
         //int result = 0;// 0-равны; 1- 1>2; 2- 1<2
         while (first_string[i] != '/0' || second_string[j] != '/0') {
             if (first_string[i] == second_string[j]) {
                 ++i;
                 ++j;}
             if (first_string[i] > second_string[j]) {
                 result = 1;
                 return result;}
             if (first_string[i] < second_string[j]) {
                 result = 2;
                 return result;}
         }
         result =0;
         return result;
     }*/
    /*_asm{
            mov al, _first_string
            mov bl, _second_string
            mov ecx, i; i=0
            mov esi, j; j=0
                    mov edi, result;


    };*/

    int first_array[]{2, 7, 1, 3, 2, 5, 5};//уточнить с сайзом
    int second_array[]{2, -1, 1, 10, 0};
    int size_first = std::size(first_array);
    int size_second=std::size(second_array);
    const int merge_size=size_first+size_second;
    int merge_array[merge_size];
    std::sort(first_array, first_array+size_first);
    std::sort(second_array, second_array+size_second);
    std::merge(first_array, first_array+size_first,second_array, second_array+size_second,  merge_array );

    for(int i=0; i< merge_size; ++i){

        std::cout<< merge_array[i]<< " ";
    }

    return 0;
}

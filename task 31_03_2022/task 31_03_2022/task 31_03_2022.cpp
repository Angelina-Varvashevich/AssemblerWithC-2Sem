// task 31_03_2022.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>



extern "C" void _fastcall IntToHex(int, char*);

extern "C" void _fastcall IntToOct(int, char*);
extern "C" int _fastcall StrToInt32(char*);

//extern "C" int _fastcall StrCompare(char*, char*);
extern "C" char _fastcall CharByIndex(char*, int);

/*char* StrChar(char* stri, char symbol) {
    int i = 0;
        while (stri[i] != '/0') {
            if (stri[i] == symbol) {
                return &stri[i];
            }
            else ++i;
        }
     return nullptr;
}*/


int main()
{
	int num = 125;
	char str[9]; 
    str[8] = '/0';
    
  
	IntToHex(num, str);
	std::cout << str<<std::endl;

    static const char abc[] = "0123456789ABCDEF";

    char str4[11];
    str4[10] = '\0';
    IntToOct(num, str4);
    std::cout << str4 << std::endl;


    char strN[] = "5070089";
    std::cout << StrToInt32(strN) << std::endl;
   

    /*char strin[] = "hello!";
    char symbol = 'e';

    std::cout<< StrChar(strin, symbol);*/


     /*char _first_string[] = "Harmony";
     char _second_string[] ="Hollo";

     std::cout << StrCompare(_first_string, _second_string);*/

    //int i = 0;//first
    //int j = 0;//second
    //int result = 0;
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

    /*_asm {

        mov esi, i; i = 0
        mov ebx, j; j = 0
        mov edi, result;

    body_:
        cmp _first_string[esi], 0
            je end_
            cmp _second_string[ebx], 0
            je end_; while (first_string[i] != '/0' || second_string[j] != '/0')


            mov al, byte ptr _first_string[esi * 1]
            mov cl, byte ptr _second_string[ebx * 1]
            cmp al, cl
            je equal_;  if (first_string[i] == second_string[j])
            jg greater_;  if (first_string[i] > second_string[j])

            mov edi, 2; result = 2; if (first_string[i] < second_string[j])
            jmp end_

            equal_ :
        inc esi; ++i
            inc ebx; ++j
            jmp body_

            greater_ :
        mov edi, 1;  result = 1;
        jmp end_

            end_ :
        mov result, edi
    };
    if (result == 0) std::cout << "equal";
    if (result == 1) std::cout << "first greater than second";
    if (result == 2)std::cout << "first less than second";*/

  
    char str2[] = "Summer";
    int index = 2;
    /**char res;
    _asm {
        mov ecx, dword ptr string;
        mov edx, index;
        mov esi, 0; int i = 0


            main_:
        cmp[ecx + esi], 0
            je bd_
            inc esi
            jmp main

            bd_ :
        cmp edx, esi
            jg end__

            mov al, [ecx + edx - 1]
            mov res, al


            end__ :
        mov al, 0
            mov res, al
    };

    std::cout << res;*/

    std::cout << CharByIndex(str2, index);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"



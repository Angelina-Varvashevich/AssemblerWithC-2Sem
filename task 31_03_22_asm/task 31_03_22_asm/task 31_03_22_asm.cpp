#include <iostream>
extern "C" void _fastcall IntToHex(int, char*);
extern "C" void _fastcall IntToOct(int, char*);
extern "C" int _fastcall StrToInt32(const char*);
extern "C" void _fastcall IntToDec(unsigned int number, char* str);
extern "C" char _fastcall CharByIndex(const char* str, int index);
extern "C" int _fastcall StrCompare(const char*, const char*);
extern "C" char* _fastcall StrChar(const char* str, char symbol);
extern "C" int _fastcall Max(int**, int);


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
    str[8] = '\0';

    IntToHex(num, str);
    std::cout << "IntToHex: " << str << std::endl;


    char str4[11];
    str4[10] = '\0';
    unsigned int numb = 0x8192A3B4;
    IntToOct(numb, str4);
    std::cout << "IntToOct: " << str4 << std::endl;


    char strN[] = "5070089";
    char strin[] = "hello!";
    char symbol = 'e';

    std::cout << "StrToInt: " << StrToInt32("5505") << std::endl;

    std::cout << "CharByIndex: " << CharByIndex(strin, 2) << std::endl;

    std::cout << "StrCompare: " << StrCompare("13", "123") << std::endl;

    std::cout << "StrChar: " << (unsigned)( StrChar(strin, 'e')-strin ) << std::endl;

    char str_new[15];;
    int number = 2568854;
    IntToDec(number, str_new);

    std::cout << "Dec: " << str_new << std::endl;

    int n = 5;  int** A = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        A[i] = new int[n];    for (int j = 0; j < n; ++j)
        {
            A[i][j] = rand()%100;
        }
    }

    int max=A[0][0];

    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < n; ++j) {
            if (A[i][j] > max) max = A[i][j];
        }
    }

    std::cout <<"From C++ algorithm= "<< max<< std::endl;

       std::cout << "max = " << Max(A, n) << std::endl;

    for (int i = 0; i < n; ++i)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}


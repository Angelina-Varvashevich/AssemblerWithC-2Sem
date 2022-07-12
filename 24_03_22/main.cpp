#include <iostream>

template<int capacity>
void foo(int B[][capacity], int size) {
    int tt;
    _asm {
            ; mov eax, type B//тип переменной
            mov eax, length B//длина массива
            mov tt, eax
    }
    std::cout << tt;
}

int main()
{

    /*const int capacity = 100;
    int A[capacity][capacity];
    int size = 5;

    foo(A, size);

    int num =125;
    char str2[33];
    str2[32]=0;// i=0
    _asm{
        mov eax, num
        mov ecx, 32;

        body_:
        shr eax,1
        jc first_
        mov str2[ecx-1], '0'

        jmp end
        first_:
        mov str2[ecx-1], '1'
        end:
        loop body_


    };
    for(int i =0; i<33; ++i){
        std::cout<< str2[i]<< std::endl;
    }

    char str3[9];
    static const char alp[]={"0123456789ABCDEF"};

    str3[8]='\0';

    _asm{
        mov ecx, 8
        mov eax, num

        begin_:
        and ebx, 0x0000000F
        mov dl, alp[edx]

        mov str3[ecx-1], dl
        shr eax, 4
        loop begin
    };
    for(int i =0; i<33; ++i){
        std::cout<< str3[i]<< std::endl;
    }

    char str4[11];
    str4[10]='\0';
    _asm{
            mov ecx, 10
            mov eax, num

            first_:
            and ebx, 0x00000007
            mov dl, alp[edx]

            mov str3[ecx-1], dl
            shr eax, 3
            loop first_
    };
    for(int i =0; i<11; ++i){
        std::cout<< str4[i]<< std::endl;
    }*/


    char strNumber[]{"12345"};
    int Number=0;

    _asm{


        xor ebx, ebx
        xor esi, esi

        m_begin3:
        xor edx, edx
        mov dl, strNumber[esi]
        cmp dl, 0
        je m_end3
        imul ebx, 10
        sub dl, '0'; число считаем
        add ebx, edx
        inc esi
        jmp m_begin3

        m_end3:
        mov Number, ebx

    };







}









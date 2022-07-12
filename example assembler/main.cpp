#include <iostream>

int main() {
   /* int a = 4; /// пара перед 10.03.2022
    int b = -12;
    int result;
    short int c = -3;
    short int result2;
    int result1;///result1 = c-a;
    int result3;/// все расширить и потом складывать
    char ck = -3;
    int resultck; //=a -ck
    //result1 = c - a;
    int ost, chast;
    ///
    int product;//a*b
    int producdiv;
    _asm{
            mov eax, b;eax<-a
            sub eax, a;сложение аналогично
            mov result, eax;mov eax, ebx;mov ah, al

            mov eax, 0
            mov ax, c
            sub eax, a
            mov result1, eax;!!!! mov eax, dword ptr a
            mov ax, c
            cwd
            sub eax, a;mov result3, eax

            movsx eax, c
            sub eax, a
            mov result3, eax

            movsx eax, ck;
            sub eax, b
            mov resultck, eax

            mov eax, a
            mov ebx, 1
            imul ebx
            idiv b
            mov ost, edx
            mov chast, eax


    }

    std::cout << result << std::endl;
    std::cout << result1 << std::endl;
    std::cout << result3 << std::endl;
    std::cout << resultck << std::endl;
    std::cout << ost<< " "<< chast << std::endl;
    return 0;*/
   const int n=5;
   int res;

    int array[n]= {1, 2, 3, 4, 5};

   // for(int i=0; i<=n; ++i){
    //    res+=array[i];
    //}
    _asm{
        mov eax, 0; eax<-sum
        mov ecx, 0; count
        start_:
        cmp ecx, n
        jnl met_and
        add eax, array[ecx*4]
        inc ecx

        jmp start_
        met_and:
        mov res, eax


    };
    //std::cout<< res<< std::endl;

    int *b= new int[n];
    /*std::copy(array, array+n, b );
    for(int i=0; i<=n; ++i){
        std::cout<< b[i]<<" ";
        }*/
    _asm{
            mov eax, 0; eax<-sum
            mov ecx, 0; count
            mov ebx, b
            start_1:
            cmp ecx, n
            jnl met_and1
            add eax, [ebx][ecx*4]
            inc ecx

            jmp start_1
            met_and1:
            mov res, eax

    };
    std::cout<< res;


}




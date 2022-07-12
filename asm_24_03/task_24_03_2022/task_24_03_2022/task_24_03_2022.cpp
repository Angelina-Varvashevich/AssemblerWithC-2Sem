#include <iostream>
#include<algorithm>
#include <windows.h>

void Algorithm4() {
    /* 4. Определить количество различных элементов массива.
Перестроить исходный массив, исключая повторяющиеся
элементы. Начальный элемент результирующего массива
содержит его новую реальную длину (см. первое
предложение). */
       int n = 7;
    int* input_array = new int[] {1, 2, 2, 3, 2, 5, 5};
 int _size = 0;
    int output_array[40];
    int i = 0;
    int j = 1;
    for (i; i < n; ++i) {
        int count = 0;
        j = 1;
        for (j; j < _size + 1; ++j) {
            if (input_array[i] == output_array[j]) {
                ++count;
            }
        }
        if (count == 0) {
            output_array[_size + 1] = input_array[i];
            ++_size;
        }
    }
    output_array[0] = _size + 1;//new real length
    for (j = 0; j < _size + 1; ++j) {
        std::cout << output_array[j] << " " << std::endl;
    }
}

void Algorithm5() {
    /*5. Слить два упорядоченных массива.*/
    int first_array[]{ 2, 7, 1, 3, 2, 5, 5 };
    int second_array[]{ 2, -1, 1, 10, 0 };
    const int size_first = std::size(first_array);
    const int size_second = std::size(second_array);
    const int merge_size = size_first + size_second;
    int merge_array[merge_size];
    std::sort(first_array, first_array + size_first);
    std::sort(second_array, second_array + size_second);
    std::merge(first_array, first_array + size_first, second_array, second_array + size_second, merge_array);

    for (int i = 0; i < merge_size; ++i) {

        std::cout << merge_array[i] << " ";
    }
}


void Task1() {
    /*1. Сравнить две строки языка Си*/
    TCHAR _first_string[100] = TEXT("Harmony");
    TCHAR _second_string[100] = TEXT("Hollo");
   
    int i = 0;//first
    int j = 0;//second
    int result = 0;
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

    _asm {

        mov esi, i; i = 0 /// cmpsb-сравнение строк, принимает esi и edi
        mov ebx, j; j = 0
        mov edi, result;

    body_:
        cmp _first_string[esi], 0
        je end_
        cmp _second_string[ebx], 0
        je end_                                 ; while (first_string[i] != '/0' || second_string[j] != '/0')
        

        mov al, byte ptr _first_string[esi * 1]
        mov cl, byte ptr _second_string[ebx * 1]
        cmp al, cl
        je equal_                               ;  if (first_string[i] == second_string[j])
        jg greater_                             ;  if (first_string[i] > second_string[j])

        mov edi, 2; result = 2                  ; if (first_string[i] < second_string[j])
        jmp end_

            equal_ :
        inc esi; ++i
        inc ebx; ++j
            jmp body_

            greater_ :
        mov edi, 1;  result = 1;
            jmp end_

            end_:
        mov result, edi
    };
    if (result ==0) std::cout << "equal";
    if (result==1) std::cout << "first greater than second";
    if (result==2)std::cout << "first less than second";
    
}
 
void Task2() {
    /*2. Вычислить сумму диагональных элементов статической
квадратной матрицы.*/
    int A[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5} };
    int n = 5;
    int m = 5;
    int main_sum = 0;
    int j = 0;
    int i = 0;
    /*for (int i = 0; i < 5; ++i) {
        main_sum += A[i][j];
        ++j;
    }
    std::cout << main_sum;*/
    _asm {
        mov edx, main_sum
        mov ecx, i
        mov esi, j

        body_ :
        cmp ecx, n; i < 5;
        jge end_

            mov eax, ecx; eax = i
            imul eax, m; eax = i * m
            add eax, esi; eax = i * m + j

            add edx, A[eax * 4]; main_sum += A[i][j];
        inc esi; ++j
            inc ecx; ++i
            jmp body_

            end_ :
        mov main_sum, edx

    };
    std::cout << main_sum;
}

void Task3() {
    /*3. Вычислить сумму диагональных элементов динамической
квадратной матрицы.*/
    int rows = 5;
    int cols = 5;
    int main_sum = 0;

    int** A = new int* [rows];
    for (int i = 0; i < rows; i++) {
        A[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = j+1;
        }
    }
    /* int j = 0;
     for (int i = 0; i < rows; i++) {
         main_sum += A[i][j];
         ++ j;
     }*/
    int i = 0;//rows
    int j = 0;//cols

    _asm {

        mov edi, main_sum
        mov ecx, i
        mov esi, j
        mov edx, A

        body_ :
            cmp ecx, rows                       ; i < rows;
            jge end_

            mov eax, [edx][ecx * 4]             ; A[i]
            add edi, [eax][esi * 4]             ; A[i][j]
            inc esi                             ; ++j
            inc ecx                             ; ++i
            jmp body_

            end_ :
        mov main_sum, edi
    };
    std::cout << main_sum;
    for (int i = 0; i < rows; i++) {
        delete[] A[i];
    }

    delete[] A;
}

int main()
{
    //Algorithm4();
    //Algorithm5();
    Task1();
    //Task2();
    //Task3();
    return 0;
}
 


#ifndef TASK_17_03_2022_ASM_TASKS_H
#define TASK_17_03_2022_ASM_TASKS_H

void Task1() {
    /*1. Дробь задается целым числителем и натуральным
    знаменателем. Если возможно, сократить ее.*/
    int numerator = -15;
    int denominator = 12;
    int numerator_;
    int denominator_;
    int GCD;
    std::cout << numerator << "/" << denominator << std::endl;
    /*if(numerator<=0) {
        gcd(-1 * numerator, denominator);
        std::cout << numerator / gcd(-1 * numerator, denominator) << "/"
                  << denominator / gcd(-1 * numerator, denominator) << std::endl;
    }
    else {
        gcd( numerator, denominator);
        std::cout << numerator / gcd( numerator, denominator) << "/"
                  << denominator / gcd( numerator, denominator) << std::endl;
    }*/
    /*int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}*/
    _asm{
            mov eax, numerator
            mov ebx, denominator
            cmp eax, 0
            jge above_zero
            mov edx, -1
            imul edx; eax= -1*numerator             ; для посчета дроби, numerator<0
            jmp gcd
            above_zero:
            jmp gcd

            gcd:
            cmp eax, ebx
            je end_                                 ;  if numerator==denominator
            jg greater_                             ; if (numerator > denominator)
            sub ebx, eax
            jmp gcd
            greater_:
            sub eax, ebx
            jmp gcd
            end_:                                   ;gcd->eax
            mov GCD, eax

            mov eax, numerator
            mov ebx, 1
            imul ebx                                ; edx:eax
            idiv GCD                                ; numerator/gcd
            mov numerator_, eax                     ; numerator_= numerator/gcd

            mov eax, denominator
            imul ebx                                ; edx:eax; edx:eax
            idiv GCD                                ; denominator/gcd
            mov denominator_, eax                   ;  denominator_=denominator/gcd
    };
    std::cout << numerator_ << "/"
              << denominator_ << std::endl;

}

void Task2() {
    /*2. Вычислить количество значащих разрядов в двоичной
    записи натурального числа.*/
    int16_t num = 30;// 30= 0000 0000 0001 1100, значащие 1 1100
    int main_count;
    int not_main = 0;
    _asm{
            mov ax, num
            body_:
            shl ax, 1;
            jb bit1; если CF=1
            add not_main, 1
            jmp body_

            bit1:
            mov ecx, 16; int16_t
            sub ecx, not_main
            mov main_count, ecx
    };
    std::cout << main_count << std::endl;
}

void Task3() {
    /*3. Задан одномерный упорядоченный массив определенной
    размерности, содержащий различные элементы, и число.
            Используя стратегию поиска «деление отрезка пополам»,
    определить, присутствует (тогда вывести его номер) или
    отсутствует такой элемент в массиве.*/
    int32_t array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int32_t element = 8;
    int flag = 0;//false
    int index_begin = 0;
    int index_end = 9;
    int middle;
    /*while ((index_begin <= index_end) &&(flag!=true) ) {
        middle = (index_begin + index_end ) / 2;

        if (array[middle] == element) flag = true;
        if (array[middle] > element) index_end  = middle - 1;
        else index_begin = middle + 1;
    }*/
    _asm{
            mov ecx, index_begin                ; ecx<-index_begin
            mov ebx, index_end                  ; ebx<-index_end
            body_:


            cmp ecx, ebx;
            jg end_                             ; if index_begin >= index_end
            cmp flag, 1                         ; (flag!=true)
            je end_

            mov eax, ecx                        ; eax<-index_begin
            add eax, ebx                        ; eax=(index_begin + index_end )
            mov esi, 1
            imul esi                            ; edx:eax
            mov esi, 2
            idiv esi                            ; eax=(index_begin + index_end )/2; eax=current-middle

            xor edx, edx
            mov edx, array[eax*4]               ; edx=array[middle]
            cmp edx, element;
            je equal_                           ;if (array[middle] == element)
            jg greater_                         ;if (array[middle] > element)
            mov ecx, eax
            inc ecx                             ; ecx=middle +1
            jmp body_

            equal_:
            mov flag, 1
            jmp body_

            greater_:
            mov ebx, eax
            dec ebx                             ; ebx=middle -1
            jmp body_

            end_:
            mov middle, eax
    };

    if (flag) std::cout << "index of element " << element << " in array equal " << middle;
    else std::cout << "there isn't element in array";
}

void Task4() {
    /*4. Задан одномерный массив определенной размерности.
            Найти длину и указать индекс начала фрагмента,
    содержащего наибольшее число одинаковых следующих друг
    за другом элементов.*/
    int max_size = 0;
    int size;
    int index = 0;
    //int j;
    const int n = 10;
    int array[n] = {1, 2, 2, 0, 1, 1, 1, 4, 4, 4};
    /*for (int i=0; i<n; ++i){
        int j=i;
        size=1;
        while(array[j]==array[j+1] && j<n-1){
            ++size;
            j++;
        }
        if(max_size<size){
            max_size=size;
            index=i;
        }
    }*/
    _asm{
            mov ebx, 0              ; i
            mov edx, 0              ; j

            body_:
            cmp ebx, n              ; i!=n
            je end_
            mov edx, ebx            ; j=i
            mov eax, 1              ; size=1


            main_:
            mov ecx, array[edx*4+4]
            cmp array[edx*4], ecx   ;while (array[j]==array[j+1])
            jne not_equal
            inc eax                 ; ++size;
            inc edx                 ;  j++
            jmp main_


            not_equal:
            cmp max_size, eax
            jge greater_
            mov max_size, eax       ;max_size=size;
            mov index, ebx          ; index=i
            inc ebx                 ; ++i
            jmp body_

            greater_:
            inc ebx                 ; ++i
            jmp body_

            end_:

    };
    std::cout << max_size << " " << index;
}

void Task5(){
    /*5. Задан одномерный массив определенной размерности.
            Получить другой массив, не содержащий повторяющихся
    элементов.*/
    int n = 6;
    int *input_array = new int[]{1, 2, 2, 3, 2, 5};
    int _size = 0;
    int output_array[40];
    int i = 0;
    int j = 0;
    /*for (i; i < n; ++i) {
        int count = 0;
        j = 0;
        for (j; j < size; ++j) {
            if (input_array[i] == output_array[j]) {
                ++count;
            }
        }
        if (count == 0) {
            output_array[size] = input_array[i];
            ++size;
        }
    }*/

    _asm{
            mov eax, input_array
            xor esi, esi                    ;i=0
            xor edi, edi
            mov ecx, 0                      ; j=0
            mov edx, _size                  ; _size=0

            body_:
            cmp esi, n                      ; i < n;
            jge end_
            mov edi, 0                      ;count = 0;
            mov ecx, 0                      ; j=0


            part:
            cmp ecx, edx                    ; j < size
            jge check_count_
            mov ebx, output_array[ecx*4]
            cmp[eax][esi*4], ebx            ;if (input_array[i] == output_array[j])
            jne not_equal
            inc edi;  ++count
            inc ecx; ++j
            jmp part

            not_equal:
            inc ecx
            jmp part

            check_count_:
            cmp edi, 0                      ; if (count == 0)
            jne next_it
            mov ebx,[eax][esi*4]
            mov output_array[edx*4], ebx    ; output_array[size] = input_array[i];

            inc edx                         ; ++size
            inc esi
            jmp body_

            next_it:
            inc esi
            jmp body_

            end_:
        mov _size, edx
    };

    for (j = 0; j < _size; ++j) {
        std::cout << output_array[j] << " " << std::endl;
    }

}


#endif //TASK_17_03_2022_ASM_TASKS_H

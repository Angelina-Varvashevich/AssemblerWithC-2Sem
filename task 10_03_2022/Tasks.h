#ifndef TASK_10_03_2022_TASKS_H
#define TASK_10_03_2022_TASKS_H
#include <iomanip>
void Task1() {
    int number = 14;// 14=1110; task1
    int bit_ = -1;
    int n = 2; // 0<=n<=31
    _asm{
            add n, 1
            mov ecx, n
            mov eax, bit_

            body_:
            shr number, 1; выталкиваю по 1 биту в СF-смотрю, какой бит вытолкнуло
            jb bit1; если СF=1
            mov eax, 0; в bit_ помещаю значение вытолкнутого бита
            jmp end_
            bit1:;если СF=1
            mov eax, 1; в bit_ помещаю значение вытолкнутого бита
            end_:

            loop body_
            mov bit_, eax

    };

     //mov ecx, 1; подготовить маску
     //shl ecx, n
     //and eax, ecx
    std::cout << bit_ << std::endl;
}

void Task2() {
    int16_t number = 14;//task2
    int n = 3;
    int fix_bit = 1;
    int iterations = 0;
    _asm{
            mov ebx, iterations
            mov ecx, 16


            body_:
            cmp ebx, n              ; проверяем не стоит ли нужный бит на 0  позиции
            je transform_; ebx=n
            ror number, 1           ; 1 итерация на 1 по часовой
            add ebx, 1; кол-во итераций
            loop body_

            transform_:
            cmp fix_bit, 1
            je process; fix_bit= 1
            or number, 0000000000000001 ; если нужно изменить на 0
            xor number, 0000000000000001
            loop body_

            process:                    ; если нужно изменить на 1
            or number, 0000000000000001;
            loop body_
    };
    std::cout << number << std::endl;
}

void Task3() {
    short first_word = 1;//3 task /////// char поменять на short
    short second_word = 2;
    std::cout << first_word << std::endl;
    std::cout << second_word << std::endl;
    _asm{
            ;mov ax, first_word; ax<-first_word ;;;;;;;;; ax, bx поставила вместо al, bh, но у меня был char, так что все норм
            ;mov bx, second_word; bx<-second_word
            ;mov second_word, ax; second_word<-first_word
            ;mov first_word, bx; first_word<-second_word
            push first_word; 2 вариант на стеке
            push second_word
            pop first_word
            pop second_word
    };
    std::cout << first_word << std::endl;
    std::cout << second_word << std::endl;
}

void Task4() {
    int a = 5;// 4 task
    int b = 20;
    int quotient;
    int surplus;
    _asm{
            mov eax, b; eax<-b
            neg eax; -b
            mov ebx, 1
            imul ebx; edx:eax
            idiv a; -b/a
            mov surplus, edx
            mov quotient, eax
    };
    std::cout << quotient << " " << surplus << std::endl;
}

void Task5() {
    int quotient;
    int surplus;
    int a_ = 0, b_ = -5, x_ = 5, c_ = 2; //task5
    _asm{
            mov eax, a_
            mov ebx, 2
            imul ebx                ; 2a
            mov ebx, c_
            imul ebx                ; eax=2ac
            mov ecx, eax            ; ecx=2ac

            mov eax, b_
            mov ebx, 1
            imul ebx
            idiv x_                 ; aex=b/x

            sub ecx, eax            ; ecx =2ac-b/x
            sub ecx, 12             ; ecx =2ac-b/x-12

            mov eax, c_
            imul x_                 ; eax=cx
            add eax, a_             ; eax=cx+a
            mov ebx, eax            ; ebx=cx+a

            mov eax, ecx            ; eax =2ac-b/x-12
            mov ecx, 1
            imul ecx                ; edx:eax
            idiv ebx                ; (2ac-b/x-12)/(cx+a)
            mov  quotient, eax
            mov surplus, edx
    };
    std::cout << quotient << " " << surplus << std::endl;

}

void Task6() {
   int16_t word_value=0x1234;///task6 //// можно использовать al(младший), ah(старший)
    std::cout << std::hex<< word_value << std::endl;
    _asm{
        /*mov ax, word_value
        ror ax,8            ; ror вытесняет старший байт в младший
        mov word_value, ax  ; word_value c переставленными байтами*/
        mov ah, byte ptr word_value; 2 dfhbfyn
        mov al, byte ptr word_value+1
        mov word_value, ax
    };
    std::cout <<std::hex<< word_value << std::endl;
    printf( "word_value= %x\n",word_value );
    float pi=3.14f;
    printf( "pi= %10.5f\n",pi );

}

void Task7() {
    int first = 2147483647;// task7
    //int first=2;
    //int second = 2333333333;
    int second = 2;
    int overflow; ///можно как флаг переполнения
    _asm{
            mov eax, first          ; eax<-first
            imul second             ; eax = first*second, контролирует OF
            jo overfl               ; проверка на переполнение
            mov overflow, 0         ; не переполнен
            jmp end_
            overfl:
            mov overflow, 1         ; переполнен
            end_:
    };
    std::cout<< overflow <<std::endl;
}

void Task8() {
    char a = 4; ///task8
    short b = -2;
    int c = 2;
    int a_, b_, result;
    _asm{
            movsx ebx, a            ; ebx<-b
            mov a_, ebx

            movsx ecx, b            ; ecx<-b
            mov b_, ecx

            mov eax, ebx            ; aex=a
            mov edx, 1
            imul edx
            idiv b_                 ; eax=a/b
            mov ecx, eax            ; ecx=a/b

            mov eax, b_
            mov edx, 1
            imul edx
            idiv c                  ; eax=b/c
            mov ebx, eax            ; ebx=b/c

            mov eax, c
            mov edx, 1
            imul edx
            idiv a_                 ; eax =c/a

            add eax, ebx            ; eax =c/a+b/c
            add eax, ecx            ; eax =c/a+b/c+a/b
            mov result, eax         ; result= 2.5, округление до int

    };
    std::cout << result << std::endl;

}

void Task9() {
    int result;//task9
       _asm{
               mov result, 1
               shl result, 5           ; сдвиг на 5 битов влево, result=1*2^5, где n=5
       };
       std::cout << result << std::endl;

}

void Task10() {
    int number = 14; ///task10 14=1110
    int count1=0;
    _asm{
            mov ecx, 32
            mov eax, count1

            body_:
            shr number, 1           ; выталкиваю по 1 биту в СF
            jb bit1                 ; если СF=1
            jmp end_
            bit1:
            add eax, 1
            end_:

            loop body_
            mov count1, eax

    };
    std::cout << count1 << std::endl;
}

#endif //TASK_10_03_2022_TASKS_H

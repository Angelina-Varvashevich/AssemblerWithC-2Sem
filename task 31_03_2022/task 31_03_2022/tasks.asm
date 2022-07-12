.386
PUBLIC @IntToHex@8
;PUBLIC @IntToOct@8
;PUBLIC @IntToDec@8

.model flat

.data

abc db "0123456789ABCDEF"

.code

@IntToHex@8 proc

; ecx - int
; edx - char*
mov esi, ecx; int 
mov ecx, 8
begin_:

mov ebx, esi; esi=int 
and ebx, 15;0000000000001111
mov al, abc[ebx]
mov [edx+ecx-1], al

shr esi, 4
loop begin_

ret
@IntToHex@8 endp




@IntToOct@8 proc

; ecx - int
; edx - char*
 mov esi, ecx; esi=int
        mov ecx, 10
        m_begin2:
        mov ebx, esi
            and ebx,7;0x00000007
            mov al, abc[ebx]
            mov [edx+ecx - 1], al
            shr esi, 3
            loop m_begin2
ret
@IntToOct@8 endp


@StrToInt32@4 proc

        xor eax, eax; собираем число
        xor ebx, ebx
        xor esi, esi; индекс по строке числа
        ;mov ecx, strN
        m_begin3 :
        mov bl, [ecx+esi]
            cmp bl, 0; не конец строки
            je m_end3
            imul eax, 10
            sub bl, '0'; в цифру  
            add eax, ebx
            inc esi
            jmp m_begin3
            m_end3 :
       

ret
@StrToInt32@4 endp


@CharByIndex@8 proc


        ;mov ecx, dword ptr string;
        ;mov edx, index;
        mov esi, 0; int i = 0


            main_:
            mov bl, [ecx + esi]
        cmp bl, 0
            je bd_
            inc esi
            jmp main_

            bd_ :
        cmp edx, esi
            jg end__

            mov al, [ecx + edx - 1]
            


            end__ :
        mov al, 0
            

ret
@CharByIndex@8 endp

@StrCompare@8 proc

mov esi, 0; i = 0
            mov edi, 0; j = 0
            ;mov eax, result;

            ;mov ecx, dword ptr _first_string
            ;mov edx, dword ptr _second_string

            body_:
            cmp [ecx+esi], 0 ; _first_string
                       je end_
            cmp [edx+edi], 0; _second_string
           
            je end_; while (first_string[i] != '/0' || second_string[j] != '/0')


            mov bl, byte ptr [ecx+esi ]
           ;mov cl, byte ptr _second_string[edi * 1]
            cmp bl, [edx+edi]
            je equal_;  if (first_string[i] == second_string[j])
            jg greater_;  if (first_string[i] > second_string[j])

            mov eax, 2; result = 2; if (first_string[i] < second_string[j])
            jmp end_

            equal_ :
            inc esi; ++i
            inc edi; ++j
            jmp body_

            greater_ :
            mov eax, 1;  result = 1;
            jmp end_

            end_ :
            

ret
@StrCompare@8 endp

end 
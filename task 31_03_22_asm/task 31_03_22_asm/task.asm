.386 
PUBLIC @Max@8 
PUBLIC @IntToHex@8
PUBLIC @IntToOct@8
PUBLIC @CharByIndex@8
PUBLIC @StrCompare@8
PUBLIC @StrChar@8
PUBLIC @IntToDec@8 
PUBLIC @StrToInt32@4 

 
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
and ebx, 15
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
and ebx,7
mov al, abc[ebx]
mov [edx+ecx - 1], al
shr esi, 3
loop m_begin2

ret
@IntToOct@8 endp


@StrToInt32@4 proc
xor eax, eax; собираем число
xor ebx, ebx
xor edx, edx; индекс по строке числа

    m_begin3 :
mov bl, [ecx+edx]
cmp bl, 0; не конец строки
je m_end3
imul eax, 10
sub bl, '0'; в цифру  
add eax, ebx
inc edx
jmp m_begin3
     
     m_end3 :
       
ret
@StrToInt32@4 endp


@CharByIndex@8 proc
  ;mov ecx, dword ptr string;
  ;mov edx, index;
xor eax, eax
xchg ecx, edx
mov ebx, 0; int i = 0
cmp ecx, 0
jl CharByIndexEnd
;;;;;;mov ah, 0
  
  CharByIndexMain:
cmp ecx, ebx
je CharByIndexEqual

cmp  byte ptr [edx+ebx], 0 ;;;;;ah
je CharByIndexEnd
inc ebx
            
jmp CharByIndexMain

   CharByIndexEqual:
xor eax, eax
mov al, [edx+ebx]
   ret
           
   CharByIndexEnd:
mov al, 0
   ret

@CharByIndex@8 endp


@StrCompare@8 proc
    ; first str is in ecx
    ; second str is in edx
    
    beginStrCompare:
    mov bl, [ecx]
    cmp bl, [edx]
    jne not_equal_
    mov al, 0
    cmp [ecx], al
    je equal_
    inc ecx
    inc edx
    jmp beginStrCompare

    equal_:
    mov eax, 0
    ret

    not_equal_:
    xor eax, eax
    mov al, [ecx]
    sub al, [edx]
    movsx eax, al
    ret

@StrCompare@8 endp


@StrChar@8 proc
    ; str is in ecx
    ; char is in dl
    mov bl,0

    beginStrChar:
    cmp [ecx], dl
    je equalStrChar
   
    cmp [ecx], bl
    je not_found
    inc ecx
    jmp beginStrChar

    not_found:
    mov eax, 0
    ret


    equalStrChar:
    mov eax, ecx
    ret
@StrChar@8 endp

@IntToDec@8 proc
    ; ecx is number
    ; edx is str

    push edx
    mov eax, ecx
    push ecx
    mov ecx, 0

    beginIntToDec:
    cmp eax, 0
    je beginIntToDec_exit
    mov ebx, 10
    cdq
    idiv ebx
    
    inc ecx
    jmp beginIntToDec

    beginIntToDec_exit:
    pop eax
    pop ebx
    mov dl, 0
    mov [ebx+ecx], dl

    bodyIntToDec:
    push ebx
    mov ebx, 10
    cdq
    idiv ebx
    
    pop ebx
    add edx, '0'
    mov [ebx+ecx-1], dl
    loop bodyIntToDec

    ret
@IntToDec@8 endp

@Max@8 proc 
   ; ecx - int** 
   ; edx - int n
  
   mov ebx, [ecx]; A[0]
   mov eax, [ebx]; A[0][0]
   mov ebx,0; i, j
   
   first_for:
   cmp ebx, edx; i<n
   jge endMax_
   push ebx; запоминаю і
  
   mov ebx, 0; для j
   second_for:
    
   cmp  ebx, edx; j<n
   jge check_

   push edx; размер в стек, возьмем для массива
   mov edx, [ecx]; A[i]
   cmp  [edx+ebx*4], eax; A[i][j]
   jg new_max
   inc ebx
   pop edx; вернули размер n
   jmp second_for

   new_max:
   mov eax, [edx+ebx*4]
   inc ebx
   pop edx; вернули размер n
   jmp second_for

   check_:
   pop ebx; значение i
   inc ebx; i++
   add ecx, 4; A[i++]
   jmp first_for

 endMax_:
          ret 
@Max@8 endp 
 
   
 end
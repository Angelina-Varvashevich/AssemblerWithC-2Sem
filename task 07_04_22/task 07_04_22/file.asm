.386
.model flat

public @CreateVectorB@16
public _FindSaddlePoints@16

.data
A dd 0
m dd 0
n dd 0
i dd 0
j dd 0

.code
@CreateVectorB@16 proc
;int A[][M], ecx
;int N, edx
;int M, first == esp+4
;int* B second== esp+4+4

	mov A, ecx
	mov n, edx
	mov eax, [esp+4]
	mov m, eax
	mov i, 0
	mov j, 0
	mov edx, [esp+8]; int*B

		bodyCreateVectorB:

	mov eax, n; columns
	cmp i, eax
	je EqualCl

	mov j, 0
	mov ecx, 0; counter=0 после обхода прохода по столбцу

		For_j:
	mov eax, m
	cmp j, eax
	je EqualRw

	push ecx; тк задействованы в GetElement
	push edx; тк задействованы в GetElement
	push j
	push i
	call GetElement
	pop edx
	pop ecx

	cmp eax,0; A[j][i]==0
	jne NotEqualZero
	inc ecx

		NotEqualZero:
	inc j
	jmp For_j

		EqualRw:
	mov [edx], ecx; B[k]= counter
	add edx, 4
	inc i
	jmp bodyCreateVectorB

		EqualCl:
	ret 8
@CreateVectorB@16 endp 


GetElement proc; i->esp+4, j->esp+8
	mov ecx, [esp+4]; i
	mov eax, [esp+8]; j
	cdq; edx:eax
	mul n; j*n 
	add eax, ecx; j*n +i

	mov edx, eax
	mov ecx, [A]
	mov eax, [ecx+edx*4]

	ret 8
GetElement endp

_FindSaddlePoints@16 proc
;int matrix[][M], esp+4
;int n, esp+8
;int m, esp+12
;int* results esp+16
mov i,0
mov j,0
mov ecx, [esp+4]
mov A, ecx
mov ecx, [esp+8]
mov n, ecx
mov ecx, [esp+12]
mov m, ecx
mov ecx, 0;counter
mov edx, [esp+16]; result 

	ForRows:
mov eax, n
cmp i, eax
je EqualRows_

mov j,0
	ForColumn:
mov eax, m
cmp j, eax
je ColumnExit

push ecx
push edx
call IsMin
mov edx, eax
push edx
call IsMax
pop edx

and edx, eax
cmp edx, 1
jne NotSaddlePoint

push i
push j
call GetElement2
pop edx
pop ecx
mov [edx+ecx*4], eax
inc ecx
inc j 
jmp ForColumn

	NotSaddlePoint:
pop edx
pop ecx
inc j
jmp ForColumn

	ColumnExit:
inc i
jmp ForRows

	EqualRows_:
mov eax, ecx
ret 16
_FindSaddlePoints@16 endp


IsMin proc 
push i
push j
call GetElement2
mov edx, eax; current_element
mov ecx, 0; j, не push j

	ForRowsMin:
cmp ecx, m
je min
push ecx
push edx

push i
push ecx
call  GetElement2
pop edx
pop  ecx

cmp edx, eax
jg not_min
inc ecx
jmp ForRowsMin

	not_min:
mov eax, 0
ret

	min:
mov eax,1
ret
IsMin endp

IsMax proc
push i
push j
call GetElement2
mov edx, eax; current_element
mov ecx, 0; не push i

	ForColumnsMax:
cmp ecx, n
je max
push ecx
push edx

push ecx
push j
call  GetElement2
pop edx
pop  ecx
cmp edx, eax
jl not_max
inc ecx
jmp ForColumnsMax

	not_max:
mov eax, 0
ret

	max:
mov eax,1
ret
IsMax endp

GetElement2 proc; j->esp+4, i->esp+8
	mov ecx, [esp+4]; j
	mov eax, [esp+8]; i
	mul eax, m; i*m 
	add eax, ecx; i*m +j
	mov edx, eax
	mov ecx, [A]
	mov eax, [ecx+edx*4]

	ret 8
GetElement2 endp
end
.586
.model flat


.code
Proc1 proc C, x:QWORD, y:QWORD, result1:DWORD
	mov edx, result1
	finit
	fld y; st(2)
	fld y; st(1)
	fld x;st(0)
	
	fdiv st(0), st(1); x/y in st(0)

	fptan; st(0)=1, st(1)=tg(x/y), st(2)=y

 
	fst st(2); st(2)=1, 
	fxch; 1 in st(1), tg(x/y) in st(0)
	fdiv  st(2), st(0); st(2)= ctg(x/y)

	         ; st(0)=tg(x/y), st(1)=1, st(2)=ctg(x/y)
	
	
	fld x; st(0)=x; st(1)=tg(x/y), st(2)=1, st(3)=ctg(x/y)
	fmul st(0), st(0); st(0)=x*x
	fmul st(0), st(1); st(0)=x*x*tg(x/y)
	fld y; st(0)=y; st(1)=x*x*tg(x/y); st(2)=tg(x/y); st(3)=1, st(4)=ctg(x/y)

	
	fmul st(0), st(0); st(0)=y*y
	fmul st(0), st(4); st(0)=y*y*ctg(x/y)
	fadd st(0), st(1); st(0)=y*y*ctg(x/y)+x*x*tg(x/y)
	fstp QWORD ptr [edx]
	ret
Proc1 endp







Proc3 proc STDCALL, delta:QWORD, tw:QWORD, result:DWORD
LOCAL k:QWORD,  current_sum:QWORD, current_el:QWORD, rub:QWORD
mov ebx, result
mov eax, 1; k_int =1
finit

fld1 
fstp k; k=1

fldz
fstp current_sum; current_sum=0

fldz
fstp current_el; current_el=0

fldz
fstp rub

body_:
fld k; 
fld1; st(0)=1, st(1)=k
fdiv st(0), st(1); st(0)=1/k, st(1)=k
fdiv st(0), st(1); st(0)=1/(k*k), st(1)=k

push eax
mov eax, 0
fcom delta; st(0)<delta
fstsw ax
sahf 
pop eax
jb delta_greater; st(0)<delta

fstp current_el; current_el=1/(k*k), st(0)=k
fld1; st(0)=1, st(1)=k 
fadd st(0), st(1); st(0)=k+1, st(1)=k
fstp k; k=k+1, st(0)=k
fstp rub; st is empty

mov ecx, 1
push eax
mul ecx; edx:eax
mov ecx, 2
div ecx; k%2=r in edx


fld current_el
fld current_sum; st(0)=current_sum, st(1)=current_el

cmp edx, 1
jne equal_zero
fadd st(0), st(1)
fstp current_sum
fstp rub; st is empty
pop eax
inc eax; inc k_int
jmp body_


equal_zero:
fsub st(0), st(1)
fstp current_sum
fstp rub; st is empty
pop eax
inc eax; inc k_int
jmp body_

delta_greater:
fstp rub
fstp rub; st is empty
fld tw
fld current_sum; st(0)=current_sum, st(1)=12
fmul st(0), st(1)
fsqrt; s(0)=current pi
fstp QWORD ptr [ebx]
ret 20
Proc3 endp



end

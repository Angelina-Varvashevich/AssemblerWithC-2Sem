// task 14_04_22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include<math.h>
extern "C" void _cdecl Proc1(double, double, double*);
extern "C" void _stdcall Proc2(double, double, double, double, double, double, double*);
extern "C" void _stdcall Proc3(double, double, double*);

double Expression(double x, double a, double b, double c) {

	return pow(x, 3.0) + a * pow(x, 2.0) + b * x + c;
}

int main()
{
	double x = 3.14;
	double y = 2.0;
	double result1 = x * x * tan(x / y) + y * y * (1 / tan(x / y));

	std::cout <<"result1= "<< std::setprecision(20)<< result1<< std::endl;
	result1 = 0.;

	Proc1(x, y, &result1);
	std::cout << "result1= " << std::setprecision(20) << result1 << std::endl;

	double result = 0.;
	double delta = 0.0000001;
	double tw = 12.0;
	Proc3(delta,tw, &result);
	std::cout << "result= " << result<< std::endl;


    const double eps = 0.000001;
    double a=2, b=3, c=2, begin=-10, end=10;
	double x_ = 0.;
	while (end - begin > eps) {
		double vbegin = Expression(begin, a, b, c);
		double middle = (begin + end) / 2;
		double vmiddle = Expression(middle, a, b, c);
		if (vbegin * vmiddle > 0) {
			begin = middle;
		}
		else {
			end = middle;
		}
	}

	x_= begin;

	std::cout << x_;

	/*Expr proc
fld current_x; st(0)=current
fmul st(0), st(0);
fmul st(0), st(0); st(0)=current^3
fstp vcurrent;  vcurrent=current^3

fld current_x;
fmul st(0), st(0);
fld a_; st(0)=a, st(1)=current^2
fmul st(0), st(1); st(0)=a*current^2, st(1)= current^2

fld vcurrent; st(0)=vcurrent, st(1)=a*current^2, st(2)= current^2
fadd st(0), st(1); st(0)=current^3 +a*current^2,  st(1)=a*current^2
fstp vcurrent
fstp rub
fstp rub;  vcurrent=current^3 +a*current^2

fld current_x;
fld b_
fmul st(0), st(1);st(0)=b*current,  st(1)=current_x

fld vcurrent; st(0)=vcurrent, st(1)=b*current,  st(2)=current_x
fadd st(0), st(1);
fstp vcurrent; vcurrent=current^3 +a*current^2+ b*current
fstp rub
fstp rub;

fld c_
fld vcurrent
fadd st(0), st(1)
fstp vcurrent; vcurrent=current^3 +a*current^2+ b*current+c
fstp rub

ret
Expr endp 


Proc2 proc STDCALL, begin_:QWORD, end_:QWORD, eps_:QWORD, a_:QWORD, b_:QWORD, c_:QWORD, x_:DWORD
LOCAL vbegin:QWORD,  vmiddle:QWORD, middle:QWORD, rub:QWORD, vcurrent:QWORD, current_x:QWORD, fzero:QWORD

mov ebx, x_

fldz
fstp fzero
finit
body_:
fld begin_
fld end_; st(0), st(1)
fsub st(0), st(1); delta

push eax
mov eax, 0
fcom eps_; st(0)<eps
fstsw ax
sahf 
pop eax
jb find_x; st(0)<eps


fstp rub;;;;
fstp rub;;;;
fld begin_
fstp current_x
call Expr; st(0)=vbegin
fstp vbegin

fld1
fadd st(0),st(0); 2
fld begin_
fld end_; st(0)=end, st(1)=begin, st(2)=2
fadd st(0), st(1)
fdiv st(0), st(2); st(0)=(end+begin)/2, st(1)=begin, st(2)=2
fstp middle;
fstp rub
fstp rub

fld middle
fstp current_x
call Expr; st(0)=vbegin
fstp vmiddle

fld vmiddle
fld vbegin; st(0)= vbegin, st(1)=vmiddle
fdiv st(1), st(0); st(1)=vbegin*vmiddle, st(0)=vbegin
fstp rub; st(0)=vbegin*vmiddle


push eax
mov eax, 0
fcom fzero; st(0)<eps
fstsw ax
sahf 
pop eax
jb less_; st(0)<eps
fstp rub;;;;
fld middle
fstp begin_
jmp body_


less_:
fstp rub;;;;;
fld middle
fstp end_
jmp body_


find_x:
fstp rub;;;;
fstp rub;;;;
fld begin_
fstp QWORD ptr [ebx]
ret 52
Proc2 endp
*/

	return 0;
}


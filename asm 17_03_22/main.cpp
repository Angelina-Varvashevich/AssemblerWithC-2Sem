#include <iostream>

int compare(const void *arg1, const void *arg2) {
    int *pi1 = (int *) arg1;
    int *pi2 = (int *) arg2;
    return *pi1 - *pi2;
}

int main() {
// a*b+b*c+a*c
/*char a=200;
short b=14;
int c=5;
int result;
int of;
_asm{
    movsx eax, a
    movsx ebx,b
    movsx ecx, c

    mov esi, 0;
    mov esi, eax
    imul  esi, ebx; a*b

    imul ebx, ecx; b*c

    imul ecx, eax;a*c

    add result, esi
    add result, ebx
    add result, eax

    jno not_of; of=0
    mov of, 1

not_of:
    mov of, 0
};
    std::cout<<of;

std::cout<<result;*/
    char t = 0x2c;
    std::cout << t;
    char a = -15;
    std::cout << a;
    char b = 0xf1;
    std::cout << b;


    int A[] = {1, -3, 5, 2, 3};
    int size = std::size(A);

    qsort(A, size, sizeof(int), compare);
    for (auto i: A) {
        std::cout << i << " ";
    }
    int key = 8;
    void *result = bsearch(&key, A, size, sizeof(int), compare);
    std::cout<< result;
    return 0;
}

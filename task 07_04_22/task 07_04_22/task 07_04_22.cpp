#include <iostream>

const int M = 4;

extern "C" void __fastcall CreateVectorB(unsigned int A[][M], int N, int M, int* B);
extern "C" int __stdcall FindSaddlePoints(int matrix[][M], int n, int m, int* results);

int main() {
    const int m = 4;
    const int n = 4;
    int A[m][n] = {
        {1, 0,  0, 0},
        {2, -1, 0, 0},
        {3, 2,  0, 0},
        {0, 0,  9, 0}
    };
    
    int B[n];
    _asm {
        lea eax, B; mov eax, B, если динамический
        lea ecx, A; A  in ecx
        mov edx, n;
        push eax;
        push m;
        call CreateVectorB; 
    };
    /*int k_B = 0;
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        for (int j = 0; j < m; ++j) {
            if (A[j][i] == 0) ++counter;
        }
        B[k_B] = counter;
        ++k_B;
    }*/
    
    for (int i = 0; i < n; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;
    int matrix[n][m] = {
        {3, 3, 3, 3},
        {3, 3, 3, 3},
        {3, 3, 0, 3},
        {3, 3, 3, 3}
    };
    int results[100];
  
    std::cout << "Number of saddle points is " << FindSaddlePoints(matrix, 4, 4, results) << std::endl;
    std::cout<<"Saddle points: ";

    for (int i = 0; i < FindSaddlePoints(matrix, 4, 4, results); ++i) {
        std::cout << results[i] << " ";
    }
  
    

    return 0;
}
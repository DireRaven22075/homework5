#include <stdio.h>
#include <stdlib.h>
void print_matrix();
void addition_matrix();
void subtraction_matrix();
void multiply_matrix();
void transpose_matrix();
void free_matrix();
int main (void) {
    //행렬 A, B, C 선언
    int **A, **B, **C;

    //행렬 A, B의 행과 열의 개수를 입력받는다.
    int Arows, Acols, Brows, Bcols;
    printf("A의 행과 열의 개수를 입력하세요: ");
    scanf("%d %d", &Arows, &Acols);
    printf("B의 행과 열의 개수를 입력하세요: ");
    scanf("%d %d", &Brows, &Bcols);

    //행렬 A, B의 메모리를 동적할당한다.
    A = (int **)malloc(sizeof(int *) * Arows);
    for (int i = 0; i < Arows; i++) {
        A[i] = (int *)malloc(sizeof(int) * Acols);
    }
    B = (int **)malloc(sizeof(int *) * Brows);
    for (int i = 0; i < Brows; i++) {
        B[i] = (int *)malloc(sizeof(int) * Bcols);
    }
    return 0;
}
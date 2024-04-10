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
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
//s == source
void print_matrix(int** s, int row, int col);
void addition_matrix(int** s1, int** s2, int** out, int row, int col);
void subtraction_matrix(int** s1, int** s2, int** out, int row, int col);
void multiply_matrix(int** s1, int** s2, int** out, int row, int col);
void transpose_matrix(int** s, int** out, int row, int col);
void free_matrix(int** matrix, int row, int col);

int main (void) {
    //행렬 A, B, C, 정수 row, col 선언
    int **A, **B, **C, row, col;
    //난수 생성을 위한 srand함수 호출
    srand(time(NULL));
    //행렬 A, B의 행과 열의 개수를 입력받는다.
    printf("행과 열의 개수를 입력하시오 >> ");
    scanf("%d %d", &row, &col);
    //행렬 A, B, C의 메모리를 동적할당한다.
    A = (int**)malloc(sizeof(int*) * row);
    B = (int**)malloc(sizeof(int*) * row);
    C = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        A[i] = (int*)malloc(sizeof(int) * col);
        B[i] = (int*)malloc(sizeof(int) * col);
        C[i] = (int*)malloc(sizeof(int) * col);
    }
    //행렬 A, B에 난수를 생성하여 저장한다.
    //렌덤 값은 0 ~ 9까지로 지정함
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }
    return 0;
}
//행렬을 출력하는 함수
void print_matrix(int** s, int row, int col) {
    //행을 반복하는 반복문
    for (int i = 0; i < row; i++)
        //열을 반복하는 반복문
        for (int j = 0; j < col; j++)
            //마지막 열이면 줄을 바꾼다.
            printf(j == col - 1 ? "%d\n" : "%d ", s[i][j]);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//난수 입력용 함수
void rand_matrix(int** s, int row, int col);
//출력용 함수
void print_matrix(int** s, int row, int col);
//행렬 덧셈용 함수
void addition_matrix(int** s1, int** s2, int row, int col);
//행렬 뺄셈용 함수
void subtraction_matrix(int** s1, int** s2, int row, int col);
//행렬 곱셈용 함수
void multiply_matrix(int** s1, int** s2, int row1, int col1, int row2, int col2);
//행렬 전치용 함수
void transpose_matrix(int**, int row, int col);
//동적 할당 해제용 함수
void free_matrix(int**, int row, int col);
//출력 행렬 동적 할당용 함수
void set_out_matrix(int**, int row, int col);
int main (void) {
    //학번 출력
    printf("[--------------[2023041004][한윤수]--------------]\n");
    //행렬 A, B, 정수 Arow, Acol, Brow, Bcol를 선언한다.
    int **A = 0, **B = 0, Arow, Acol, Brow, Bcol;
    //난수 생성을 위한 srand함수 호출
    srand(time(NULL));
    //행렬 A, B의 행과 열의 개수를 입력받는다.
    scanf("%d %d", &Arow, &Acol);
    scanf("%d %d", &Brow, &Bcol);
    //행렬 A, B, C의 메모리를 동적할당한다.
    A = (int**)malloc(sizeof(int*) * Arow);
    for (int i = 0; i < Arow; i++)
        A[i] = (int*)malloc(sizeof(int) * Acol);
    B = (int**)malloc(sizeof(int*) * Brow);
    for (int i = 0; i < Brow; i++)
        B[i] = (int*)malloc(sizeof(int) * Bcol);

    //행렬 A, B에 난수를 입력한다.
    rand_matrix(A, Arow, Acol);
    rand_matrix(B, Brow, Bcol);
    printf("행렬 A\n");
    print_matrix(A, Arow, Acol);
    printf("행렬 B\n");
    print_matrix(B, Brow, Bcol);

    printf("행렬 A + B\n");
    addition_matrix(A, B, Arow, Acol);
    printf("행렬 A - B\n");
    subtraction_matrix(A, B, Arow, Acol);
    printf("행렬 A * B\n");
    multiply_matrix(A, B, Arow, Acol, Brow, Bcol);
    printf("행렬 A의 전치\n");
    transpose_matrix(A, Arow, Acol);
    printf("행렬 B의 전치\n");
    transpose_matrix(B, Brow, Bcol);
    free_matrix(A, Arow, Acol);
    free_matrix(B, Brow, Bcol);
    return 0;
}
void rand_matrix(int** s, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            s[i][j] = rand() % 10;
}
void set_out_matrix(int** out, int row, int col) {
    out = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
        out[i] = (int*)malloc(sizeof(int) * col);
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
//행렬의 덧셈수행하고 출력하는 함수
void addition_matrix(int** s1, int** s2, int row, int col) {
    int** out = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
        out[i] = (int*)malloc(sizeof(int) * col);
    //행을 반복하는 반복문
    for (int i = 0; i < row; i++)
        //열을 반복하는 반복문
        for (int j = 0; j < col; j++)
            //행렬의 각 원소를 더하여 out에 저장한다.
            out[i][j] = s1[i][j] + s2[i][j];
    print_matrix(out, row, col);
    free_matrix(out, row, col);
}
//행렬의 뺄셈을 out 행렬에 저장하는 함수
void subtraction_matrix(int** s1, int** s2, int row, int col) {
    int** out = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
        out[i] = (int*)malloc(sizeof(int) * col);
    //행을 반복하는 반복문
    for (int i = 0; i < row; i++)
        //열을 반복하는 반복문
        for (int j = 0; j < col; j++)
            //행렬의 각 원소를 빼서 out에 저장한다.
            out[i][j] = s1[i][j] - s2[i][j];
    print_matrix(out, row, col);
    free_matrix(out, row, col);
}
//전치 행렬을 out 행렬에 저장하는 함수
void transpose_matrix(int** s, int row, int col) {
    int** out = (int**)malloc(sizeof(int*) * col);
    for (int i = 0; i < row; i++)
        out[i] = (int*)malloc(sizeof(int) * row);
    //행을 반복하는 반복문
    for (int i = 0; i < row; i++)
        //열을 반복하는 반복문
        for (int j = 0; j < col; j++)
            //행렬의 각 원소를 전치하여 out에 저장한다.
            out[j][i] = s[i][j];
    print_matrix(out, col, row);
    free_matrix(out, col, row);
}
void multiply_matrix(int** s1, int** s2, int row1, int col1, int row2, int col2) {
    //행렬의 곱셈이 불가능할 경우 오류 메시지를 출력하고 함수를 종료한다.
    if (col1 != row2) {
        printf("곱셈 불가\n");
        return;
    }
    //곱셈 결과를 저장할 out 행렬을 동적할당한다.
    int** out = (int**)malloc(sizeof(int*) * row1);
    for (int i = 0; i < row1; i++)
        out[i] = (int*)malloc(sizeof(int) * col2);

    //행렬의 곱셈을 수행하는 반복문
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            out[i][j] = 0; 
            for (int k = 0; k < col1; k++) {
                out[i][j] += s1[i][k] * s2[k][j];
            }
        }
    }
    print_matrix(out, row1, col2);
    free_matrix(out, row1, col2);
}
void free_matrix(int** s, int row, int col) {
    for (int i = 0; i < row; i++)
        free(s[i]);
    free(s);
}
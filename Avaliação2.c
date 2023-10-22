#include <stdio.h>
//Isaias Fabricio da Costa - LLP 2023.2
void somaMatrizes(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("C[%d][%d] = A[%d][%d] + B[%d][%d] = %d + %d = %d\n", i, j, i, j, i, j, A[i][j], B[i][j], C[i][j]);
        }
    }
}

int main() {
    int n = 3;  // Tamanho das matrizes (n x n)

    int A[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3];

    somaMatrizes(n, A, B, C);

    // Imprimindo a matriz C (soma de A e B)
    printf("\nMatriz C (A + B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
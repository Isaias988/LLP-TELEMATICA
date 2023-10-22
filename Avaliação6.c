#include <stdio.h>
//Isaias Fabricio da Costa - LLP 2023.2
int somatorio(int N) {
    if (N == 0) {
        return 0;
    } else {
        return N + somatorio(N - 1);
    }
}

int main() {
    int N;
    printf("Informe o valor de N: ");
    scanf("%d", &N);

    int resultado = somatorio(N);

    printf("O somatório de %d é igual a %d\n", N, resultado);

    return 0;
}

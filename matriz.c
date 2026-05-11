#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void preencheMatriz(int **m, int L, int C) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

float calculaMediaMatriz(int **m, int L, int C) {
    int soma = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            soma += m[i][j];
        }
    }
    return (float)soma / (L * C);
}

int valorProximoMatriz(int **m, int L, int C) {
    float media = calculaMediaMatriz(m, L, C);
    float menordif = 999999.0;
    int valorEscolhido = m[0][0];

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            float dif = fabs(media - m[i][j]);
            if (dif < menordif) {
                menordif = dif;
                valorEscolhido = m[i][j];
            }
        }
    }
    return valorEscolhido;
}

int main(void) {
    int L, C;
    printf("Digite a quantidade de linhas: ");
    scanf("%d", &L);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &C);

    int **mat = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        mat[i] = (int *)malloc(C * sizeof(int));
    }

    printf("\n--- Preenchendo a Matriz ---\n");
    preencheMatriz(mat, L, C);

    float media = calculaMediaMatriz(mat, L, C);
    printf("\nA media calculada foi de: %.2f\n", media);

    int valor = valorProximoMatriz(mat, L, C);
    printf("O valor mais proximo da media e: %d\n", valor);

    for (int i = 0; i < L; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

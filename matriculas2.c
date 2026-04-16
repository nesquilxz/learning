#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void preencheturma(int *v, int n) {

    for (int i =0; i < n; i++) {

        printf("Digite a matricula do aluno numero %d:  ", i+1);
        scanf("%d", &v[i]);
    }


}


void verificairregulares(int *v1, int *v2, int n1, int n2) {

    for(int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (v1[i] == v2[j]) {
                printf("Aluno com a matricula: %d esta irregular!", v1[i]);
            }
        }
    }



}



int main(void) {

    int N, M, i;

    int *prog1, *prog2;


    printf("Digite a quantidade de alunos de Prog 1: ");
    scanf("%d", N);
    prog1 = (int *) malloc(sizeof(int) * N);


    printf("Digite a quantidade de alunos de Prog 2: ");
    scanf("%d", M);
    prog2 = (int *) malloc(sizeof(int) * M);


    printf("\n Digite as matrículas dos alunos de prog1\n");
    preencheturma(prog1, N);


    printf("\n Digite as matrículas dos alunos de prog2\n");
    preencheturma(prog2, M);

    verificairregulares(prog1, prog2, N, M);
}

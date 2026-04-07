#include <stdio.h>

typedef struct {
    float p1;
    float p2;
    float p3;
    float soma;
    float media;
} Aluno;

int main() {

    int alunos;
    printf("Digite quantos alunos são desta turma: ");
    scanf("%d", &alunos);

    Aluno turma[alunos];

    for(int i = 0; i < alunos; i++) {

        printf("== %dº aluno ==\n", i+1);

        printf("Digite a nota da P1: ");
        scanf("%f", &turma[i].p1);

        printf("Digite a nota da P2: ");
        scanf("%f", &turma[i].p2);

        printf("Digite a nota da P3: ");
        scanf("%f", &turma[i].p3);

        turma[i].soma =
            turma[i].p1 +
            turma[i].p2 +
            turma[i].p3;

        turma[i].media = turma[i].soma / 3;
    }

    int qntd = 0;

    for(int i = 0; i < alunos; i++) {
        if(turma[i].media > 6) {
            qntd++;
        }
    }

    printf("\n%d alunos passaram!\n", qntd);

    return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float p1, p2, p3, p4;
    int anoIngresso;
    float media;
} Aluno;

float calcularMedia(float p1, float p2, float p3, float p4) {
    return (p1 + p2 + p3 + p4) / 4.0;
}

int main() {
    int n;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    Aluno alunos[n];

    for (int i = 0; i < n; i++) {
        printf("\n=== Aluno %d ===\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].p1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].p2);

        printf("Nota 3: ");
        scanf("%f", &alunos[i].p3);

        printf("Nota 4: ");
        scanf("%f", &alunos[i].p4);

        printf("Ano de ingresso: ");
        scanf("%d", &alunos[i].anoIngresso);

        alunos[i].media = calcularMedia(
            alunos[i].p1,
            alunos[i].p2,
            alunos[i].p3,
            alunos[i].p4
        );
    }

    float maior = alunos[0].media;

    for (int i = 1; i < n; i++) {
        if (alunos[i].media > maior) {
            maior = alunos[i].media;
        }
    }

    printf("\nMaior média: %.2f\n", maior);
    printf("Aluno(s) com maior média:\n");

    for (int i = 0; i < n; i++) {
        if (alunos[i].media == maior) {
            printf("Nome: %s | Média: %.2f\n", alunos[i].nome, alunos[i].media);
        }
    }

    return 0;
}

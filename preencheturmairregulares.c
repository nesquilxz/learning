#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void preencheturma(int *v, int n) {

    for (int i =0; i < n; i++) {

        printf("Digite a matricula do aluno numero %d:  ", i+1);
        scanf("%d", &v[i]);
    }


}


void irregulares(int *v1, int *v2, int n1, int n2) {

    for(int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (v1[i] == v2[j]) {
                printf("Aluno com a matricula: %d esta irregular!", v1[i]);
            }
        }
    }



}




int main(void)  {

int NALUNOS1, NALUNOS2;

printf("Digite a quantidade de alunos de Prog 1: ");
scanf("%d", &NALUNOS1);

printf("Digite a quantidade de alunos de Prog 2: ");
scanf("%d", &NALUNOS2);


int turma1[NALUNOS1], turma2[NALUNOS2];


printf("Para os alunos de Prog 1: ");
preencheturma(turma1, NALUNOS1);


printf("Para os alunos de Prog 2: ");
preencheturma(turma2, NALUNOS2);

printf("\n\n Agora, vamos ver os alunos que estão irregulares (matriculados em ambas as turmas): \n\n");


irregulares(turma1, turma2, NALUNOS1, NALUNOS2);



}

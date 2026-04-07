#include <stdio.h>

main() {

int alunos;
printf("Digite quantos alunos são desta turma: ");
scanf("%d", &alunos);

float media[alunos], soma, nota;


for(int i = 0; i <= alunos-1; i++) {

    printf(" == %d* aluno == \n ", i +1);
    soma = 0;

    for(int j = 1; j <= 3; j++) {
        printf("Digite a nota da P%d do %d aluno: ", j, i+1);
        scanf("%f", &nota);
        soma += nota;
    }

    media[i] = soma/3;


}

int qntd = 0;


for (int i = 0; i < alunos; i ++) {
    if(media[i] > 6) {
        qntd++;
    }
}

printf(" \n \n%d alunos passaram!", qntd);

return 0;



}

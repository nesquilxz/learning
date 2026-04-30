#include <stdio.h>
#include <string.h>
#define N 10


typedef struct aluno {

    char nome[100];
    float p1, p2, p3, p4;
    int anoingresso;

}Taluno;

void leraluno(Taluno *a) {

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", a->nome);
    printf("Digite a nota da p1, p2, p3 e p4 do aluno (separado por espaço): ");
    scanf("%f %f %f %f", &a->p1, &a->p2, &a->p3,&a->p4 );

}

float calculamedia(Taluno *a) {
    float media = (a->p1+ a->p2+ a->p3+a->p4 )/4.0;
    return media;
}


int main(void) {

float mediamaior = 0, media; 
char alunotop[100];
Taluno alunos[N];


for(int i =0; i < N; i++) {
    leraluno(&alunos[i]);
    media = calculamedia(&alunos[i]);
    if (media > mediamaior) {
        mediamaior = media;
        strcpy(alunotop, alunos[i].nome);
    }
}


printf("O aluno com maior media é: %s, com incriveis: %.2f!", alunotop, mediamaior);



}

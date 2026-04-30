#include <stdio.h>
#include <string.h>
#define MES 3

typedef struct equipe {

    char nome[100];
    int quantidade[MES];

} tEquipe;



void lerdados(tEquipe *a) {

    printf("Digite o nome da equipe: "); 
    scanf("%s", a->nome);
    

    printf("Digite a quantidade produzida: \n\n"); 

    for(int i = 0; i < MES; i++) {
            printf("No mes %d: ", i+1);
            scanf("%d", &a->quantidade[i]);
        
    }


}

int calculamedia(tEquipe *a) {
    int media = (a->quantidade[0] + a->quantidade[1] + a->quantidade[2]) / 3;
    return media;
}




int main(void) {

int n;
printf("Digite a quantidade de equipes na empresa: ");
scanf("%d", &n);

tEquipe Equipes[n];
int menorMedia = 9999, maiorMedia = 0;
char melhorequipe[100], piorequipe[100];

for(int i =0; i < n; i++) {
    printf("===== Para a equipe %d =====\n\n", i+1);
    lerdados(&Equipes[i]);

    int mediaAno = calculamedia(&Equipes[i]);

    if(mediaAno > maiorMedia) {
        maiorMedia = mediaAno;
        strcpy(melhorequipe, Equipes[i].nome);
    }

    if(mediaAno < menorMedia) {
        menorMedia = mediaAno;
        strcpy(piorequipe, Equipes[i].nome);
    }
    


}



printf("A equipe que se saiu melhor foi a equipe %s, com incriveis %d de media!\n\n", melhorequipe, maiorMedia);

printf("A equipe que se saiu pior foi a equipe %s, com  %d de media.\n\n", piorequipe, menorMedia);


}





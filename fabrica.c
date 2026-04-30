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

void maiormedia(int n, tEquipe *a) {


    int maior = 0; int media = 0; char equipemaior[100];

    for(int i = 0; i < n; i++) {
        
        media = (a[i].quantidade[0] + a[i].quantidade[1] + a[i].quantidade[2]) / 3;
        if (media > maior) {
            maior = media;
            strcpy(equipemaior, a[i].nome);
        }
    }

    printf("Equipe com maior media: %s. Alcançou uma media de: %d \n", equipemaior, maior);

}


void menormedia(int n, tEquipe *a) {


    int menor = 9999; int media = 0; char equipemenor[100];

    for(int i = 0; i < n; i++) {
        
        media = (a[i].quantidade[0] + a[i].quantidade[1] + a[i].quantidade[2]) / 3;
        if (media < menor) {
            menor = media;
            strcpy(equipemenor, a[i].nome);
        }
    }

    printf("Equipe com menor media: %s. Alcançou uma media de: %d \n", equipemenor, menor);

}




int main(void) {

int n;
printf("Digite a quantidade de equipes na empresa: ");
scanf("%d", &n);

tEquipe Equipes[n];


for(int i =0; i < n; i++) {
    printf("===== Para a equipe %d =====\n\n", i+1);
    lerdados(&Equipes[i]);


}


    maiormedia(n, Equipes);
    menormedia(n, Equipes);





}





#include <stdio.h>
#include <stdlib.h>

#define quantum 2

typedef struct fila {
    int processo;
    int texe;
    struct fila* prox;
    
} Tfila;


void preenchefila(Tfila**inicio, Tfila**fim, int processo, int texe) {
    Tfila *el;
    el = (Tfila*) malloc(sizeof(Tfila));
    el->processo = processo;
    el->texe = texe;
    el->prox = NULL;

 

    if (inicio == NULL) {
        (*inicio) = el;
        
    }

    else {
       
        (*fim)->prox = el;}

    
    (*fim) = el;

    
    

}


Tfila* removefila(Tfila* inicio, Tfila* fim, int *num, int *texe) {
    Tfila* lixo;

    if ((*inicio) != NULL) {
        *num = inicio->processo;
        *texe = inicio->texe;
        lixo = inicio;
        inicio = inicio->prox;
        free(lixo);
    }

    return a;

}




int main(void) {

Tfila* fila, *inicio, *fim;
inicio = NULL;
fim = NULL;
int n, processo, texe;
printf("Digite quantos nós de processo haverao inicialmente: ");
scanf("%d", &n);


for(int i = 0; i < n; i++) {

    printf("Digite o processo %d: ", i+1);
    scanf("%d", &processo);
    printf("Digite o tempo de execução do %d: ", i+1);
    scanf("%d", &processo);
    preenchefila(&inicio, &fim, processo, texe);

}

//Execução dos processos
printf("\n Ordem de execução: \n");

while(inicio != NULL) {

    inicio = removefila(inicio, fim, &processo, &texe);

    if (texe > quantum) {
        printf("\n Executando #P%d (%d)", processo, quantum);
        preenchefila(&inicio, &fim, processo, texe-quantum);
    }

    else {
        printf("\n Executando #P%d (%d)", processo, texe);
    }


}




}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct no
{
    int info;
    struct no* prox;
}Tlista;


int busca(Tlista*a, int numero, Tlista **pre) {

    Tlista *aux;
    aux = a;

    while((aux != NULL) && (aux->info < numero)) {
        (*pre) = aux;
        aux = aux->prox;
    }

    if((aux != NULL) && (aux->info == numero)) {
        return 1;
    }
    else {
        return 0;
    }


}

void insere(Tlista** a, int numero) {
    Tlista *pre = NULL; 
    int x;
    x = busca(*a, numero, &pre); 
    
    Tlista *el = (Tlista*) malloc(sizeof(Tlista));
    el->info = numero;
    
    if (pre == NULL) { 
        el->prox = *a;
        *a = el;
    } else {           
        el->prox = pre->prox;
        pre->prox = el;
    }
}


void imprime(Tlista *a) {

    Tlista *aux;
    aux = a;

    while(aux != NULL) {
        printf("%d \n", aux->info);
        aux = aux->prox;
    }

}





Tlista *intercalaprof (Tlista *a, Tlista *b) {

    Tlista *aux1, *aux2;

    aux1 = a;
    while(aux1 != NULL) {
        aux2 = b->prox;
        b->prox = aux1->prox;
        aux1->prox = b;
        aux1 = b->prox;
        b = aux2;
    }

    return a;
}




int main(void) {

    Tlista *l1, *l2;
    l1 = NULL;
    l2 = NULL;

    // Preenchendo a primeira lista
    for(int i = 0; i < N; i++) {
        int num1;
        printf("Digite o elemento que você deseja na pos %d na lista 1: ", i+1);
        scanf("%d", &num1);
        insere(&l1,num1);
    }

    for(int i = 0; i < N; i++) {
        int num2;
        printf("Digite o elemento que você deseja na pos %d na lista 2: ", i+1);
        scanf("%d", &num2);
        insere(&l2,num2);
    }

    printf(" === Lista 1 ===\n\n");
    imprime(l1);

    printf(" === Lista 2 ===\n\n");
    imprime(l2);



}











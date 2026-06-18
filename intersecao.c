#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 10


typedef struct no
{
    int info;
    struct no* prox;
}Tlista;




int busca (Tlista *a, int n, Tlista **pre) {

    Tlista *preL, *aux;
    preL = a;
    aux = preL->prox;

    while((aux != NULL)) {

        if (aux->info == n) {
            return 1;
        }
        preL = aux;
        aux = aux->prox;
    } 

    (*pre) = preL;
    return 0;

}


void insere (Tlista **a, int n) {
    Tlista *pre;
    if(!busca(*a, n, &pre)) {

        Tlista *el;
        el = (Tlista*) malloc(sizeof(Tlista));
        el->info = n;
        el->prox = pre->prox;
        pre->prox = el;
        
        
    }

   
}

Tlista* intersecao (Tlista *l1, Tlista *l2) { 

   
    Tlista *l3;
    l3 = (Tlista*) malloc(sizeof(Tlista));
    l3->prox = NULL;

    Tlista *aux1, *aux2;
    aux1 = l1->prox;
    aux2 = l2->prox;

    while(aux1 != NULL) {

        while(aux2->prox != NULL) { // buscaelem(l2, l1->num)

            if (aux1->info == aux2->info) {
            Tlista *novo;
            novo = (Tlista*) malloc(sizeof(Tlista));
            novo->info = aux1->info;
            novo->prox = l3->prox;
            l3->prox = novo;
        }

        aux2 = aux2->prox;

        }
        aux1 = aux1->prox;
    }


    return l3;

}

//fazer a da uniao!!



int main(void) {

    Tlista *l1, *l2;


    l1= (Tlista*) malloc(sizeof(Tlista));
    l1->prox = NULL;

    l2= (Tlista*) malloc(sizeof(Tlista));
    l2->prox = NULL;

    int num;

    for(int i = 0; i < max; i++) {
        
        printf("Digite o numero %d da lista 1", i+1);
        scanf("%d", &num);
        insere(&l1, num);

        printf("\n========\n");

        printf("Digite o numero %d da lista 2", i+1);
        scanf("%d", &num);
        insere(&l1, num);
    }


    Tlista *l3;
    l3 = (Tlista*) malloc(sizeof(Tlista));
    l3->prox = NULL;
    l3 = intersecao(l1, l2);


}

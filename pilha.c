#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no
{
    int info;
    struct lista *prox;
} Tpilha;



Tpilha* pull(Tpilha* topo, int elem) {

    Tpilha *novo = malloc(sizeof(Tpilha));
    novo->info = elem;
    novo->prox = topo;
    topo = novo;
    return novo;

}


Tpilha* pop(Tpilha *topo) {

    Tpilha*aux = (Tpilha*) malloc(sizeof(Tpilha));
    aux->info = topo->info;

    Tpilha *lixo = topo;
    topo = topo->prox;

    free(lixo);

    return aux;

}

// ou; 
Tpilha* pop(Tpilha *topo) {

    if(topo!=NULL) {

        Tpilha *lixo = topo;
    topo = topo->prox;
    free(lixo);

    }
    

    return topo;

}



int main(void) {

    Tpilha *topo;
    topo = NULL;

    // . . . testar funções
}


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    struct no *esq;
    struct no *dir;
} Tarvore;

typedef struct pilha {
    Tarvore *info;
    struct pilha *prox;
} Tpilha;

Tarvore *criaNo(char info, Tarvore *esq, Tarvore *dir) {
    Tarvore *novo = (Tarvore *) malloc(sizeof(Tarvore));

    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}

Tpilha *push(Tpilha *topo, Tarvore* info) {
    Tpilha *novo = (Tpilha*) malloc(sizeof(Tpilha));
    novo->info = info;
    novo->prox = topo;
    topo = novo;
    return novo;
}

Tarvore *pop(Tpilha** topo) {

    if (topo == NULL) {return NULL;}
    Tpilha *aux = (*topo);
    (*topo) = (*topo)->prox;
    Tarvore *info = aux->info;
    free(aux);
    return info;


}


void preordem(Tarvore* raiz, Tpilha **topo) {


    (*topo) = push((*topo), raiz);

    while (*topo != NULL)
    {
        Tarvore *atual = pop(topo);
        printf("%c ", atual->info);

        if (atual->dir) {
            (*topo) =  push((*topo), atual->dir);
        }

        if (atual->esq) {
             (*topo) = push((*topo), atual->esq);
        }
       
         

    }
    


}





int main(void) {
    Tpilha *topo = NULL;

    //criando uma arvore basica

    //    A
    //  B    C
    // D  E    F

    Tarvore *raiz = criaNo('A',criaNo('B',criaNo('D', NULL, NULL),criaNo('E', NULL, NULL)),criaNo('C',NULL,criaNo('F', NULL, NULL)));

    preordem(raiz, &topo);

    return 0;
}

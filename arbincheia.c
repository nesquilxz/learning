#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char info;
    struct no* esq;
    struct no* dir;
}Tarv;

int altura(Tarv *a) { // primeiro B->esq(D) e B->dir(E)
    if (a == NULL) return 0;
    int he = altura(a->esq);
    int hd = altura(a->dir);
    if (he > hd) return (he + 1);
    else return (hd + 1);
}



int arvoreCheiaRec(Tarv *a, int nivelAtual, int alturaTotal) {

    if (a->esq == NULL && a->dir == NULL) return (nivelAtual == alturaTotal); //folha

    if (a->esq == NULL || a->dir == NULL) return 0; // 1 filho

    return arvoreCheiaRec(a->esq, nivelAtual + 1, alturaTotal) && arvoreCheiaRec(a->dir, nivelAtual + 1, alturaTotal);

}

int arvoreCheia(Tarv *a) {

    if (a == NULL) return  0; 

    return arvoreCheiaRec(a, 1, altura(a));

}

Tarv *criaNo(char info, Tarv *esq, Tarv *dir) {

    Tarv *novo = (Tarv*) malloc(sizeof(Tarv));
    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;

    return novo;

}


void imprimearvore (Tarv *a, int tab) {

for (int i = 0; i < tab; i++) {printf("-");}

if (a != NULL) {
    printf("%c\n", a->info);
    imprimearvore(a->esq, tab+2);
    imprimearvore(a->dir, tab+2);
    }
else {
printf("vazio!\n");

}
}


int main(void) {

    Tarv *raiz = criaNo('A',criaNo('B', criaNo('D', NULL, NULL), criaNo('E', NULL, NULL)),criaNo('C', criaNo('F', NULL, NULL), criaNo('G', NULL, NULL)));

//        A
//    B       C
//  D   E   F  G 


//a arvore teste é esta. ai agora vou testar.

// imprimearvore(raiz, 2);


printf("Resultado: %d\n", arvoreCheia(raiz));

//nos meus testes, tudo certo.

}

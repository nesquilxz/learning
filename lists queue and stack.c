#include <stdio.h>

#define MAX 100

typedef struct {
    int dado[MAX];
    int inicio;
    int fim;
    int total;
} TFila;

void inicializa(TFila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

void insere(TFila *f, int x) {

    if (f->total == MAX) {
        printf("Fila cheia!\n");
    }
    else {
        f->dado[f->fim] = x;

        f->fim++;

        if (f->fim == MAX) {
            f->fim = 0;
        }

        f->total++;
    }
}

void removeFila(TFila *f) {

    if (f->total == 0) {
        printf("Fila vazia!\n");
    }
    else {

        f->inicio++;

        if (f->inicio == MAX) {
            f->inicio = 0;
        }

        f->total--;
    }
}

void imprime(TFila *f) {

    int i;
    int pos = f->inicio;

    for (i = 0; i < f->total; i++) {

        printf("%d ", f->dado[pos]);

        pos++;

        if (pos == MAX) {
            pos = 0;
        }
    }

    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//se encontrar o do meio, encontrou, se ele for maior que o meio anda o inicio... maior que o meio, igual o meio, ou menor que o meio.

typedef struct lista
{
    int dado[MAX];
    int total;
}Tlista;


int busca(Tlista *a, int elem, int *pos) {
    int i = 0;
    while ((i < a->total) && (elem>a->dado[i]))
    {i++;}
    
    (*pos) = i;
    if ((i < a->total) && (elem == a->dado[i])){return 1;}

    return 0;
    
}


void remover(Tlista *a, int elem) {

    int pos, achou = busca(a, elem, &pos);

     if (a->total == 0) {
        printf("Lista vazia!");
    }

    

    else if(!achou) {
        printf("Elemento nao existe na lista.");
    }

    else {

        for(int i = pos; i < a->total-1; i++) {

        a->dado[i] = a->dado[i+1];
       

        }
 (a->total)--;
    }
    

}


void insere(Tlista *a, int x) {
    int pos, achou = busca(a, x, &pos),i;

    if (a->total >= MAX) {
        printf("Lista cheia!");
    }

    

    else if(achou) {
        printf("Elemento ja existe.");
    }

    else {
        
        for(i = a->total; i > pos; i--) {
            a->dado[i] = a->dado[i-1];
        }

        a->dado[pos] = x;
        a->total++;

    }

}



void inicia(Tlista *a) {
    a->total = 0;
}

void escreve(Tlista a) {
    for (int i =0; i < a.total; i++) {
        printf("%d ", a.dado[i]);
    }
    printf("\n");
}


int main(void) {

    Tlista L;
    inicia(&L);


    int elem, n;
    printf("Digite quantos numeros voce deseja inserir inicialmente: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Digite o elemento: ");
        scanf("%d", &elem);
        insere(&L, elem);

    }


}

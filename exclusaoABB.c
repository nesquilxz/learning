#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;


TNoA *maior(TNoA *no) {
    TNoA *aux = no;
    while(aux->dir != NULL) {
        aux = aux->dir;
    }

    return aux;
}
//reutilizando a função do exercicio anterior.

TNoA *exclui(TNoA *raiz, int chave) {
    //TODO: Implementar essa função
    //Ela recebe a raiz da árvore e a chave a ser excluída
    //Ela retorna ponteiro para a nova raiz

    if (raiz == NULL) {return NULL;} //chegou no final e nao achou o no

    //nao achou ainda, entao vejamos se é maior ou menor e chamamos na recursiva.
    else if (raiz->chave < chave) {
        raiz->dir = exclui(raiz->dir, chave);
    }

    else if (raiz->chave > chave) {
        raiz->esq =exclui(raiz->esq, chave);
    }

    else { //nao é NULL e tambem nao é menor ou maior. ou seja (é igual)

        //se é igual, ver se é folha, tem uma subarvore ou se tem duas subarvores

        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        if (raiz->esq == NULL) { //tem subarvore na direita, ja que ja passou pela verif de n ter 2 filhos
            TNoA* subarv = raiz->dir;
            free(raiz);
            return subarv;
        }

        if (raiz->dir == NULL) { //subarvore na esquerda
            TNoA* subarv = raiz->esq;
            free(raiz);
            return subarv;
        }

        //agora no pior caso, onde tem duas subarvores...

        TNoA *maiorEsq = maior(raiz->esq);

        raiz->chave = maiorEsq->chave;

        raiz->esq = exclui(raiz->esq, maiorEsq->chave); // exclui retorna uma chamada de exclui direita novamente (pois chave é maior que raiz->esq), e ai no exemplo do video, quando chamo dnv a segunda chamada da a->dir = NULL. por que NULL? porque achou o valor, deu free e fez a->esq->dir apontar para NULL (valor retornado na segunda chamada).


    }

    return raiz;

}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

int main(void) {

    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no problema
     * depois imprime o resultado solicitado
     * ELA NÃO DEVE SER MODIFICADA
     * */
    TNoA *raiz;
    raiz = NULL;

    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    /* lê valores para criar a arvore
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        raiz = insere(raiz, valor);
        ptr = strtok(NULL, delimitador);
    }

    //le valor a ser excluido
    scanf("%d", &valor);
    //Chama função
    raiz = exclui(raiz, valor);
    imprime(raiz, 0);
};

// Com nó cabeça
#define MAX 10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no {
    char nome[50];
    struct no *prox;
} Tlista;

int busca(Tlista *a, char *fruta, Tlista **pre) {

    Tlista *aux = a->prox;
    Tlista *preL = a;

    while ((aux != NULL) && (strcmp(aux->nome, fruta) < 0)) {
        preL = aux;
        aux = aux->prox;
    }

    *pre = preL;

    if ((aux != NULL) && (strcmp(aux->nome, fruta) == 0))
        return 1;

    return 0;
}

void inserirordenado(Tlista *a, char *novafruta) {

    Tlista *preL;

    if (!busca(a, novafruta, &preL)) {

        Tlista *novo = (Tlista *)malloc(sizeof(Tlista));

        strcpy(novo->nome, novafruta);

        novo->prox = preL->prox;
        preL->prox = novo;
    }
}

void imprime(Tlista *a) {

    Tlista *aux = a->prox;

    while (aux != NULL) {
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
}

void removeNo(Tlista *a, char *nome) {

    Tlista *preL, *lixo;

    if (busca(a, nome, &preL)) {

        lixo = preL->prox;
        preL->prox = lixo->prox;

        free(lixo);
    }
}

int contanos(Tlista *a) {

    if (a == NULL)
        return 0;

    if (strcmp(a->nome, "fim") == 0)
        return 0;

    return 1 + contanos(a->prox);
}

int main(void) {

    Tlista *listafrutas = (Tlista *)malloc(sizeof(Tlista));

    strcpy(listafrutas->nome, "cabeca");
    listafrutas->prox = NULL;

    char fruta[50];

    for (int i = 0; i < MAX; i++) {

        printf("Digite a fruta que voce deseja: ");
        scanf("%49s", fruta);

        inserirordenado(listafrutas, fruta);

        if (strcmp(fruta, "fim") == 0)
            break;
    }

    int opcao;
    char valor[50];

    do {

        printf("\n== Menu ==\n");
        printf("1. Insere elemento\n");
        printf("2. Remove elemento\n");
        printf("3. Mostrar lista\n");
        printf("4. Informa quantidade de nos\n");
        printf("5. Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("Digite a fruta: ");
                scanf("%s", valor);

                inserirordenado(listafrutas, valor);
                break;

            case 2:

                printf("Digite a fruta a remover: ");
                scanf("%49s", valor);

                removeNo(listafrutas, valor);
                break;

            case 3:

                printf("\nLista de frutas:\n");
                imprime(listafrutas);
                break;

            case 4:

                printf("Quantidade de nos: %d\n",
                       contanos(listafrutas->prox));
                break;

            case 5:

                printf("Encerrando programa...\n");
                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}

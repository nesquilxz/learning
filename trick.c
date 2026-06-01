#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *prox;
};

typedef struct NO lista;

int buscaElem(lista *L, int elem, lista **pre) {
    lista *aux, *preL;
    aux = L;
    preL = NULL;

    while ((aux != NULL) && (elem > aux->info)) {
        preL = aux;
        aux = aux->prox;
    }

    (*pre) = preL;

    if ((aux != NULL) && (elem == aux->info))
        return 1;

    return 0;
}

void inserirConjunto(lista **L, int elem) {
    lista *pre = NULL;
    
    if (buscaElem(*L, elem, &pre) == 1) {
        return; 
    }

    lista *novo = (lista*) malloc(sizeof(lista));
    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->info = elem;

    if (pre == NULL) {
        novo->prox = *L;
        *L = novo;
    } else {
        novo->prox = pre->prox;
        pre->prox = novo;
    }
}

lista* uniao(lista *L1, lista *L2) {
    lista *resultado = NULL;
    lista *aux = L1;
    
    while (aux != NULL) {
        inserirConjunto(&resultado, aux->info);
        aux = aux->prox;
    }
    
    aux = L2;
    while (aux != NULL) {
        inserirConjunto(&resultado, aux->info);
        aux = aux->prox;
    }
    
    return resultado;
}

lista* intersecao(lista *L1, lista *L2) {
    lista *resultado = NULL;
    lista *aux = L1;
    lista *pre_ignorado;
    
    while (aux != NULL) {
        if (buscaElem(L2, aux->info, &pre_ignorado)) {
            inserirConjunto(&resultado, aux->info);
        }
        aux = aux->prox;
    }
    
    return resultado;
}

lista* diferenca(lista *L1, lista *L2) {
    lista *resultado = NULL;
    lista *aux = L1;
    lista *pre_ignorado;
    
    while (aux != NULL) {
        if (!buscaElem(L2, aux->info, &pre_ignorado)) {
            inserirConjunto(&resultado, aux->info);
        }
        aux = aux->prox;
    }
    
    return resultado;
}

void exibirLista(lista *L) {
    if (L == NULL) {
        printf("{ }\n");
        return;
    }
    printf("{ ");
    lista *aux = L;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("}\n");
}

void liberarLista(lista *L) {
    lista *aux = L;
    while (aux != NULL) {
        lista *proxNo = aux->prox;
        free(aux);
        aux = proxNo;
    }
}

int main() {
    lista *L1 = NULL;
    lista *L2 = NULL;
    lista *L_res = NULL;
    lista *pre_busca = NULL;
    int opcao, valor;

    inserirConjunto(&L1, 40);
    inserirConjunto(&L1, 10);
    inserirConjunto(&L1, 30);
    inserirConjunto(&L1, 20);

    inserirConjunto(&L2, 50);
    inserirConjunto(&L2, 30);
    inserirConjunto(&L2, 60);
    inserirConjunto(&L2, 40);

    do {
        printf("\n====== CONJUNTOS COM LISTA ORDENADA ======\n");
        printf("L1 = "); exibirLista(L1);
        printf("L2 = "); exibirLista(L2);
        printf("-----------------------------------------\n");
        printf("1. Testar Pertinencia (buscaElem)\n");
        printf("2. Uniao (L1 U L2)\n");
        printf("3. Intersecao (L1 n L2)\n");
        printf("4. Diferenca (L1 - L2)\n");
        printf("5. Inserir elemento manualmente\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                
                if (buscaElem(L1, valor, &pre_busca)) printf("Pertence a L1.\n");
                else printf("NAO pertence a L1.\n");
                
                if (buscaElem(L2, valor, &pre_busca)) printf("Pertence a L2.\n");
                else printf("NAO pertence a L2.\n");
                break;

            case 2:
                L_res = uniao(L1, L2);
                printf("Resultado da Uniao: "); exibirLista(L_res);
                liberarLista(L_res);
                break;

            case 3:
                L_res = intersecao(L1, L2);
                printf("Resultado da Intersecao: "); exibirLista(L_res);
                liberarLista(L_res);
                break;

            case 4:
                L_res = diferenca(L1, L2);
                printf("Resultado da Diferenca (L1 - L2): "); exibirLista(L_res);
                liberarLista(L_res);
                break;

            case 5:
                printf("Em qual lista quer inserir? (1 ou 2): ");
                int esc;
                scanf("%d", &esc);
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if(esc == 1) inserirConjunto(&L1, valor);
                else if(esc == 2) inserirConjunto(&L2, valor);
                else printf("Lista invalida.\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    liberarLista(L1);
    liberarLista(L2);
    return 0;
}

#define MAX 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct no {
    char nome[50];
    struct no* prox;

}Tlista;



int busca(Tlista *a, char *fruta, Tlista **pre) {

    Tlista *aux, *preL = NULL;
    aux = a;
    while((aux != NULL) && (strcmp(aux->nome, fruta) < 0)) {

        preL = aux;
        aux = aux->prox;
    }

    (*pre) = preL;

    if((aux != NULL) && strcmp(aux->nome, fruta) == 0) {
        return 1;
    }

    return 0;


}

void inserirordenado(Tlista **a, char *novafruta) {


Tlista *preL = NULL, *novo = (Tlista*) malloc(sizeof(Tlista)); strcpy(novo->nome, novafruta);

if(!busca(*a, novafruta, &preL)) {

    if(preL == NULL || (*a) == NULL) {
        novo->prox = (*a);
        (*a) = novo;
        
    }

    
    else {
       novo->prox = preL->prox;
       preL->prox = novo;

    }

}

}


void imprime(Tlista *a) {
    Tlista *aux = a;

    while(aux != NULL) {
        printf("%s", aux->nome);
        aux = aux->prox;
    }

}


void removeNo(Tlista **a, char *nome) {

    Tlista *preL, *lixo;
    if(busca(*a, nome, &preL)) {
        if ((strcmp((*a)->nome, nome) == 0)) {
            lixo = (*a);
            (*a) = (*a)->prox;
            

        }

        else {
             lixo = preL->prox;
        preL->prox = lixo->prox;
       
        }
        free(lixo);
    }
    


}


int contanos(Tlista *a) {

    if(strcmp(a->nome, "fim") == 0) {
        return 0;
    }

    return (1 + contanos(a->prox));

}



int main(void) {


    Tlista *listafrutas = NULL;
    char fruta[50];
    
    for(int i = 0; i < MAX; i++) {
        printf("Digite a fruta que você deseja: ");
        scanf("%s", fruta);
        inserirordenado(&listafrutas, fruta);

        if(strcmp(fruta, "fim") == 0) {
            break;
        }

    }

    int opcao; char valor[50];

    do {
        printf("\n== Menu ==\n");
        printf("1. Insere elemento.");
        printf("2. Remove elemento.");
        printf("3. Mostrar lista.");
        printf("4. Informa quantidade de nós.");
        printf("5. Sair");
        scanf("%d", &opcao);


      switch(opcao)
{
    case 1:
        printf("Digite a fruta: ");
        scanf("%s", valor);

        inserirordenado(&listafrutas, valor);
        break;

    case 2:
        printf("Digite a fruta a remover: ");
        scanf("%s", valor);

        removeNo(&listafrutas, valor);
        break;

    case 3:
        printf("\nLista de frutas:\n");
        imprime(listafrutas);
        printf("\n");
        break;

    case 4:
        printf("Quantidade de nos: %d\n", contanos(listafrutas));
        break;

      case 5:
        printf("Encerrando programa...\n");
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }

} while(opcao != 5);

return 0;
}












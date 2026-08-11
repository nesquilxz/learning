#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

int busca(TLista *l, int elem, TLista **pre)
{

    TLista *aux = l, *preL = NULL;

    while ((aux != NULL) && (l->info < elem))
    {
        preL = aux;
        aux = aux->prox;
    }

    (*pre) = preL;

    if ((aux != NULL) && (aux->info == elem))
    {

        return 1;
    }
    return 0;
}

TLista *exclui(TLista *li, int valor)
{
    TLista *lixo, *pre = NULL;

    while (busca(li, valor, &pre))
    {

        TLista *lixo;

        if (pre == NULL)
        { // remover primeiro elemento
            lixo = li;
            li = li->prox;
        }

        else
        {
            lixo = pre->prox;
            pre->prox = lixo->prox;
        }

        free(lixo);
    }

    return li;
}

void imprime_lista(TLista *li)
{
    TLista *p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

TLista *insere_fim(TLista *li, int i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista *p = li;
    TLista *q = li;
    while (p != NULL)
    {
        /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}



int main(void)
{
    /* A função main lê os dados de entrada, cria a lista e chama a função altera
     * depois imprime a lista resultante
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TLista *lista = NULL;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    /* lê valores para criar a lista
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    // quebra a string de entrada
    ptr = strtok(l, delimitador);
    while (ptr != NULL)
    {
        valor = atoi(ptr);
        lista = insere_fim(lista, valor);
        ptr = strtok(NULL, delimitador);
    }

    // Le dados da exclusão a ser realizada
    scanf("%d", &valor);
    lista = exclui(lista, valor);
    imprime_lista(lista);
}

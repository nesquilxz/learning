struct lista {

int dado;
struct lista *prox;
}typedef struct lista Tlista;


int buscaElem (Tlista *L, int elem, Tlista **pre) {
Tlista *aux, *preL;
aux = L;
preL = NULL;

while((aux != NULL)&&(elem < aux->dado) {
preL = aux;
aux = aux->prox;
}

(*pre) = preL;
if ((aux!=NULL) && (elem == aux->info)) {return 1;}
return 0;
}


Tlista *insereElem (lista *l, int elem) {

lista *pre, *el;
if(!busca(l, elem, &pre) {

el = (lista*) malloc(sizeof(lista));
el->dado = elem;
if((L == NULL) || (pre == NULL)) {
el->prox = l;
l = el;
}
el->prox = pre->prox;
pre->prox = el;
}
return l;
}


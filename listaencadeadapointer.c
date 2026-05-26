typedef struct lista {

int dado;
struct lista *prox;
} Tlista;


int buscaElem (Tlista *L, int elem, Tlista **pre) {
Tlista *aux, *preL;
aux = L;
preL = NULL;

while((aux != NULL)&&(elem < aux->dado)) {
preL = aux;
aux = aux->prox;
}

(*pre) = preL;
if ((aux!=NULL) && (elem == aux->dado)) {return 1;}
return 0;
}


Tlista *insereElem (lista *l, int elem) {

Tlista *pre, *el;
if(!busca(l, elem, &pre) {

el = (Tlista*) malloc(sizeof(Tlista));
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


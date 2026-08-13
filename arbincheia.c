int altura(Tarv *a) {
    if (a == NULL) return -1;
    int he = altura(a->esq);
    int hd = altura(a->dir);
    if (he > hd) return he + 1;
    else return hd + 1;
}

int arvoreCheia(Tarv *a) {
    if (a == NULL) return 1;
    if (a->esq == NULL && a->dir == NULL) return 1;      // folha
    if (a->esq == NULL || a->dir == NULL) return 0;      // um filho só
    if (altura(a->esq) != altura(a->dir)) return 0;      // alturas diferentes
    return arvoreCheia(a->esq) && arvoreCheia(a->dir);   // nenhum dos casos acima, entao vamos ter q rodar recursivamente
}

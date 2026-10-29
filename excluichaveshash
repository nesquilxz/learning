void exclui_chaves(Hash *tab, int m, int *chaves, int qtd_chaves) {
    for (int i = 0; i < qtd_chaves; i++) {
        int h = hash(chaves[i], m);
        TAluno *p = tab[h];
        TAluno *ant = NULL;

        while (p != NULL) {
            imprime_chave(p->matricula);

            if (p->matricula == chaves[i]) {
                if (ant == NULL) {
                    tab[h] = p->prox;
                } else {
                    ant->prox = p->prox;
                }

                free(p);
                break;
            }

            ant = p;
            p = p->prox;
        }
    }
}

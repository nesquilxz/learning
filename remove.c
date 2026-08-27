TNoA *remove_no(TNoA *a, int valor) {
    if (a == NULL) { // valor nao esta na arvore - nada a fazer
        return NULL;
    }

    if (valor < a->info) {
        a->esq = remove_no(a->esq, valor);
    } else if (valor > a->info) {
        a->dir = remove_no(a->dir, valor);
    } else { // achou o no a remover (valor == a->info)

        // Caso 1: folha (nenhum filho)
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        }

        // Caso 2a: só tem filho direito
        if (a->esq == NULL) {
            TNoA *filho = a->dir;
            free(a);
            return filho;
        }

        // Caso 2b: só tem filho esquerdo
        if (a->dir == NULL) {
            TNoA *filho = a->esq;
            free(a);
            return filho;
        }

        // Caso 3: tem os dois filhos
        // Acha o sucessor (menor valor da subarvore direita)
        TNoA *sucessor = menor(a->dir);

        // Copia o valor do sucessor para o no atual
        a->info = sucessor->info;

        // Remove o sucessor do lugar onde ele estava (na subarvore direita).
        // O sucessor nunca tem filho esquerdo, entao essa chamada sempre
        // cai no Caso 1 ou Caso 2a - nunca precisa entrar no Caso 3 de novo.
        a->dir = remove_no(a->dir, sucessor->info);
    }

    return a;
}

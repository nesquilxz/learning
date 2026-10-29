TLista *menor_k_aux(TNo *no, int k, TLista *lista) {
    if (no == NULL) return lista;

    for (int i = 0; i <= no->m; i++) {
        if (no->p[i] != NULL) {
            lista = menor_k_aux(no->p[i], k, lista);
        }
    }

    for (int j = 0; j < no->m; j++) {
        if (no->s[j] < k) {
            lista = insere_ordenado(lista, no->s[j]);
        }
    }

    return lista;
}

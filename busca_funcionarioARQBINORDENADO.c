TFunc *busca_binaria(int cod, FILE *arq, int tam) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        // Vai até o começo do registro do meio.
        if (fseek(arq, (long) meio * tamanho_registro(),
                  SEEK_SET) != 0) {
            return NULL;
        }

        // Lê o funcionário dessa posição.
        TFunc *f = le(arq);

        if (f == NULL) {
            return NULL;
        }

        if (f->cod == cod) {
            return f;
        }

        if (cod < f->cod) {
            fim = meio - 1;       // Continua na metade esquerda.
        } else {
            inicio = meio + 1;    // Continua na metade direita.
        }

        free(f); // Descarta o funcionário que não era o procurado.
    }

    return NULL; // Não encontrou.
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE *arq1 = fopen(nomeArq1, "r");
    FILE *arq2 = fopen(nomeArq2, "r");

    if (arq1 == NULL || arq2 == NULL) {
        if (arq1 != NULL) fclose(arq1);
        if (arq2 != NULL) fclose(arq2);
        return;
    }

    FILE *saida = fopen(nomeArqMerge, "w");

    if (saida == NULL) {
        fclose(arq1);
        fclose(arq2);
        return;
    }

    int n1, n2;
    int leu1 = fscanf(arq1, "%d", &n1);
    int leu2 = fscanf(arq2, "%d", &n2);

    int ultimo = 0;
    int primeiro = 1;

    // Continua enquanto algum arquivo ainda tiver números.
    while (leu1 == 1 || leu2 == 1) {
        int atual;

        if (leu1 != 1) {
            // O primeiro arquivo acabou: pega do segundo.
            atual = n2;
            leu2 = fscanf(arq2, "%d", &n2);
        }
        else if (leu2 != 1) {
            // O segundo arquivo acabou: pega do primeiro.
            atual = n1;
            leu1 = fscanf(arq1, "%d", &n1);
        }
        else if (n1 <= n2) {
            // Ambos têm números: pega o menor.
            atual = n1;
            leu1 = fscanf(arq1, "%d", &n1);
        }
        else {
            atual = n2;
            leu2 = fscanf(arq2, "%d", &n2);
        }

        // Só grava se for o primeiro número ou se não for repetido.
        if (primeiro || atual != ultimo) {
            fprintf(saida, "%d\n", atual);
            ultimo = atual;
            primeiro = 0;
        }
    }

    // Linha em branco no final do arquivo.
    fprintf(saida, "\n");

    fclose(arq1);
    fclose(arq2);
    fclose(saida);
}

#include <stdio.h>
#include <string.h>

#define TAM 50

int main() {
    FILE *arq1, *arq2;
    char atual[TAM], verif[TAM];
    int cont;

    arq1 = fopen("texto.txt", "r");
    if (arq1 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(arq1, "%s", atual) == 1) {
        cont = 0;

        arq2 = fopen("texto.txt", "r");

        while (fscanf(arq2, "%s", verif) == 1) {
            if (strcmp(atual, verif) == 0) {
                cont++;
            }
        }

        fclose(arq2);

        printf("%s: %d\n", atual, cont);
    }

    fclose(arq1);
    return 0;
}

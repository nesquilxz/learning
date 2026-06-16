#include <stdio.h>
#include <string.h>

#define MAX_PALAVRAS 1000
#define TAM 50

int main() {
    FILE *arq;
    char palavra[TAM];

    char palavras[MAX_PALAVRAS][TAM];
    int cont[MAX_PALAVRAS];

    int n = 0, i, achou;

    arq = fopen("musica.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    while (fscanf(arq, "%s", palavra) == 1) {

        achou = 0;

        for (i = 0; i < n; i++) {
            if (strcmp(palavras[i], palavra) == 0) {
                cont[i]++;
                achou = 1;
                break;
            }
        }

        if (!achou) {
            strcpy(palavras[n], palavra);
            cont[n] = 1;
            n++;
        }
    }

    fclose(arq);

    for (i = 0; i < n; i++) {
        printf("%s: %d\n", palavras[i], cont[i]);
    }

    return 0;
}

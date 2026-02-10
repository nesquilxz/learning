#include <stdio.h>
#include <string.h>

#define MAX 1000
#define TAM 50

typedef struct {
    char palavra[TAM];
    int qtd;
} Palavra;

int main() {
    FILE *arq = fopen("texto.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Palavra palavras[MAX];
    int total = 0;
    char aux[TAM];

    while (fscanf(arq, "%s", aux) != EOF) {
        int achou = 0;

        for (int i = 0; i < total; i++) {
            if (strcmp(palavras[i].palavra, aux) == 0) {
                palavras[i].qtd++;
                achou = 1;
                break;
            }
        }

        if (!achou) {
            strcpy(palavras[total].palavra, aux);
            palavras[total].qtd = 1;
            total++;
        }
    }

    fclose(arq);

    for (int i = 0; i < total; i++) {
        printf("%s: %d\n", palavras[i].palavra, palavras[i].qtd);
    }

    return 0;
}

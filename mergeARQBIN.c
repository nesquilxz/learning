#include <stdio.h>

void imprime_arquivo(char *nomeArq) {
    FILE *arq = fopen(nomeArq, "r");

    if (arq != NULL) {
        char s[10];
        fscanf(arq, "%s", s);

        while (!feof(arq)) {
            printf("%s\n", s);
            fscanf(arq, "%s", s);
        }

        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo\n");
    }
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    FILE *arquivo1 = fopen(nomeArq1, "r");
    FILE *arquivo2 = fopen(nomeArq2, "r");

    // verifica se os arquivos de entrada foram abertos.
    if (arquivo1 == NULL || arquivo2 == NULL) {
        if (arquivo1 != NULL) {
            fclose(arquivo1);
        }

        if (arquivo2 != NULL) {
            fclose(arquivo2);
        }

        return;
    }

    FILE *arquivoMerge = fopen(nomeArqMerge, "w");

    if (arquivoMerge == NULL) {
        fclose(arquivo1);
        fclose(arquivo2);
        return;
    }

    int numero1, numero2;

    // cada leitura retorna 1 se conseguiu ler um número.
    int leitura1 = fscanf(arquivo1, "%d", &numero1);
    int leitura2 = fscanf(arquivo2, "%d", &numero2);

    int ultimoGravado = 0;
    int primeiroNumero = 1;

    // continua enquanto pelo menos um arquivo tiver números
    while (leitura1 == 1 || leitura2 == 1) {
        int numeroAtual;

        if (leitura1 != 1) {
            // O arquivo 1 acabou: pega do arquivo 2.
            numeroAtual = numero2;
            leitura2 = fscanf(arquivo2, "%d", &numero2);
        }
        else if (leitura2 != 1) {
            // O arquivo 2 acabou: pega do arquivo 1.
            numeroAtual = numero1;
            leitura1 = fscanf(arquivo1, "%d", &numero1);
        }
        else if (numero1 <= numero2) {
            // os dois tem números: pega o menor, do arquivo 1
            numeroAtual = numero1;
            leitura1 = fscanf(arquivo1, "%d", &numero1);
        }
        else {
            // o menor está no arquivo 2
            numeroAtual = numero2;
            leitura2 = fscanf(arquivo2, "%d", &numero2);
        }

        // grava somente o primeiro número ou um valor diferente do último que foi gravado
        if (primeiroNumero == 1 || numeroAtual != ultimoGravado) {
            fprintf(arquivoMerge, "%d\n", numeroAtual);

            ultimoGravado = numeroAtual;
            primeiroNumero = 0;
        }
    }

    
    fprintf(arquivoMerge, "\n");

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoMerge);
}

int main(int argc, char **argv) {
    merge("numeros1.txt", "numeros2.txt", "merge.txt");
    imprime_arquivo("merge.txt");

    return 0;
}

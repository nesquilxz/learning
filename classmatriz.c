#include <stdio.h>

int n;

void preenchermatriz(int (*matriz)[n]) {

    int i, j, valor;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Digite o valor: ");
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }

}


void escrevematriz(int (*matriz)[n]) {

    int i, j, valor;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d",matriz[i][j]);
        }
        printf("\n");
    }

}


int somasecundaria(int (*matriz)[n]) {

    int i, j, valor = 0;

    for(i = 0; i < n; i++) {
        
        valor += matriz[i][n - 1 - i];

        }

        return valor;
    }

int simetrica(int (*matriz)[n]) {

    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(matriz[i][j] != matriz[j][i]) {
                return 0;
            }
        }
        

        }

        return 1;
    }





main() {
    
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    int matriz[n][n], soma, ehsimetrica;
    preenchermatriz(matriz);
    escrevematriz(matriz);
    soma = somasecundaria(matriz);
    printf("A soma da diagonal secundaria é: %d\n", soma);

    ehsimetrica = simetrica(matriz);

    if(ehsimetrica) {
        printf("É simetrica.\n");
    }

    else{
        printf("Nao é simetrica.\n");
    }


}

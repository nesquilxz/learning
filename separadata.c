#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void separaData(char *data, int* d, int* m, int *a) {
// 16/05/2026 
    char D[3], M[3], A[5]; //tamanho total de 3 caracteres, 3, e 5...

    printf("\n\n Vamos separar a DATA: %s \n\n", data);
    strncpy(D, data, 2);
    strncpy(M, &data[3], 2);
    strncpy(A, &data[6], 4);

    D[2] = '\0';
    M[2] = '\0';
    A[4] = '\0';

//  int        char
    *d = atoi(D);
    *m = atoi(M);
    *a = atoi(A);

  

}




int main(void) {


    int dia, mes, ano;
    char data[12];
    char nome[120];

    printf("Digite sua data de nascimento (dd/mm/aaaa): ");
    scanf(" %s", data);

    separaData(data, &dia, &mes, &ano);

    printf("Voce nasceu no dia %d, mes %d e ano %d.", dia, mes, ano);
    
    printf("\n Digite seu nome: ");
    scanf("%[^\n]s", nome );

    printf("Oi, %s! tudo bem?", nome);

}

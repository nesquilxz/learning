#include <stdio.h>
#include <stdlib.h>


void preenchematriz(int **matriz, int c, int l) {

    for(int i =0; i < l; i++) {
        for(int j=0; j < c; j++) {

        printf("Digite o numero que irá ficar na linha %d e coluna %d", i+1, j+1);
        scanf("%d", &matriz[i][j]); //por que o & mesmo? o v[i] ja é a desreferenciação? porque voce quer o endereço daquele numero

    }

    }

}

void imprimematriz(int **matriz, int c, int l) {

    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d", &matriz[l][c]);
        }
        printf("\n");
    }


}



float calculamedia (int *m, int c, int l) {

    int soma = 0;

    for(int i =0; i < n; i++) {

        soma += v[i];

    }

    return (soma*1.0/n);

}


int valorproximo(int **m, int c, int l) {

    float media;
    int i, valor;

    media = calculamedia(v, n);

    int menordif = 999, dif;

    for(int i = 0; i < n; i++) {

    dif = media - v[i];

    if(dif < menordif) {
        menordif = dif;
    }



    }

    return dif;

}





int main(void) {

    int l, c;
    printf("Digite quantas linhas sao: ");
    scanf("%d", &l);

    printf("Digite quantas colunas sao: ");
    scanf("%d", &c);

    int **m;
    m = (int**) malloc(sizeof(int*) * l);

    for(int i = 0; i < c; i ++) {
        m[i] = (int*) malloc(sizeof(int*) * c);
    }

    printf("Vamos preencher a matriz! \n\n");
    preenchevetor(m, c, l);


    imprimematriz(m, c, l);
    
    float media;

    media = calculamedia(m, c, l);

    printf("A media calculada foi de: %d.\n\n", media);

   int valor = valorproximo(m, c,l);
   printf("O valor mais proximo é o: %d\n", valor);


   for(int i = 0; i < c; i++) {
    free(m[i]);
   }

   free(m);

   return 0;
}

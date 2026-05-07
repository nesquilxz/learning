#include <stdio.h>
#include <stdlib.h>


void preenchevetor(int *v, int n) {

    for(int i =0; i < n; i++) {

        printf("Digite o numero que irá ficar na posição %d", i+1);
        scanf("%d", &v[i]); //por que o & mesmo? o v[i] ja é a desreferenciação?

    }

}



float calculamedia (int *v, int n) {

    int soma = 0;

    for(int i =0; i < n; i++) {

        soma += v[i];

    }

    return (soma*1.0/n);

}


int valorproximo(int *v, int n) {

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

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *v;
    v = (int*) malloc(sizeof(int) * n);

    printf("Vamos preencher o vetor! \n\n");
    preenchevetor(v, n);
    
    float media;

    media = calculamedia(v, n);

    printf("A media calculada foi de: %d.\n\n", media);

   int valor = valorproximo(v, n);
   printf("O valor mais proximo é o: %d\n", valor);


}

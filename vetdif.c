#include <stdio.h>
#define TAM 100


void preenchevetor(int *vet) {
    
    for(int i = 0; i < TAM; i ++) {

        printf("Digite um numero: ");
        scanf("%d", &vet[i]);

    }


}

int vetdif (int* vetA, int* vetB) {
    int cont = 0;
    for(int i = 0; i < TAM; i++) {

        if(vetA[i] != vetB[i]) {
            cont++;
        }

    }

    return cont;

}




main() {

    int vetA, vetB;
    printf("Vetor A: \n");
    preenchevetor(vetA);

    printf("Vetor B: \n");
    preenchevetor(vetB);

    printf("Diferentes: %d", vetdif(vetA, vetB));
}



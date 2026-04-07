#include <stdio.h>
# define TAM 20


main() {
    int vet[TAM]; int n = 1;

    for(int i = TAM-1; i >= 0;i--) {
        printf("Digite o numero %d: ", n);
        scanf("%d", &vet[i]);
        n++;
    }

    printf("numeros na ordem contraria: \n\n");

    for(int i= 0; i <= TAM-1; i++) {
        printf("%d \n", vet[i]);
    }

    return 0;
}

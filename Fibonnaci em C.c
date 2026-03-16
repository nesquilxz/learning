#include <stdio.h>

// -> Implemente um programa que, infinitamente, leia uma sequência de tamanho n
// e retorne o número de vezes que essa sequência deixou de ser estritamente crescente. Esse programa pára quando n ≤ 0;

int main() {


    while (1)
    {
        int n;
        printf("Digite o tamanho da sequencia, por favor: ");
        scanf("%d", &n);

        if (n <= 0) {
            break;
        }

        int atual, anterior, contador = 0;
        printf("Digite a sequencia, por favor: ");
        scanf("%d", &anterior);


        for(int i=1; i < n; i++)
        {
            scanf("%d", &atual);
            if (atual <= anterior) {
                contador ++;
            }

            anterior = atual;
        }

        printf("A sequencia deixou de ser estritamente crescente %d vez(es).\n", contador);

    }
    
    return 0;

}

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int maxValor(int *vet) {
    int i, max, maisVezes = 0;
    for(i = 2; i < 12; i++) {
        if (vet[i] > maisVezes) {
            maisVezes = vet[i];
            max = i;
        }
        
    }
    return max;
}


int main(void) {

    int i, dado1, dado2, somaDado;
    int vetCont[13], max;
    srand(time(NULL));


    for(i =0; i<13;i++) {
        vetCont[i] = 0;}

    for(i = 0; i <N; i++) {
        dado1 = (rand() % 6+1);
        dado2 = (rand() %6 +1);
        vetCont[dado1+dado2] += 1;
    }

    max = maxValor(vetCont);
    printf("\n\n O valor que saiu mais vezes foi: %d", max);
    printf(" (%.2f%%)\n\n", vetCont[max]*100.00/N);

}

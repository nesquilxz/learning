#include <stdio.h>

//hanoi: 2^n - 1


void hanoi(int n, char orig, char aux, char dest) {

    if(n == 1) {
        printf("mover de %c para %c.\n", orig, dest);
    }

    else {
        hanoi(n-1, orig, dest, aux);
        printf("Mover de %c para %c\n", orig, dest);
    hanoi(n-1, aux, orig, dest);
    }
}

// 3 discos = (2 * (2*(1)+1)+1)


main() {

    int discos, resposta;
    do {        printf("Digite a quantidade total de discos: ");
    scanf("%d", &discos);

    }
    while(discos < 0);
    hanoi(discos, 'A', 'C', 'B');

}

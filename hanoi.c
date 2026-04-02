#include <stdio.h>

//hanoi: 2^n - 1


hanoi(int n) {

    if(n == 1) {
        return 1;
    }

    return (2 * hanoi(n-1) + 1);
}

// 3 discos = (2 * (2*(1)+1)+1)


main() {

    int discos, resposta;

    printf("Digite a quantidade total de discos: ");
    scanf("%d", &discos);


    resposta = hanoi(discos);
    printf("Irá precisar de %d movimentos! \n \n", resposta);

}

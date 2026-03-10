#include <stdio.h>

int main() {
    int valor = 10;
    int *ptr1 = &valor;
    int **ptr2 = &ptr1;

    // A pegadinha: alterando o valor via ponteiro de ponteiro
    **ptr2 = 20; 

    // Alterando para onde ptr1 aponta (perigo!)
    int outra_var = 100;
    *ptr2 = &outra_var; // Agora ptr1 aponta para outra_var!

    printf("Valor final de 'valor': %d\n", valor);
    printf("Conteudo apontado por *ptr1: %d\n", *ptr1);
    printf("Conteudo apontado por **ptr2: %d\n", **ptr2);

    return 0;
}

#include <stdio.h>
#include <string.h>
int main(void) {


    int vetor[5] = {2, 4, 6, 8, 10};
    int *ptr;
    ptr = &vetor[3];

    printf("%d", *ptr);


}

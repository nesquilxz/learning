#include <stdio.h>
#include <string.h>


int ocorre(char *A, char *B) {

    int tamB = strlen(B), posigual = 0, tamA = strlen(A), achou = 0;

    for(int i = 0; i < tamA; i++) {
        for(int j = posigual; j < tamB; j++) {
             if (A[i] == B[j]){
                posigual = j+1;
                achou++;
                break;
             }
        }
       
    }

    return (achou == tamA);

}


int main(void) {

    char A[100], B[300];

    printf("Digite a palavra A: ");
    scanf("%s", A);

    printf("Digite o texto B: ");
    scanf(" %[^\n]", B);

    if (ocorre(A,B)) {
        printf("A está dentro de B!\n");
    }

    else {
        printf("A não está dentro de B!\n");
    }


return 0;
}

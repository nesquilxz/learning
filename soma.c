#include <stdio.h>

int soma(int a, int b) {


return a + b;
    
}
int main(void) {

    int a, b, resposta;


    do {
        printf("Digite dois numeros separados por espaco: ");
        scanf("%d %d", &a, &b);
       

        resposta = soma(a, b);
        printf("A soma e': %d\n\n", resposta);
   
    } while(a > 0 || b > 0);


    return 0;

}

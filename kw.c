#include <stdio.h>
#include <math.h>

int main(void) {

    char nome[100];
    float cm, preco;

    printf("Digite seu nome, por favor: \n");
    scanf("%s", nome);

    printf("Digite seu consumo mensal (kw): \n");
    scanf("%f", &cm);


    printf("Digite quanto custa um kw: \n");
    scanf("%f", &preco);

    float pagar;

    pagar = cm * preco;

    printf("Voce, (%s), devera pagar um total de: %.2f reais.\n", nome,  pagar);

}

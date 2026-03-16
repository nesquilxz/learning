#include <stdio.h>
#include <string.h>

int main (void) {

    char nome[100];


    printf("Digite seu nome: \n");
    scanf("%99s", nome);


    int idade;
    scanf("%d", &idade);

    float salarioMin;
    printf("Digite o salario minimo: \n");
    scanf("%f", &salarioMin);

    float qtdKw;
    printf("Digite a quantidade de KiloWatts gasto pelo o usuário (%s): \n", nome);
    scanf("%f", &qtdKw);

    float valorKw = salarioMin * 0.01;

    printf("O valor do Kw é de: %f \n", valorKw);

    float pagar = valorKw*qtdKw;

    printf("O valor a ser pago este mes e': %.2f \n", pagar);



}

#include <stdio.h>

int main(void) {


    float salario, contas[2], adicionalMulta, sobra;

    printf("Digite o seu salario com um ponto no lugar de ',': ");
    scanf("%f", &salario);

    printf("Digite o valor das contas separado por espaco: ");
    scanf("%f %f", &contas[0], &contas[1]);

    for(int i = 0; i <= 2; i++){
        contas[i] += contas[i] * 0.02;

    }

    adicionalMulta = contas[0] + contas[1];

    sobra = salario - adicionalMulta;

    printf("Sobrara: %.2f R$ do seu salario! \n", sobra);
}

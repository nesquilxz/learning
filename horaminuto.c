#include <stdio.h>


int main(void) {

    int hora, minutos;

    printf("Digite a hora (espaco) minutos, por favor: ");
    scanf("%d %d", &hora, &minutos);

    int conversaohora = hora * 60 + minutos;
    int conversaominutos = conversaohora * 60;
    
    printf("Hora convertida: %d minutos e %d segundos.", conversaohora, conversaominutos);





}

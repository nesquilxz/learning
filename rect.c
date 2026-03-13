#include <stdio.h>
#include <math.h>

int main(void) {

    printf("Digite a base e a altura do retângulo: \n");
    
    int b, h;

    scanf("%d %d", &b, &h);

    int perimetro = (2 * b) + (2 * h);

    int area = b * h;

    int diagonal = sqrt((b*b) + (h*h));

    printf("%d (perimetro), %d (area), %d (diagonal).", perimetro, area, diagonal);





}

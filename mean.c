#include <stdio.h>

int main(void) {

  int a, b, c;
  int media;
  int somatorio;


  printf("Digite as 3 notas: "\n");
  scanf("%d %d %d", &a, &b, &c);

  somatorio = a + b + c;
  media = somatorio / 3.0;

  printf("A média é: %.2f", media);

}

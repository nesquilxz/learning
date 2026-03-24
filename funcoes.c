int soma(int a, int b) {
  return (a+b);
}


main(void) {

  int a, b, valor;

  printf("Digite o valor de a e b separados por espaço: ");
  scanf("%d %d", &a, &b);

  valor = soma(a,b);

  printf("A soma é: %d", valor);


}

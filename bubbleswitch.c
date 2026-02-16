#include <stdio.h>
#include <math.h>

int bulbSwitch(int n) {
    // o valor retornado é a raiz quadrada inteira de n0
    return (int)sqrt(n);
}

// função para testar
int main() {
    
    int tests[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000};
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    
    printf("n\tLâmpadas\n");
    
    for (int i = 0; i < num_tests; i++) {
        int n = tests[i];
        int result = bulbSwitch(n);
        printf("%d\t%d\n", n, result);
    }
    
    // exemplo específico do problema
    printf("\nExemplo do enunciado (n = 3):\n");
    printf("Lâmpadas acesas: %d\n", bulbSwitch(3));
    
    return 0;
}

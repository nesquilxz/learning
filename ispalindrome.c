#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Números negativos não são palíndromos
    if (x < 0) {
        return false;
    }
    
    // Se termina com 0 mas não é 0, não é palíndromo
    if (x % 10 == 0 && x != 0) {
        return false;
    }
    
    int reversed = 0;
    int original = x;
    
    // Inverte apenas metade do número
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    // Para números com quantidade par de dígitos: x == reversed
    // Para números com quantidade ímpar de dígitos: x == reversed/10
    return x == reversed || x == reversed / 10;
}

// Função principal para teste
int main() {
    // Testes
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;
    int test4 = 12321;
    
    printf("%d é palíndromo? %s\n", test1, isPalindrome(test1) ? "true" : "false");
    printf("%d é palíndromo? %s\n", test2, isPalindrome(test2) ? "true" : "false");
    printf("%d é palíndromo? %s\n", test3, isPalindrome(test3) ? "true" : "false");
    printf("%d é palíndromo? %s\n", test4, isPalindrome(test4) ? "true" : "false");
    
    return 0;
}

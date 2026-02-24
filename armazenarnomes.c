#include <stdio.h>

int main() {
    char nome[50];
    char partes[10][50];  // array para armazenar até 10 partes do nome
    int i, j, k;
    
    printf("Digite um nome completo: ");
    fgets(nome, 50, stdin);
    
    // remover o \n do final
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break;
        }
    }
    
    // separar as partes do nome
    i = 0;  // índice na string original
    k = 0;  // idx parte completa
    
    while (nome[i] != '\0' && k < 10) {
        j = 0;  // idx letra de cada parte
        
        // ignorar espaços no início
        while (nome[i] == ' ') {
            i++;
        }
        
        // copiar caracteres até encontrar espaço ou fim da string
        while (nome[i] != ' ' && nome[i] != '\0') {
            partes[k][j] = nome[i];
            i++;
            j++;
        }
        
        // finaliza nome atual
        if (j > 0) {
            partes[k][j] = '\0';
            k++;
        }
    }
    
 
    printf("\nPartes do nome:\n");
    for (i = 0; i < k; i++) {
        printf("- %s\n", partes[i]);
    }
    
    return 0;
}

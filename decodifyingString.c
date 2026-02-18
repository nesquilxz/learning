#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(10000 * sizeof(char)); // Tamanho grande o suficiente
    int resultIndex = 0;
    
    // Pilhas para guardar números e strings
    int numStack[30];
    char* strStack[30];
    int numTop = -1;
    int strTop = -1;
    
    int currentNum = 0;
    char* currentStr = (char*)malloc(10000 * sizeof(char));
    int currentStrIndex = 0;
    
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            currentNum = currentNum * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            // Salva o número atual na pilha
            numStack[++numTop] = currentNum;
            currentNum = 0;
            
            // Salva a string atual na pilha
            char* temp = (char*)malloc((currentStrIndex + 1) * sizeof(char));
            strncpy(temp, currentStr, currentStrIndex);
            temp[currentStrIndex] = '\0';
            strStack[++strTop] = temp;
            
            // Reseta a string atual
            currentStrIndex = 0;
        }
        else if (s[i] == ']') {
            // Pega a string atual (que está dentro dos colchetes)
            char* temp = (char*)malloc((currentStrIndex + 1) * sizeof(char));
            strncpy(temp, currentStr, currentStrIndex);
            temp[currentStrIndex] = '\0';
            
            // Pega o número de repetições
            int repeat = numStack[numTop--];
            
            // Pega a string anterior da pilha
            char* prevStr = strStack[strTop--];
            int prevLen = strlen(prevStr);
            
            // Concatena a string repetida com a anterior
            currentStrIndex = prevLen;
            strcpy(currentStr, prevStr);
            
            for (int j = 0; j < repeat; j++) {
                strcat(currentStr, temp);
                currentStrIndex += strlen(temp);
            }
            
            free(temp);
            free(prevStr);
        }
        else {
            currentStr[currentStrIndex++] = s[i];
        }
    }
    
    // Copia o resultado final
    strcpy(result, currentStr);
    free(currentStr);
    
    return result;
}

int main() {
    // Testes
    char* test1 = "3[a]2[bc]";
    char* test2 = "3[a2[c]]";
    char* test3 = "2[abc]3[cd]ef";
    
    printf("Input: %s\nOutput: %s\n\n", test1, decodeString(test1));
    printf("Input: %s\nOutput: %s\n\n", test2, decodeString(test2));
    printf("Input: %s\nOutput: %s\n\n", test3, decodeString(test3));
    
    return 0;
}

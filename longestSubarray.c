#include <stdio.h>

int longestSubarray(int arr[], int n) {
    int max_comprimento = 0;
    
    for (int inicio = 0; inicio < n; inicio++) {
        int contador0 = 0;
        int contador1 = 0;
        
        for (int fim = inicio; fim < n; fim++) {
            // Conta os 0s e 1s
            if (arr[fim] == 0) {
                contador0++;
            } else {
                contador1++;
            }
            
            // Se forem iguais, verifica se é o maior
            if (contador0 == contador1) {
                int comprimento = fim - inicio + 1;
                if (comprimento > max_comprimento) {
                    max_comprimento = comprimento;
                }
            }
        }
    }
    
    return max_comprimento;
}



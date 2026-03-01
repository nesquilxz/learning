int singleNumber(int* nums, int numsSize) {
    // Para cada número no array
    for (int i = 0; i < numsSize; i++) {
        int contador = 0;
        
        // Conta quantas vezes esse número aparece
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                contador++;
            }
        }
        
        // Se apareceu só uma vez, é ele!
        if (contador == 1) {
            return nums[i];
        }
    }
    
    return 0; // Se não achar (não vai acontecer, mas precisa ter retorno)
}

int pivotIndex(int* nums, int numsSize) {
    
    int somatotal, somaesquerda = 0, somadireita = 0, i;

    for(i=0; i<numsSize; i++) {
        somatotal += nums[i];
    }

    for(i =0; i < numsSize; i++) {

        somadireita = somatotal-somaesquerda-nums[i];
        if(somadireita == somaesquerda) return i;
        somaesquerda += nums[i];
        
    }

    return -1;
}

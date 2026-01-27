/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int index1, index2;
    int *v = malloc(sizeof(2 * sizeof(int)));

    if (!v) {
        *returnSize = 0;
        return 0;
    }

    for(index1 =0; index1 < numbersSize; index1++ ) {

        for(index2 = index1 + 1; index2 < numbersSize; index2++ ) {

        if ((numbers[index1] + numbers[index2]) == target) {
            v[0] = index1+1;
            v[1] = index2+1;
            *returnSize = 2;
            return v;
        }
    }

    }

    *returnSize = 0;
    free(v);
    return 0;
    
}

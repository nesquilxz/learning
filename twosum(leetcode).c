/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    int *v = (int*) malloc(2 * sizeof(int));

    if (v == NULL) {
        *returnSize = 0;
        return 0;
    }

    for(i = 0; i < numsSize; i++) {

        for(j = i+1; j < numsSize; j++) {

            if ((nums[i] + nums[j]) == target) {
                v[0] = i;
                v[1] = j;
                *returnSize = 2;
                return v;
            }

        }

    }


    return 0;
    free(v);
    *returnSize = 0;
}

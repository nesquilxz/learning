void moveZeroes(int* nums, int numsSize) {
    int pos = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[pos] = nums[i];
            pos++;
        }
    }

    while (pos < numsSize) {
        nums[pos] = 0;
        pos++;
    }
}

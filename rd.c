int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int i = 0, j;


    for(j = 1; j < numsSize; j++) {
        
            if (nums[i] != nums[j]) {
                i++;
                k++;
                nums[i] = nums[j];
            }
           
    }
    return k;
}

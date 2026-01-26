int findDuplicate(int* nums, int numsSize) {

   int i, j;
   int numeromaisrepetido;

   for (i = 0; i < numsSize; i++) {

    for (j = i+1; j < numsSize; j++) {

        if (nums[i] == nums[j]) {

            numeromaisrepetido = nums[i];
           return numeromaisrepetido;
        }


    }
   }
    return 0;
}

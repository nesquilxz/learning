int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // subindo, o pico está à direita
            left = mid + 1;
        } else {
            // descendo, o pico está à esquerda ou no mid
            right = mid;
        }
    }

    return left; // ou right, são iguais aqui
}

#include <stdio.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);

int main() {
    int target;
    int nums[MAX_ARRAY_SIZE] = {0};
    int array_size = 0;

    scanf("%d", &target);

    while (scanf("%d", &nums[array_size++]) == 1);
    array_size--;

    twoSum(nums, array_size, target);

    return (0);
}

void twoSum(int nums[], int nums_size, int target) {


    for (int i = 0; i < nums_size; i++) {
        for (int j = 1 + i; j < nums_size; j++) {
            if (nums[i] + nums[j] == target) {
                printf("(%d,%d)", i, j);
            }
        }

    }

}

#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int index = linearSearch(nums, target);
    printf("Index of %d: %d\n", target, index);
    return 0;
}

int linearSearch(int nums[], int target)
{
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        if (nums[i] == target)
            return i;
    }
}
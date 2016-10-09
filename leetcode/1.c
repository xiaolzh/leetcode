// Two Sum
#include <stdio.h>
#include <malloc.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int*)malloc(sizeof(int)*2);
    int i, j;
    for (i = 0; i < numsSize - 1; i++){
		result[0] = i;
		for (j = i + 1; j < numsSize; j++){
			if (nums[i] + nums[j] == target){
				result[1] = j;
				break;
			}
		}
		if (j < numsSize){
			break;
		}
	}
    return result;
}

int main()
{
	int nums[] = {0,1,3,0};
	int *result = twoSum(nums, 4, 0);
	printf("%d %d\n",result[0],result[1]);
	return 0;
}

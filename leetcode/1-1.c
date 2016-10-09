// Two Sum
#include <stdio.h>
#include <stdlib.h>

struct node {
	int number;
	int index;
};
int cmp(const void *a, const void *b){
	struct node n1 = *(struct node*)a;
	struct node n2 = *(struct node*)b;
	return n1.number - n2.number;
}

int* twoSum(int* nums, int numsSize, int target){
	int i, j;
	struct node st[numsSize];
	for (i = 0; i < numsSize; i++){
		st[i].number = nums[i];
		st[i].index = i;
	}
	int *result = (int*)malloc(2*sizeof(int));
	qsort(st, numsSize, sizeof(struct node), cmp);
	i = 0, j = numsSize - 1;
	while (i < j){
		if (st[i].number + st[j].number < target){
			i++;
		}
		else if (st[i].number + st[j].number > target){
			j--;
		}
		else {
			result[0] = st[i].index;
			result[1] = st[j].index;
			break;
		}
	}
	return result;
}

int main(){
	int nums[] = {0, 1, 3, 0};
	int *result = twoSum(nums, 4, 0);
	printf("%d %d\n", result[0], result[1]);
	return 0;
}

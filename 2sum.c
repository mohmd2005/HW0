#include <stdio.h>

#define MAX_ARRAY_SIZE 10000

void twoSum(int nums[], int nums_size, int target);

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	scanf("%d", &target);

	while (scanf("%d", &nums[array_size++]) != EOF);
	array_size--;

	twoSum(nums, array_size, target);

	return (0);
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int bsearch(int nums[],int size,int target){
	int left = 0, right = size-1,mid;
	while(left<right){
		mid = (left+right)/2;
		if(target < nums[mid]){
			right = mid -1;
		}else if(target > nums[mid]){
			left= mid +1;
		}else
			return mid;
	}
	return -1;
}

void twoSum(int nums[], int nums_size, int target) {
	mergeSort(nums,0,nums_size);
	int temp = 0;
	for(int i=1;i < nums_size;i++){
		temp = bsearch(&nums[i],nums_size-i,target-nums[i-1]);
		if(temp != -1){
			printf("(%d , %d)",i-1,temp+i-1);
		}
	}
}

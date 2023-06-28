//给你一个整数数组 nums，请你将该数组升序排列。
//
// 
//
//示例 1：
//
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
//示例 2：
//
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
//
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/sort-an-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void quickSort(int * nums, int left , int right);
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize =  numsSize;
    quickSort(nums,0, numsSize-1);	
    return nums;
}


void quickSort(int * nums, int left , int right){
	int pivot = nums[left];
	int l= left;
	int r = right;
	while(l < r){
		while(l<r && nums[r]> pivot){
			r--;
		}
		if(nums[r] <= pivot){
			nums[l] = nums[r];
		}
		while(l<r && nums[l] <= pivot){
			l++;
		}
		if(nums[l] > pivot){
			nums[r] = nums[l];
		}
		if(l >=r){
		  nums[l] = pivot;
		}
	}	
	if(l > 0 && left < l-1){
		quickSort(nums,left,l-1);
	}
	if(l+1 < right){
		quickSort(nums, l+1 ,right);
	}
}


int main(int argc, char * argv[]){
	int nums[] = {5,1,1,2,0,0};
	int * resultNum ;
	resultNum = 	malloc(sizeof(int *));
	int * result=	 sortArray(nums,6,resultNum);
	
	for(int i=0;i<6;i++){
		printf("num[i]:%d\n",result[i]);
	
	}
	return 0;
}

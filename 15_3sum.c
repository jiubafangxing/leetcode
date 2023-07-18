//15. 三数之和
//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//
//你返回所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
// 
//
// 
//
//示例 1：
//
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。
//示例 2：
//
//输入：nums = [0,1,1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
//示例 3：
//
//输入：nums = [0,0,0]
//输出：[[0,0,0]]
//解释：唯一可能的三元组和为 0 。
// 
//
//提示：
//
//3 <= nums.length <= 3000
//-105 <= nums[i] <= 105
//
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>
int cmp(const void* pa, const void* pb){
    int a=*(int*)pa;
    int b=*(int*)pb;
    return a>b?1:-1;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	qsort(nums,numsSize, sizeof(int), cmp);
	int base = 100;
	int ** res = (int **) malloc(sizeof(int *)* base);
    	*returnColumnSizes=(int*)malloc(sizeof(int)*base);

	*returnSize = 0;
	int i,j,k = 0;
	for(i=0;i< numsSize ; i++){
		if(i>0 && nums[i] == nums[i-1]){
			continue;
		}
		j=i+1;
		k=numsSize-1;
		while(j<k){
			int sum = nums[i]+nums[j]+nums[k];
			if(sum == 0){
				res[*returnSize ] = (int*) malloc(sizeof(int)*3);
				   (*returnColumnSizes)[*returnSize]=3;
			   	res[*returnSize][0] = nums[i];	   
			   	res[*returnSize][1] = nums[j];	   
			   	res[*returnSize][2] = nums[k];	   
				(*returnSize)++;
				if(*returnSize == base){
					base*=2;
				    	res=(int**)realloc(res,sizeof(int*)*base);
					    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*base);
				}
				int num1 = nums[j];
				int num2 = nums[k];
				while(nums[j]== num1 && j<k){
					j++;
				}
				while(nums[k]== num1 && j<k){
					k--;
				}

			}else if(sum < 0 ){
				j++;
			}else{
				k++;
			}
		}
	}
	return res;
}
int main(int argc, char * argv[]){
	int  nums[6] = 	{-1,0,1,2,-1,-4};
	int  returnSize = 0;
	int * array;
	threeSum(nums, 6,&returnSize, &array);
	printf("all array size if %d", returnSize);
	return 0;
}





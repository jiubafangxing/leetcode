#include <stdio.h>

 void moveZeroes(int* nums, int numsSize);


void swapa(int * right , int * left);

 void moveZeroes(int* nums, int numsSize){
	int left = 0 , right = 0 ;
	while(right < numsSize){	
		if(nums[right]){
			swapa(&nums[right],&nums[left]);
			left++;
		}  
		right++;	
	}
}

void swapa(int * right , int * left){
  int num = * right;
  * right = * left;
  * left = num;
  return ;
}

int main(int argc, char * argv[]){
	int  nums[1] = { 1 };
	moveZeroes(nums,1);
	for(int i=0; i< 1; i++){
		printf("thd num is %d\n",nums[i]);
	}
	return 0;
}

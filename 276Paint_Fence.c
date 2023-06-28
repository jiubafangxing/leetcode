//粉刷栅栏
//
//一个栅栏上有n个柱子，每个柱子可以从k个颜色中选择一种进行粉刷。
//
//粉刷所有柱子，并且最多只允许2棵相邻柱子颜色相同。
//
//求总共的粉刷方案数。
//
//注意：n和k都是非负整数。
//
//示例：
//
//输入: n = 3, k = 2
//输出: 6
//解释: 颜色1为c1，颜色2为c2，所有的粉刷方案如下:
//
//            post1  post2  post3      
// -----      -----  -----  -----       
//   1         c1     c1     c2 
//   2         c1     c2     c1 
//   3         c1     c2     c2 
//   4         c2     c1     c1  
//   5         c2     c1     c2
//   6         c2     c2     c1
#include <stdio.h>

static int numWays(int  n,int  k);

static int numWays(int  n,int  k){
	if(n < 1){
		return 0;
	}
	if(n == 1){
		return k;
	}else if (n == 2){
		return k*k;
	}else{
		int notsame = (numWays(n-1,k)) * (k-1)	;	
		int same = numWays(n-2,k)*( k-1);	
		return notsame+same;
	}
}

int main(int argc, char * argv[]){
	int ways = numWays(3,2);
	printf("the ways is %d\n", ways);
}

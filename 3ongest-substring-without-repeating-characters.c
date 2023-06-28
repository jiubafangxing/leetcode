//3. 无重复字符的最长子串
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//
// 
//
//示例 1:
//
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//示例 2:
//
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//示例 3:
//
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
//提示：
//
//0 <= s.length <= 5 * 104
//s 由英文字母、数字、符号和空格组成
//
#include <stdio.h>
#include <stdlib.h>

int  exist(char * s, int i , int b){
	   for(; i<b; i++){
		if(s[i] == s[b]){
			return 1;
		}
	   }
	   return 0;
}
int max(int a , int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int lengthOfLongestSubstring(char * s){
	int a = 0;
	int result = 0;
	while(s[a] != '\0' ){
		int b = a +1;
		int length = 1;
		while(s[b] != '\0'){
			if(0 == exist(s,a,b)){
				b++;
				length++;
			}else{
				break;
			}

		}
		result = max(length,result);
		a++;
	
	}
	return result;
}
int main(int argc , char * argv[]){
   
	char * checkstr = "abcabcbb";
	int length = lengthOfLongestSubstring(checkstr);
	fprintf(stdout, "the max length is %d\n",length);
}

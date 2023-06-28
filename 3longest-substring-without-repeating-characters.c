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
#include <string.h>
int lengthOfLongestSubstring(char * s){
	int len = strlen(s);
	int result = 0;
	int left=0, right = 0;
	int same = 0;
	for (int i=0; i< len; i++){
		if(left < right ){
			same = 0;
			for(int j = left; j < right; j++){
				if(s[j] == s[right]){
					same = 1;
				}
			}
			if(same == 1){
				left++;
			}
		}
		result =( right -left  +1 > result) ? (right -left+1):result;
		right++;
	}
	return result;
}
int main(int argc , char * argv[]){
   
	char * checkstr = "bbbbb";
	int length = lengthOfLongestSubstring(checkstr);
	fprintf(stdout, "the max length is %d\n",length);
}

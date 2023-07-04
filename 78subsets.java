import java.util.*;

class Solution {


	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> result = new ArrayList();
		LinkedList<Integer> helpArray = new LinkedList<Integer>();
		findArray(nums,0,helpArray, result);
		return result;
	}

	public void findArray(int[] nums, int start, LinkedList<Integer> helpArray, List<List<Integer>> result){
		List<Integer> subList = new ArrayList(helpArray);
		result.add(subList);
		if(start >= nums.length){
			return;
		}
		for(int i=start; i  <nums.length;i++){
			helpArray.push(nums[i]);
			findArray(nums,i+1,helpArray, result);
			helpArray.pop();
		}
	}

}

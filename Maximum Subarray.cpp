//Maximum Subarray 
//动态规划，先找出局部最优解，再从局部最优解中找出全局最优解
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int local = nums[0];
		int global = nums[0];;

		for (int i = 1; i < nums.size(); ++i)
		{
			local = max(local + nums[i], nums[i]);
			global = max(global, local);
		}

		return global;
	}
};

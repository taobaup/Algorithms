英文链接: https://leetcode.com/problems/maximum-subarray/  
中文链接: https://leetcode-cn.com/problems/maximum-subarray/


```
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0)
		{
			return 0;
		}

		int local = nums[0];
		int global = nums[0];
		for (int i = 1; i < len; ++i)
		{
			// 不要写成 local = max(local, local + nums[i]);
			local = max(nums[i], local + nums[i]);
			global = max(global, local);
		}

		return global;
	}
};
```

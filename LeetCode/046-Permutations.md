英文链接: https://leetcode.com/problems/permutations/  
中文链接: https://leetcode-cn.com/problems/permutations/

```
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		permute(res, nums, 0);

		return res;
	}

	// 注意 res 要用引用
	void permute(vector<vector<int>>& res, vector<int>& nums, int start)
	{
		if (start >= nums.size())
		{
			res.push_back(nums);
		}

		for (int i = start; i < nums.size(); ++i)
		{
			swap(nums[i], nums[start]);
			permute(res, nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
};
```

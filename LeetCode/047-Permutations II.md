英文链接: https://leetcode.com/problems/permutations-ii/  
中文链接: https://leetcode-cn.com/problems/permutations-ii/

```
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		permute(res, nums, 0);

		return res;
	}

	bool findRepeat(vector<int> &nums, int start, int end)
	{
		bool find = false;
		for (int i = start; i < end; ++i)
		{
			if (nums[i] == nums[end])
			{
				find = true;
				break;
			}
		}

		return find;
	}

	//  注意 vector<vector<int>>& res 要用引用
	void permute(vector<vector<int>>& res, vector<int> &nums, int start)
	{
		if (start >= nums.size())
		{
			res.push_back(nums);
		}

		for (int i = start; i < nums.size(); ++i)
		{
			if (findRepeat(nums, start, i))
			{
				continue;
			}	

			swap(nums[i], nums[start]);
			permute(res, nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
};
```

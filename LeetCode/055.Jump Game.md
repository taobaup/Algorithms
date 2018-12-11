英文链接: https://leetcode.com/problems/jump-game/   
中文链接: https://leetcode-cn.com/problems/jump-game/


```
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		int reach = 0;

		for (int i = 0; i < len; ++i)
		{
			// 不要遗漏 reach < i
			if (reach < i || reach >= len - 1)
			{
				break;
			}

			reach = max(reach, i + nums[i]);
		}

		return reach >= len - 1;
	}
};
```

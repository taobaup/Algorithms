英文链接: https://leetcode.com/problems/jump-game-ii/  
中文链接: https://leetcode-cn.com/problems/jump-game-ii/

参考: http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html

```
class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0;
		int last = 0;
		int cur = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > last)
			{
				last = cur;
				++step;
			}

			cur = max(cur, i + nums[i]);
		}

		return step;
	}
};
```

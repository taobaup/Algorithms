英文链接: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/  
中文链接: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/


```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 2)
		{
			return len;
		}

		int index = 2;
		for (int i = 2; i < len; ++i)
		{
			if (nums[i] != nums[index - 2])
			{
				nums[index] = nums[i];
				++index;
			}
		}

		return index;
	}
};

```



```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();

		int index = 0;
		for (int i = 0; i < len; ++i)
		{
			if (i > 0 && i < len - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
			{
				continue;
			}

			nums[index] = nums[i];
			++index;
		}

		return index;
	}
};
```

英文链接: https://leetcode.com/problems/remove-duplicates-from-sorted-array/  
中文链接: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/


```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();

		if (len <= 1)
		{
			return len;
		}

		int index = 1;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] != nums[i - 1])
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

		if (len <= 1)
		{
			return len;
		}

		int index = 1;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] != nums[index - 1])
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
		auto last = unique(nums.begin(), nums.end());
		return distance(nums.begin(), last);
	}
};
```



```
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		auto last = removeDuplicates(nums.begin(), nums.end(), nums.begin());
		return distance(nums.begin(), last);
	}

private:
	template<typename InIt, typename OutIt>
	OutIt removeDuplicates(InIt first, InIt last, OutIt output)
	{
		while (first != last)
		{
			// 不要遗漏 ++
			*output++ = *first;
			first = upper_bound(first, last, *first);
		}

		return output;
	}
};

```

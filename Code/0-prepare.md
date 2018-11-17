#### 全排列
>字符串“abc”的全排列：
abc acb bac bca cba cab

* 无重复的全排列
```
#include<iostream>  
#include<assert.h>  

using namespace std;

void Permutation(char *pStr, char *pBegin)
{
	assert(pStr && pBegin);

	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			swap(*pBegin, *pCh);
			Permutation(pStr, pBegin + 1);
			swap(*pBegin, *pCh);
		}
	}
}

int main()
{
	char str[] = "abc";
	Permutation(str, str);

	return 0;
}
```

LeetCode 46. Permutations
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

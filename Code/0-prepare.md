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

```
#include<iostream>  
#include<string>

using namespace std;

void permutationRecursion(string &s, int start)
{
	if (start == s.size())
	{
		cout << s << endl;
		return;
	}

	// 注意这里是 i = start; 而不是 i = 0;
	for (int i = start; i < s.size(); ++i)
	{
		swap(s[i], s[start]);
		permutationRecursion(s, start + 1);
		swap(s[i], s[start]);
	}
}

int main()
{
	string s = "abc";
	permutationRecursion(s, 0);

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


LeetCode 27. Remove Element

遍历数组, 将不等于val的值放回原数组   
注意此前已经++index;所以最后return index;即可, 不需要return index + 1; 

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int index = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != val)
			{
				nums[index] = nums[i];
				++index;
			}
		}

		return index;
	}
};
```


每找到一个等于val的元素, 将数组末尾的数移到该位置   
这样可以保证如果没有重复就没有写操作 
```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[len - 1];
				--len;
				--i;
			}
		}

		return len;
	}
};
```


借助STL也可以AC, 但不推荐

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;

		return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};
```

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{
			if (*it == val)
			{
				it = nums.erase(it);
				--it;
			}
		}

		return nums.size();
	}
};
```

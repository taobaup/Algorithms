LeetCode 28.Implement strStr()

```
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}

		int m = haystack.size();
		int n = needle.size();

		if (m < n)
		{
			return -1;
		}

		for (int i = 0; i <= m - n; ++i)
		{
			int j;
			for (j = 0; j < n; ++j)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}		
			}

			if (j == n)
			{
				return i;
			}
		}

		return -1;
	}
};
```

字符串匹配

```
#include<iostream>  
#include<string>

using namespace std;

bool hasSubString(const char *str, const char *find)
{
	if (str[0] == '\0' && find[0] == '\0')
	{
		return true;
	}

	for (int i = 0; str[i] != '\0'; ++i)
	{
		bool found = true;
		for (int j = 0; find[j] != '\0'; ++j)
		{
			if (str[i + j] != find[j])
			{
				found = false;
				break;
			}
		}

		if (found)
		{
			return true;
		}
	}

	return false;
}

bool hasSubString2(const char *str, const char *find)
{
	const int m = strlen(str);
	const int n = strlen(find);

	if (m == 0 && n == 0)
	{
		return true;
	}

	// 注意是 i <= m - n; 而不是 i < m - n;
	for (int i = 0; i <= m - n; ++i)
	{
		bool found = true;
		for (int j = 0; j < n; ++j)
		{
			if (str[i + j] != find[j])
			{
				found = false;
				break;
			}
		}

		if (found)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	char s[] = "leetcode";
	char t[] = "code";

	bool flag = hasSubString(s, t);
	cout << flag << endl;
    	flag = hasSubString2(s, t);
	cout << flag << endl;

	char p[] = "mycode";
	flag = hasSubString(s, p);
	cout << flag << endl;
	flag = hasSubString2(s, p);
	cout << flag << endl;

	return 0;
}
```



LeetCode 128. Longest Consecutive Sequence
>Get the length of the longest consecutive elements sequence in an array  
For example, given [31, 6, 32, 1, 3, 2],the longest consecutive elements sequence is [1, 2, 3].   
Return its length: 3.  
判断array[i] – 1，array[i] + 1是否存在于数组中。如何保存之前的处理结果？可以使用hash table 由于序列是一系列连续整数，所以只要序列的最小值以及最
大值，就能唯一确定序列。而所谓的“作为后继加入序列”，“作为前驱加入序列”，更新最大最小值。hash table的value可以是一个记录最大／最小值的
structure，⽤用以描述当前节点参与构成的最长序列。  
时间复杂度O(n)，附加空间O(n)


```
struct Bound
{
	int high;
	int low;

	Bound(int h = 0, int l = 0)
	{
		high = h;
		low = l;
	}
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, Bound> hashMap;

        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (hashMap.count(nums[i]))
        	{
        		continue;
        	}

        	int local = nums[i];

        	int low = local, high = local;
        	if (hashMap.count(local - 1))
        	{
        		low = hashMap[local - 1].low;
        	}
        	if (hashMap.count(local + 1))
        	{
        		high = hashMap[local + 1].high;
        	}

        	hashMap[local].low = low;
        	hashMap[local].high = high;

        	hashMap[low].high = high;
        	hashMap[high].low = low;

        	if (high - low + 1 > maxLen)
        	{
        		maxLen = high - low + 1;
        	}
        }

        return maxLen;
    }
};
```

英文链接: https://leetcode.com/problems/longest-substring-without-repeating-characters/   
中文链接: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/


```
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		int m[256] = { 0 };
		int left = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			if (m[s[i]] == 0 || m[s[i]] < left)
			{
				res = max(res, i - left + 1);
			}
			else
			{
				left = m[s[i]];
			}

			m[s[i]] = i + 1;
		}

		return res;
	}
};
```



```
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;

		// 不能用 int m[256] = { -1 };
		vector<int> m(256, -1);
		int left = -1;

		for (int i = 0; i < s.size(); ++i)
		{
			left = max(left, m[s[i]]);
			res = max(res, i - left);
			m[s[i]] = i;
		}

		return res;
	}
};
```

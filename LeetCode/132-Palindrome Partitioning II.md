英文链接: https://leetcode.com/problems/palindrome-partitioning-ii/  
中文链接: https://leetcode-cn.com/problems/palindrome-partitioning-ii/ 


```
class Solution {
public:
	int minCut(string s) {
		const int len = s.size();

		// bool P[len][len];
		// int dp[len + 1];

		int **P = new int*[len];
		for (int i = 0; i < len; ++i)
		{
			P[i] = new int[len];
		}
		int *dp = new int[len + 1];

		// len 而非 len - 1
		for (int i = len; i >= 0; --i)
		{
			dp[i] = len - 1 - i;
		}

		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				P[i][j] = false;
			}
		}

		for (int i = len - 1; i >= 0; --i)
		{
			for (int j = i; j < len; ++j)
			{
				if (s[i] == s[j] && (j - i <= 1 || P[i + 1][j - 1]))
				{
					P[i][j] = true;
					dp[i] = min(dp[i], dp[j + 1] + 1);
				}
			}
		}

		return dp[0];
	}
};
```

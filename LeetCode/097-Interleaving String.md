英文链接: https://leetcode.com/problems/interleaving-string/  
中文链接: https://leetcode-cn.com/problems/interleaving-string/

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"  
输出: true

```
  Ø d b b c a
Ø T F F F F F
a T F F F F F
a T T T T T F
b F T T F T F
c F F T T T T
c F F F T F T
```

```
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size();
		int n = s2.size();

		if (m + n != s3.size())
		{
			return false;
		}

		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= m; ++i)
		{
			dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
		}

		for (int j = 1; j <= n; ++j)
		{
			dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
		}

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j])
							|| (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}

		return dp[m][n];
	}
};
```

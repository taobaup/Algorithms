英文链接: https://leetcode.com/problems/edit-distance/  
中文链接: https://leetcode-cn.com/problems/edit-distance/


```
class Solution {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.size();
		const int n = word2.size();

        	// 不要写成 vector<vector<int>> dp(m, vector<int>(n, 0));
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; ++i)
			dp[i][0] = i;
		for (int j = 0; j <= n; ++j)
			dp[0][j] = j;

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					int mn = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(mn, dp[i - 1][j - 1]) + 1;
				}
			}
		}

		return dp[m][n];
	}
};
```

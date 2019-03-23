英文链接: https://leetcode.com/problems/unique-paths/  
中文链接: https://leetcode-cn.com/problems/unique-paths/

Time Limit Exceeded
```
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1)
		{
			return 0;
		}

		if (m == 1 && n == 1)
		{
			return 1;
		}

		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};
```


深搜+缓存，即备忘录法
```
class Solution {
public:
	int uniquePaths(int m, int n) {
		f = vector<vector<int>>(m, vector<int>(n, 0));

		f[0][0] = 1;
		int res = dfs(m - 1, n - 1);
		
		return res;
	}

private:
	vector<vector<int>> f;

	int dfs(int x, int y)
	{
		if (x < 0 || y < 0)
		{
			return 0;
		}

		if ((x > 0 || y > 0) && f[x][y] == 0)
		{
			// 不要写成 f[x][y] = f[x - 1][y] + f[x][y - 1];
			f[x][y] = dfs(x - 1, y) + dfs(x, y - 1);
		}

		return f[x][y];
	}
};
```

动态规划
```
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[0][0] = 1;
		for (int i = 1; i < m; ++i)
		{
			// 不要写成 f[i][1]
			dp[i][0] = 1;
		}
		for (int j = 1; j < n; ++j)
		{
			// 不要写成 f[1][j]
			dp[0][j] = 1;
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};
```

动态规划+滚动数组
```
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> dp(n, 0);

		dp[0] = 1;
		/*for (int j = 1; j < n; ++j)
		{
			dp[j] = dp[j] + dp[j - 1];
		}*/

		for (int i = 0; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[j] = dp[j] + dp[j - 1];
			}
		}

		return dp[n - 1];
	}
};
```

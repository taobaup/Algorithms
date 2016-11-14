//Minimum Path Sum 
//动态规划，状态转移方程为 
//result[i][j]=min(result[i-1][j], result[i][j-1])+grid[i][j];
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;

		const int m = grid.size();
		const int n = grid[0].size();

		int *result = new int[n];

		result[0] = grid[0][0];
		for (int i = 1; i < n; ++i)
			result[i] = result[i - 1] + grid[0][i];

		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (j == 0)
					result[j] += grid[i][j];
				else
					result[j] = min(result[j - 1], result[j]) + grid[i][j];
			}
		}

		return result[n - 1];
	}
};

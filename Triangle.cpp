//Triangle 
//利用动态规划，其状态转移方程为 
//f(i,j) = min{f(i + 1,j),f(i + 1,j + 1)} + (i,j)
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;

		for (int i = triangle.size() - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}

		return triangle[0][0];
	}
};

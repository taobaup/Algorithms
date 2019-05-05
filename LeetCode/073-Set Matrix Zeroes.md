
英文链接: https://leetcode.com/problems/set-matrix-zeroes/  
中文链接: https://leetcode-cn.com/problems/set-matrix-zeroes/

```
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		const int m = matrix.size();
		// const int n=matrix.front().size();
		const int n = matrix[0].size();

		if (m < 0 || n < 0)
			return;

		vector<bool> row(m, false);
		vector<bool> col(n, false);

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					row[i] = true;
					col[j] = true;
				}
			}
		}

		for (int i = 0; i < m; ++i)
		{
			if (row[i])
			{
				for (int j = 0; j < n; ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}

		for (int j = 0; j < n; ++j)
		{
			if (col[j])
			{
				for (int i = 0; i < m; ++i)
				{
					matrix[i][j] = 0;
				}
			}
		}

		return;
	}
};
```

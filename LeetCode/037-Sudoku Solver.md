英文链接: https://leetcode.com/problems/sudoku-solver/  
中文链接: https://leetcode-cn.com/problems/sudoku-solver/

```
这道题是 Valid Sudoku 验证数独的扩展题：求解数独数组 
对于每个可以填数字的格子尝试写入1到9，每写入一个数字都判定其是否合法 
如果合法就继续下一次递归，结束时把数字设回'.' 
判断新加入的数字是否合法时，只需要判定当前数字是否合法 
不需要判定这个数组是否为数独数组，因为之前加进的数字都是合法的 
注意不要把

if (dfs(board, i, j + 1))
{
	return true;
}

写成 return dfs(board, i, j + 1)
```


```
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		int row = board.size();
		int col = board[0].size();

		if (row != 9 || col != 9)
		{
			return;
		}

		dfs(board, 0, 0);
	}

private:
	bool dfs(vector<vector<char>>& board, int i, int j)
	{
		if (i == 9)
		{
			return true;
		}

		if (j == 9)
		{
			return dfs(board, i + 1, 0);
		}

		if (board[i][j] == '.')
		{
			for (int k = 1; k <= 9; ++k)
			{
				board[i][j] = (char)(k + '0');
				if (isValid(board, i, j))
				{
					if (dfs(board, i, j + 1))
					{
						return true;
					}
				}
				board[i][j] = '.';
			}
		}
		else
		{
			return dfs(board, i, j + 1);
		}

		return false;
	}

	bool isValid(vector<vector<char>>& board, int i, int j)
	{
		for (int row = 0; row < 9; ++row)
		{
			if (row != i && board[row][j] == board[i][j])
			{
				return false;
			}
		}

		for (int col = 0; col < 9; ++col)
		{
			if (col != j && board[i][col] == board[i][j])
			{
				return false;
			}
		}

		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row)
		{
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col)
			{
				if ((row != i || col != j) && board[row][col] == board[i][j])
				{
					return false;
				}
			}
		}

		return true;
	}
};
```

英文链接: https://leetcode.com/problems/valid-sudoku/  
中文链接: https://leetcode-cn.com/problems/valid-sudoku/


>验证一个方阵是否为数独矩阵


>判断标准是各行各列，以及每个3x3的小方阵是否有重复数字   
都无重复，则当前矩阵是数独矩阵，但不代表该数独矩阵有解

>遍历每个数字时检查包含当前位置的行和列以及小方阵中是否已经出现该数字   
使用三个标志矩阵，分别记录各行，各列，各小方阵是否出现某个数字即可   
其中行和列标志下标很好对应，小方阵的下标需要转换一下  
注意一定要判断board[i][j]的范围

```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        if(m == 0 || n == 0)
            return false;

        vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
        vector<vector<bool>> colFlag(m, vector<bool>(n, false));
        vector<vector<bool>> cellFlag(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9')
                {
                    int c = board[i][j] - '1';
                    if(rowFlag[i][c] || colFlag[c][j] || cellFlag[i / 3 * 3 + j / 3][c])
                        return false;

                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[i / 3 * 3 + j / 3][c] = true;
                }
            }
        }

        return true;
    }
};
```


英文链接: https://leetcode.com/problems/ones-and-zeroes/  
中文链接: https://leetcode-cn.com/problems/ones-and-zeroes/

0-1背包问题，dp[i][j][k]代表前i个字符串1的个数为j，0的个数为k的最多字符串个数  
对第i个字符串，既可用取也可以用不取的做法，状态转移方程为

dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-ones][k-zeros])+1

i只与i-1有关，可以变为二维数组

dp[i][j] = max(dp[i][j], dp[i – a][j – b] + 1).

注意遍历的时候是从最右底部开始遍历

```
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string str : strs) 
        {
            int zeros = 0, ones = 0;

            for (char c : str) 
            {
            	(c == '0') ? ++zeros : ++ones;
            }

            for (int i = m; i >= zeros; --i) 
            {
                for (int j = n; j >= ones; --j) 
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
```

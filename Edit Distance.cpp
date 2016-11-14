//Edit Distance
//动态规划
class Solution {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.size();
		const int n = word2.size();

		int result[m+1][n+1];

		for (int i = 0; i <= m; ++i)
			result[i][0] = i;
		for (int j = 0; j <= n; ++j)
			result[0][j] = j;

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					result[i][j] = result[i - 1][j - 1];
				else
				{
					int mn = min(result[i - 1][j], result[i][j - 1]);
					result[i][j] = 1 + min(result[i - 1][j - 1], mn);
				}
			}
		}

		return result[m][n];
	}
};

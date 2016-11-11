//Pascal’s Triangle 
//第一个元素和最后一个元素赋值为 1 
//中间的每个元素，等于上一行的左上角和右上角元素之和
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;

		for (int i = 0; i < numRows; ++i)
		{
			result.emplace_back(i + 1);
			result[i][0] = 1;
			result[i][i] = 1;
			for (int j = 1; j < i; ++j)
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}

		return result;
	}
};

//Pascal's Triangle II
//利用滚动数组
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1);

		result[0] = 1;
		for (int i = 1; i < rowIndex + 1; ++i)
		{
			for (int j = i; j >= 1; --j)
				result[j] += result[j - 1];
		}

		return result;
};

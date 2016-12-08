解题思路：以数组右上角的数为参考，
若target等于右上角数，则查找成功；
若target小于右上角数，则右上角数所在列不在查找范围；
若target大于右上角数，则右上角数所在行不在查询范围；
若查找范围为空，则说明target不存在。
以数组左下角的数为参考亦可。
但不能选取左上角或右下角，因target与数组中的min，max比较并不能缩小查找范围。
而若选取数组中任意数，则会让查找范围变得复杂。
//以数组右上角的数为参考
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())
			return false;

		const int row = array.size(), column = array[0].size();
		int i = 0, j = column - 1;

		while (i <= row - 1 && j >= 0)
		{
			if (array[i][j] == target)
				return true;
			else if (target < array[i][j])
				--j;
			else
				++i;
		}

		return false;
	}
};
//以数组左下角的数为参考
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())
			return false;

		const int row = array.size(), column = array[0].size();
		int i = row - 1, j = 0;

		while(i>=0&&j<=column-1)
		{
			if (array[i][j] == target)
				return true;
			else if (target > array[i][j])
				++j;
			else
				--i;
		}

		return false;
	}
};

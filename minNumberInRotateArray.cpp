解题思路：
有以下几种解法
1.遍历数组，找到minValue，但效率不高
2.使用二分查找
若rotateArray[mid] < rotateArray[last]
则minValue存在于first，mid
若rotateArray[mid] > rotateArray[last])
则minValue存在于mid+1，last
若rotateArray[mid] == rotateArray[last])		
则minValue存在于first，--last
//解法1
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;

		int minValue = rotateArray[0];

		for (unsigned int i = 1; i < rotateArray.size(); ++i)
		{
			if (rotateArray[i] < minValue)
				minValue = rotateArray[i];
		}

		return minValue;
	}
};
//解法2
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;

		int first = 0, last = rotateArray.size() - 1;
		while (first < last)
		{
			const int mid = first + (last - first) / 2;

			if (rotateArray[mid] < rotateArray[last])
				last = mid;
			else if (rotateArray[mid] > rotateArray[last])
				first = mid + 1;
			else
				--last;
		}

		return rotateArray[first];
	}
};

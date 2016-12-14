把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。 
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

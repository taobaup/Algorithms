//Sqrt(x) 
//二分查找
class Solution {
public:
	int mySqrt(int x) {
		if (x < 2)
			return x;

		int left = 1, right = x / 2;
		int result = 0;

		while (left <= right)
		{
			const int mid = left + (right - left) / 2;
			if (x / mid > mid)
			{
				left = mid + 1;
				result = mid;
			}
			else if (x / mid < mid)
				right = mid - 1;
			else
				return mid;
		}

		return result;
	}
};

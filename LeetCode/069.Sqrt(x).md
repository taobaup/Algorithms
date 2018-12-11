英文链接: https://leetcode.com/problems/sqrtx/  
中文链接: https://leetcode-cn.com/problems/sqrtx/


二分查找，取定左值和右值，每次砍掉不符合条件的一半，直到左值和右值相遇  
也可采用牛顿迭代法


```
class Solution {
public:
	int mySqrt(int x) {
		// 不加该条件，x为1不成立
		if (x < 2)
		{
			return x;
		}

		// left 为1而不是0
		int left = 1;
		int right = x / 2;

		int res = 0;
		while (left <= right)
		{
			// not left + (right - left) >> 1
			const int mid = left + ((right - left) >> 1);

			if (x / mid > mid)
			{
				left = mid + 1;
				res = mid;
			}
			else if (x / mid < mid)
			{
				// right = mid;
				right = mid - 1;
			}
			else
			{
				// res = mid;
				return mid;
			}

			// 加上这两行是错误的
			/*++left;
			--right;*/
		}

		return res;
	}
};
```

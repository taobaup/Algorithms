题目：二进制中1的个数

题意：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

解题思路：
(n - 1)&n即是把n的二进制表示中的最后一个1变为0
则while执行次数对应n的二进制中1的个数

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;

		while (n)
		{
			++count;
			n = (n - 1)&n;
		}

		return count;
	}
};

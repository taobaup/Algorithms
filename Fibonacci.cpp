题目：斐波那契数列

题意：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39

解题思路：
有以下几种解法：
1.递归：
若n==0，返回0。
若n==1，返回1。
若n>=2，返回f(n - 1) + f(n - 2)。
2.循环：
若n==0，返回0。
若n==1，返回1。
若n>=2，由cur = prev + cur; 得到cur的值

//解法1
class Solution {
public:
	int Fibonacci(int n) {
		if (n < 0)
			return -1;

		if (n == 0)
			return 0;

		if (n == 1)
			return 1;

		else
			return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};

//解法2
class Solution {
public:
	int Fibonacci(int n) {
		if (n < 0)
			return -1;

		if (n == 0)
			return 0;

		if (n == 1)
			return 1;

		int prev = 0, cur = 1;
		for (int i = 2; i <= n; ++i)
		{
			int temp = cur;
			cur = prev + cur;
			prev = temp;
		}

		return cur;
	}
};

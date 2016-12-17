题目：数值的整数次方

题意：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

解题思路：
首先判断传入的base，exponent参数的有效性
当底数为0且指数为负数时，应判断输入无效
使用成员变量inputInvalid记录参数的有效性
这里需要注意的是：计算机表示小数（包括float，double）都有误差。
因此不能直接用==判断两个小数是否相等，当两数差的绝对值< 0.0000001时，即可判断它们相等
判断完参数有效性后，即可循环得到数值的整数次方
为保证高效，可借助位运算减少乘法次数
以下两种解法仅PowerNum的实现不同


//解法1
class Solution {
public:
	double Power(double base, int exponent) {
		inputInvalid = false;

		if (equal(base, 0.0) && exponent < 0)
		{
			inputInvalid = true;
			return 0.0;
		}
		
		int absexponent = exponent;
		if (exponent < 0)
			absexponent = -exponent;

		return exponent > 0 ? PowerNum(base, absexponent) : 1.0 / PowerNum(base, absexponent);
	}

private:
	bool inputInvalid = false;

	bool equal(double num1, double num2)
	{
		if ((num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001)
			return true;
		else
			return false;
	}

	double PowerNum(double base, int num)
	{
		double result = 1.0;

		for (int i = 0; i < num; ++i)
			result *= base;

		return result;
	}
};


//解法2
class Solution {
public:
	double Power(double base, int exponent) {
		inputInvalid = false;

		if (equal(base, 0.0) && exponent < 0)
		{
			inputInvalid = true;
			return 0.0;
		}

		int absexponent = exponent;
		if (exponent < 0)
			absexponent = -exponent;

		return exponent > 0 ? PowerNum(base, absexponent) : 1.0 / PowerNum(base, absexponent);
	}

private:
	bool inputInvalid = false;

	bool equal(double num1, double num2)
	{
		if ((num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001)
			return true;
		else
			return false;
	}

	double PowerNum(double base, int num)
	{
		if (num == 0)
			return 1;
		if (num == 1)
			return base;

		double result = PowerNum(base, num >> 1);
		result *= result;

		if (num&0x1 == 1)
			result *= base;

		return result;
	}
};

英文链接: https://leetcode.com/problems/powx-n/  
中文链接: https://leetcode-cn.com/problems/powx-n/

#### 递归版  
求 x 的 n 次方，for循环让 x 乘以自己 n 次，会因超时无法通过   
用递归来折半计算，每次把 n 缩小一半，这样 n 最终会缩小到等于 0   
任何数的 0 次方都为1   
这时再往回乘   
如果 n 是偶数，直接把上次递归得到的值平方后返回   
如果 n 是奇数，则还需要乘以 x    
注意对于 n 是负数的情况，可以先用相反数计算出结果再取其倒数即可


#### 迭代版   
迭代解法，i 的初始值为 n，若 i 为 2 的倍数，则 x 乘以自己   
否则 res 乘以 x   
i 每次循环缩小一半，直到为 0 停止循环   
最后注意不要遗漏 n 的正负，如果为负，返回其倒数   
n 在最后在判断符号，所以 i != 0 不能写成 i > 0  
if(i & 0x1 == 1) 不要写成  if(n & 0x1 == 1)   
return n > 0 ? res : 1.0 / res; 一定不要写成  return n > 0 ? res : -res;


```
class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0)
		{
			// -n, not n
			return 1.0 / myPower(x, -n);
		}
		else
		{
			return myPower(x, n);
		}
	}

private:
	double myPower(double x, int n) {
		if (n == 0)
		{
			return 1.0;
		}
		if (n == 1)
		{
			return x;
		}

		double half = myPower(x, n / 2);
		if (n & 0x1 == 1)
		{
			return x * half * half;
		}
		else
		{
			return half * half;
		}
	}
};
```


```
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
		{
			return 1.0;
		}

		if (n == 1)
		{
			return x;
		}

		// double, not int
		double res = 1.0;
		// /= 不能分开
		for (int i = n; i != 0; i /= 2)
		{
			if (i & 0x1 == 1)
			{
				res *= x;
			}

			x *= x;
		}

		// 不要遗漏对 n 的符号的判断
		return n > 0 ? res : 1.0 / res;
	}
};
```

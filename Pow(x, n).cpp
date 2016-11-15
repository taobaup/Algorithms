//Pow(x, n) 
//二分法，递归求解即可 
//注意判断n的奇偶性
class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0)
			return 1.0 / power(x, -n);
		else
			return power(x, n);
	}
private:
	double power(double x, int n)
	{
		if (n == 0)
			return 1;
		double result = power(x, n / 2);
		if (n % 2)
			return x*result*result;
		else
			return result*result;
	}
};

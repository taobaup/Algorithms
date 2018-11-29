//Reverse Integer 
//取模，依次进位即可 
//为防止result * 10 + num % 10 > INT_MAX越界
//应判断result > (INT_MAX - num % 10) / 10
class Solution {
public:
	int reverse(int x)
	{
		if (x == INT_MIN)
			return 0;

		int num = abs(x);
		int result = 0;

		while (num)
		{
			if (result > (INT_MAX - num % 10) / 10)
				return 0;

			result = result * 10 + num % 10;
			num = num / 10;
		}

		return x > 0 ? result : -result;
	}
};

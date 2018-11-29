//Palindrome Number 
//依次比较头尾两位即可
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		int dig = 1;
		while (x / dig >= 10)
			dig *= 10;

		while (x)
		{
			if (x / dig != x % 10)
				return false;
			x = (x%dig) / 10;
			dig /= 100;
		}

		return true;
	}
};

//Reverse Integer 
//取模，依次进位即可 
//时间复杂度 O(logn)，空间复杂度 O(1)
class Solution {
public:
    int reverse(int x) {
	int result = 0;

	while (x)
	{
		result = result * 10 + x % 10;
		x = x / 10;
	}

	return result;
    }
};

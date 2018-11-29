//Multiply Strings 
//遍历两个字符串，依次进位即可 
//先将vector中无效位的0去除然后逆序得到的string为所求
class Solution {
public:
	string multiply(string num1, string num2) {
		const int m = num1.size();
		const int n = num2.size();
		vector<int> a(m + n, 0);

		for (int i = 0; i < m; ++i)
		{
			int dig = 0;
			for (int j = 0; j < n; ++j)
			{
				a[i + j] += (num1[m - 1 - i] - '0')*(num2[n - 1 - j] - '0') + dig;
				dig = a[i + j] / 10;
				a[i + j] %= 10;
			}
			if (dig)
				a[n + i] += dig;
		}

		while (a.size() > 1 && a.back() == 0)
			a.pop_back();

		string result;
		for (auto it = a.rbegin(); it != a.rend(); ++it)
			result += *it + '0';

		return result;
	}
};

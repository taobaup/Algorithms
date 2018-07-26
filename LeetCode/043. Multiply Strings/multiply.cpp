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

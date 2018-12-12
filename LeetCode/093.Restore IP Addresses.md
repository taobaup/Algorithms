英文链接: https://leetcode.com/problems/restore-ip-addresses/  
中文链接: https://leetcode-cn.com/problems/restore-ip-addresses/


```
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string out;

		restore(s, 4, out, res);

		return res;
	}

private:
	void restore(string s, int k, string out, vector<string> &res) {
		if (k == 0)
		{
			// 不要遗漏这个条件
			if (s.empty())
			{
				res.push_back(out);
			}
		}
		else
		{
			for (int i = 1; i <= 3; ++i)
			{
				// 不要遗漏这个条件
				if (s.size() >= i && isValid(s.substr(0, i)))
				{
					if (k == 1)
					{
						// 不要写成 return
						restore(s.substr(i), k - 1, out + s.substr(0, i), res);
					}
					else
					{
						// 不要写成 return
						restore(s.substr(i), k - 1, out + s.substr(0, i) + '.', res);
					}
				}
			}
		}
	}

	bool isValid(string s)
	{
		if (s.empty() || s.size() > 3)
		{
			return false;
		}

		if (s.size() > 1 && s[0] == '0')
		{
			return false;
		}

		int num = atoi(s.c_str());
		return num >= 0 && num <= 255;
	}
};
```

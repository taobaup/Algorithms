英文链接: https://leetcode.com/problems/multiply-strings/  
中文链接: https://leetcode-cn.com/problems/multiply-strings/


```
class Solution {
public:
    string multiply(string num1, string num2) {
        const int m = num1.size();
        const int n = num2.size();
        vector<int> v(m + n, 0);

        for(int i = 0; i < m; ++i)
        {
        	int dig = 0;
        	for(int j = 0; j < n; ++j)
        	{
        		v[i + j] += (num1[m - 1- i] - '0') * (num2[n - 1 - j] - '0') + dig;
        		dig = v[i + j] / 10;
        		v[i + j] %= 10;
        	}

        	if(dig > 0)
        		v[n + i] += dig;
        }

	// not v.size() > 0
        while(v.size() > 1 && v.back() == 0)
        	v.pop_back();

        string res;
        for(auto it = v.rbegin(); it != v.rend(); ++it)
        	res += *it + '0';

        return res;
    }
};
```

英文链接: https://leetcode.com/problems/palindrome-partitioning/  
中文链接: https://leetcode-cn.com/problems/palindrome-partitioning/


```
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> out;

		partitionDFS(s, 0, out, res);

		return res;
	}

private:
	// 注意 out 跟 res 都是引用
	void partitionDFS(string s, int start, 
		vector<string> out, vector<vector<string>> &res)
	{
		if (start == s.size())
		{
			res.push_back(out);
			return;
		}

		for (int i = start; i < s.size(); ++i)
		{
			if (isPalindrome(s, start, i))
			{
				// 不要写成 s.substr(i, i - start + 1)
				out.push_back(s.substr(start, i - start + 1));
				partitionDFS(s, i + 1, out, res);
				out.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int start, int end)
	{
		bool isPalindrome = true;
		while (start < end)
		{
			if (s[start] != s[end])
			{
				isPalindrome = false;
			}

			++start;
			--end;
		}

		return isPalindrome;
	}
};
```

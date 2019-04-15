英文链接: https://leetcode.com/problems/letter-combinations-of-a-phone-number/   
中文链接: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/ 


>给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

>排列组合问题   
1: 递归版   
建立字典保存每个数字所代表的字符串   
用一个变量level，记录当前生成的字符串的字符个数   
递归出口为level == digits.size()   
注意letterCombinationsDFS(result, dict, digits, level + 1, temp);   
不要写成letterCombinationsDFS(result, dict, digits, level + 1, str);   
level == digits.size()之后result.push_back(temp);再return;不要写成return result;

```
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;

		if (digits.empty())
		{
			return result;
		}

		string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		letterCombinationsDFS(result, dict, digits, 0, "");

		return result;
	}

private:
	 void letterCombinationsDFS(vector<string> &result, string dict[],
			string digits, int level, string temp) {
		 if (level == digits.size())
		 {
			 result.push_back(temp);
			 return;
		 }

		 string str = dict[digits[level] - '2'];
		 for (int i = 0; i < str.size(); ++i)
		 {
			 temp.push_back(str[i]);
			 letterCombinationsDFS(result, dict, digits, level + 1, temp);
			 temp.pop_back();
		 }

		 return;
	}
};
```

>2: 迭代版   
依次读取数字   
将数字可以代表的字符加入当前结果   
然后进入下一次迭代   
注意提前result.push_back(“”);   
string temp = result.front();不要写成string temp = result.begin();   
不要忘记return reuslt;
```
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;

		if (digits.empty())
		{
			return result;
		}

		string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		result.push_back("");

		for (int i = 0; i < digits.size(); ++i)
		{
			int n = result.size();
			string str = dict[digits[i]-'2'];

			for (int j = 0; j < n; ++j)
			{
				string temp = result.front();
				result.erase(result.begin());

				for (int k = 0; k < str.size(); ++k)
				{
					result.push_back(temp + str[k]);
				}
			}
		}

		return result;
	}
};
```

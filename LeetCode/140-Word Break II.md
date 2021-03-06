
英文链接: https://leetcode.com/problems/word-break-ii/  
中文链接: https://leetcode-cn.com/problems/word-break-ii/


```
class Solution {
public:
    	vector<string> wordBreak(string s, vector<string>& wordDict) {
        	unordered_set<string> dict;

        	for(int i = 0; i < wordDict.size(); ++i)
        	{
			dict.insert(wordDict[i]);
        	}
        
        	vector<bool> f(s.size() + 1, false);
		vector<vector<bool> > prev(s.size() + 1, vector<bool>(s.size()));
		f[0] = true;

		for (int j = 1; j <= s.size(); ++j) 
		{
			for (int i = j - 1; i >= 0; --i) 
			{
				if (f[i] && dict.find(s.substr(i, j - i)) != dict.end()) 
				{
					f[j] = true;
					prev[j][i] = true;
				}
			}
		}

		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.size(), path, result);
		
		return result;
	}

private:
	void gen_path(const string &s, const vector<vector<bool> > &prev,
			int cur, vector<string> &path, vector<string> &result) 
	{
		if (cur == 0) 
		{
			string tmp;
			for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
			{
				tmp += *iter + " ";
			}
			
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}

		for (int i = 0; i < s.size(); ++i) 
		{
			if (prev[cur][i]) 
			{
				path.push_back(s.substr(i, cur - i));
				gen_path(s, prev, i, path, result);
				path.pop_back();
			}
		}
	}
};
```

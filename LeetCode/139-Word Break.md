英文链接: https://leetcode.com/problems/word-break/  
中文链接: https://leetcode-cn.com/problems/word-break/


>l   
le e   
lee ee e   
leet   
leetc eetc etc tc c   
leetco eetco etco tco co o   
leetcod eetcod etcod tcod cod od d   
leetcode eetcode etcode tcode code   
T F F F T F F F T 


```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    		unordered_set<string> dict;

        	for(int i = 0; i < wordDict.size(); ++i)
        	{
			dict.insert(wordDict[i]);
        	}

       	 	vector<bool> f(s.size() + 1, false);
		f[0] = true; 
		
		for (int j = 1; j <= s.size(); ++j) 
		{
			for (int i = j - 1; i >= 0; --i) 
			{
				if (f[i] && dict.find(s.substr(i, j - i)) != dict.end()) 
				{
					f[j] = true;
					break;
				}
			}
		}

		return f[s.size()];
    }
};
```

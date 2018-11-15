LintCode 158. Valid Anagram

```
class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
    	if(s.empty() || t.empty())
    	{
    		return false;
    	}

    	if(s.size() != t.size())
    	{
    		return false;
    	}

    	int count[256] = {0};
    	for(int i = 0; i < s.size(); ++i)
    	{
    		++count[s[i]];
            // 不要写成 --count[s[i]];
    		--count[t[i]];
    	}

    	for(int i = 0; i < s.size(); ++i)
    	{
    		if(count[s[i]] != 0)
    		{
    			return false;
    		}
    	}

    	return true;
    }
};
```

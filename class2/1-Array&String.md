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

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
```


LeetCode 387. First Unique Character in a String
```
class Solution {
public:
    int firstUniqChar(string s) {
        int count[256] = {0};

        for(int i = 0; i != s.size(); ++i)
        {
            ++count[s[i]];
        }

        for(int i = 0; i != s.size(); ++i)
        {
            // 不要写成 if(count[s[i]])
            if(count[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
```

```
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};

        for(int i = 0; i != s.size(); ++i)
        {
            ++count[s[i] - 'a'];
        }

        for(int i = 0; i != s.size(); ++i)
        {
            // 不要写成 if(count[s[i] - 'a'])
            if(count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
```

Determine if all characters of a string are unique.
* 一般来说，一旦出现“unique”，就落入使用hash table或者bitset来判断元素出现与否的范畴。
```
#include <iostream>      
#include <bitset>        

using namespace std;

bool isUnique(string &s)
{
	bitset<256> hashMap;

	for (int i = 0; i != s.size(); ++i)
	{
		if(hashMap[s[i]])
		{
			return false;
		}

		hashMap[s[i]] = 1;
	}

	return true;
}

int main()
{
	string s = "leetcode";
	bool flag = isUnique(s);
	cout << flag << endl;

	s = "code";
	flag = isUnique(s);
	cout << flag << endl;

	return 0;
}
```

Determine if all characters of a string are unique.
* 一般来说，一旦出现“unique”，就落入使用hash table或者bitset来判断元素出现与否的范畴。
```
#include <iostream>      
#include <bitset>        

using namespace std;

bool isUnique(string &s)
{
	bitset<256> hashMap;

	for (int i = 0; i < s.size(); ++i)
	{
		if (hashMap[s[i]])
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

>Given a newspaper and message as two strings, check if the messagecan be composed using letters in the newspaper.  
解题分析：message中⽤用到的字符必须出现在newspaper中。其次，message中  
任意字符出现的次数⼀一定少于其在newspaper中出现的次数。统计⼀一个元素集中  
元素出现的次数，我们就应该想到hash table  
复杂度分析：假设message长度为m ，newspaper长度为n，我们的算法需要  
hash整条message和整个newspaper，故时间复杂度O(m+n)。假设字符集⼤大⼩小  
为c，则平均空间是O(c)
```
#include <iostream>      
#include <unordered_map>    

using namespace std;

bool canCompose(string &s, string &t)
{
	// 不要写成 if (s.size() != t.size())
	if (s.size() < t.size())
	{
		return false;
	}

	unordered_map<char, int> hashMap;

	for (int i = 0; i != s.size(); ++i)
	{
		++hashMap[s[i]];
	}

	for (int i = 0; i != t.size(); ++i)
	{
		if (hashMap.count(t[i]) == 0)
		{
			return false;
		}

		--hashMap[t[i]];

		if (hashMap[t[i]] < 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string s = "leetcode";
	string t = "codeleet";
	bool flag = canCompose(s, t);
	cout << flag << endl;

	s = "leetcode";
	t = "lintcode";
	flag = canCompose(s, t);
	cout << flag << endl;

	return 0;
}
```

>Anagram  
Write a method anagram(s,t) to decide if two strings are anagrams or not.  
Example  
Given s="abcd", t="dcab", return true.  
Challenge  
O(n) time, O(1) extra space

模式识别  
当处理当前节点需要依赖于之前的部分结果时，可以考虑使用hash table  
记录之前的处理结果。其本质类似于Dynamic Programming，利用hash  
table以O(1)的时间复杂度获得之前的结果。

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

英文链接: https://leetcode.com/problems/substring-with-concatenation-of-all-words/  
中文链接: https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/


>不额外插入字符，找出串联列表中所有单词的子串的起始位置   
每个单词的长度相同


>借助两个哈希表   
m1记录所有单词出现的次数   
每次找出给定单词长度的子串，看其是否在m1里   
如果不存在，立即break   
如果有，则加入m2，如果该单词在m2中出现次数更多，也break   
如果正好匹配完words里所有的单词，则i存入result

>一定要注意两个点   
i<=(int)s.size()-m*n中的==号不要遗漏，s.size()要类型转换   
int j=0;放在循环外，否则得到的结果为空


```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int len = s.size();
        int m = words.size();

        if(len == 0 || m == 0)
            return result;

        unordered_map<string, int> m1;
        for(auto &tmp : words)
            ++m1[tmp];

        int n = words[0].size();

        for(int i = 0; i <= len - m * n; ++i)
        {
            unordered_map<string, int> m2;
            int j = 0;

            for(j = 0; j < m; ++j)
            {
                string tmp = s.substr(i + j * n, n);
                if(m1.find(tmp) == m1.end())
                    break;
                ++m2[tmp];
                if(m2[tmp] > m1[tmp])
                    break;
            }

            if(j == m)
                result.push_back(i);
        }

        return result;
    }
};
```

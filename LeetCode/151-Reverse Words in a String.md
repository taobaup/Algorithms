
英文链接: https://leetcode.com/problems/reverse-words-in-a-string/  
中文链接: https://leetcode-cn.com/problems/reverse-words-in-a-string/

>字符串反转   
尝试在 O (1) 空间中就地解决它  
先将整个字符串翻转一次，再分别翻转每一个单词   
或者先分别翻转每一个单词，然后再整个字符串翻转一次

```
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        int index = 0;

        reverse(s.begin(), s.end());

        for(int i = 0; i < len; ++i)
        {
            if(s[i] != ' ')
            {
                if(index != 0)
                    s[index++] = ' ';

                int j = i;
                while(j < len && s[j] != ' ')
                    s[index++] = s[j++];

                reverse(s.begin() + index - (j - i), s.begin() + index);

                i = j;
            }
        }

        s.resize(index);
    }
};
```

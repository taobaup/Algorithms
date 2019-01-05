英文链接: https://leetcode.com/problems/length-of-last-word/  
中文链接: https://leetcode-cn.com/problems/length-of-last-word/


```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;

        while(right >= 0 && s[right] == ' ')
            --right;

        int res = 0;
        // 不要把 s[right] != ' ' 写成 s[right] != ''
        while(right >= 0 && s[right] != ' ')
        {
            // 不要遗漏 --right; 否则 Run Code Status: Time Limit Exceeded
            --right;
            ++res;
        }

        return res;
    }
};
```

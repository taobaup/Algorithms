英文链接: https://leetcode.com/problems/longest-valid-parentheses/  
中文链接: https://leetcode-cn.com/problems/longest-valid-parentheses/


>求最长的有效括号序列长度  
使用栈，遇到左括号就进栈，遇到右括号则出栈

>主要问题在于右括号的的判断   
1: 如果栈为空，说明加上当前右括号没有合法序列   
2: 否则弹出栈顶元素

>弹出后   
如果栈为空，则说明当前括号匹配，长度为i-start+1；   
如果栈非空，则长度为i-(m.top()+1)+1   
因为m.top()+1之后的括号对肯定是已经匹配成功了

>只需要一遍扫描，所以时间复杂度是O(n)   
空间复杂度是栈的空间，最坏情况是都是左括号，所以是O(n)


```
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int start = 0;

        stack<int> m;

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                m.push(i);
            else if(s[i] == ')')
            {
                if(m.empty())
                    start = i + 1;
                else
                {
                    m.pop();
                    if(m.empty())
                        res = max(res, i - start + 1);
                    else
                        // res = max(res, i - (m.top() + 1) + 1);
                        res = max(res, i - m.top());
                }
            }
        }

        return res;
    }
};
```

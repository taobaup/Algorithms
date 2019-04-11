英文链接: https://leetcode.com/problems/string-to-integer-atoi/  
中文链接: https://leetcode-cn.com/problems/string-to-integer-atoi/

INT_MIN: -2147483648  
INT_MAX: +2147483647

```
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        if (str.empty())
        {
            return res;
        }

        int i = 0;
        int n = str.size();
        int sign = 1;

        while (i < n && str[i] == ' ')
        {
            ++i;
        }

        if (i < n && (str[i] == '+' || str[i] == '-'))
        {
            sign = (str[i++] == '+') ? 1 : -1;
        }

        while (i < n && str[i] >= '0' && str[i] <= '9')
        {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = 10 * res + (str[i++] - '0');
        }

        return sign * res;
    }
};
```

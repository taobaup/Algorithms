英文链接: https://leetcode.com/problems/zigzag-conversion/  
中文链接: https://leetcode-cn.com/problems/zigzag-conversion/


```
比如有一个字符串 “0123456789ABCDEF”，转为zigzag

当 n = 2 时：

0  2  4  6  8  A  C  E

1  3  5  7  9  B  D  F

当 n = 3 时：

0     4     8     C

1  3  5  7  9  B  D  F

2     6     A     E

当 n = 4 时：

0       6       C

1    5  7    B  D

2  4    8  A    E

3       9       F
```



```
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) 
            return s;

        string res = "";
        int size = 2 * numRows - 2;

        for (int i = 0; i < numRows; ++i) 
        {
            for (int j = i; j < s.size(); j += size) 
            {
                res += s[j];
                int tmp = j + size - 2 * i;

                if (i != 0 && i != numRows - 1 && tmp < s.size()) 
                    res += s[tmp];
            }
        }

        return res;
    }
};
```

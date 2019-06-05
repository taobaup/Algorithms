
英文链接: https://leetcode.com/problems/plus-one/  
中文链接: https://leetcode-cn.com/problems/plus-one/


```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;

        for(auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            *it += plus;
            plus = *it / 10;
            *it %= 10;
        }

        if(plus > 0)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
```

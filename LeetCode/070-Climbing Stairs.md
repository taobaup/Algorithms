
英文链接: https://leetcode.com/problems/climbing-stairs/  
中文链接: https://leetcode-cn.com/problems/climbing-stairs/

```
class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        int cur = 1;

        for(int i = 1; i <= n; ++i)
        {
        	int temp = cur;
        	cur += prev;
        	prev = temp;
        }

        return cur;
    }
};
```

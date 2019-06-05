英文链接: https://leetcode.com/problems/count-and-say/  
中文链接: https://leetcode-cn.com/problems/count-and-say/

>对于前一个数，找出相同元素的个数，把个数和该元素存到新的string里，第一个数为1   
注意一定不要把cur += to_string(cnt) + res[i];写成cur = to_string(cnt) + res[i];


```
class Solution {
public:
    string countAndSay(int n) {
        if(n < 0)
            return "";

        string res = "1";
        for(int k = 2; k <= n; ++k)
        {
            string cur = "";
            for(int i = 0; i < res.size(); ++i)
            {
                int cnt = 1;

                while(i + 1 < res.size() && res[i] == res[i + 1])
                {
                    ++cnt;
                    ++i;
                }

                cur += to_string(cnt) + res[i];
            }

            res = cur;
        }

        return res;
    }
};
```

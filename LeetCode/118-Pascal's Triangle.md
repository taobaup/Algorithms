英文链接: https://leetcode.com/problems/pascals-triangle/  
中文链接: https://leetcode-cn.com/problems/pascals-triangle/


第一个元素和最后一个元素赋值为 1   
中间的每个元素，等于上一行的左上角和右上角元素之和

```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        if (numRows <= 0) 
        {
            return res;
        }

        for (int i = 0; i < numRows; ++i) 
        {
            vector<int> out;
            out.push_back(1);

            if (i == 0) 
            {
                // 不要遗漏这一步
                res.push_back(out);
                continue;
            }

            for (int j = 1; j < i; ++j) 
            {
                out.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }

            out.push_back(1);
            res.push_back(out);
        }
    
        return res;
    }
};
```

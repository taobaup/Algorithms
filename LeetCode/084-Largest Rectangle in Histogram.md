
英文链接: https://leetcode.com/problems/largest-rectangle-in-histogram/  
中文链接: https://leetcode-cn.com/problems/largest-rectangle-in-histogram/


在直方图中找到最大矩形的区域
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;

        int len = heights.size();
        for(int i = 0; i < len; ++i)
        {
            // heights[i] <= heights[i + 1], 不要写成 heights[i] == heights[i + 1]
            if(i + 1 < len && heights[i] <= heights[i + 1])
                continue;

            int minH = heights[i];
            for(int j = i; j >= 0; --j)
            {
                //  heights[j] 不要写成 heights[i]
                //  i - j + 1 不要写成 j - i + 1
                minH = min(minH, heights[j]);

                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }   

        return res;   
    }
};
```

>借助栈保存递增序列，找出局部最大值   
若当前值小于栈顶值时，取出栈顶元素，计算当前矩形面积   
继续比较当前值和新的栈顶值，若还是栈顶值大，则再取出栈顶元素，计算新的矩形面积   
依次类推，得到最大矩形

```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;

        heights.push_back(0);

        for(int i = 0; i < heights.size(); ++i)
        {
            while(!s.empty() && heights[i] <= heights[s.top()])
            {
                int cur = s.top();
                s.pop();

                if(s.empty())
                    res = max(res, heights[cur] * i);
                else
                    res = max(res, heights[cur] * (i - s.top() - 1));
            }

            s.push(i);
        }

        return res;
    }
};
```

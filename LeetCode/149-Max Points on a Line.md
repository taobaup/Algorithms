
英文链接: https://leetcode.com/problems/max-points-on-a-line/  
中文链接: https://leetcode-cn.com/problems/max-points-on-a-line/


>计算几何，给定一个点集合，求最大的共线点的个数

>找出相同点和相同斜率的点  
通过斜率来判断共线需要用到除法   
用double表示的双精度小数在有的系统里不一定准确   
为了精确无误的计算，应当避免除法，避免无限不循环小数的出现   
可将两数分别除以它们的最大公约数，pair作为key   
gcd采用算法导论中的欧几里德算法  
注意两个max函数要放在外层循环，不要忘记return res;

```
// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
```


```
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;

        for(int i = 0; i < points.size(); ++i)
        {
            int duplicate = 1;
            map<pair<int, int>, int> m;
            for(int j = i + 1; j < points.size(); ++j)
            {
                if(points[j].y == points[i].y && points[j].x == points[i].x)
                {
                    ++duplicate;
                }
                else
                {
                    int dy = points[j].y - points[i].y;
                    int dx = points[j].x - points[i].x;
                    int d = gcd(dx, dy);
                    ++m[{dx/d, dy/d}];
                }
            }

            res = max(res, duplicate);
            for(auto it = m.begin(); it != m.end(); ++it)
            {
                res = max(res, it->second + duplicate);
            }
        }

        return res;
    }

private:
    int gcd(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
};
```

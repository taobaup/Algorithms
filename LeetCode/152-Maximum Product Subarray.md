

英文链接: https://leetcode.com/problems/maximum-product-subarray/  
中文链接: https://leetcode-cn.com/problems/maximum-product-subarray/


>f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )  
g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )



```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int len = nums.size();
        if (len == 0) 
            return 0;
        
        int res = nums[0], mn = nums[0], mx = nums[0];
        for (int i = 1; i < len; ++i) 
        {
            int tmax = mx, tmin = mn;
            mx = max(max(nums[i], tmax * nums[i]), tmin * nums[i]);
            mn = min(min(nums[i], tmax * nums[i]), tmin * nums[i]);
            res = max(res, mx);
        }
        
        return res;
    }
};
```

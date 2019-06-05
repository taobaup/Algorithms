
英文链接: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/  
中文链接: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/


```
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        const int len = nums.size();
        int left = 0;
        int right = len - 1;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else if (nums[mid] == nums[right])
            {
                --right;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};
```

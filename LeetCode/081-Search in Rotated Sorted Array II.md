
英文链接: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/  
中文链接: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int len = nums.size();
        if(len <= 0)
        	return 0;

        int left = 0;
        int right = len - 1;
        while(left <= right)
        {
        	int mid = left + ((right - left) >> 1);
        	if(target == nums[mid])
        		return 1;

        	if(nums[left] < nums[mid])
        	{
        		if(nums[left] <= target && target < nums[mid])
        			right = mid - 1;
        		else
        			left = mid + 1;
        	}
        	else if(nums[left] > nums[mid])
        	{
        		if(nums[mid] < target && target <= nums[right])
        			left = mid + 1;
        		else
        			right = mid - 1;
        	}
        	else
        		++left;
        }

        return 0;
    }
};
```

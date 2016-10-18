//Search in Rotated Sorted Array II
//数组中存在重复的数，则当nums[start]==nums[mid]
//无法确定数组的递增序列，需要进一步查找
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int size=nums.size();
        int start=0,end=size-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return true;
                
            if(nums[start]<nums[mid])
            {
                if(nums[start]<=target&&target<nums[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else if(nums[start]>nums[mid])
            {
                if(nums[mid]<target&&target<=nums[end])
                    start=mid+1;
                else
                    end=mid-1;
            }
            else
                ++start;
        }
        
        return false;
    }
};

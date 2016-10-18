//Search in Rotated Sorted Array
//数组中没有重复的数
//若nums[start]<=nums[mid]，则左半部分递增，先在左半部分搜索
//若搜索不到，则往右半部分搜索
//若nums[start]>nums[mid]，则右半部分递增，先在右半部分搜索
//若搜索不到，则往左半部分搜索
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int size=nums.size();
        int start=0,end=size-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
                
            if(nums[start]<=nums[mid])
            {
                if(nums[start]<=target&&target<nums[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else
            {
                if(nums[mid]<target&&target<=nums[end])
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        
        return -1;
    }
};

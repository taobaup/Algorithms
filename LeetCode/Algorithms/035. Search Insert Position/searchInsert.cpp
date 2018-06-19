class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <= 0)
        	return 0;

        int left = 0;
        int right = len - 1;
        while(left <= right)
        {
        	int mid = left + ((right - left) >> 1);
        	if(target > nums[mid])
        		left = mid + 1;
        	else
        		right = mid - 1;
        }

        return left;
    }
};

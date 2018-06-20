1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result;
    	result.push_back(-1);
    	result.push_back(-1);

        int len = nums.size();
        if(len <= 0)
        	return result;

        int l = searchFirstEqual(nums, target);
        if(l < 0 || l > nums.size())
        	return result;

        int r = l;
        while(r < nums.size() - 1 && nums[r + 1] == nums[l])
        	++r;

        if(l < 0 || l > nums.size() || r < l)
        	return result;

        result[0] = l;
        result[1] = r;
        return result;
    }

    int searchFirstEqual(vector<int>& nums, int target) {
    	int left = 0;
    	int right = nums.size() - 1;

    	while(left <= right)
    	{
    		int mid = left + ((right - left) >> 1);
    		if(target > nums[mid])
    			left = mid + 1;
    		else
    			right = mid - 1;
    	}

    	if(left >= 0 && left <= nums.size() - 1 && nums[left] == target)
    		return left;

    	return -1;
    }
};

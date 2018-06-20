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

        if(l < 0 || l > nums.size())
        	return result;
        
        if(r < l)
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




2）
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

       	int r = searchLastEqual(nums, l, target);
        if(r < 0 || r > nums.size())
        	return result;
        
        // 不要写漏或者写反
        if(r < l)
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

    int searchLastEqual(vector<int>& nums, int l, int target) {
    	int left = l;
    	int right = nums.size() - 1;

    	while(left <= right)
    	{
    		int mid = left + ((right - left) >> 1);
    		if(target < nums[mid])
    			right = mid - 1;
    		else
    			left = mid + 1;
    	}

    	if(right >= l && right <= nums.size() - 1 && nums[right] == target)
    		return right;

    	return -1;
    }
};

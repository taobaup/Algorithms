class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> res;
        permute(nums, 0, res);

        return res;
    }

    bool findRepeat(vector<int> &nums, int start, int end)
    {
    	bool find = false;
    	for(int i = start; i < end; ++i)
    	{
    		if(nums[i] == nums[end])
    		{
    			find = true;
    			break;
    		}
    	}

    	return find;
    }

    //  vector<vector<int>>& res, not vector<vector<int>> res
    void permute(vector<int> &nums, int start, vector<vector<int>>& res)
    {
    	if(start >= nums.size())
    	{
    		res.push_back(nums);
    	}

    	for(int i = start; i < nums.size(); ++i)
    	{
    		if(findRepeat(nums, start, i))
    			continue;

    		swap(nums[i], nums[start]);
    		permute(nums, start + 1, res);
    		swap(nums[i], nums[start]);
    	}
    }
};

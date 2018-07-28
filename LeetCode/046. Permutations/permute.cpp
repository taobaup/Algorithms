class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> res;
        permute(nums, 0, res);

        return res;
    }

    void permute(vector<int>& nums, int start, vector<vector<int>>& res)
    {
    	if(start >= nums.size())
    	{
    		res.push_back(nums);
    	}

    	for(int i = start; i < nums.size(); ++i)
    	{
    		swap(nums[i], nums[start]);
    		permute(nums, start + 1, res);
    		swap(nums[i], nums[start]);
    	}
    }
};

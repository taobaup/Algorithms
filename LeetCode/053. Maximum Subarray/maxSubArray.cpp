class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0)
        	return 0;

        int local = nums[0];
        int global = nums[0];

        for(int i = 1; i < len; ++i)
        {
        	local = max(local + nums[i], nums[i]);
        	global = max(global, local);
        }
        
        return global;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();

        int last = 0;
        int cur = 0;
        int step = 0;
        for(int i = 0; i < len; ++i)
        {
        	if(i > last)
        	{
        		last = cur;
        		++step;
        	}

        	cur = max(cur, i + nums[i]);
        }

        return step;
    }
};

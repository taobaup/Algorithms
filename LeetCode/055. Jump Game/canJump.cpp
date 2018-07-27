class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();

        int reach = 0;
        for(int i = 0; i < len; ++i)
        {
        	if(reach < i || reach >= len - 1)
        		break;

        	reach = max(reach, i + nums[i]);
        }

        return reach >= len - 1;
    }
};

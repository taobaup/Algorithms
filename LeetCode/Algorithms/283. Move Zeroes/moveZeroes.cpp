class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int len = nums.size();
    	if(len <= 1)
    		return;

    	int index = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                swap(nums[index], nums[i]);
                ++index;
            }
        }

        return;
    }
};

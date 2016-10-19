//Remove Element
//遍历数组，判断是否等于val即可
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]!=val)
            {
                nums[index]=nums[i];
                ++index;
            }
        }
        
        return index;
    }
};

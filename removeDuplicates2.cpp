//Remove Duplicates from Sorted Array II
//若数组长度<=2，则返回值为数组长度
//若数组非空，从0~size-1遍历数组，依次与相邻元素比较即可
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int size=nums.size();
        if(size<=2)
            return size;
            
        int index=0;
        for(int i=0;i<size;++i)
        {
            if(i>0 && i<size-1 && nums[i]==nums[i-1] && nums[i]==nums[i+1])
                continue;
        
            nums[index]=nums[i];
            ++index;
        }
        
        return index;
    }
};

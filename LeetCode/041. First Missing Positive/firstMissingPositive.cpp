1:  not constant extra space

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxNum = 0;

        unordered_set<int> s;

        for(auto num : nums)
        {
        	if(num <= 0)
        		continue;

        	s.insert(num);
        	maxNum = max(maxNum, num);
        }

        for(int i = 1; i <= maxNum; ++i)
        {
        	if(s.count(i) == 0)
        		return i;
        }

        return maxNum + 1;
    }
};




2:
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
        	while(nums[i] >= 1 && nums[i] <= len && nums[i] != nums[nums[i] - 1])
        	{
        		swap(nums[i], nums[nums[i] - 1]);
        	}
        }

        for(int i = 0; i < len; ++i)
        {
        	if(nums[i] != i + 1)
        		return i + 1;
        }

        return len + 1;
    }
};

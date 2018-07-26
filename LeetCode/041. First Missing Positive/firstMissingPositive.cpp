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

英文链接: https://leetcode.com/problems/single-number-ii/  
中文链接: https://leetcode-cn.com/problems/single-number-ii/

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
        {
        	return 0;
        }

        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
        	int sum = 0;
        	for(int j = 0; j < nums.size(); ++j)
        	{
                // nums[j], not nums[i]
        		sum += (nums[j] >> i) & 1;
        	}

        	res |= (sum % 3) << i;
        }

        return res;
    }
};
```

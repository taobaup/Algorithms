英文链接: https://leetcode.com/problems/single-number/  
中文链接: https://leetcode-cn.com/problems/single-number/

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	if(nums.empty())
    	{
    		return 0;
    	}

    	int res = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		res ^= nums[i];
    	}

    	return res;
    }
};
```

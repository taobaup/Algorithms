英文链接: https://leetcode.com/problems/single-number-iii/  
中文链接: https://leetcode-cn.com/problems/single-number-iii/

```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	int flag = 0;
    	for(auto &t : nums)
    	{
    		flag ^= t;
    	}

        flag &= (-flag);

        vector<int> res(2, 0);
        for(auto &t : nums)
        {
            if (t & flag)
            {
                res[0] ^= t;
            }
            else
            {
                res[1] ^= t;
            }
        }

    	return res;
    }
};
```

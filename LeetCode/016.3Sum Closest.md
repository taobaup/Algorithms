英文链接: https://leetcode.com/problems/3sum-closest/  
中文链接: https://leetcode-cn.com/problems/3sum-closest/


```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int len = nums.size();
    	if(len < 3)
    		return 0;

    	sort(nums.begin(), nums.end());
    	int result = nums[0] + nums[1] + nums[2];
    	int minDiff = abs(target - result);

    	for(int i = 0; i < len - 2; ++i)
    	{
    		int j = i + 1;
    		int k = len - 1;

    		while(j < k)
    		{
    			int sum = nums[i] + nums[j] + nums[k];
    			// 不要写成 targe - result
    			int newDiff = abs(target - sum);

    			if(newDiff < minDiff)
    			{
    				result = sum;
    				minDiff = newDiff;
    			}

    			if(sum < target)
    				++j;
    			else
    				--k;
    		}
    	}

    	return result;
    }
};
```

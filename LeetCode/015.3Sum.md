1）
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if(len < 3)
        	return result;

        // 一定不要遗漏先排序
        sort(nums.begin(), nums.end());
        // 到小于 len - 2 的范围即可
        for(int i = 0; i < len - 2; ++i)
        {
        	if(nums[i] > 0)
        		break;
        	// 是 continue 而不是 ++i;
        	if(i > 0 && nums[i] == nums[i - 1])
        		continue;

        	const int target = 0 - nums[i];
        	int j = i + 1;
        	int k = len - 1;
        	while(j < k)
        	{
        		if(nums[j] + nums[k] == target)
        		{
        			// 插入值而非下标
        			result.push_back({nums[i], nums[j], nums[k]});
        			++j;
        			--k;

        			// 去重，不要写错下标
        			while(j < k && nums[j] == nums[j - 1])
        				++j;
        			while(j < k && nums[k] == nums[k + 1])
        				--k;
        		}
        		else if(nums[j] + nums[k] < target)
        		{
        			++j;
        			while(j < k && nums[j] == nums[j - 1])
        				++j;
        		}
        		else
        		{
        			--k;
        			while(j < k && nums[k] == nums[k + 1])
        				--k;
        		}
        	}
        }

        return result;
    }
};




2）
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        int len = nums.size();
        if(len < 3)
        	return vector<vector<int>>();

        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; ++i)
        {
        	if(nums[i] > 0)
        		break;
        	if(i > 0 && nums[i] == nums[i - 1])
        		continue;

        	const int target = 0 - nums[i];
        	int j = i + 1;
        	int k = len - 1;
        	while(j < k)
        	{
        		if(nums[j] + nums[k] == target)
        		{
        			result.insert({nums[i], nums[j], nums[k]});
        			++j;
        			--k;
        		}
        		else if(nums[j] + nums[k] < target)
        			++j;
        		else
        			--k;
        	}
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};

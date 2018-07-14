1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
    	int len = nums.size();
    	if(len < 4)
    		return result;

    	sort(nums.begin(), nums.end());

    	for(int a = 0; a < len - 3; ++a)
    	{
    		for(int b = a + 1; b < len - 2; ++b)
    		{
    			int c = b + 1;
    			int d = len - 1;

    			while(c < d)
    			{
    				if(nums[a] + nums[b] + nums[c] + nums[d] == target)
    				{
    					result.push_back({nums[a], nums[b], nums[c], nums[d]});
    					++c;
    					--d;
    				}
    				else if(nums[a] + nums[b] + nums[c] + nums[d] < target)
    				{
    					++c;
    				}
    				else
    				{
    					--d;
    				}
    			}
    		}
    	}

    	sort(result.begin(), result.end());
    	result.erase(unique(result.begin(), result.end()), result.end());

    	return result;
    }
};




2)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> result;
        int len = nums.size();
        if(len < 4)
        	return result;

        unordered_multimap<int, pair<int, int>> cache;
        for(int i = 0; i < len - 1; ++i)
        {
        	for(int j = i + 1; j < len; ++j)
        	{
        		cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
        	}
        }


        for(auto i = cache.begin(); i != cache.end(); ++i)
        {
        	int gap = target - i->first;
        	auto tag = cache.equal_range(gap);
        	for(auto j = tag.first; j != tag.second; ++j)
        	{
        		int a = i->second.first;
        		int b = i->second.second;
        		int c = j->second.first;
        		int d = j->second.second;
                
                if(a != c && a != d && b != c && b != d)
        	    {
        		    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
        		    sort(vec.begin(), vec.end());
        		    result.push_back(vec);
        	    }
        	}	
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};

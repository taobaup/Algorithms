
英文链接: https://leetcode.com/problems/longest-consecutive-sequence/  
中文链接: https://leetcode-cn.com/problems/longest-consecutive-sequence/


>在O(n)的时间复杂度内找出数组中最长连续序列的长度   
如数组[100,15,200,17,120,16,18]，其最长连续序列为4   
时间复杂度要求O(n)，因此不能直接排序   
可借助哈希表，以空间换时间   
在哈希表中查找每个元素的左右相邻数

```
class Solution {
public:
    	int longestConsecutive(vector<int>& nums) {
        	int longest = 0;
        	unordered_map<int,bool> map;
        	for(auto i : nums)
        	{
            		map[i] = false;
        	}

        	for(auto i : nums)
        	{
            		if(map[i])
            		{
                		continue;
            		}

            		int length = 1;
            		map[i] = true;
            
            		for(int j = i - 1; map.find(j) != map.end(); --j)
            		{
                		map[j] = true;
                		++length;
            		}
            
            		for(int j = i + 1; map.find(j) != map.end(); ++j)
            		{
                		map[j] = true;
                		++length;
            		}

            		longest = max(longest, length);
        	}

        	return longest;
    	}
};
```



```
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int res = 0;
		unordered_set<int> s(nums.begin(), nums.end());

		for (int val : nums) 
		{
			if (!s.count(val)) 
			{
				continue;
			}
			
			s.erase(val);
			int pre = val - 1, next = val + 1;

			while (s.count(pre)) 
			{
				s.erase(pre--);
			}

			while (s.count(next)) 
			{
				s.erase(next++);
			}

			int len = next - pre - 1;
			res = max(res, len);
		}
		
		return res;
	}
};
```

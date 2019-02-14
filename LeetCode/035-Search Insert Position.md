英文链接: https://leetcode.com/problems/search-insert-position/  
中文链接: https://leetcode-cn.com/problems/search-insert-position/

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] >= target) 
                return i;
        }

        return nums.size();
    }
};
```

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <= 0)
        	return 0;

        if(target == nums[len - 1])
        	return len - 1;
        else if(target > nums[len - 1])
        	return len;

        // i < len 而不是 len -1
        for(int i = 0; i < len; ++i)
        {
        	// 注意不要把条件写反
        	if(nums[i] >= target)
        		return i;
        }

        // 注意不要写成 return -1;
        return len;
    }
};
```



```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int len = nums.size();

    	if(len <= 0)
    		return 0;

    	if(target <= nums[0])
    		return 0;
    	else if(target == nums[len - 1])
    		return len - 1;
    	else if(target > nums[len - 1])
    		return len;

    	int left = 0;
    	int right = len - 1;
    	while(left <= right)
    	{
    		int mid = left + ((right - left) >> 1);
    		if(target == nums[mid])
    			return mid;
    		else if(target > nums[mid])
    			left = mid + 1;
    		else
    			right = mid - 1;
    	}

    	return left;
    }
};
```

```
// 重新实现 lower_bound
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }

    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound (ForwardIterator first,
            ForwardIterator last, T value) {
        while (first != last) 
        {
            auto mid = next(first, distance(first, last) / 2);
            if (value > *mid)
                first = ++mid;
            else
                last = mid;
        }

        return first;
    }
};
```

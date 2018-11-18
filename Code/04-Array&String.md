LintCode 8. Rotate String
>Rotate String
Given a string and an offset, rotate string by offset. (rotate from left toright)   
Example   
Given "abcdefg"   
for offset=0, return "abcdefg"   
for offset=1, return "gabcdef"
```
class Solution {
public:
	/**
	* @param str: An array of char
	* @param offset: An integer
	* @return: nothing
	*/
	void rotateString(string &str, int offset) {
		if (str.empty())
		{
			return;
		}

		int len = str.size();

		offset %= len;
		reverse(str, 0, len - offset - 1);
		reverse(str, len - offset, len - 1);
		reverse(str, 0, len - 1);
	}

private:
	void reverse(string &str, int start, int end)
	{
		while (start < end)
		{
			swap(str[start], str[end]);
			++start;
			--end;
		}
	}
};
```

LeetCode 796. Rotate String
```
class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.empty() && B.empty())
		{
			return true;
		}

		if (A.size() != B.size())
		{
			return false;
		}

		int len = A.size();
		for (int i = 0; i < len; ++i)
		{
			if (A.substr(i, len - i) + A.substr(0, i) == B)
			{
				return true;
			}
		}

		return false;
	}
};
```
```
class Solution {
public:
	bool rotateString(string A, string B) {
		return A.size() == B.size() && (A + A).find(B) != string::npos;
	}
};
```

LeetCode 27. Remove Element

遍历数组, 将不等于val的值放回原数组   
注意此前已经++index;所以最后return index;即可, 不需要return index + 1; 

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int index = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != val)
			{
				nums[index] = nums[i];
				++index;
			}
		}

		return index;
	}
};
```


每找到一个等于val的元素, 将数组末尾的数移到该位置   
这样可以保证如果没有重复就没有写操作 
```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[len - 1];
				--len;
				--i;
			}
		}

		return len;
	}
};
```


借助STL也可以AC, 但不推荐

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;

		return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};
```

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{
			if (*it == val)
			{
				it = nums.erase(it);
				--it;
			}
		}

		return nums.size();
	}
};
```

LeetCode 88. Merge Sorted Array
>Merge Sorted Array
>1. Merge Two Sorted Array into a new Array
>2. Merge Two Sorted Array A and B into A, assume A has enough space.

```
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m < 0 || n < 0)
		{
			return;
		}

		int len = m + n;
		int *total = new int[len];

		int i = 0, j = 0, k = 0;
		while (i < m && j < n)
		{
			if (nums1[i] <= nums2[j])
			{
				total[k++] = nums1[i++];
			}
			else
			{
				total[k++] = nums2[j++];
			}
		}

		while (i < m)
		{
			total[k++] = nums1[i++];
		}
		while (j < n)
		{
			total[k++] = nums2[j++];
		}

		for (int p = 0; p < len; ++p)
		{
			nums1[p] = total[p];
		}

		return;
	}
};
```

```
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m < 0 || n < 0)
		{
			return;
		}

		int k = m + n - 1;
		--m;
		--n;

		while (m >= 0 && n >= 0)
		{
			if (nums1[m] > nums2[n])
			{
				nums1[k--] = nums1[m--];
			}	
			else
			{
				nums1[k--] = nums2[n--];
			}		
		}

		while (n >= 0)
		{
			nums1[k--] = nums2[n--];
		}
			
		return;
	}
};
```

LintCode 31. Partition Array
>Partition
Given an array nums of integers and an int k, partition the array(i.e move the elements in "nums") such that:  
All elements < k are moved to the left  
All elements >= k are moved to the right  
Return the partitioning index, i.e the first index i nums[i] >= k.  
Example  
If nums=[3,2,2,1] and k=2, a valid answer is 1.  
If all elements in nums are smaller than k, then return nums.length  
Challenge  
Can you partition the array in-place and in O(n)?

```
class Solution {
public:
	/**
	* @param nums: The integer array you should partition
	* @param k: An integer
	* @return: The index after partition
	*/
	int partitionArray(vector<int> &nums, int k) {
		int right = 0;
		const int len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			if (nums[i] < k && i >= right)
			{
				swap(nums[i], nums[right]);
				++right;
			}
		}

		return right;
	}
};
```

```
class Solution {
public:
	/**
	* @param nums: The integer array you should partition
	* @param k: An integer
	* @return: The index after partition
	*/
	int partitionArray(vector<int> &nums, int k) {
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right)
		{
			while (left <= right && nums[left] < k)
			{
				++left;
			}

			while (left <= right && nums[right] >= k)
			{
				--right;
			}

			if (left < right)
			{
				swap(nums[left], nums[right]);
				++left;
				--right;
			}
		}

		// 一定不要遗漏 return left;
		return left;
	}
};
```


LintCode 80. Median
>Median  
Given a unsorted array with integers, find the median of it.  
A median is the middle number of the array after it is sorted.  
If there are even numbers in the array, return the N/2-th number after sorted.  
Example  
Given [4, 5, 1, 2, 3], return 3  
Given [7, 9, 4, 5], return 5
```
class Solution {
public:
    	/**
     	* @param nums: A list of integers
     	* @return: An integer denotes the middle number of the array
     	*/
    	int median(vector<int> &nums) {
        	if (nums.empty())
        	{
        		return 0;
        	}

        	int len = nums.size();
        	return helper(nums, 0, len - 1, (len + 1) / 2);
   	}

private:
	int helper(vector<int> &nums, int l, int r, int size)
	{
		if (l >= r)
		{
			return nums[r];
		}

		int m = l;
		for (int i = l + 1 ; i <= r; ++i)
		{
			if (nums[i] < nums[l])
			{
				++m;
				swap(nums[i], nums[m]);
			}
		}

		swap(nums[l], nums[m]);

		if (m - l + 1 == size)
		{
			return nums[m];
		}
		else if (m - l + 1 > size)
		{
			return helper(nums, l, m - 1, size);
		}
		else
		{
			return helper(nums, m + 1, r, size - (m - l + 1));
		}
	}
};
```

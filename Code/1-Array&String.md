Determine if all characters of a string are unique.
* 一般来说，一旦出现“unique”，就落入使用hash table或者bitset来判断元素出现与否的范畴。
```
#include <iostream>      
#include <bitset>        

using namespace std;

bool isUnique(string &s)
{
	bitset<256> hashMap;

	for (int i = 0; i < s.size(); ++i)
	{
		if (hashMap[s[i]])
		{
			return false;
		}

		hashMap[s[i]] = 1;
	}

	return true;
}

int main()
{
	string s = "leetcode";
	bool flag = isUnique(s);
	cout << flag << endl;

	s = "code";
	flag = isUnique(s);
	cout << flag << endl;

	return 0;
}
```

LeetCode 387. First Unique Character in a String
```
class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };

		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i]];
		}

		for (int i = 0; i < s.size(); ++i)
		{
			// 不要写成 if(count[s[i]])
			if (count[s[i]] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};
```

```
class Solution {
public:
	int firstUniqChar(string s) {
		int count[26] = { 0 };

		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i] - 'a'];
		}

		for (int i = 0; i < s.size(); ++i)
		{
			// 不要写成 if(count[s[i] - 'a'])
			if (count[s[i] - 'a'] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};
```

>Given a newspaper and message as two strings, check if the message can be composed using letters in the newspaper.  
解题分析：message中用到的字符必须出现在newspaper中。其次，message中任意字符出现的次数一定少于其在newspaper中出现的次数。统计一个元素集中元素出现的次数，我们就应该想到hash table  
复杂度分析：假设message长度为m ，newspaper长度为n，我们的算法需要hash整条message和整个newspaper，故时间复杂度O(m+n)。  
假设字符集大小为c，则平均空间是O(c)

```
#include <iostream>      
#include <unordered_map>    

using namespace std;

bool canCompose(string &s, string &t)
{
	// 不要写成 if (s.size() != t.size())
	if (s.size() < t.size())
	{
		return false;
	}

	unordered_map<char, int> hashMap;

	for (int i = 0; i < s.size(); ++i)
	{
		++hashMap[s[i]];
	}

	for (int i = 0; i < t.size(); ++i)
	{
		if (hashMap.count(t[i]) == 0)
		{
			return false;
		}

		--hashMap[t[i]];

		if (hashMap[t[i]] < 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string s = "leetcode";
	string t = "codeleet";
	bool flag = canCompose(s, t);
	cout << flag << endl;

	s = "leetcode";
	t = "lintcode";
	flag = canCompose(s, t);
	cout << flag << endl;

	return 0;
}
```

>Anagram  
Write a method anagram(s,t) to decide if two strings are anagrams or not.  
Example  
Given s="abcd", t="dcab", return true.  
Challenge  
O(n) time, O(1) extra space

模式识别  
当处理当前节点需要依赖于之前的部分结果时，可以考虑使用hash table记录之前的处理结果。  
其本质类似于Dynamic Programming，利用hash table以O(1)的时间复杂度获得之前的结果。

LintCode 158. Valid Anagram

```
class Solution {
public:
	/**
	* @param s: The first string
	* @param t: The second string
	* @return: true or false
	*/
	bool anagram(string &s, string &t) {
		if (s.empty() || t.empty())
		{
			return false;
		}

		if (s.size() != t.size())
		{
			return false;
		}

		int count[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i]];
			// 不要写成 --count[s[i]]; 
			--count[t[i]];
		}

		for (int i = 0; i < s.size(); ++i)
		{
			if (count[s[i]] != 0)
			{
				return false;
			}
		}

		return true;
	}
};
```


```
class Solution {
public:
	/**
	* @param s: The first string
	* @param t: The second string
	* @return: true or false
	*/
	bool anagram(string &s, string &t) {
		if (s.empty() || t.empty())
		{
			return false;
		}

		if (s.size() != t.size())
		{
			return false;
		}

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}
};
```

LeetCode 128. Longest Consecutive Sequence
>Get the length of the longest consecutive elements sequence in an array  
For example, given [31, 6, 32, 1, 3, 2],the longest consecutive elements sequence is [1, 2, 3].   
Return its length: 3.  
判断array[i] – 1，array[i] + 1是否存在于数组中。如何保存之前的处理结果？可以使用hash table 由于序列是一系列连续整数，所以只要序列的最小值以及最
大值，就能唯一确定序列。而所谓的“作为后继加入序列”，“作为前驱加入序列”，更新最大最小值。hash table的value可以是一个记录最大／最小值的
structure，⽤用以描述当前节点参与构成的最长序列。  
时间复杂度O(n)，附加空间O(n)


```
struct Bound
{
	int high;
	int low;

	Bound(int h = 0, int l = 0)
	{
		high = h;
		low = l;
	}
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, Bound> hashMap;

        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (hashMap.count(nums[i]))
        	{
        		continue;
        	}

        	int local = nums[i];

        	int low = local, high = local;
        	if (hashMap.count(local - 1))
        	{
        		low = hashMap[local - 1].low;
        	}
        	if (hashMap.count(local + 1))
        	{
        		high = hashMap[local + 1].high;
        	}

        	hashMap[local].low = low;
        	hashMap[local].high = high;

        	hashMap[low].high = high;
        	hashMap[high].low = low;

        	if (high - low + 1 > maxLen)
        	{
        		maxLen = high - low + 1;
        	}
        }

        return maxLen;
    }
};
```

LintCode 79. Longest Common Substring
>Longest Common Substring  
Given two strings, find the longest common substring.  
Return the length of it.  
Example  
Given A="ABCD", B="CBCE", return 2.  
Note  
The characters in substring should occur continuously in original string.  
This is different with subsequence.

```
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
    	if (A.empty() || B.empty())
    	{
    		return 0;
    	}

    	int lcs = 0, lcs_temp = 0;
    	for (int i = 0; i < A.size(); ++i)
    	{
    		for (int j = 0; j < B.size(); ++j)
    		{
    			lcs_temp = 0;
    			while (i + lcs_temp < A.size()
    				&& j + lcs_temp < B.size()
    				&& A[i + lcs_temp] == B[j + lcs_temp])
    			{
    				++lcs_temp;
    			}

    			if (lcs_temp > lcs)
    			{
    				lcs = lcs_temp;
    			}
    		}
    	}

    	return lcs;
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
		while (i < m && j <n)
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


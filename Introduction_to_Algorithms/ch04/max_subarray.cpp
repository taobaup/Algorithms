1) 暴力解法
#include <iostream>
#include <vector>

using namespace std;

void maxSubArray(vector<int> &nums)
{
	int len = nums.size();
	if (len <= 0)
		return;

	int max = INT_MIN;
	for (int i = 0; i < len; ++i)
	{
		int sum = 0;
		for (int j = i; j < len; ++j)
		{
			sum += nums[j];
			if (sum > max)
				max = sum;
		}
	}

	cout << max << endl;

	return;
}

int main()
{
	vector<int> nums = { 1, -2, 3, 10, -4, 7, 2, -5 };
	maxSubArray(nums);

	return 0;
}




2) 分治
#include <iostream>
#include <vector>

using namespace std;

int find_max_crossing_subarray(vector<int> &nums, int left, int mid, int right)
{
	int left_sum = INT_MIN;
	int sum = 0;
	
	for (int i = mid; i >= left; --i)
	{
		sum += nums[i];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}

	int right_sum = INT_MIN;
	sum = 0;
	for (int j = mid + 1; j <= right; ++j)
	{
		sum += nums[j];
		if (sum > right_sum)
		{
			right_sum = sum;
		}
	}

	return left_sum + right_sum;
}

int find_maximum_subarray(vector<int> &nums, int left, int right)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int cross_sum = INT_MIN;

	if (left == right)
		return nums[left];
	else
	{
		int mid = left + (right - left) / 2;
		left_sum = find_maximum_subarray(nums, left, mid);
		right_sum = find_maximum_subarray(nums, mid + 1, right);
		cross_sum = find_max_crossing_subarray(nums, left, mid, right);

		if (left_sum >= cross_sum)
			return left_sum;
		else if (right_sum >= cross_sum)
			return right_sum;
		else
			return cross_sum;
	}
}

int main()
{
	vector<int> nums = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = nums.size();
	if (len <= 0)
		return 0;
	else
	{
		int res = find_maximum_subarray(nums, 0, len - 1);
		cout << res << endl;
	}

	return 0;
}




3) 区间法
#include <iostream>
#include <vector>

using namespace std;

int find_maximum_subarray(vector<int> &nums)
{
	int len = nums.size();
	if (len <= 0)
		return 0;

	int max = INT_MIN;
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		sum += nums[i];
		if (sum > max)
		{
			max = sum;
		}
		
		if (sum < 0)
			sum = 0;
	}
	
	return max;
}

int main()
{
	vector<int> nums = { 1, -2, 3, 10, -4, 7, 2, -5 };
	
	int res = find_maximum_subarray(nums);
	cout << res << endl;

	return 0;
}



4) 动态规划
#include <iostream>
#include <vector>

using namespace std;

int find_maximum_subarray(vector<int> &nums)
{
	int len = nums.size();
	if (len <= 0)
		return 0;

	int max = INT_MIN;
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		// 不要写成 nums[i] >= 0
		if (sum >= 0)
			sum += nums[i];
		else
			sum = nums[i];

		if (sum > max)
			max = sum;
	}
	
	return max;
}

int main()
{
	vector<int> nums = { 1, -2, 3, 10, -4, 7, 2, -5 };
	
	int res = find_maximum_subarray(nums);
	cout << res << endl;

	return 0;
}

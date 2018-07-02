1)
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

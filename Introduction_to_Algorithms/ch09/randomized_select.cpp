#include <iostream>
#include <ctime>

using namespace std;

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;

	for (int j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);

	return i + 1;
}

int ranged_rand(int range_min, int range_max)
{
	// Generate random numbers in the half-closed interval
	// [range_min, range_max). In other words,
	// range_min <= random number < range_max

	// rand 函数返回一个伪随机整数在范围 0 到 RAND_MAX (32767)
	int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;

	return u;
}


int randomized_partition(int A[], int p, int r)
{
	srand((unsigned)time(NULL));

	int i = ranged_rand(p, r + 1);
	swap(A[r], A[i]);

	return partition(A, p, r);
}

int randomized_select(int A[], int p, int r, int i)
{
	if (p == r)
	{
		return A[p];
	}

	int q = randomized_partition(A, p, r);
	int k = q - p + 1;

	if (i == k)
	{
		return A[q];
	}
	else if (i < k)
	{
		return randomized_select(A, p, q - 1, i);
	}
	else
		return randomized_select(A, q + 1, r, i - k);
}

int main()
{
	int A[] = { 100,0,-10,80,200 };
	int len = sizeof(A) / sizeof(A[0]);

	for (int i = 1; i <= len; ++i)
	{
		int res = randomized_select(A, 0, len - 1, i);
		cout << res << endl;
	}

	return 0;
}

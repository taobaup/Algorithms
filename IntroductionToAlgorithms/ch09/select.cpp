#include <iostream>
#include <cassert>

using namespace std;

int select(int A[], int p, int r, int k);

int insert_sort(int A[], int len)
{
	for (int j = 1; j < len; ++j)
	{
		int key = A[j];
		// insert A[j] into the sorted sequence A[0..j-1]
		int i = j - 1;
		// 注意是 i >= 0 而不是 i > 0
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			--i;
		}

		A[i + 1] = key;
	}

	return A[len / 2];
}

int find_median(int A[], int p, int r)
{
	int len = r - p + 1;

	int *temp = new int[len / 5 + 1];

	int start = p;
	int end = p;
	int j = 0;

	for (int i = 0; i < len; ++i)
	{
		if (i % 5 == 0)
			start = start + i;

		if ((i + 1) % 5 == 0 || i == len - 1)
		{
			end = end + i;
			int small_median = insert_sort(A, end - start + 1);

			temp[j] = small_median;
			++j;
		}
	}

	int total_median = select(temp, 0, j - 1, (j - 1) / 2);

	delete[] temp;

	return total_median;
}

int partition(int A[], int p, int r, int num)
{
	for (int i = p; i <= r; i++)
	{
		if (A[i] == num)
		{
			swap(A[i], A[r]);
			break;
		}
	}

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

int select(int A[], int p, int r, int k)
{
	assert(p <= r);
	assert(k <= r - p + 1);

	if (p == r)
		return A[p];

	int num = find_median(A, p, r);
	int mid = partition(A, p, r, num);

	int count = mid - p + 1;
	if (k == count)
		return A[mid];
	else if (k < count)
		return select(A, p, mid - 1, k);
	else
		return select(A, mid + 1, r, k - count);
}

int main()
{
	int A[] = { 7,4,6,9,2,1,5,8,3,0,12,23,78 };
	int len = sizeof(A) / sizeof(A[0]);

	for (int i = 1; i <= len; ++i)
	{
		int res = select(A, 0, len - 1, i);
		cout << i << ":" << res << endl;
	}

	return 0;
}

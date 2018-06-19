#include <iostream>

using namespace std;

// 找出第一个与value相等的元素
int firstEqual(int A[], int left, int right, int value)
{
	int originleft = left, originright = right;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value > A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}

	if (A[left] == value && left >= originleft && right <= originright)
		return left;

	return -1;
}

// 查找第一个大于value的元素
int firstBigger(int A[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value >= A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}

// 查找第一个等于或者大于value的元素
int firstEqualOrBigger(int A[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value > A[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}

// 找出最后一个与value相等的元素
int lastEqual(int A[], int left, int right, int value)
{
	int originleft = left, originright = right;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value < A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (A[right] == value && left >= originleft && right <= originright)
		return right;

	return -1;
}

// 查找最后一个小于value的元素
int lastSmaller(int A[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value <= A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right;
}

// 查找最后一个等于或者小于value的元素
int lastEqualOrSmaller(int A[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value < A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right;
}

int main()
{
	int A[] = {
		1, 2, 5, 5, 5,
		5, 5, 5, 5, 5,
		5, 5, 6, 6, 10 };
	int n = sizeof(A) / sizeof(A[0]);

	int result = firstEqual(A, 0, n - 1, 0);
	cout << result << endl;
	result = firstBigger(A, 0, n - 1, 5);
	cout << result << endl;
	result = firstEqualOrBigger(A, 0, n - 1, 5);
	cout << result << endl;

	result = lastEqual(A, 0, n - 1, 12);
	cout << result << endl;
	result = lastSmaller(A, 0, n - 1, 5);
	cout << result << endl;
	result = lastEqualOrSmaller(A, 0, n - 1, 5);
	cout << result << endl;

	return 0;
}

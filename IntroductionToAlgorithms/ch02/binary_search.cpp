// 特别注意对于迭代版，mid的计算不能写在while循环外，否则无法得到更新

#include <iostream>

using namespace std;

// 迭代版
int binary_search_iterative(int A[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (value < A[mid])
			right = mid - 1;
		else if (value > A[mid])
			left = mid + 1;
		else
			return mid;
	}

	return -1;
}

// 递归版
int binary_search_recursive(int A[], int left, int right, int value)
{
	if (left > right)
		return -1;

	int mid = left + ((right - left) >> 1);
	if (value < A[mid])
		return binary_search_recursive(A, 0, mid - 1, value);
	else if (value > A[mid])
		return binary_search_recursive(A, mid + 1, right, value);
	else
		return mid;
}

int main()
{
	int A[] = { 1, 4, 10, 25, 800, 5000 };
	int n = sizeof(A) / sizeof(A[0]);

	int expected = 1;
	int res = binary_search_iterative(A, 0, n - 1, 4);
	// int res = binary_search_recursive(A, 0, n - 1, 4);
	if (expected == res)
		cout << "true" << endl;
	else
		cout << "error" << endl;

	return 0;
}

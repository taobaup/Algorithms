#include <iostream>

using namespace std;

int merge(int A[], int left, int mid, int right)
{
	int count = 0;

	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = A[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = A[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			A[k++] = L[i++];
		}
		else
		{
			A[k++] = R[j++];
			// 一定不能遗漏这一行，左边子序列的数大于右子序列，则逆序对数为 n1 - i;
			count += n1 - i;
		}
			
	}

	while (i < n1)
		A[k++] = L[i++];
	while (j < n2)
		A[k++] = R[j++];

	delete L;
	L = NULL;

	delete R;
	R = NULL;

	return count;
}

int merge_sort(int A[], int left, int right)
{
	int count = 0;
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		count += merge_sort(A, left, mid);
		count += merge_sort(A, mid + 1, right);
		count += merge(A, left, mid, right);
	}

	return count;
}

int main()
{
	int A[] = { 1, 2, 3, 4, 7, 6, 5 };
	int expected = 3;

	int len = sizeof(A) / sizeof(A[0]);
	if (len <= 1)
	{
		cout << "len <=1" << endl;
		return 0;
	}

	int count = merge_sort(A, 0, len - 1);
	if (expected == count)
		cout << "true" << endl;
	else
		cout << "error" << endl;

	return 0;
}

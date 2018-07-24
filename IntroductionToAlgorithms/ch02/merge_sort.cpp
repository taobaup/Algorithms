1）
#include <iostream>

using namespace std;

void mergeWithSentry(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];

	for (int i = 0; i < n1; ++i)
		L[i] = A[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = A[mid + 1 + j];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0, j = 0;

	int k = left;
	while (k <= right)
	{
		if (L[i] <= R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}

	delete L;
	L = NULL;

	delete R;
	R = NULL;
}

void mergeWithoutSentry(int A[], int left, int mid, int right)
{
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
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}

	while (i < n1)
		A[k++] = L[i++];
	while (j < n2)
		A[k++] = R[j++];

	delete L;
	L = NULL;

	delete R;
	R = NULL;
}

void merge_sort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);
		// mergeWithSentry(A, left, mid, right);
		mergeWithoutSentry(A, left, mid, right);
	}
}

int main()
{
	int A[] = { 3, -1, 200, 0 };
	int n = sizeof(A) / sizeof(A[0]);
	merge_sort(A, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;

	return 0;
}




2）
#include <iostream>

using namespace std;

void merge(int A[], int left, int mid, int right, int temp[])
{
	int i = left, j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	while(i <= mid)
		temp[k++] = A[i++];
	while (j <= right)
		temp[k++] = A[j++];

	// 注意 i <= right 不要写成 i < right
	for (int i = left; i <= right; ++i)
		A[i] = temp[i];
}


void merge_sort(int A[], int left, int right, int temp[])
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(A, left, mid, temp);
		merge_sort(A, mid + 1, right, temp);
		merge(A, left, mid, right, temp);
	}
}

int main()
{
	int A[] = { -20,0,800,-3,2000,50 };
	int n = sizeof(A) / sizeof(A[0]);
	int *B = new int[n];

	merge_sort(A, 0, n - 1, B);
	delete B;
	B = NULL;

	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;

	return 0;
}

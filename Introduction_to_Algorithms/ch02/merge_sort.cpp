#include <iostream>

using namespace std;

void mergeWithSentry(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *ALeft = new int[n1 + 1];
	int *ARight = new int[n2 + 1];

	for (int i = 0; i < n1; ++i)
		ALeft[i] = A[left + i];
	for (int j = 0; j < n2; ++j)
		ARight[j] = A[mid + 1 + j];

	ALeft[n1] = INT_MAX;
	ARight[n2] = INT_MAX;

	int i = 0, j = 0;

	int k = left;
	while (k <= right)
	{
		if (ALeft[i] <= ARight[j])
			A[k++] = ALeft[i++];
		else
			A[k++] = ARight[j++];
	}

	delete ALeft;
	ALeft = NULL;

	delete ARight;
	ALeft = NULL;
}

void mergeWithoutSentry(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int *ALeft = new int[n1];
	int *ARight = new int[n2];

	for (int i = 0; i < n1; ++i)
		ALeft[i] = A[left + i];
	for (int j = 0; j < n2; ++j)
		ARight[j] = A[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (ALeft[i] <= ARight[j])
			A[k++] = ALeft[i++];
		else
			A[k++] = ARight[j++];
	}

	while (i < n1)
		A[k++] = ALeft[i++];
	while (j < n2)
		A[k++] = ARight[j++];

	delete ALeft;
	ALeft = NULL;

	delete ARight;
	ALeft = NULL;
}

void merge_sort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);
		//mergeWithSentry(A, left, mid, right);
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

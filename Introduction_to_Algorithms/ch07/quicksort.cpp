#include <iostream>
#include <vector>

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

void quicksort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

int main()
{
	int A[] = { 1000,-30,100,0,-2,200 };
	int n = sizeof(A) / sizeof(A[0]);
	quicksort(A, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;

	return 0;
}

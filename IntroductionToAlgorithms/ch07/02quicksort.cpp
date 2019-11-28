#include <iostream>

using namespace std;

void quicksort(int A[], int low, int high)
{
	int i = low;
	int j = high;

	int temp = A[low];

	while(i < j)
	{
		while(i < j && A[j] >= temp)
			--j;
		if(i < j)
		{
			A[i] = A[j];
			++i;
		}

		while(i < j && A[i] < temp)
			++i;
		if(i < j)
		{
			A[j] = A[i];
			--j;
		}
	}

	A[i] = temp;
	if(low < i)
		quicksort(A, low, i - 1);
	if(i < high)
		quicksort(A, i + 1, high);
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

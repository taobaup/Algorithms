#include <iostream>

using namespace std;

void select_sort(int A[], int len)
{
	if(A == NULL || len <= 1)
		return;

	for(int i = 0; i < len - 1; ++i)
	{
		int min = i;
		for(int j = i + 1; j < len; ++j)
		{
			if(A[j] < A[min])
			{
				min = j;
			}
		}

		if(min != i)
			swap(A[min], A[i]);
	}

	return;
}

int main()
{
	int A[] = {-3, -4 ,2 ,0, 1000};
	int len = sizeof(A) / sizeof(A[0]);

	select_sort(A, len);
	
	for(int i = 0; i < len; ++i)
		cout << A[i] << endl;

	return 0;
}

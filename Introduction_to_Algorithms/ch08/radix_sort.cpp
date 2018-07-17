#include <iostream>

using namespace std;

#define len 7

void radix_sort(int A[], int B[], int d)
{
	int *C = new int[10];

	int radix = 1;
	for (int k = 1; k <= d; ++k)
	{
		for (int i = 0; i < 10; ++i)
			C[i] = 0;

		for (int i = 0; i < len; ++i)
		{
			int temp = (A[i] / radix) % 10;
			++C[temp];
		}

		for (int i = 1; i < 10; ++i)
			C[i] = C[i] + C[i - 1];

		for (int i = len - 1; i >= 0; --i)
		{
			int temp = (A[i] / radix) % 10;
			B[C[temp] - 1] = A[i];
			--C[temp];
		}

		radix *= 10;
		memcpy(A, B, len * sizeof(int));
	}
}

int main() 
{
	int A[len] = { 329,457,657,839,436,720,355 };
	int B[len];

	radix_sort(A, B, 3);

	for (int i = 0; i < len; i++)
		cout << A[i] << "\t";
	cout << endl;

	return 0;
}

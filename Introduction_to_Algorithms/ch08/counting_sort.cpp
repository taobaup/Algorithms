#include <iostream>
using namespace std;

#define len 8

void counting_sort(int A[], int B[], int k)
{
	int *C = new int[k + 1];

	for (int i = 0; i <= k; ++i)
		C[i] = 0;

	for (int i = 0; i < len; ++i)
		++C[A[i]];

	for (int i = 1; i <= k; ++i)
		C[i] = C[i] + C[i - 1];

	for (int i = len - 1; i >= 0; --i)
	{
		B[C[A[i]] - 1] = A[i];
		--C[A[i]];
	}

	delete C;
}


int main() 
{
	int A[len] = { 2,5,3,0,2,3,0,3 };
	int B[len];

	counting_sort(A, B, 5);

	for (int i = 0; i < len; i++)
		cout << B[i] << "\t";
	cout << endl;

	return 0;
}

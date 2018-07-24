#include <iostream>

using namespace std;

int minimum(int A[], int len)
{
	int min = A[0];
	for (int i = 1; i < len; ++i)
	{
		if (A[i] < min)
			min = A[i];
	}

	return min;
}

int maximum(int A[], int len)
{
	int max = A[0];
	for (int i = 1; i < len; ++i)
	{
		if (A[i] > max)
			max = A[i];
	}

	return max;
}

int main()
{
	int A[] = { -1,100,0,-20,30 };
	int len = sizeof(A) / sizeof(A[0]);

	int min = minimum(A, len);
	cout << "min: " << min << endl;
	int max = maximum(A, len);
	cout << "max: " << max << endl;

	return 0;
}

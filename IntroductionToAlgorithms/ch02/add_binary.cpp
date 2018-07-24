#include <iostream>

using namespace std;

void reverseArray(int A[], int len)
{
	int i = 0;
	int j = len - 1;
	while (i < j)
	{
		swap(A[i], A[j]);
		++i;
		--j;
	}
}

void addBinary(int A[], int B[], int C[], int len)
{
	if (len == 0)
		return;

	reverseArray(A, len);
	reverseArray(B, len);

	int carry = 0;
	for (int i = 0; i < len; ++i)
	{
		const int sum = A[i] + B[i] + carry;
		C[i] = sum % 2;
		carry = sum / 2;
	}

	// 不要写成 C[len + 1] = carry;
	C[len] = carry;
	reverseArray(C, len + 1);
}

int main()
{
	int A[] = { 1,1,1 };
	int B[] = { 1,0,0 };
	int len = sizeof(A) / sizeof(A[0]);
	int *C = new int[len + 1];
	addBinary(A, B, C, len);
	for (int i = 0; i < len + 1; ++i)
		cout << C[i] << endl;

	return 0;
}

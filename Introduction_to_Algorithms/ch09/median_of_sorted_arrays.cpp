#include <iostream>
#include <cassert>

using namespace std;

int select_mid(int A[], int B[], int left, int right)
{
	assert(A != NULL);
	assert(B != NULL);

	int len = right - left + 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (mid == len - 1 && A[mid] <= B[0])
			return A[mid];
		else if (mid < len - 1)
		{
			if (B[len - mid - 1] < A[mid] && A[mid] <= B[len - mid])
				return A[mid];
			else if (A[mid] <= B[len - mid - 1])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	return -1;
}

void two_arr_mid(int A[], int B[], int len)
{
	assert(A != NULL);
	assert(B != NULL);

	int mid;
	if (select_mid(A, B, 0, len - 1) == -1)
		mid = select_mid(B, A, 0, len - 1);

	cout << mid << endl;
}

int main()
{
	int A[] = { 1,2,3,4,8,9,13 };
	int B[] = { 0,5,6,7,10,11,12 };


	two_arr_mid(A, B, 7);

	return 0;
}

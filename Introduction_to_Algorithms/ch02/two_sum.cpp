#include <iostream>
#include <algorithm>

using namespace std;

bool find(int A[], int len, int target)
{
	if (len <= 1)
		return false;
	
	int i = 0;
	int j = len - 1;
	// i < j 不要写成 i <= j
	while (i < j)
	{
		if (A[i] + A[j] == target)
			return true;
			
		else if (A[i] + A[j] < target)
			++i;
		else
			--j;
	}

	return false;
}

int main()
{
	int A[] = { 10, 0, 3, 4, 100, 5 };
	int len = sizeof(A) / sizeof(A[0]);
	sort(A, A + len);
	cout << find(A, len, 5) << endl;
	cout << find(A, len, 0) << endl;

	return 0;
}

#include <iostream>
#include <cassert>
#include <cmath>

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

int select(int A[], int p, int r, int k)
{
	assert(p <= r);
	assert(k <= r - p + 1);

	if (p == r)
		return A[p];

	int mid = partition(A, p, r);

	int count = mid - p + 1;
	if (k == count)
		return A[mid];
	else if (k < count)
		return select(A, p, mid - 1, k);
	else
		return select(A, mid + 1, r, k - count);
}

int* kth_select(int A[], int len, int k)
{
	assert(k <= len);

	int *dis = new int[len - 1];
	int *dis_cpy = new int[len - 1];
	int *res = new int[k];

	int nmid = select(A, 0, len - 1, len / 2);
	int imid = 0;
	int count = 0;

	for (int i = 0; i < len; ++i)
	{
		if (A[i] != nmid)
			dis[count++] = abs(A[i] - nmid);
		else
			imid = i;
	}

	memcpy(dis_cpy, dis, sizeof(int)*(len - 1));
	int nkmid = select(dis_cpy, 0, count - 1, k);

	delete dis_cpy;
	dis_cpy = NULL;

	int ik = 0;
	for (int i = 0; ik < k && i < count; ++i)
	{
		if (dis[i] <= nkmid)
		{
			if (i < imid)
				res[ik++] = nmid - dis[i];
			else
				res[ik++] = nmid + dis[i];
		}
	}

	delete dis;
	dis = NULL;

	return res;
}

int main()
{
	int A[] = { 10,100,0,30,50,-20,800 };
	int len = sizeof(A) / sizeof(A[0]);

	int *res = kth_select(A, len, 4);
	for (int i = 0; i < 4; ++i)
	{
		cout << res[i] << " ";
	}

	return 0;
}

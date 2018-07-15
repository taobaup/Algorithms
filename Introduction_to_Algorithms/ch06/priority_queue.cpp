#include <iostream>
#include <vector>

using namespace std;

int heap_size = 0;

// 父结点下标
int parent(int i)
{
	return (i - 1) / 2;
}

// 左孩子下标
int left(int i)
{
	return 2 * i + 1;
}

// 右孩子下标
int right(int i)
{
	return 2 * i + 2;
}

// max_heapify 通过让 A[i] 的值在最大堆中“逐级下降”，从而使得以下标 i 为根结点的子树重新遵循最大堆的性质
void max_heapify(int A[], int i)
{
	int l = left(i);
	int r = right(i);

	int largest = i;
	if (l < heap_size && A[l] > A[i])
		largest = l;

	if (r < heap_size && A[r] > A[largest])
		largest = r;

	if (largest != i)
	{
		swap(A[i], A[largest]);
		max_heapify(A, largest);
	}
}

void max_heapify_iterative(int A[], int i)
{
	bool flag = true;

	while (i < heap_size && flag)
	{
		int l = left(i);
		int r = right(i);

		int largest = i;
		if (l < heap_size && A[l] > A[i])
			largest = l;

		if (r < heap_size && A[r] > A[largest])
			largest = r;

		if (largest != i)
		{
			swap(A[i], A[largest]);
			i = largest;
		}
		else
			flag = false;
	}
}

// 建堆，用自底向上的方法利用过程 max_heapify 把一个大小为 len 的数组 A[0..len-1] 转换为最大堆
void build_max_heap(int A[], int len)
{
	heap_size = len;
	for (int i = (len - 1) / 2; i >= 0; --i)
	{
		max_heapify(A, i);
		// max_heapify_iterative(A, i);
	}
}

int heap_maximum(int A[])
{
	return A[0];
}

int heap_extract_max(int A[])
{
	if (heap_size < 1)
	{
		cout << "heap underflow" << endl;
		return -1;
	}

	int max = A[0];
	A[0] = A[heap_size - 1];
	--heap_size;
	max_heapify(A, 0);

	return max;
}

void heap_increase_key(int A[], int i, int key)
{
	if (key < A[i])
	{
		cout << "new key is smaller than current key" << endl;
		return;
	}

	A[i] = key;
	while (i > 0 && A[parent(i)] < A[i])
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}
}

void heap_increase_key_oneassign(int A[], int i, int key)
{
	if (key < A[i])
	{
		cout << "new key is smaller than current key" << endl;
		return;
	}

	while (i > 0 && A[parent(i)] < key)
	{
		swap(A[i], A[parent(i)]);
		i = parent(i);
	}

	A[i] = key;
}

void max_heap_insert(int A[], int key)
{
	++heap_size;
	A[heap_size - 1] = INT_MIN;
	heap_increase_key_oneassign(A, heap_size - 1, key);
}

void heap_delete(int A[], int i)
{
	swap(A[i], A[heap_size - 1]);
	--heap_size;
	max_heapify(A, 0);
}

void heap_delete_thevalue(int A[], int target)
{
	int tag = -1;
	for (int i = 0; i < heap_size; ++i)
	{
		if (A[i] == target)
		{
			tag = i;
			break;
		}
	}

	if (tag != -1)
		heap_delete(A, tag);
}

void print_heap(int A[])
{
	cout << "最大优先队列（堆）: ";
	for (int i = 0; i < heap_size; ++i)
		cout << A[i] << "\t";
	cout << endl;
}


int main()
{
	int A[100] = { 100, -3, 10, -1, 0, 1000, 200 };
	int len = 7;

	build_max_heap(A, len);
	print_heap(A);
	cout << "堆中具有最大键值的元素: ";
	cout << heap_maximum(A) << endl;
	cout << "去掉并返回堆中具有最大键值的元素: ";
	cout << heap_extract_max(A) << endl;
	print_heap(A);

	cout << "1: " << A[1] << endl;
	heap_increase_key(A, 1, 10000);
	print_heap(A);

	cout << "插入新的值: -300" << endl;
	max_heap_insert(A, -300);
	print_heap(A);

	cout << "删除第 1 位元素" << endl;
	heap_delete(A, 1);
	print_heap(A);

	cout << "删除元素 10 " << endl;
	heap_delete_thevalue(A, 10);
	print_heap(A);

	return 0;
}

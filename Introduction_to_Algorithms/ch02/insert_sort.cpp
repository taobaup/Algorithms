#include <iostream>

using namespace std;

void insert_sort_iterative(int A[], int len)
{
    if (A == NULL || len <= 1)
        return;

    for (int j = 1; j < len; ++j)
    {
        int key = A[j];
        // insert A[j] into the sorted sequence A[1..j-1]
        int i = j - 1;
        // 注意是 i >= 0 而不是 i > 0
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            --i;
        }

        A[i + 1] = key;
    }

    return;
}

void insert_sort(int A[], int len)
{
    if (len > 1)
    {
        int key = A[len - 1];
        int i = len - 2;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            --i;
        }

        A[i + 1] = key;
    }
}

void insert_sort_recursive(int A[], int len)
{
    if (len > 1)
    {
        insert_sort_recursive(A, len - 1);
        insert_sort(A, len);
    }
}

int main()
{
    int A[] = { 2, -1, 3 };
    int len = sizeof(A) / sizeof(A[0]);

    insert_sort_iterative(A, len);
    //insert_sort_recursive(A, len);

    for (int i = 0; i < len; ++i)
        cout << A[i] << endl;

    return 0;
}

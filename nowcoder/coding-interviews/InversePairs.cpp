数组中的逆序对





class Solution {
public:
    long long merge(vector<int> &A, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *L = new int[n1];
        int *R = new int[n2];

        for (int i = 0; i < n1; ++i)
            L[i] = A[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = A[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;

        long long count = 0;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                A[k++] = L[i++];
            }
            else
            {
                A[k++] = R[j++];
                // 很重要的一步
                count += n1 - i;
            }
        }

        while (i < n1)
            A[k++] = L[i++];
        while (j < n2)
            A[k++] = R[j++];

        delete L;
        L = NULL;

        delete R;
        R = NULL;

        return count;
    }

    long long merge_sort(vector<int> &A, int left, int right)
    {
        long long count = 0;
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            count += merge_sort(A, left, mid);
            count += merge_sort(A, mid + 1, right);
            count += merge(A, left, mid, right);
        }

        return count;
    }

    int InversePairs(vector<int> data) {
        int len = data.size();
        if(len <= 1)
            return 0;

        long long count = merge_sort(data, 0, len -1);
        return count % 1000000007;
    }
};

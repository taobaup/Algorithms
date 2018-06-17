[数组中的逆序对](https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)


class Solution {
public:
    long long mergeWithoutSentry(vector<int> &A, int left, int mid, int right)
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
                count += n1 - i;
                A[k++] = R[j++];
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
            // mergeWithSentry(A, left, mid, right);
            count += mergeWithoutSentry(A, left, mid, right);
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

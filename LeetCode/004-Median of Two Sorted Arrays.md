英文链接: https://leetcode.com/problems/median-of-two-sorted-arrays/  
中文链接: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/


```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int lenA = A.size();
        int lenB = B.size();
        int len = lenA + lenB;

        if(len & 0x1)
            return find(A, B, 0, lenA - 1, 0, lenB - 1, len / 2 + 1);
        else
            return (find(A, B, 0, lenA - 1, 0, lenB - 1, len / 2) +
                        find(A, B, 0, lenA - 1, 0, lenB - 1, len / 2 + 1)) / 2.0;
    }

private:
    int find (vector<int>& A, vector<int>& B, int i, int i2, int j, int j2, int k) 
    {
        int m = i2 - i + 1;
        int n = j2 - j + 1;
        if(m > n)
            return find(B, A, j, j2, i, i2, k);
        if(m == 0)
            return B[j + k - 1];
        if(k == 1)
            return min(A[i], B[j]);

        int posA = min(k / 2, m);
        int posB = k - posA;
        if(A[i + posA - 1] == B[j + posB - 1])
            return A[i + posA -1];
        else if(A[i + posA - 1] < B[j + posB - 1])
            return find(A, B, i + posA, i2, j, j + posB - 1, k - posA);
        else
            return find(A, B, i, i + posA - 1, j + posB, j2, k - posB);
    }
};
```

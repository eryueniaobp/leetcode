/**
 * O(log(m+n)) 
 */
class Solution {
public:
    double findKth(int A[], int m, int B[], int n, int k)
    {
        //m is equal or smaller than n
        if (m > n)
            return findKth(B, n, A, m, k);
        if (m == 0)
            return B[k-1];
        if (k <= 1)
            return min(A[0], B[0]);

        int pa = min(k / 2, m), pb = k - pa;
        if (A[pa-1] < B[pb-1])
        {
            return findKth(A + pa, m - pa, B, n, k - pa);
        }
        else if(A[pa-1] > B[pb-1])
        {
            return findKth(A, m, B + pb, n - pb, k - pb);
        } else
            return A[pa-1];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k = m + n;
        if (k & 0x1)
        {
            return findKth(A, m, B, n, k / 2 + 1);
        } else
        {
            return (findKth(A, m, B, n, k / 2) + findKth(A, m, B, n, k / 2 + 1)) / 2;
        }
    }
};


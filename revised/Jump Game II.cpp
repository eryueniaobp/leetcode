/**
 * O(n)
 */
class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last  ) {
                if(curr < i ){
                    return -1;
                }
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }
};


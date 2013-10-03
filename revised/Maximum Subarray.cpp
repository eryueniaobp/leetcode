/**
 * O(n) 扫描一遍搞定
 */
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxi = INT_MIN;
        int cur = 0 ; 
        int i = 0 ;
        while( i < n ) {
            cur = max(cur+A[i],A[i]);
            i++;
            if(cur > maxi){
                maxi = cur;
            }
        }
        return maxi;
    }
};



/**
 * O(n)
 */
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
            return false;
            
        int far = A[0];
        
        for(int i = 1; far < n-1 && i < n; i++){
            if (far >= i ) {
                far = max(far, A[i] + i );
            }else{
                return false;
            }
        }
        return far >= n-1;
    }
};



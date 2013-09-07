/**
 * O(n)
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        int i = 1 ;
        int l = 1 ;
        while(i<n){
            if(A[i] == A[i-1]) i++ ;
            else{
                A[l++] = A[i];
                i++ ;
            
            }
        }
        return l;
    }
};



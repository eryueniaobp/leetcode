/**
 * O(n) 每次要么前进一位，要么使某个数归位
 */
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0 ; 
        while(i<n){
            if(A[i] != i){
                while(A[i] < n &&A[i]>=0  && A[A[i]] != A[i]) {
                    swap(A[i],A[A[i]]);
                }
                i++;
            }else{
                i++;
            }
        }
        i = 1  ; 
        while(  i < n && A[i] ==  i) i++;
        if( i < n ) return i;
        return A[0] == n ? n + 1 : n ;
    }
};


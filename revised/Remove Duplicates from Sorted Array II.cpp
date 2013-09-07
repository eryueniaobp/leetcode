/**
 * 加标记，O(n) 
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        int i = 1 ;
        int l = 1 ;
        A[0] = A[0];
        int pre = 0 ; 
        while(i<n){
            if(A[i] == A[i-1]){
                if(pre!= 1){
                    A[l++] = A[i];
                }
                pre = 1 ;
                i++;
            }else{
                A[l++] = A[i];
                pre = 0 ;
                i++ ;
            }
        }
        return l;
    }
};


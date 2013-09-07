/**
 * O(m+n)
 */
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a = m-1,b = n-1;
        int i;
        for(i =  m+n-1;i >= 0 && a>=0 && b>= 0 ; i--){
            if(A[a] >= B[b]){
                A[i] = A[a];
                a--;
            }else{
                A[i] = B[b];
                b--;
            }
        }
        while(b>=0){
            A[i--] = B[b--];
        }
    }
};


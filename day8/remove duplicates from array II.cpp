class Solution {
       vector<int> B;
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        int i = 1 ;
        int l = 1 ;
        B.assign(n,0);
        A[0] = A[0];
        while(i<n){
            if(A[i] == A[i-1]){
                B[i] = 1;
                if(B[i-1] != 1){
                    A[l++] = A[i];
                }
                i++;
            }else{
                A[l++] = A[i];
                i++ ;
            }
        }
        return l;
    }
};


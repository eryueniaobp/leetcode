class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = INT_MIN;
        int cur = 0 ; 
        int i = 0 ;
        while( i < n ) {
            if( cur + A[i] > 0 ){
                if( cur <= 0 ) {
                    cur = A[i] ;
                }else{
                    cur += A[i];
                }
                i++ ;
            }else{
                cur = A[i] ;
                i++;    
            }
            if(cur > max){
                max = cur;
            }
        }
        return max;
    }
};


class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n <= 0 ) return 0 ;
        if( n < 2 ) return 1; 
        if( n == 2 ) return 2; 
        int n1 = 2 ; 
        int n2 = 1 ; 
        int sum = 0 ;
        for(int i = 3 ; i<= n ; i++ ){
            sum = n1 + n2 ;                
            n2 = n1;
            n1 = sum;
            
        }
        return sum;
    }
};



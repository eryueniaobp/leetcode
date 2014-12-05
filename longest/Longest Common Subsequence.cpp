class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int maxv ( int a , int b ) {
        return a > b ? a :b ; 
    }
    int longestCommonSubsequence(string A, string B) {
          int dp[100][100] = {0} ;
        
        
        int max = 0 ;
        
        for(int i = 1 ;i <=A.size() ; i ++ ) {
            
            for(int j = 1 ; j <= B.size() ; j++ ) {
                int add = 0 ;
                if (A[i-1] == B[j-1]) {
                    add = 1; 
                }
                
                dp[ i   ][j ] =   maxv ( 
                    ( ( dp[i][j-1] >  dp[i-1][j]) ?dp[i][j-1]:dp[i-1][j])  , 
                    dp[i-1][j-1] + add ) ; 
                
                
                if(dp[i ][j] > max ) {
                    max = dp[ i ][j ]; 
                    
                }
                
            }
            
        }
        return max;
    }
};



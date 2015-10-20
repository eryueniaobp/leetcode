class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int dp[1000][1000] = {0} ;
        int max = 0 ; 
        for(int i = 0 ;i <A.size() ; i ++ ) 
            for(int j = 0 ; j < B.size() ; j++ ) {
                if (A[i] == B[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1  ; 
                }else{
                    dp[i+1][j+1] = 0  ; 
                }
                
                if(dp[i+1][j+1] > max ) {
                    max = dp[i+1][j+1]; 
                }
            }
        return max;
    }
};

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int dp[2][1000] = {0} ;
        
        
        int max = 0 ;
        int d = 0 ; 
        for(int i = 0 ;i <A.size() ; i ++ ) {
            
            for(int j = 0 ; j < B.size() ; j++ ) {
                if (A[i] == B[j]) {
                    dp[d ^ 1 ][j+1] = dp[d][j] + 1  ; 
                }else{
                    dp[d ^ 1 ][j+1] = 0  ; 
                }
                
                if(dp[d ^ 1 ][j+1] > max ) {
                    max = dp[d^ 1 ][j+1]; 
                }
                
            }
            d = d^ 1; 
        }
        return max;
            
    }
};

// compress space. 
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int dp[2][1000] = {0} ;
        
        
        int max = 0 ;
        int d = 0 ; 
        for(int i = 0 ;i <A.size() ; i ++ ) {
            
            for(int j = 0 ; j < B.size() ; j++ ) {
                if (A[i] == B[j]) {
                    dp[d ^ 1 ][j+1] = dp[d][j] + 1  ; 
                }else{
                    dp[d ^ 1 ][j+1] = 0  ; 
                }
                
                if(dp[d ^ 1 ][j+1] > max ) {
                    max = dp[d^ 1 ][j+1]; 
                }
                
            }
            d = d^ 1; 
        }
        return max;
            
    }
};



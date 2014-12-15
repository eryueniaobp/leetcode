// http://lintcode.com/zh-cn/problem/backpack/ 
public class Solution {
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int max = Integer.MIN_VALUE;
    public int backPack(int m, int[] A) {
        // write your code here
        /*int [][]dp = new int[m+1][A.length+1] ;
        for(int i = 0 ; i <= m ; i++ )  dp[i][0] = 0 ; 
        for(int i = 0 ; i <= A.length ; i++) dp[0][i] = 0 ; */
        // dp[A[0]][1] = 1 ;  
        int [][]dp = new int[2][m+1] ; Arrays.fill(dp[0],0); Arrays.fill(dp[1],0) ;
        int p = 0 ; 
        
         for(int j = 1; j<=A.length ; j++) { 
             Arrays.fill(dp[p] , 0 ) ;
        for(int i  = 1 ; i <= m ;i++){
           
                if( i >= A[j-1] ) { // i size .
                    dp[p][i]  = Math.max ( dp[p^1][i] , dp [p^1][ i - A[j-1] ]   + A[j-1] )  ;  
                }else{
                    dp[p][i] = dp[p^1][i] ; 
                }
                 
            }
            p = p ^ 1; 
        }
        
        return dp[p^1][m] ; 
    }
    
}

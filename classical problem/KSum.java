// 类似背包问题的解法  伪多项式时间 
public class Solution {
    int sum = 0 ; 
    
    
	 public int  kSum(int A[], int N, int target) {
	        // write your code here
	        sum = 0 ;
	        int [][][]dp = new int[A.length+1][N+1][target+1];
	        for(int i = 0 ;i <= A.length ; i++) {
		        for(int j = 0 ; j <= N ;j ++ ) {
		            for(int k = 0 ; k <= target ; k++ ){
		            	
		                dp[i][j][k] = 0 ; 
		                if ( j == 0 && k == 0 ) {
		                    dp[i][j][k] = 1 ; 
		                }
		            }
		        }
	        }
	        
	       
	        for(int i = 1 ; i<=A.length ; i++ ) {
	        	if( A[i-1] <= target ) {
	        	
	        		for(int  j = i  ; j <= A.length ; j ++){
	        			dp[j][1][A[i-1]] = 1 ; //at least .
	        		}
	        		// for(int j = i + 1 ; j<A.length ; j++)
	        	}
	        	// System.out.printf("%d %d %d\n", i , A[i-1] ,sum );
	        }
	        
	        // 
	        for(int i = 1 ; i<=A.length ;i++){
	            for(int j = 1 ; j<= (i < N ? i: N) ; j++){
	                for(int k = 1 ; k <= target ; k++){
	                	
	                	
	                	dp[i][j][k] = 
	                	( k-A[i-1]>=0 ?dp[i-1][j-1][k-A[i-1] ] : 0)  +
	                	dp[i-1][j][k] ; 
	                	
	                	// dp[1][1][k] =   dp[0][0][0]  dp[2][1][k] ; ?? 
	                	
	                }
	            }
	        }
	        
	        return dp[A.length][N][target] ; 
	}
}

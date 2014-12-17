// http://lintcode.com/zh-cn/problem/maximum-subarray-iii/  
// solution from friend : @LDC 
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
        int size = nums.size() ; 
        if(size < k) return 0 ; 
        vector<vector<int>> dp(size+1 , vector<int>(k+1 , 0)) ;

        dp[1][1] =nums[0];
        
        for(int i = 2 ; i<=size ;i++){
            for(int j = 1; j<=min(i,k) ;j++){
                dp[i][j] = dp[i-1][j-1] + nums[i-1] ;
                int maxNum = nums[i-1] ;
                int total = nums[i-1] ;
                for(int m = i -1 ; m>=1 && m>=j ; m -- ){
                    total+= nums[m-1] ; 
                    maxNum = max(maxNum , total) ;
                    if(j ==1 ){
                        dp[i][j] = max(dp[i][j] , maxNum) ;
                    }else{
                        dp[i][j] = max(dp[i][j] , maxNum + dp[m-1][j-1] ) ;
                    }
                }
            }
        }
        int ret = dp[k][k] ; 
        for(int i = k +1 ;i<=size ; i++ ){
            ret = max(ret,dp[i][k]) ;
        }
        return ret;


    }
};

// another better solution . awesome!
class Solution {
public:
   /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        // write your code here
        int size = nums.size() ; 
        if(size < k) return 0 ; 
        vector<int> dp(k ,INT_MIN);
        vector<int> trans(k,INT_MIN);

        dp[0] = nums[0] ;
        trans[0] = nums[0] ; 
        for(int i = 1 ;i<size ; i++){
            for(int j = min(i,k-1) ;j>=0 ; j--){
                // Left: trans[j] 将nums[i] 加入进去
                // Right: trans[j] 将nums[i-1]加进去的全局最优并 nums[i-1]一定属于j+1最后一段
                // dp[j-1]已经是 i 下，分成 j 段的全局最优 .
                // nums[i] + dp[j-1] : 把nums[i] 单独作为最后一段 加进去 
                // nums[i] + trans[j] : 把nums[i] 作为最后一段的补充 加进去
                // trans[j]: best solution ,subject to nums[i] is included in the last subarray.
                trans[j] = nums[i] + max( j==0?0:dp[j-1] ,trans[j] ) ;
                dp[j] = max(dp[j],trans[j]) ; 
            }
        }
        return dp[k-1];

    }
};


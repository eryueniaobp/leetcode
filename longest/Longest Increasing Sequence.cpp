class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        int *dp = new int [nums.size()] ; 
        for(int i = 0 ; i < nums.size() ; i++ ) dp[i] = 1 ; 
        int max = 0 ;
        for(int i = 0 ; i < nums.size() ; i++ ){
            for(int j = i - 1 ; j >= 0 ; j-- ) {
                if( nums[i] >= nums[j] && dp[j] + 1 > dp [i] ) { 
                    dp[i] = dp[j]+ 1; 
                }
            }
            if(dp[i] > max ) { max = dp[i] ; }  
        }
        return max ; 
    }
};



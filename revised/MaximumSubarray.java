/** Given an array of integers, find two non-overlapping subarrays which have the largest sum.

The number in each subarray should be contiguous.

Return the largest sum.
*/
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    public int maxTwoSubArrays(ArrayList<Integer> nums) {
        int max =Integer.MIN_VALUE; 
        int []dp = new int[nums.size()]  ;
        int cur = 0 ; 
        for(int i = 0 ;i < nums.size() ; i++  ) {
            cur = Math.max(cur+ nums.get(i) , nums.get(i)) ; 
            if( cur > max ) {
                max = cur ;
            }
            dp[i] = max ; 
        }
        cur = 0 ; max = Integer.MIN_VALUE;
        for(int i = nums.size() -1 ; i>= 1 ; i -- ) {
            cur = Math.max(cur + nums.get(i) , nums.get(i) ) ; 
            if( cur + dp[i-1]  > max ){
                max = cur+ dp[i-1] ; 
            }
        }
        return max ;
    }
}




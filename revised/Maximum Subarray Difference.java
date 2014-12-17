// http://lintcode.com/zh-cn/problem/maximum-subarray-difference/
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    public int maxDiffSubArrays(ArrayList<Integer> nums) {
        // write your code
        int []lmax = new int[nums.size()];
        int []lmin = new int[nums.size()];
        int []rmax = new int[nums.size()];
        int []rmin = new int[nums.size()] ; 
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE; 
        int cmax = 0  , cmin = 0 ; 
        for( int  i =  0 ; i< nums.size() ; i++){
            cmax = Math.max( cmax+nums.get(i) , nums.get(i)) ; 
            cmin = Math.min(cmin + nums.get(i) , nums.get(i)) ;
            if(max < cmax) max = cmax ;
            if(min > cmin ) min = cmin ; 
            lmax[i] = max ; 
            lmin[i] = min ; 
        }
        cmax = cmin = 0 ; max = Integer.MIN_VALUE ; min = Integer.MAX_VALUE;
        for(int i = nums.size() -1 ; i>= 0 ; i--) {
            cmax = Math.max(cmax + nums.get(i) , nums.get(i))  ;
            cmin = Math.min(cmin + nums.get(i) , nums.get(i))  ; 
            if(max < cmax) max = cmax ;
            if(min > cmin ) min = cmin ;
            
            rmax[i] = max ;
            rmin[i] = min  ;
        }
        max = Integer.MIN_VALUE ; min = Integer.MAX_VALUE;
        
        for(int i = 1 ; i< nums.size() ; i++ ){
            int cur = Math.max(Math.abs(lmax[i-1] - rmin[i]) ,Math.abs(lmin[i-1] - rmax[i]) ) ; 
            if( cur > max) {
                max = cur; 
            }
        }
        return max ; 
    }
    
}




/**
Easy Subarray Sum 提交历史

23% 通过
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

样例
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
*/
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    public ArrayList<Integer> subarraySum(int[] nums) {
        // write your code here
        Map<Integer,Integer> sum2pos = new HashMap<Integer,Integer>() ;
        sum2pos.put(0 , -1 ) ; 
        int sum = 0 ;
        ArrayList<Integer> ret = new ArrayList<Integer>(2) ; 
        for(int i = 0 ;i<nums.length;i++){
            sum += nums[i] ; 
            if(sum2pos.containsKey(sum) ) {
                int prepos = sum2pos.get(sum); 
                ret.add( prepos +1 ) ;
                ret.add(  i ) ;
                break; 
            }else{
                sum2pos.put(sum , i ) ; 
            }
        }
        return ret; 
    }
}

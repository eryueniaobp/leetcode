public class Solution {
    /**
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        int prev = -1  , cnt = 0 ; 
        for(int i = 0 ;i < nums.size() ; i++){
            int cur = nums.get(i) ; 
            if(cnt == 0 ) {
                prev = cur ; cnt = 1; 
                continue; 
            }
            if( prev == cur) {
                cnt ++ ; 
            }else{
                cnt -- ;
            }
        }
        return prev; 
    }
}
/**
* Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.
*/
mport java.util.* ;
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: The majority number that occurs more than 1/3
     */
    public int majorityNumber(ArrayList<Integer> nums) {
        Triple triple = new Triple() ;
        for(Integer n : nums) {
            triple.push(n) ;
        }
        return triple.find(nums) ;

    }
    public static class Triple {
        int []nums = { Integer.MAX_VALUE , Integer.MAX_VALUE,Integer.MAX_VALUE } ;
        int []cnts = { 0 ,  0 , 0 }  ;
        public Triple(){

        }
        public void push(int num ){
            for(int i =  0 ; i< nums.length ; i++ ) {
                if( num == nums[i] ) {
                    cnts[i] ++ ;
                    return ;
                }
            }

            for(int i = 0 ; i< nums.length ; i++ ){
                if (cnts[i] == 0 ) {
                    cnts[i] = 1 ;
                    nums[i] = num ;
                    break ;
                }
            }

            for(int i = 0 ; i< nums.length ; i++ ){
                if(cnts[i] == 0) {
                    return ;
                }
            }
            // delete  . 
            for(int i = 0 ; i< nums.length ; i++ ){

                cnts[i] -= 1 ;
                if(cnts[i] == 0 ) {
                    nums[i] = Integer.MAX_VALUE;
                }

            }
        }
        public int count(ArrayList<Integer> line , int target) {
            int cnt = 0 ;
            for(Integer i :line) {
                if( i == target) cnt++ ;
            }
            return cnt ;
        }
        public int find(ArrayList<Integer> line){
            int ret = 0  ;
            int max = -1 ;
            for(int i = 0 ; i< nums.length ; i++ ){
                if (cnts[i] > 0  ) {
                    int cur = count(line , nums[i]) ;
                    if(cur > max) {
                        max = cur ;
                        ret = nums[i] ; 
                    }
                }
            }
            return ret;
        }
    }
    
}



/**
* Time Complexity : O(N) 
*/
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
* Time Complexity: O(N) 
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
/** 
Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array. Find it. 

O(n) time and O(k) extra space 
*/
import java.util.* ;
public class Solution {
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    public int majorityNumber(List<Integer> nums, int k) {
        int cnt = nums.size()/k ;
        Cache cache = new Cache(k) ;
        for(Integer i :nums) {
            cache.push(i) ;
        }
        return cache.find(nums) ;
    }
    public  static void main(String []args) {
        Solution sol = new Solution() ;
        System.out.println(sol.majorityNumber(Arrays.asList(7, 1, 7, 7, 61, 61, 61, 10, 10, 10, 61), 3));
        // 7,1,7,7,61,61,61,10,10,10,61
        // 7,7 , 61,61,10,10,10,61
        // 7 , 61 , 10 10 61
        // 10 61
    }

    public static class Cache {
        Map<Integer,Integer> cache =  null; 
        int size = 0 ;
        public Cache(int k ){
            this.size = k ;
            cache = new HashMap<Integer,Integer>(k) ;
        }
        public void push(int num) {
            if(cache.containsKey(num)) {
                cache.put(num , cache.get(num) + 1 ) ;
            }else{
                cache.put(num , 1 )  ;
            }
            if(cache.size() == size ) {
                Iterator<Map.Entry<Integer,Integer>>  iter = cache.entrySet().iterator() ;
                while(iter.hasNext()){
                    Map.Entry<Integer,Integer> entry = iter.next() ;
                    int k = entry.getKey() ;
                    int v = entry.getValue();
                    if(v - 1 == 0 ) {
                        iter.remove();
                    }else{
                        entry.setValue(v-1) ;
                    }
                }
            }
        }
        public int count(int cur , List<Integer> nums ) {
            int cnt = 0 ;
            for(Integer i : nums ) {
                if(cur == i ) {
                    cnt ++ ;
                }
            }
            return cnt ;
        }
        public int find(List<Integer> nums) {
            int max = -1 ;
            int val  = -1 ;
            Iterator<Map.Entry<Integer,Integer>>  iter = cache.entrySet().iterator() ;
            List<Integer> mvals = new ArrayList<Integer>() ;
            int i = 0 ;
            while(iter.hasNext()){
                Map.Entry<Integer,Integer> entry = iter.next() ;
                int k = entry.getKey() ;
                int v = entry.getValue();
                if(v >= max ) {
                    max = v ;
                    mvals.add(k)  ;
                }
            }
            if(mvals.size() == 1 ) { //Critical :  mvals.size maybe > 1 
                val = mvals.get(0)  ;
            }else{
                max = -1 ;
                for(Integer cur : mvals ) {
                    int cnt = count( cur, nums ) ;
                    if(cnt > max ) {
                        max  =cnt ;
                        val = cur ;
                    }
                }
            }

            return val ;
        }
    }
}




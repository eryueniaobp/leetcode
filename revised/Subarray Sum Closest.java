/**
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.
*/
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    public ArrayList<Integer> subarraySumClosest(int[] nums) {
        // write your code here
        // O(n^2) for for .
        Node []sums = new Node[nums.length+1];
        for(int i = 0 ;i < nums.length+1 ; i++ ) {
            sums[i] = new Node(); 
        }
        sums[0].set(0,nums[0]) ; 
        sums[nums.length].set(-1 , 0 ) ; 
        
        int []ret = new int[2] ; 
        
        
        int minv = Math.abs(nums[0] ) ; ret[0] = ret[1] = 0 ; 
        
        for(int i = 1 ; i< nums.length ;i ++){
            sums[i].set( i , sums[i-1].v + nums[i]) ;  
        } 
       //  System.out.println(sums.length) ; 
        Arrays.sort(sums , new NodeCmp()) ; 
        
        for(int i = 1 ; i< nums.length +1 ; i++ ){
            int diff = sums[i].v - sums[i-1].v ; 
            if( Math.abs(diff) < minv ) {
                minv = Math.abs(diff) ; 
                ret[0] = (sums[i].pos < sums[i-1].pos ? sums[i].pos : sums[i-1].pos ) + 1;
                ret[1] = sums[i].pos < sums[i-1].pos ? sums[i-1].pos : sums[i].pos ;  
                
            }
        }
        ArrayList<Integer> ral =new ArrayList<Integer>() ; 
        ral.add(ret[0]) ; ral.add(ret[1]) ; 
        return ral; 
    }
    public static class Node  {
        int pos ; 
        int v; 
        public void set(int pos,int v){
            this.pos = pos; 
            this.v = v; 
        }
    }
    public static class NodeCmp implements Comparator<Node> {
        
        public int compare(Node o1, Node o2) {
            return o1.v - o2.v ; 
        }
    }
}


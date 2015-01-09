/**
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination. 
注意
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
*/
public class Solution {
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
     List<List<Integer>> cs = null; 
     int []flag  = null; 
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        // write your code here
        cs = new ArrayList<List<Integer>> () ;
        if(num.length == 0 ) return cs; 
        Arrays.sort(num) ; 
        flag = new int[num.length]; Arrays.fill(flag, 0) ; 
        dfs(num,target, 0 ) ;  
        return cs; 
    }
    public void dfs(int []num , int target , int s ){
        if(target < 0 ) return ; 
        if(target == 0 ){
            List<Integer> row = new ArrayList<Integer>();
            for(int i = 0 ;i <num.length ; i++ ){
                if(flag[i] == 1 ) {
                    row.add(num[i]) ; 
                }
            }
            cs.add(row); 
            return ; 
        }
        for(int i = s ; i< num.length ; i++){
            if(i>s && num[i] == num[i-1] ) { // avoid duplicated combinations
                continue; 
            }
            flag[i] = 1 ; 
            dfs(num , target - num[i] , i + 1 ) ; 
            flag[i] = 0 ; 
        }
    }
    
}


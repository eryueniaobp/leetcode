/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
/**
Given an integer array with no duplicates. A max tree building on this array is defined as follow:

The root is the maximum number in the array
The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array. 

*/
// Recursive Solution will make stack-over-flow . not the expected solution .
public class Solution {
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    public TreeNode maxTree(int[] A) {
        return dfs(A , 0 , A.length) ; 
    }
    public TreeNode dfs(int[] A , int s, int e ) {
        if(s >= e) return null; 
        int pos = max(A , s ,e) ; 
        TreeNode root = new TreeNode(A[pos]) ; 
        root.left = dfs(A , s , pos) ; 
        root.right = dfs(A, pos+1 , e) ; 
        return root; 
    }
    public int max(int []A , int s , int e) {
        int ret = s ; 
        int max = Integer.MIN_VALUE; 
        for(int i = s ; i< e ; i++ ) {
            if(A[i]>max){
                ret = i ; 
                max = A[i]; 
            }
        }
        return ret; 
    }
}


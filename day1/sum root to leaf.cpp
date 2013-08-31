 /** Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int sumNumbers(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if(root==null) return 0;
        return  sumRec(root, 0) ;
    }
    
    private int sumRec(TreeNode root, int parentSum) {
        
        int x = parentSum*10 + root.val;
        
        int l=0, r=0;
        
        if(root.left!=null) {
            l = sumRec(root.left, x);
        }
        
        if(root.right!=null) {   
            r = sumRec(root.right, x);
        }
        
        if( l==0 && r==0) return x;
        else return l+r;
    }
}



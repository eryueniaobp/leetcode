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
public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode A, TreeNode B) {
        return dfs(root,A,B) ; 
    }
    public TreeNode dfs(TreeNode root , TreeNode A, TreeNode B){
        if(root == null ) return null; 
        
        if(root == A || root == B) {
            return root; 
        }
        TreeNode l = dfs(root.left , A, B) ;
        TreeNode r = dfs(root.right , A, B) ; 
        
        if(l != null && r!=null) return root ;  
        if(l == null) {
            return r ; 
        } 
        return l ; 
    }
}


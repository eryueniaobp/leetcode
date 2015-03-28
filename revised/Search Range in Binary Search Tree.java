//  http://lintcode.com/zh-cn/problem/search-range-in-binary-search-tree/ 
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
// Simple! just use in-order traverse iteratively
public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    public ArrayList<Integer> searchRange(TreeNode root, int k1, int k2) {
        ArrayList<Integer> ret =new ArrayList<Integer>() ;

        Stack<TreeNode> s = new Stack<TreeNode>() ; 
        TreeNode n = root ; 
        
        while(!s.isEmpty()||n!=null){
            while(n!=null){
                s.push(n); 
                n = n.left ; 
            }
            if(!s.isEmpty()) {
                n = s.pop(); 
                if(k1 <= n.val && n.val <= k2) {
                    ret.add(n.val) ; 
                }
                n = n.right; 
            }
        } 
        return ret; 
    }
}


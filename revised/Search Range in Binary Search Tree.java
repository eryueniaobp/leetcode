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
public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
     Stack<TreeNode> s = null; 
    public ArrayList<Integer> searchRange(TreeNode root, int k1, int k2) {
        s = new Stack<TreeNode>() ; 
        while(root!=null) {
            s.push(root) ; 
            root = root.left ; 
        }
        ArrayList<Integer> ret =new ArrayList<Integer>() ;
        while(hasNext()) {
            TreeNode node = next(); 
            if(node.val <=k2 && node.val >= k1 ){
                ret.add(node.val) ; 
            }
        }
        return ret ; 
        
    }
    public boolean hasNext() {
        return !s.isEmpty(); 
    }
    public TreeNode next() {
        TreeNode n = s.pop() ; 
        TreeNode n1 = n.right; 
        while(n1!=null) {
            s.push(n1) ; 
            n1 = n1.left ; 
        }
        return n ; 
    }
}


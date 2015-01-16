/**
 * Definition of TreeNode:
 * public class TreeNode {
 * public int val;
 * public TreeNode left, right;
 * public TreeNode(int val) {
 * this.val = val;
 * this.left = this.right = null;
 * }
 * }
 */
/**
Given a root of Binary Search Tree with unique value for each node.  Remove the node with given value. If there is no such a node with given value in the binary search tree, do nothing. You should keep the tree still a binary search tree after removal 

Note: Implement it carefully . 
*/
public class Solution {
    /**
     * @param root:  The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    public TreeNode removeNode(TreeNode root, int value) {
        TreeNode[] nodes = find(root, value);

        if (nodes == null) return root;

        if (nodes[0].left == null && nodes[0].right == null) {
            if( nodes[1] == null)  root = null; // root.val == value
            return root;
        }

        TreeNode node = nodes[0] ;
        TreeNode r = findMinInRight(nodes[0]);
        TreeNode tmp  = null ;
        if (r != null) {
            r.left = node.left;
            r.right = node.right;
            tmp = inherit(nodes[1] , r ) ;


        } else {
            TreeNode l = findMaxInLeft(nodes[0]);
            if (l != null) {
                l.left = node.left;
                l.right = node.right;
                tmp = inherit(nodes[1] , l ) ;

            }
        }
        if(nodes[1] == null ) {
            root = tmp ;
        }
        return root;


    }
    protected TreeNode inherit(TreeNode parent  ,TreeNode child) {
        if(parent == null ) return child;
        if(parent.val > child.val) {
            parent.left = child ;
        }else{
            parent.right = child ;
        }
        return parent  ;
    }
    protected TreeNode findMaxInLeft(TreeNode root) {
        if(root == null || root.left == null ) return null;
        TreeNode n = root.left, prev = null;
        if(n.right == null ) {
            root.left = n.left ;
            n.left = null;
            return n ;
        }
        prev = n;
        n = n.right;

        while (n.right != null) {
            prev =  n ;
            n = n.right;
        }
        prev.right = n.left ;
        n.left = null;
        return n;
    }

    protected TreeNode findMinInRight(TreeNode root) {
        if(root== null || root.right == null )return null  ;

        TreeNode n = root.right, prev = null ;
        if(n.left == null ) {
            root.right = n.right ;
            n.right = null;
            return n ;
        }
        prev = n  ;
        n = n.left  ;

        while (n.left != null) {
            prev = n ;
            n = n.left;
        }
        prev.left = n.right ;
        n.right = null;

        return n;
    }

    // make parent.next = null if you can find one .
    protected TreeNode[] find(TreeNode root, int value) {
        TreeNode n = root, prev = null;

        while (n != null) {

            if (n.val < value) {
                prev = n;
                n = n.right;
            } else if (n.val > value) {
                prev = n;
                n = n.left;
            } else {
                if(prev!=null ) {
                    if (prev.val > n.val) {
                        prev.left = null;
                    } else {
                        prev.right = null;
                    }
                }
                return new TreeNode[]{n, prev};
            }
        }
        return null;
    }
    //  public static class TreeNode {
    //      public int val;
    //      public TreeNode left, right;

    //      public TreeNode(int val) {
    //          this.val = val;
    //          this.left = this.right = null;
    //      }
    //  }
    public static void main(String []args){
        TreeNode root = new TreeNode(2) ;
        root.right = new TreeNode(3) ;
        root.right.right = new TreeNode(4) ;
        Solution sol = new Solution() ;
        TreeNode nroot = sol.removeNode(root ,3 ) ;
        if(nroot==null) {
            System.out.println("NULL");
        }else{
            System.out.println(nroot.val);
        }
    }
}


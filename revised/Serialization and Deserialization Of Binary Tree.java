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
import java.util.* ;
class Solution {
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    public String serialize(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>() ;
        q.offer(root);
        StringBuilder sb = new StringBuilder() ;
        while(!q.isEmpty()) {
            TreeNode n = q.poll() ;
            if(n==null) {
                sb.append("#,") ;
            }else{
                sb.append(n.val+",") ;
            }

            if(n!=null) {
                q.offer(n.left) ;
                q.offer(n.right) ;
            }
        }
        return sb.toString();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    public TreeNode deserialize(String data) {
        this.charr = data.toCharArray() ;
        this.size = this.charr.length ;

        TreeNode root = null;
        root = give(next())  ;

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(root!=null) q.offer(root) ;
        while( hasNext()) {
            TreeNode l = give(next())  ;
            TreeNode r = give(next()) ;
            TreeNode p = q.poll() ;
            p.left  = l ; p.right = r  ;
            if(l!=null)  q.offer(l) ;
            if(r!=null)  q.offer(r) ;

        }
        return root;
    }
    private int pos = 0  ;
    private int size = 0 ;
    private char []charr = null;
    public boolean hasNext() {
        return  pos < size ;
    }
    public int next() {
        int i = pos ;
        if(charr[i] == '#' ) {
            pos = i + 2 ;
            return Integer.MIN_VALUE ;
        }
        int n =  0 ;
        while(charr[i] != ',') {
            n = 10*n + charr[i] - '0'  ;
            i++ ;
        }
        pos = i +1  ;
        return n ;

    }
    public TreeNode give(int  c) {
        TreeNode  n = null;
        if(c != Integer.MIN_VALUE) {
            n = new TreeNode(c ) ;
        }
        return n ;
    }
    public static class TreeNode {
        public int val;
        public TreeNode left, right;

        public TreeNode(int val) {
            this.val = val;
            this.left = this.right = null;
        }
    }
    public static void main(String []args){
        Solution sol = new Solution();
        TreeNode root = new TreeNode(1) ;
        TreeNode N = root ;
        root.left = new TreeNode(2) ;
        root.right = new TreeNode(3) ;
        root = root.right ;
        root.left = new TreeNode(4) ;
        root.right = new TreeNode(5) ;
        root.right.right = new TreeNode(10) ;
        root =root.left  ;
        root.left = new TreeNode(6) ;
        root.right = new TreeNode(7) ;

        root =root.right ;
        root.left = new TreeNode(8) ; root.right = new TreeNode(9) ;

        root =root.left ;
        root.left = new TreeNode(12) ;root.right =new TreeNode(13) ;
        root = root.right ;
        root.right = new TreeNode(14)  ;

        String s = sol.serialize(N ) ;
        TreeNode n = sol.deserialize(s) ;

    }
}



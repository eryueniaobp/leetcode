/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * O(n) 遍历一遍
 */
 // Solution 1 : the most direct way .using iterative way to solve it  

public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        Stack<TreeNode> st = new Stack<TreeNode>(); 
        TreeNode n = root;
        boolean touch = false ; 
        int pre = Integer.MIN_VALUE ; 
        while(!st.isEmpty() || n!=null ) {
            while(n!=null) {
                st.push(n) ; 
                n = n.left ; 
            }
            if(!st.isEmpty()){
                n = st.pop() ; 
                if( n.val > pre || (!touch && n.val == Integer.MIN_VALUE ) ) {
                    pre = n.val ; 
                }else{
                    return false; 
                }
                touch = true ; 
                n = n.right ; 
            }
        }
        return true ; 
    }
}
// Solution 2: the method is not very direct . but the code is most compact ! 
class Solution {
public:
    bool check(TreeNode *node, int leftVal, int rightVal)
    {
        if (node == NULL)
            return true;
        return leftVal < node->val && node->val < rightVal && check(node->left, leftVal, node->val) &&
            check(node->right, node->val, rightVal);
        //return check(node->left, leftVal, node->val) && (leftVal < node->val && node->val < rightVal) && check(node->right, node->val, rightVal);
        //return check(node->left, leftVal, node->val) &&check(node->right, node->val, rightVal) &&  (leftVal < node->val && node->val < rightVal);
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root, INT_MIN, INT_MAX);        
    }
};
// More consistent one solution . consider the boundary of int .
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        if(root == null ) return true ; 
        return dfs(root , Integer.MIN_VALUE , Integer.MAX_VALUE) ; 
    }
    public boolean dfs(TreeNode root , int left , int right) {
        if(root == null ) return true ; 
        if(root.val == Integer.MAX_VALUE) {
            return root.val > left && root.right == null && dfs(root.left ,left,root.val) ;  
        }
        if(root.val == Integer.MIN_VALUE) {
            return root.val < right && root.left == null && dfs(root.right,root.val , right) ; 
        }
        return root.val<right && root.val >left && dfs(root.left , left , root.val) 
        && dfs(root.right, root.val , right) ; 
    }
}



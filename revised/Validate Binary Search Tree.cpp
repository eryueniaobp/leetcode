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
class Solution {
public:
    bool check(TreeNode *node, int leftVal, int rightVal)
    {
        if (node == NULL)
            return true;
            
        return leftVal < node->val && node->val < rightVal && check(node->left, leftVal, node->val) &&
            check(node->right, node->val, rightVal);
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


